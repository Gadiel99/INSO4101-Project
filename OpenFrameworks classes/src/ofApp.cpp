
#pragma once
#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup()
{
    deck = new Deck();
};

//--------------------------------------------------------------
void ofApp::update()
{
    deck->handler->update();
};
//--------------------------------------------------------------
void ofApp::draw()
{
    deck->render();
};

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

};

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

};

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

    if (deck->showingTimeSlots)
    {
        if ((deck->viewTimeSlots->x <= x) && (x <= (deck->viewTimeSlots->x + deck->viewTimeSlots->w)) && (deck->viewTimeSlots->y <= y) && (y <= (deck->viewTimeSlots->y + deck->viewTimeSlots->h)))
        {
            deck->viewTimeSlots->clicked = true;
        }

        for (std::map<string, tuple<vector<Button *> *, vector<bool> *> *>::iterator it = deck->currentUser->timeSlots->daysButtons.begin(); it != deck->currentUser->timeSlots->daysButtons.end(); ++it)
        {

            for (int i = 0; i < get<0>(*it->second)->size(); i++)
            {
                int tsX, tsY, tsW, tsH;
                tsX = get<0>(*it->second)->at(i)->x;
                tsY = get<0>(*it->second)->at(i)->y;
                tsW = get<0>(*it->second)->at(i)->w;
                tsH = get<0>(*it->second)->at(i)->h;

                if ((tsX <= x) && (x <= (tsX + tsW)) && (tsY <= y) && (y <= (tsY + tsH)))
                {
                    get<0>(*it->second)->at(i)->clicked = true;
                }
            }
        }

        return;
    }

    for (Button *btn : deck->buttons)
    {

        if ((btn->x <= x) && (x <= (btn->x + btn->w)) && (btn->y <= y) && (y <= (btn->y + btn->h)))
        {
            btn->clicked = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

//--------------------------------------------------------------
