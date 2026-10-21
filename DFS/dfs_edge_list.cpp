#include <iostream>
using namespace std;

int od[10005], kon[10005];
bool visited[105];
int n, m;

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < m; i++) {
        int sosed = -1;
        if (od[i] == x) sosed = kon[i];
        else if (kon[i] == x) sosed = od[i];

        if (sosed != -1 && !visited[sosed])
            dfs(sosed);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> od[i] >> kon[i];
    }

    int start;
    cin >> start;

    dfs(start);
    cout << endl;

    return 0;
}
