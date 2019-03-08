#include<iostream>
using namespace std;

struct node {
    int flag;
    int pos;
    struct node* next;
};

void Insert(node* n, int d);
node* lastptr;

int main(void) {
    float n, k, m;
    int cnt = 1;
    cin >> n >> k >> m;
    if (n <= 0 || k > n || (int)k != k || m<0) {
        cout << "ERROR" << endl;
        return -1;
    }
    int N = n;
    int K = k;
    int M = m;
    int num = 1;
    node* joseph = new node;
    joseph->flag = 0;
    joseph->pos = 1;
    joseph->next = NULL;
    lastptr = joseph;

    for (register int i = 2; i <= N; i++) {
        Insert(joseph, i);
        num++;
    }
    lastptr->next = joseph;
    node* ptr = joseph;
    while (1) {
        ptr = ptr->next;
        while (ptr->flag == 1) {
            ptr = ptr->next;
        }
        cnt++;
        if (cnt>M) {
            ptr->flag = 1;
            num--;
            cnt = 0;
        }
        if (num == K) break;
    }
    node* p2 = joseph;
    register int i = 0;
    int cnt2 = 0;
    while (i<N) {
        if (p2->flag == 0) {
            cout << p2->pos << ',';
        }
        else cnt2++;
        p2 = p2->next;
        i++;
    }
    if (cnt2 == N) cout << 0;
    return 0;
}

void Insert(node* n, int d) {
    node* tmp = new node;
    tmp->pos = d;
    tmp->flag = 0;
    tmp->next = NULL;
    lastptr->next = tmp;
    lastptr = tmp;
}