#pragma once

struct Wall {
    int x, y, type;
    Wall(int xx, int yy, int ttype) :x(xx), y(yy), type(ttype) {}
};
