#include"maze.h"
#include"player.h"
#include"acllib.h"
#include<stack>
using namespace std;

extern Maze m;
extern Player p;
stack<Player> s;
int x, y;

void timerEvent(int id) {
    if (id == 0) {
        x = s.top().x;
        y = s.top().y;
        m.changeVisitedTo1(x, y);
        p.move(x, y);
        p.show();
        if (x == LENGTH - 1 && y == WIDTH - 1) {
            cancelTimer(0);
            return;
        }
        if (!m.getWall(x, y, DOWN) && y<(WIDTH - 1) && !m.getVisited(x, y + 1)) {
            s.push(Player(x, y + 1));
        }
        else if (!m.getWall(x, y, RIGHT) && (x<LENGTH - 1) && !m.getVisited(x + 1, y)) {
            s.push(Player(x + 1, y));
        }
        else if (!m.getWall(x, y, UP) && y>0 && !m.getVisited(x, y - 1)) {
            s.push(Player(x, y - 1));
        }
        else if (!m.getWall(x, y, LEFT) && x>0 && !m.getVisited(x - 1, y)) {
            s.push(Player(x - 1, y));
        }
        else {
            s.pop();
        }
    }
}

void find(int& xx,int& yy) {
    m.initVisited();
    s.push(Player(xx,yy));
    m.changeVisited(xx, yy);
    x = xx; y = yy;
    registerTimerEvent(timerEvent);
    startTimer(0, 50);
    timerEvent(0);
}

