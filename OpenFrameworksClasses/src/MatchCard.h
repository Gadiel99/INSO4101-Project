#pragma once
#include "ofMain.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Match.h"

class MatchCard
{
public:
    string cardName;
    vector<Match *> *matches;
    int x;
    int y;
    int w;

    MatchCard(string cardName_, vector<Match *> *matches_, int x_, int y_, int w_)
    {
        cardName = cardName_;
        matches = matches_;

        x = x_;
        y = y_;
        w = w_;
    };

    void updateCard(vector<Match *> *matches_)
    {
        matches = matches_;
    }

    void render()
    {
        ofSetColor(100);

        int h = 50;
        h = h + (matches->size() * 50);
        ofDrawRectangle(x, y, w, h);

        ofSetColor(255);
        ofDrawBitmapString(cardName, x, y + 10);

        int newY = y + 30;

        if (matches->size() == 0)
        {
            ofDrawBitmapString("empty", x, newY);
            return;
        }

        for (Match *match : *matches)
        {
            ofDrawBitmapString("Match between: ", x, newY);
            ofDrawBitmapString("  User: " + match->user1Id, x, newY + 11);
            ofDrawBitmapString("  User: " + match->user2Id, x, newY + 22);
            ofDrawBitmapString("  Place: " + match->matchPlace, x, newY + 33);
            ofDrawBitmapString("  TimeSlot: " + match->matchTimeSlot, x, newY + 44);

            newY += 100;
        }
    }
};