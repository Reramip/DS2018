#pragma once
#include"utility.h"

class Maze {
    struct Wall {
        bool up, down, left, right;
    };
public:
    Maze();
    ~Maze();
    void show();
    bool getVisited(int x, int y);
    bool getWall(int x, int y, int type);
    void changeWall(int x, int y, int type);
    void changeVisited(int x, int y);
    void changeVisitedTo1(int x, int y);
    void changeVisitedTo0(int x, int y);
    friend void judgeAndPush();
    void initVisited();
private:
    bool visited[WIDTH][LENGTH];
    Wall wall[WIDTH][LENGTH];
    void init();
};
