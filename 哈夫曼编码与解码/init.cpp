#include"utility.h"
char alphabet[ALPHABET];
void init(Node* tree, Code* code) {
    for (int i = 0; i < MAX_NODE; ++i) {
        tree[i].weight = 0;
        tree[i].left = -1;
        tree[i].right = -1;
        tree[i].parent = -1;
        tree[i].bit = 0;
    }
    for (int i = 0; i < ALPHABET; ++i) {
        alphabet[i] = i + 'a';
    }
}
