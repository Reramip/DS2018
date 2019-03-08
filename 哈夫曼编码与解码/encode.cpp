#include"utility.h"
using namespace std;

void encode(Node* tree, Code* code) {
    for (int i = 0; i < MAX_NODE - 1; ++i) {
        if (tree[tree[i].parent].left == i) {
            tree[i].bit = 0;
        }
        else if (tree[tree[i].parent].right == i) {
            tree[i].bit = 1;
        }
    }
    tree[MAX_NODE - 1].bit = 1;
    for (int i = 0; i < ALPHABET; ++i) {
        int j = i;
        while (tree[j].parent != -1) {
            code[i].bit.insert(code[i].bit.begin(), tree[j].bit);
            j = tree[j].parent;
        }
    }
}
