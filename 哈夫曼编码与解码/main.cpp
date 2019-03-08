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
    cout << "����һ���򵥵Ĺ���������ѹ������" << endl;
    cout << "����1��ȡ��ѹ���ļ�����ȡ��ǰ·���µ�qwq.txt��ѹ��ΪTAT.hfm" << endl;
    cout << "����2��ѹ�ļ����ڵ�ǰ·����ȡTAT.hfm�е���Ϣ�������ѹΪ0v0.txt" << endl;
    cout << "����3����windows��fc.exe���Ƚ�ѹ��ǰ(qwq.txt)���ѹ��(0v0.txt)���ļ���ͬ" << endl;
    cout << "����q�˳�" << endl;
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
            cout << "ѹ���ɹ���" << endl;
            break;
        case '2':
            Node tree2[MAX_NODE];
            fin.open("TAT.hfm", ios::in | ios::binary);
            fout.open("0v0.txt", ios::out | ios::binary);
            readOutFileDecompression(fin, fout, tree2);
            fin.close();
            fout.close();
            cout << "��ѹ�ɹ���" << endl;
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