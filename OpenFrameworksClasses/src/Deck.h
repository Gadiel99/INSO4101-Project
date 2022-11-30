#pragma once
#include "ofMain.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "User.h"
#include "Button.h"
#include "Card.h"
#include "ListCard.h"
#include "MatchCard.h"

class Deck{
public:
    class DeckLogicHandler{
    public:
        Deck *deck;
            DeckLogicHandler(Deck *deck_){deck = deck_;}
        void update(){
            
            handleButtons();

            if (deck->showingTimeSlots){
                deck->currentUser->timeSlots->update();}

            checkForMatches();

            deck->currUserCard->updateCard(deck->currentUser);
            deck->userToEvalCard->updateCard(deck->userToEval);
            deck->allUsersCard->updateCard(deck->allUsers);
            deck->acceptedUsersCard->updateCard(deck->currentUser->acceptedUsers);
            deck->declinedUsersCard->updateCard(deck->currentUser->declinedUsers);
            deck->matchesCard->updateCard(deck->currentUser->matches);
        }

        void handleButtons(){
        if (deck->addUser->clicked){
            deck->addUser->clicked = false;

                newUser(deck->allUsers->size());
                if (deck->userToEval->name == "Dummy"){
                    deck->userToEval = deck->allUsers->at(deck->allUsers->size()-1);}} 

        else
        if (deck->switchUser->clicked){
        deck->switchUser->clicked = false;

                deck->currentUserId++;
                if (deck->currentUserId == deck->allUsers->size()){
                    deck->currentUserId = 0;}

                deck->currentUser = deck->allUsers->at(deck->currentUserId);

                if (deck->currentUser->userToEvalId == deck->allUsers->size()){
                    deck->userToEval = deck->noMoreUsers;}
                else {
                    deck->userToEval = deck->allUsers->at(deck->currentUser->userToEvalId);}}
            
        else
        if (deck->viewTimeSlots->clicked){
            deck->viewTimeSlots->clicked = false;
                
                deck->showingTimeSlots = !deck->showingTimeSlots;}
            
        else 
        if (deck->declineUser->clicked){
            deck->declineUser->clicked = false;
                
                if (deck->currentUser->userToEvalId == deck->allUsers->size()){
                    return;}

                deck->currentUser->declinedUsers->push_back(deck->allUsers->at(deck->currentUser->userToEvalId));

                deck->currentUser->userToEvalId++;

                if (deck->currentUser->userToEvalId == deck->allUsers->size()){
                    deck->userToEval = deck->noMoreUsers;
                    return;}
                
                deck->userToEval = deck->allUsers->at(deck->currentUser->userToEvalId);}
            
        else 
        if (deck->acceptUser->clicked){
            deck->acceptUser->clicked = false;
                
                if (deck->currentUser->userToEvalId == deck->allUsers->size()){
                    return;}

                if (deck->currentUser->id == deck->currentUser->userToEvalId){
                    deck->declineUser->clicked = true;
                    handleButtons();
                    return;}

                deck->currentUser->acceptedUsers->push_back(deck->allUsers->at(deck->currentUser->userToEvalId));
                deck->currentUser->userToEvalId++;

                if (deck->currentUser->userToEvalId == deck->allUsers->size()){
                    deck->userToEval = deck->noMoreUsers;
                    return;}
                deck->userToEval = deck->allUsers->at(deck->currentUser->userToEvalId);}
        };

