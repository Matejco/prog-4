#include <iostream>
using namespace std;

const int MAXN = 105;
int adj[MAXN][MAXN];
int deg[MAXN];
bool visited[MAXN];
int q[MAXN];

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

    int pocetok = 0, kraj = 0;
    q[kraj] = start;
    kraj++;
    visited[start] = true;

    while (pocetok < kraj) {
        int x = q[pocetok];
        pocetok++;
        cout << x << " ";

        for (int i = 0; i < deg[x]; i++) {
            int y = adj[x][i];
            if (!visited[y]) {
                visited[y] = true;
                q[kraj] = y;
                kraj++;
            }
        }
    }
    cout << endl;

    return 0;
}
