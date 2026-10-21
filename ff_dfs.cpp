#include <iostream>
using namespace std;

int n, t;
int cap[105][105];
bool visited[105];

int dfs(int x, int f) {
    if (x == t) return f;
    visited[x] = true;
    for (int y = 0; y < n; y++) {
        if (!visited[y] && cap[x][y] > 0) {
            int mal = f;
            if (cap[x][y] < mal) mal = cap[x][y];

            int p = dfs(y, mal);
            if (p > 0) {
                cap[x][y] -= p;
                cap[y][x] += p;
                return p;
            }
        }
    }
    return 0;
}

int maxflow(int V) {
    n = V;
    t = V - 1;
    int flow = 0;
    while (true) {
        for (int i = 0; i < n; i++)
            visited[i] = false;

        int f = dfs(0, 1000000000);
        if (f == 0) break;
        flow += f;
    }
    return flow;
}

void isprazni() {
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
            cap[i][j] = 0;
}

int main() {
    isprazni();
    cap[0][1] = 8; cap[0][2] = 8; cap[1][3] = 8;
    cap[2][3] = 8; cap[2][1] = 1;
    cout << "Prv primer (FF killer), max protok = " << maxflow(4) << endl;

    isprazni();
    cap[0][1] = 1; cap[0][2] = 1; cap[0][3] = 1;
    cap[1][4] = 1; cap[1][5] = 1; cap[1][6] = 1;
    cap[2][5] = 1; cap[3][5] = 1;
    cap[4][7] = 1; cap[5][7] = 1; cap[6][7] = 1;
    cout << "Vtor primer (od CP4), max protok = " << maxflow(8) << endl;

    isprazni();
    cap[0][1] = 10; cap[0][2] = 5; cap[0][3] = 15;
    cap[1][2] = 4; cap[1][4] = 9; cap[1][5] = 15;
    cap[2][3] = 4; cap[2][5] = 8; cap[3][6] = 16;
    cap[4][5] = 15; cap[4][7] = 10; cap[5][6] = 15;
    cap[5][7] = 10; cap[6][2] = 6; cap[6][7] = 10;
    cout << "Tret primer (CS4234 demo), max protok = " << maxflow(8) << endl;

    isprazni();
    cap[0][1] = 2; cap[0][2] = 3; cap[1][3] = 99;
    cap[1][4] = 99; cap[2][4] = 99;
    cap[3][5] = 2; cap[4][5] = 2;
    cout << "Cetvrt primer (matching so kapaciteti), max protok = " << maxflow(6) << endl;

    return 0;
}
