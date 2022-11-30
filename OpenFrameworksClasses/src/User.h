#pragma once
#include "ofMain.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "TimeSlots.h"

#include "Match.h"

class User
{
public:
    int id;
    string name;
    TimeSlots *timeSlots;
    vector<User *> *acceptedUsers;
    vector<User *> *declinedUsers;
    vector<Match *> *matches;

    int userToEvalId;

    User(int id_)
    {
        userToEvalId = 0;

        name = to_string(id_);
        id = id_;
        timeSlots = new TimeSlots();

        acceptedUsers = new vector<User *>;
        declinedUsers = new vector<User *>;
        matches = new vector<Match *>;
    }
};