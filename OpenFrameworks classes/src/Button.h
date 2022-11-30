#pragma once
#include "ofMain.h"

class Button
{

public:
    bool clicked = false;
    string label;
    int x;
    int y;
    int w;
    int h;
    ofColor renderColor;

    Button(string label_, int x_, int y_, int w_, int h_, ofColor color)
    {
        label = label_;
        x = x_;
        y = y_;
        w = w_;
        h = h_;
        renderColor = color;
    };

    void render()
    {
        render(renderColor);
    };

    void render(ofColor color)
    {
        ofSetColor(color);
        ofDrawRectangle(x, y, w, h);

        ofSetColor(255);

        if (color == ofColor::green)
        {
            ofSetColor(0);
        }

        ofDrawBitmapString(label, x, y + 10);
    }
};