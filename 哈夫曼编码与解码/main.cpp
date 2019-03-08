#include"utility.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

void outFileCompression(ofstream& fout, ifstream& fin, Code* code, Node* tree);
void encode(Node* tree, Code* code);
void buildTree(Node* tree);
void readFileOriginal(ifstream& fin, Node* tree);
void init(Node* tree, Code* code);
void readOutFileDecompression(ifstream& fin, ofstream& fout, Node* tree);


int main() {
    Node tree[MAX_NODE];
    Code code[ALPHABET];
    ifstream fin;
    ofstream fout;
    init(tree, code);
    char input;
    cout << "这是一个简单的哈夫曼编码压缩程序" << endl;
    cout << "输入1读取并压缩文件，读取当前路径下的qwq.txt，压缩为TAT.hfm" << endl;
    cout << "输入2解压文件，于当前路径读取TAT.hfm中的信息并将其解压为0v0.txt" << endl;
    cout << "输入3调用windows下fc.exe，比较压缩前(qwq.txt)与解压后(0v0.txt)两文件异同" << endl;
    cout << "输入q退出" << endl;
    while (1) {
        cin >> input;
        switch (input) {
        case '1':
            fin.open("qwq.txt", ios::in | ios::binary);
            readFileOriginal(fin, tree);
            buildTree(tree);
            encode(tree, code);
            fin.close();
            fin.open("qwq.txt", ios::in | ios::binary);
            fout.open("TAT.hfm", ios::out | ios::binary);
            outFileCompression(fout, fin, code, tree);
            fout.close();
            fin.close();
            cout << "压缩成功！" << endl;
            break;
        case '2':
            Node tree2[MAX_NODE];
            fin.open("TAT.hfm", ios::in | ios::binary);
            fout.open("0v0.txt", ios::out | ios::binary);
            readOutFileDecompression(fin, fout, tree2);
            fin.close();
            fout.close();
            cout << "解压成功！" << endl;
            break;
        case '3':
            system("fc qwq.txt 0v0.txt");
            break;
        case 'q':
            exit(0);
        default:break;
        }
    }
    return 0;
}