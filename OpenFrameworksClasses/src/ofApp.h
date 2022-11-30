#pragma once
#include "ofMain.h"
#include "Deck.h"
class ofApp : public ofBaseApp
{
public:
	Deck *deck;
	void setup(){
		deck = new Deck();
	};
	void update(){
		deck->handler->update();
	};
	void draw(){
		deck->render();
	};
	void mousePressed(int x, int y, int button){
		if (deck->showingTimeSlots)
				
						{if ((deck->viewTimeSlots->x <= x) && (x <= (deck->viewTimeSlots->x + deck->viewTimeSlots->w)) && (deck->viewTimeSlots->y <= y) && (y <= (deck->viewTimeSlots->y + deck->viewTimeSlots->h))){
					deck->viewTimeSlots->clicked = true;} //first check timeslot button

			for (std::map<string, tuple<vector<Button *> *, vector<bool> *> *>::iterator it = deck->currentUser->timeSlots->daysButtons.begin(); it != deck->currentUser->timeSlots->daysButtons.end(); ++it){ for (int i = 0; i < get<0>(*it->second)->size(); i++){
					//then check each button inside the list of buttons inside the value of each day key 
					int tsX, tsY, tsW, tsH;
					tsX = get<0>(*it->second)->at(i)->x;
					tsY = get<0>(*it->second)->at(i)->y;
					tsW = get<0>(*it->second)->at(i)->w;
					tsH = get<0>(*it->second)->at(i)->h;
						if ((tsX <= x) && (x <= (tsX + tsW)) && (tsY <= y) && (y <= (tsY + tsH))){
					get<0>(*it->second)->at(i)->clicked = true;}}}
			return; //return cause no other buttons can be clicked
		}

		for (Button *btn : deck->buttons){
			if ((btn->x <= x) && (x <= (btn->x + btn->w)) && (btn->y <= y) && (y <= (btn->y + btn->h))){
		btn->clicked = true;} //else check every button inside deck's button list
		}
	};
	

private:
};
