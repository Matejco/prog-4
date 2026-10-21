#include <iostream>
using namespace std;

int adj[105][105];
int br[105];
bool visited[105];

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < br[x]; i++) {
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
        adj[a][br[a]] = b;
        br[a]++;
        adj[b][br[b]] = a;
        br[b]++;
    }

    int start;
    cin >> start;

    dfs(start);
    cout << endl;

    return 0;
}
