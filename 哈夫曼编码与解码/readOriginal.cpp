#include"utility.h"
#include<fstream>
using namespace std;

void readFileOriginal(ifstream& fin, Node* tree) {
    char chrin;
    while (!fin.eof()) {
        fin >> chrin;
        tree[chrin - 'a'].weight++;
    }
}
