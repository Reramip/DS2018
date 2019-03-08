#include"utility.h"
#include"maze.h"
#include"wall.h"
#include"player.h"
#include"acllib.h"
#include<time.h>
#include<vector>
using namespace std;

Maze m;
Player p;
vector<Wall> v;

void build();
void judgeAndPush(Wall& wall);
void keyboardEvent(int key, int event);
void find(int& x,int& y);

int Setup() {
    build();
    initWindow("Maze", 0, 0, LENGTH*PX + PX, WIDTH*PX + PX * 3);
    m.show();
    p.show();
    registerKeyboardEvent(keyboardEvent);

    return 0;
}

void build() {
    srand((unsigned int)time(NULL));
    int rand_x = rand() % LENGTH;
    int rand_y = rand() % WIDTH;
    v.push_back(Wall(rand_x, rand_y, UP));
    v.push_back(Wall(rand_x, rand_y, DOWN));
    v.push_back(Wall(rand_x, rand_y, LEFT));
    v.push_back(Wall(rand_x, rand_y, RIGHT));
    m.changeVisited(rand_x,rand_y);
    while (v.size() > 0) {
        int random = rand() % v.size();
        judgeAndPush(v[random%v.size()]);
        auto itr = v.begin() + random;
        v.erase(itr);
    }
}

void judgeAndPush(Wall& wall) {
    int x = wall.x, y = wall.y, type = wall.type;
    switch (type) {
    case UP:
        if (y > 0) {
            if (!m.getVisited(x,y-1)) {
                m.changeWall(x,y,UP);
                m.changeWall(x,y-1,DOWN);
                m.changeVisited(x, y - 1);
                v.push_back(Wall(x, y - 1, UP));
                v.push_back(Wall(x, y - 1, LEFT));
                v.push_back(Wall(x, y - 1, RIGHT));
            }
        }
        break;
    case DOWN:
        if (y < WIDTH - 1) {
            if (!m.getVisited(x,y+1)) {
                m.changeWall(x, y, DOWN); 
                m.changeWall(x, y + 1, UP);
                m.changeVisited(x, y + 1);
                v.push_back(Wall(x, y + 1, DOWN));
                v.push_back(Wall(x, y + 1, LEFT));
                v.push_back(Wall(x, y + 1, RIGHT));
            }
        }
        break;
    case LEFT:
        if (x > 0) {
            if (!m.getVisited(x-1, y)) {
                m.changeWall(x, y, LEFT);
                m.changeWall(x - 1, y, RIGHT);
                m.changeVisited(x-1, y);
                v.push_back(Wall(x - 1, y, UP));
                v.push_back(Wall(x - 1, y, DOWN));
                v.push_back(Wall(x - 1, y, LEFT));
            }
        }
        break;
    case RIGHT:
        if (x < LENGTH - 1) {
            if (!m.getVisited(x + 1, y)) {
                m.changeWall(x, y, RIGHT);
                m.changeWall(x+1, y, LEFT);
                m.changeVisited(x + 1, y);
                v.push_back(Wall(x + 1, y, UP));
                v.push_back(Wall(x + 1, y, DOWN));
                v.push_back(Wall(x + 1, y, RIGHT));
            }
        }
        break;
    default:
        break;
    }
}

void keyboardEvent(int key, int event) {
    if (event != KEY_DOWN) {
        return;
    }
    switch (key) {
    case VK_UP:
        if (!m.getWall(p.x,p.y,UP)) {
            p.y--;
            p.show();
        }
        break;
    case VK_DOWN:
        if (!m.getWall(p.x,p.y,DOWN)) {
            p.y++;
            p.show();
        }
        break;
    case VK_LEFT:
        if (!m.getWall(p.x,p.y,LEFT) && p.x>0) {
            p.x--;
            p.show();
        }
        break;
    case VK_RIGHT:
        if (!m.getWall(p.x,p.y,RIGHT) && p.x<LENGTH - 1) {
            p.x++;
            p.show();
        }
        break;
    case 0x45:
        find(p.x,p.y);
        break;
    case 0x51:
        exit(0);
    }
}
