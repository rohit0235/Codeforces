#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> chocolates, int M, int N) {
    long long s = 0;
    long long mx = 0;
    vector<long long> f(M, -1);
    f[0] = 0;
    for (int i = 0; i < N; i++) {
        s += chocolates[i];
        int r = s % M;
        if (f[r] != -1) {
            long long cur = (s - f[r]) / M;
            if (cur > mx) mx = cur;
        } else {
            f[r] = s;
        }
    }
    return (int)mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            int n, m;
            cin >> n >> m;
            vector<int> a(n);
            for (int i = 0; i < n; i++) cin >> a[i];
            cout << solution(a, m, n) << endl;
        }
    }
    return 0;
}