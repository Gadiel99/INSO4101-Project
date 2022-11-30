#pragma once
#include "ofMain.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include "Button.h"

using namespace std;

class TimeSlots
{

public:
    // map<string, vector<bool> *> days;
    map<string, tuple<vector<Button *> *, vector<bool> *> *> daysButtons;
    vector<bool> *hours;
    vector<Button *> *buttons;

    vector<string> initials;

    vector<string> hoursStrings;

    vector<string> getAvailableTimeSlots(){
        vector<string> availableTimeSlots;
        for (std::map<string, tuple<vector<Button *> *, vector<bool> *> *>::iterator it = daysButtons.begin(); it != daysButtons.end(); ++it){
            for (int i = 0; i < get<0>(*it->second)->size(); i++){
                if (get<1>(*it->second)->at(i) == true){
                    availableTimeSlots.push_back(it->first + hoursStrings.at(i));}
        }}
        return availableTimeSlots;
    }

    TimeSlots(){
        initials = {"D", "L", "K", "M", "J", "V", "S"};
        hoursStrings = {"6am", "7am", "8am", "9am", "10am", "11am", "12pm", "1pm", "2pm", "3pm", "4pm", "5pm", "6pm", "7pm", "8pm", "9pm"};

        int newX = 400;
        for (string day : initials){
            hours = new vector<bool>(16, false);
            buttons = new vector<Button *>;

            int newY = 80;
            for (int i = 0; i < hours->size(); i++){
                buttons->push_back(new Button("", newX, newY, 20, 20, ofColor(100)));
                newY += 40;}
            
            tuple<vector<Button *> *, vector<bool> *> *tp = new tuple<vector<Button *> *, vector<bool> *>(buttons, hours);
            daysButtons[day] = tp;
            newX += 64;
        }
    }

    void update()
    {
        for (std::map<string, tuple<vector<Button *> *, vector<bool> *> *>::iterator it = daysButtons.begin(); it != daysButtons.end(); ++it){
            for (int i = 0; i < get<0>(*it->second)->size(); i++){
                if (get<0>(*it->second)->at(i)->clicked){
                    get<1>(*it->second)->at(i) = !get<1>(*it->second)->at(i);
                    get<0>(*it->second)->at(i)->clicked = false;
                }
            }
        }
    }

    void render()
    {
        ofFill();
        ofSetColor(150);
        ofDrawRectangle(350, 20, 500, 1000);

        ofSetColor(255);
        ofDrawBitmapString("time slots", 360, 30);

        ofDrawBitmapString("D       L       K       M       J       V       S", 405, 60);

        int newY = 90;
        int i = 0;
        for (string time : hoursStrings)
        {
            ofDrawBitmapString(time, 360, newY + i);
            i += 40;
        }

        for (std::map<string, tuple<vector<Button *> *, vector<bool> *> *>::iterator it = daysButtons.begin(); it != daysButtons.end(); ++it)
        {

            for (int i = 0; i < get<0>(*it->second)->size(); i++)
            {

                if (get<1>(*it->second)->at(i) == false)
                {
                    get<0>(*it->second)->at(i)->render(ofColor::blue);
                }
                else
                {
                    get<0>(*it->second)->at(i)->render(ofColor::green);
                }
            }
        }
    }
};