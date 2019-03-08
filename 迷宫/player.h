#pragma once
#include"utility.h"

struct Player {
    int x, y;
    Player();
    Player(int x, int y);
    ~Player();
    void show();
    void move(int x, int y);
};
