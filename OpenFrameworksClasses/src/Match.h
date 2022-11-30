#pragma once
#include "ofMain.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

class Match
{

public:
    string matchPlace = "undefined";
    string matchTimeSlot;
    string user1Id;
    string user2Id;

    Match(string ts, string id1, string id2)
    {
        matchTimeSlot = ts;
        user1Id = id1;
        user2Id = id2;
    }
};