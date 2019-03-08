#pragma once
#include"player.h"
#include"acllib.h"

Player::Player() :x(0), y(0){
    ;
}

Player::Player(int xx, int yy) : x(xx), y(yy) {
    ;
}

Player::~Player() {
    ;
}

void Player::show() {
    beginPaint();
    setPenWidth(10);
    setPenColor(RED);
    moveTo(x*PX + PX / 2, y*PX + PX / 2);
    lineTo(x*PX + PX / 2, y*PX + PX / 2);
    setPenColor(WHITE);
    moveTo(x*PX - PX / 2, y*PX + PX / 2);
    lineTo(x*PX - PX / 2, y*PX + PX / 2);
    moveTo(x*PX + PX / 2, y*PX - PX / 2);
    lineTo(x*PX + PX / 2, y*PX - PX / 2);
    moveTo(x*PX + PX / 2 + PX, y*PX + PX / 2);
    lineTo(x*PX + PX / 2 + PX, y*PX + PX / 2);
    moveTo(x*PX + PX / 2, y*PX + PX / 2 + PX);
    lineTo(x*PX + PX / 2, y*PX + PX / 2 + PX);
    endPaint();
}

void Player::move(int x, int y) {
    this->x = x;
    this->y = y;
}
