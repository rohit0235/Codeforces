#include <bits/stdc++.h>
using namespace std;

int findMax(vector<vector<int>> A, int k) {
    vector<vector<pair<int, int>>> g(5005);
    for (auto& x : A) g[x[0]].push_back({x[1], x[2]});
    
    vector<int> d(k + 1, 0);
    for (auto& v : g) {
        if (v.empty()) continue;
        vector<int> t = d;
        for (auto& p : v) {
            for (int j = k; j >= p.first; --j) {
                t[j] = max(t[j], d[j - p.first] + p.second);
            }
        }
        d = t;
    }
    return d[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        vector<vector<int>> a(n, vector<int>(3));
        for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
        int k;
        cin >> k;
        cout << findMax(a, k) << endl;
    }
    return 0;
}