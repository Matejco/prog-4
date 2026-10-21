#include <iostream>
using namespace std;

int mat[105][105];
bool visited[105];
int n, m;

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < n; i++) {
        if (mat[x][i] == 1 && !visited[i])
            dfs(i);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    int start;
    cin >> start;

    dfs(start);
    cout << endl;

    return 0;
}
