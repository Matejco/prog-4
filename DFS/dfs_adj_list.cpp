#include <iostream>
using namespace std;

const int MAXN = 105;
int adj[MAXN][MAXN];
int deg[MAXN];
bool visited[MAXN];

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < deg[x]; i++) {
        int y = adj[x][i];
        if (!visited[y])
            dfs(y);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][deg[a]] = b;
        deg[a]++;
        adj[b][deg[b]] = a;
        deg[b]++;
    }

    int start;
    cin >> start;

    dfs(start);
    cout << endl;

    return 0;
}
