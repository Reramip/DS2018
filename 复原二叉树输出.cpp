#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char* p;
string s1, s2;

int find(int left, int right);
void pseudoBuild(int left, int right);

int main() {
    cin >> s1;
    cin >> s2;
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1 != len2) {
        cout << "error";
        return 0;
    }
    char* isError1 = new char[len1 + 1];
    char* isError2 = new char[len2 + 1];
    strcpy(isError1, s1.c_str());
    strcpy(isError2, s2.c_str());
    sort(isError1, isError1 + len1);
    sort(isError2, isError2 + len2);
    for (int i = 0; i < len1; i++) {
        if (isError1[i] != isError2[i]) {
            cout << "error";
            return 0;
        }
    }

    p = &s1[0];
    pseudoBuild(0, len2 - 1);

    return 0;
}

int find(int left, int right) {
    if (*p == '\n' || *p == '\0') return -1;
    for (int i = left; i <= right; i++) {
        if (s2[i] == *p) {
            p++;
            return i;
        }
    }
    return -1;
}

void pseudoBuild(int left, int right) {
    int target = find(left, right);
    if (target == -1) return;
    pseudoBuild(left, target - 1);
    pseudoBuild(target + 1, right);
    cout << s2[target];
}
