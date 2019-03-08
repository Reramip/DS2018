#pragma once
#include<vector>

struct Node {
    int weight, left, right, parent;
    bool bit;
};

struct Code {
    std::vector<bool> bit;
};
