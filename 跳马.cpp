#include<iostream>
#include<queue>
using namespace std;

struct Block {
    int steps;
    bool mark;
    Block() :steps(-1), mark(false) {}//cpp结构同全为public的类，初始化为不可达，未访问。
};

struct Coordinate {
    int x, y;
    Coordinate(int xx, int yy) :x(xx), y(yy) {}//坐标数对
};

int main() {
    int n, m, x_start, y_start, N;
    cin >> n >> m >> x_start >> y_start >> N;
    Block** board = new Block*[n + 1];
    for (int i = 1; i < n + 1; ++i) {
        board[i] = new Block[m + 1];//由于board等到程序结束才失去作用，不需要for循环再
    }                                                           //delete[]。
    board[x_start][y_start].steps = 0;
    board[x_start][y_start].mark = true;
    queue<Coordinate> q;
    q.push(Coordinate(x_start, y_start));
    while (!q.empty()) {//BFS操作，每次对八个方向进行搜索。
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        if (x + 1 <= n&&y + 2 <= m && !board[x + 1][y + 2].mark) {
            board[x + 1][y + 2].steps = board[x][y].steps + 1;
            board[x + 1][y + 2].mark = true;
            q.push(Coordinate(x + 1, y + 2));
        }
        if (x + 2 <= n&&y + 1 <= m && !board[x + 2][y + 1].mark) {
            board[x + 2][y + 1].steps = board[x][y].steps + 1;
            board[x + 2][y + 1].mark = true;
            q.push(Coordinate(x + 2, y + 1));
        }
        if (x + 2 <= n&&y - 1 > 0 && !board[x + 2][y - 1].mark) {
            board[x + 2][y - 1].steps = board[x][y].steps + 1;
            board[x + 2][y - 1].mark = true;
            q.push(Coordinate(x + 2, y - 1));
        }
        if (x + 1 <= n&&y - 2 > 0 && !board[x + 1][y - 2].mark) {
            board[x + 1][y - 2].steps = board[x][y].steps + 1;
            board[x + 1][y - 2].mark = true;
            q.push(Coordinate(x + 1, y - 2));
        }
        if (x - 1 > 0 && y - 2 > 0 && !board[x - 1][y - 2].mark) {
            board[x - 1][y - 2].steps = board[x][y].steps + 1;
            board[x - 1][y - 2].mark = true;
            q.push(Coordinate(x - 1, y - 2));
        }
        if (x - 2 > 0 && y - 1 > 0 && !board[x - 2][y - 1].mark) {
            board[x - 2][y - 1].steps = board[x][y].steps + 1;
            board[x - 2][y - 1].mark = true;
            q.push(Coordinate(x - 2, y - 1));
        }
        if (x - 2 > 0 && y + 1 <= m && !board[x - 2][y + 1].mark) {
            board[x - 2][y + 1].steps = board[x][y].steps + 1;
            board[x - 2][y + 1].mark = true;
            q.push(Coordinate(x - 2, y + 1));
        }
        if (x - 1 > 0 && y + 2 <= m && !board[x - 1][y + 2].mark) {
            board[x - 1][y + 2].steps = board[x][y].steps + 1;
            board[x - 1][y + 2].mark = true;
            q.push(Coordinate(x - 1, y + 2));
        }
    }
    while (N--) {
        int x, y;
        cin >> x >> y;
        printf("%d\n", board[x][y].steps);
    }
    return 0;
}
