#include"utility.h"
#include<fstream>
using namespace std;
extern char alphabet[];
void readOutFileDecompression(ifstream& fin, ofstream& fout, Node* tree) {
    int bit_size;
    fin >> bit_size;
    int read_size = 0;
    int left_size = bit_size % 8;
    for (int i = 0; i < MAX_NODE; ++i) {
        fin >> tree[i].weight >> tree[i].left >> tree[i].right >> tree[i].parent >> tree[i].bit;
    }
    char temp;
    fin.get(temp);
    char byte = 0;
    int i = MAX_NODE - 1;
    int position = 7;
    bool bit_now;
    bool flag = 0;
    while (fin.peek() != EOF) {
        fin.get(byte);
        position = 7;
        while (position >= 0) {
            bit_now = (byte >> position) & 1;
            if (!(tree[i].left == -1 && tree[i].right == -1)) {
                if (bit_now) {
                    i = tree[i].right;
                }
                else {
                    i = tree[i].left;
                }
                position--;
                read_size++;
                flag = 0;
            }
            else if (tree[i].left == -1 && tree[i].right == -1) {
                fout << alphabet[i];
                i = MAX_NODE - 1;
                flag = 1;
            }
        }
        if (bit_size - read_size == left_size) {
            break;
        }
    }
    fin.get(byte);
    if (flag && (fin.peek() != EOF)) {
        i = MAX_NODE - 1;
    }
    position = 7;
    for (int j = 0; j < left_size; ++j) {
        if (!(tree[i].left == -1 && tree[i].right == -1)) {
            bit_now = (byte >> position) & 1;
            if (bit_now) {
                i = tree[i].right;
            }
            else {
                i = tree[i].left;
            }
            position--;
        }
        else if (tree[i].left == -1 && tree[i].right == -1) {
            fout << alphabet[i];
            i = MAX_NODE - 1;
        }
    }
}
