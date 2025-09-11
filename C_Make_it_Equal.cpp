#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    map<long long, int> s_map;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        long long rem = val % k;
        s_map[min(rem, (k - rem) % k)]++;
    }

    map<long long, int> t_map;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        long long rem = val % k;
        t_map[min(rem, (k - rem) % k)]++;
    }

    if (s_map == t_map) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}