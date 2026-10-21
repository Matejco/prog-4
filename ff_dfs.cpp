#include <iostream>
using namespace std;

const int MAXN = 105;
const int INF = 1000000000;

int n, s, t;
int cap[MAXN][MAXN];
bool visited[MAXN];

void init(int V) {
    n = V;
    s = 0;
    t = V - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cap[i][j] = 0;
}

void addEdge(int a, int b, int c) {
    cap[a][b] += c;
}

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

int maxflow() {
    int flow = 0;
    while (true) {
        for (int i = 0; i < n; i++)
            visited[i] = false;

        int f = dfs(s, INF);
        if (f == 0) break;
        flow += f;
    }
    return flow;
}

int main() {
    init(4);
    addEdge(0, 1, 8); addEdge(0, 2, 8); addEdge(1, 3, 8);
    addEdge(2, 3, 8); addEdge(2, 1, 1);
    cout << "FF Killer: " << maxflow() << endl;

    init(8);
    addEdge(0, 1, 1); addEdge(0, 2, 1); addEdge(0, 3, 1);
    addEdge(1, 4, 1); addEdge(1, 5, 1); addEdge(1, 6, 1);
    addEdge(2, 5, 1); addEdge(3, 5, 1);
    addEdge(4, 7, 1); addEdge(5, 7, 1); addEdge(6, 7, 1);
    cout << "CP4 Ex 8.5.3.1* (correct): " << maxflow() << endl;

    init(8);
    addEdge(0, 1, 10); addEdge(0, 2, 5); addEdge(0, 3, 15);
    addEdge(1, 2, 4); addEdge(1, 4, 9); addEdge(1, 5, 15);
    addEdge(2, 3, 4); addEdge(2, 5, 8); addEdge(3, 6, 16);
    addEdge(4, 5, 15); addEdge(4, 7, 10); addEdge(5, 6, 15);
    addEdge(5, 7, 10); addEdge(6, 2, 6); addEdge(6, 7, 10);
    cout << "CS4234 MF Demo: " << maxflow() << endl;

    init(6);
    addEdge(0, 1, 2); addEdge(0, 2, 3); addEdge(1, 3, 99);
    addEdge(1, 4, 99); addEdge(2, 4, 99);
    addEdge(3, 5, 2); addEdge(4, 5, 2);
    cout << "Matching with Capacity: " << maxflow() << endl;

    return 0;
}
