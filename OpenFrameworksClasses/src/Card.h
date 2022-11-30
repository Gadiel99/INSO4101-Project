#pragma once
#include "ofMain.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "User.h"

class Card
{
public:
    string cardName;
    int id;
    string name;

    int x;
    int y;
    int w;
    int h;

    Card(string cardName_, User *user, int x_, int y_, int w_, int h_)
    {
        cardName = cardName_;
        id = user->id;
        name = user->name;

        x = x_;
        y = y_;
        w = w_;
        h = h_;
    };

    void updateCard(User *user)
    {
        id = user->id;
        name = user->name;
    };

    void render()
    {
        ofSetColor(100);
        ofDrawRectangle(x, y, w, h);
        ofSetColor(255);
        ofDrawBitmapString(cardName, x, y + 10);

        if (name == "Dummy")
        {
            ofDrawBitmapString("No More Users", x, y + 40);
            ofDrawBitmapString("  To Eval", x, y + 55);
            return;
        }

        ofDrawBitmapString("Name: " + name, x, y + 40);
        ofDrawBitmapString("Id: " + to_string(id), x, y + 55);
    };
};