        void checkForMatches(){
            vector<string> currUserAvailableTimeSlots = deck->currentUser->timeSlots->getAvailableTimeSlots();
            if (currUserAvailableTimeSlots.size() == 0){
                return;}

            if (deck->currentUser->acceptedUsers->empty())
            {return;}

            for (User *acceptedUser : *deck->currentUser->acceptedUsers){
                bool bothAcceptedEachOther = false;
                if (acceptedUser->acceptedUsers->empty())
                {continue;}
                else
                {for (User *acceptedUserAcceptedUser : *acceptedUser->acceptedUsers){
                    if (acceptedUserAcceptedUser->id == deck->currentUser->id)
                    {bothAcceptedEachOther = true;}}
                }
                if (!bothAcceptedEachOther)
                {continue;}


                vector<string> acceptedUserAvailableTimeSlots = acceptedUser->timeSlots->getAvailableTimeSlots();
                if (acceptedUserAvailableTimeSlots.size() == 0)
                {continue;}
                
                string timeSlotInCommon = "";

                for (string currTS : currUserAvailableTimeSlots){
                    for (string accTS : acceptedUserAvailableTimeSlots){
                        if (currTS == accTS){
                            timeSlotInCommon = currTS;
                            break;}
                    } if (timeSlotInCommon != ""){
                        break;}
                } if (timeSlotInCommon == ""){
                    continue;}

                string name1 = deck->currentUser->name;

                deck->currentUser->matches->push_back(new Match(timeSlotInCommon, name1, acceptedUser->name));
                acceptedUser->matches->push_back(new Match(timeSlotInCommon, acceptedUser->name, name1));

                vector<User *>::iterator newEnd;
                newEnd = remove(deck->currentUser->acceptedUsers->begin(), deck->currentUser->acceptedUsers->end(), acceptedUser);

                deck->currentUser->acceptedUsers->pop_back();
                vector<User *>::iterator newEnd2;
                newEnd2 = remove(acceptedUser->acceptedUsers->begin(), acceptedUser->acceptedUsers->end(), deck->currentUser);
                acceptedUser->acceptedUsers->pop_back();
                vector<string>::iterator newEnd3;
                newEnd3 = remove(currUserAvailableTimeSlots.begin(), currUserAvailableTimeSlots.end(), timeSlotInCommon);
            };
        }
        void newUser(int id){deck->allUsers->push_back(new User(id));}
    };

    int currentUserId;
    User *currentUser;
    User *userToEval;
    User *noMoreUsers;

    vector<User *> *allUsers;

    Card *currUserCard;
    Card *userToEvalCard;
    ListCard *allUsersCard;
    ListCard *acceptedUsersCard;
    ListCard *declinedUsersCard;
    MatchCard *matchesCard;

    Button *addUser;
    Button *switchUser;
    Button *viewTimeSlots;
    Button *acceptUser;
    Button *declineUser;
    vector<Button *> buttons;
    bool showingTimeSlots = false;

    Deck::DeckLogicHandler *handler;
    Deck(){
        noMoreUsers = new User(-1);
        noMoreUsers->name = "Dummy";
        // initialize users
        currentUserId = 0;

        allUsers = new vector<User *>;
        allUsers->push_back(new User(0));
        currentUser = allUsers->at(0);

        userToEval = allUsers->at(0);
        allUsers->push_back(new User(1));


        // initialize cards
        currUserCard = new Card("Current User", currentUser, 250, 10, 100, 60);
        userToEvalCard = new Card("User to Eval", currentUser, 250, 170, 100, 60);

        // initialize list cards
        allUsersCard = new ListCard("All Users", allUsers, 10, 10, 100);
        acceptedUsersCard = new ListCard("Acccepted Users", currentUser->acceptedUsers, 420, 10, 130);
        declinedUsersCard = new ListCard("Declined Users", currentUser->declinedUsers, 600, 10, 120);
        matchesCard = new MatchCard("Matches", currentUser->matches, 800, 10, 120);

        addUser = new Button("+", 120, 10, 30, 30, ofColor(100, 100, 100));
        switchUser = new Button(">", 120, 60, 30, 30, ofColor(100, 100, 100));
        viewTimeSlots = new Button("TS", 285, 110, 30, 30, ofColor(100, 100, 100));
        acceptUser = new Button("Accept", 310, 250, 90, 30, ofColor::green);
        declineUser = new Button("Decline", 210, 250, 90, 30, ofColor::red);

        buttons = {addUser, switchUser, viewTimeSlots, acceptUser, declineUser};

        handler = new Deck::DeckLogicHandler(this);
    }

    void render(){
        ofSetColor(0);
        ofFill();
        ofDrawRectangle(0, 0, 1000, 1000);
        if (showingTimeSlots){
            currentUser->timeSlots->render();
            viewTimeSlots->render();
        return;}

        currUserCard->render();
        userToEvalCard->render();
        allUsersCard->render();
        acceptedUsersCard->render();
        declinedUsersCard->render();
        matchesCard->render();

        for (Button *btn : buttons){
            btn->render();}
    }
};
