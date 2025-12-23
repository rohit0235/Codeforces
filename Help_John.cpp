#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            long long n, x, p;
            cin >> n >> x >> p;

            long long max_bottles = 0;
            long long temp;

            for (int i = 0; i < n; i++) {
                cin >> temp;
                if (temp > max_bottles) {
                    max_bottles = temp;
                }
            }

            long long total_cost = max_bottles * x;

            if (total_cost <= p) {
                cout << "Possible" << endl;
                cout << p - total_cost << endl;
            } else {
                cout << "Impossible" << endl;
                cout << total_cost - p << endl;
            }
        }
    }
    return 0;
}