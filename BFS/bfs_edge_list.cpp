#include <iostream>
using namespace std;

const int MAXN = 105;
const int MAXM = 10005;
int od[MAXM], kon[MAXM];
bool visited[MAXN];
int q[MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> od[i] >> kon[i];
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

        // mora da se pominat site rabovi za sekoe teme
        for (int i = 0; i < m; i++) {
            int sosed = -1;
            if (od[i] == x) sosed = kon[i];
            else if (kon[i] == x) sosed = od[i];

            if (sosed != -1 && !visited[sosed]) {
                visited[sosed] = true;
                q[kraj] = sosed;
                kraj++;
            }
        }
    }
    cout << endl;

    return 0;
}
