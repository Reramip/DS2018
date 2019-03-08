#include"utility.h"
#include<fstream>
using namespace std;

void outFileCompression(ofstream& fout, ifstream& fin, Code* code, Node* tree) {
    char chrin;
    char byte = 0;
    int position = 0;
    int bit_size = 0;
    fout << "          ";
    /*Êä³öÊ÷*/
    for (int i = 0; i < MAX_NODE; ++i) {
        fout << tree[i].weight << ' ' << tree[i].left << ' ' << tree[i].right << ' ' << tree[i].parent << ' ' << tree[i].bit << ' ';
    }
    /*Êä³öÄÚÈÝ*/
    while (!fin.eof()) {
        fin.get(chrin);
        for (auto itr = code[chrin - 'a'].bit.begin(); itr != code[chrin - 'a'].bit.end(); ++itr) {
            if (*itr) {
                byte |= (bool)1 << (7 - position);
            }
            position++;
            if (position > 7) {
                fout << byte;
                position = 0;
                byte = 0;
                bit_size += 8;
            }
        }
    }
    fout << byte;
    bit_size += position;
    fout.seekp(ios::beg);
    fout << bit_size;
}
