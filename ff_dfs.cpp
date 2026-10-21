#include <iostream>
using namespace std;

int n, m, s, t;
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

int maxflow() {
    int flow = 0;
    while (true) {
        for (int i = 0; i < n; i++)
            visited[i] = false;

        int f = dfs(s, 1000000000);
        if (f == 0) break;
        flow += f;
    }
    return flow;
}

int main() {
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cap[a][b] += c;
    }

    cout << maxflow() << endl;

    return 0;
}
