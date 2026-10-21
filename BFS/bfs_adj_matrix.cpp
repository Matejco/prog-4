#include <iostream>
using namespace std;

const int MAXN = 105;
int mat[MAXN][MAXN];
bool visited[MAXN];
int q[MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
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

        for (int i = 0; i < n; i++) {
            if (mat[x][i] == 1 && !visited[i]) {
                visited[i] = true;
                q[kraj] = i;
                kraj++;
            }
        }
    }
    cout << endl;

    return 0;
}
