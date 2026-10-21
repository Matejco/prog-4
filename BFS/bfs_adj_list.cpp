#include <iostream>
using namespace std;

int adj[105][105];
int br[105];
bool visited[105];
int q[105];

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

    int pocetok = 0, kraj = 0;
    q[kraj] = start;
    kraj++;
    visited[start] = true;

    while (pocetok < kraj) {
        int x = q[pocetok];
        pocetok++;
        cout << x << " ";

        for (int i = 0; i < br[x]; i++) {
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
