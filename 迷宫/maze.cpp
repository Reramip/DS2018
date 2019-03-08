#include"maze.h"
#include"acllib.h"
using namespace std;

Maze::Maze() {
    init();
}

Maze::~Maze() {
    ;
}

void Maze::init() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            wall[i][j].up = true;
            wall[i][j].down = true;
            wall[i][j].left = true;
            wall[i][j].right = true;
            visited[i][j] = false;
        }
    }
    wall[0][0].left = false;
    //visited[0][0] = true;
    //v.push_back(Wall(0, 0, DOWN));
    //v.push_back(Wall(0, 0, RIGHT));
    wall[WIDTH - 1][LENGTH - 1].right = false;
}

void Maze::show() {
    beginPaint();
    setPenWidth(1);
    setPenColor(BLACK);
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (wall[i][j].up == true) {
                moveTo(j*PX, i*PX);
                lineTo(j*PX + PX, i*PX);
            }
            if (wall[i][j].down == true) {
                moveTo(j*PX, i*PX + PX);
                lineTo(j*PX + PX, i*PX + PX);
            }
            if (wall[i][j].left == true) {
                moveTo(j*PX, i*PX);
                lineTo(j*PX, i*PX + PX);
            }
            if (wall[i][j].right == true) {
                moveTo(j*PX + PX, i*PX);
                lineTo(j*PX + PX, i*PX + PX);
            }
        }
    }
    setTextSize(16);
    paintText(0, WIDTH*PX + PX, "方向键移动，按E自动寻路，按Q退出。");
    endPaint();
}

bool Maze::getVisited(int x, int y) {
    return visited[y][x];
}

bool Maze::getWall(int x, int y, int type) {
    switch (type) {
    case UP:
        return wall[y][x].up;
    case DOWN:
        return wall[y][x].down;
    case LEFT:
        return wall[y][x].left;
    case RIGHT:
        return wall[y][x].right;
    default:break;
    }
    return false;
}

void Maze::changeWall(int x, int y, int type) {
    switch (type) {
    case UP:
        wall[y][x].up ^= 1;
        break;
    case DOWN:
        wall[y][x].down ^= 1;
        break;
    case LEFT:
        wall[y][x].left ^= 1;
        break;
    case RIGHT:
        wall[y][x].right ^= 1;
        break;
    default:break;
    }
}

void Maze::changeVisited(int x, int y) {
    visited[y][x] ^= 1;
}

void Maze::changeVisitedTo1(int x, int y) {
    visited[y][x] = 1;
}

void Maze::changeVisitedTo0(int x, int y) {
    visited[y][x] = 0;
}

void Maze::initVisited() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            visited[i][j] = false;
        }
    }
}
