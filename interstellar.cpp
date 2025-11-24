#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct R { string p; int r; };
map<string, R> M;


pair<int, int> P(string s, int t) {
    if (!M.count(s)) return {0, 0}; 
    auto par = P(M[s].p, t);
    int d = M[s].r - 1, m = 8 * d, p = t % m;
    int x = 0, y = 0;

    if (p < d) x = d, y = p;
    else if (p < 3 * d) x = d - (p - d), y = d;
    else if (p < 5 * d) x = -d, y = d - (p - 3 * d);
    else if (p < 7 * d) x = -d + (p - 5 * d), y = -d;
    else x = d, y = -d + (p - 7 * d);
    
    return {par.first + x, par.second + y};
}

int main() {
    int n;
    if (cin >> n) {
        for(int i = 0; i < n; i++) {
            string u, v; int r; 
            cin >> u >> v >> r;
            M[u] = {v, r};
        }
        string S, E; 
        cin >> S >> E;


        for(int t = 0; t <= 100; t++) {
            auto pE = P(E, t);
      
            for(int t0 = 0; t0 <= t; t0++) {
                auto pS = P(S, t0);
                int dist = abs(pS.first - pE.first) + abs(pS.second - pE.second);
       
                if(dist <= t - t0) {
                    cout << t; 
                    return 0;
                }
            }
        }
    }
    return 0;
}