#include"utility.h"
using namespace std;
void buildTree(Node* tree) {
    for (int i = ALPHABET; i < MAX_NODE; ++i) {
        int min_fre1 = MAX_FREQUENCY, min_fre2 = MAX_FREQUENCY;
        int min_num1 = -1, min_num2 = -1;
        for (int j = 0; j < i; ++j) {
            if (tree[j].parent == -1 && tree[j].weight < min_fre1) {
                min_fre2 = min_fre1;
                min_num2 = min_num1;
                min_fre1 = tree[j].weight;
                min_num1 = j;
            }
            else if (tree[j].parent == -1 && tree[j].weight < min_fre2) {
                min_fre2 = tree[j].weight;
                min_num2 = j;
            }
        }
        tree[min_num1].parent = tree[min_num2].parent = i;
        tree[i].weight = tree[min_num1].weight + tree[min_num2].weight;
        tree[i].left = min_num1;
        tree[i].right = min_num2;
    }
}

