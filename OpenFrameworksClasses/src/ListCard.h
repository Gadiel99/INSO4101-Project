#pragma once
#include "ofMain.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "User.h"

class ListCard
{
public:
    string cardName;

    vector<User *> *listToShow;

    int x;
    int y;
    int w;

    ListCard(string name_, vector<User *> *listToShow_, int x_, int y_, int w_)
    {
        cardName = name_;
        listToShow = listToShow_;

        x = x_;
        y = y_;
        w = w_;
    };

    void updateCard(vector<User *> *listToShow_)
    {
        listToShow = listToShow_;
    }

    void render()
    {
        ofSetColor(100);

        int h = 50;
        h = h + (listToShow->size() * 40);
        ofDrawRectangle(x, y, w, h);

        ofSetColor(255);
        ofDrawBitmapString(cardName, x, y + 10);

        int newY = y + 30;

        if (listToShow->size() == 0)
        {
            ofDrawBitmapString("empty", x, newY);
            return;
        }

        for (User *user : *listToShow)
        {
            ofDrawBitmapString("Name: " + user->name, x, newY);
            ofDrawBitmapString("Id: " + to_string(user->id), x, newY + 15);

            newY += 40;
        }
    }
};