#include <iostream>

using namespace std;

const int sz = 35;

int main() {
    long n, p, q, i, j, k, cnt, T, cas = 1, sum, a[sz];

    //freopen();
    cin >> T;
    while (T--) {
        cin >> n >> p >> q;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        sum = 0;
        cnt = 0;
        for (i = 0; i < n; i++) {
            if (cnt >= p || sum + a[i] > q) {
                break;
            }
            sum += a[i];
            cnt++;
        }
        cout << "Case " << cas++ << ": " << cnt << endl;
    }

    return 0;
}
