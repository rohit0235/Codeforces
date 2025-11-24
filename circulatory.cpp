#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    if (!(cin >> n)) return 0;
    
    vector<string> g(n);
    vector<vector<int>> d(n);
    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++) {
        cin >> g[i];
        int sz = (int)g[i].size();
        d[i].assign(sz, -1);
        
        if(i == n - 1) {
            for(int j = 0; j < sz; j++) {
                if(g[i][j] == '0') {
                    d[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
    }
    
    while(!q.empty()) {
        pair<int, int> p = q.front(); 
        q.pop();
        int r = p.f, c = p.s;
        int dist = d[r][c];
        
        if(r == 0) {
            cout << dist;
            return 0;
        }
        
        int sz = (int)g[r].size();
        
        // Lateral neighbors (circular)
        int lat[] = {(c + 1) % sz, (c - 1 + sz) % sz};
        for(int nc : lat) {
            if(g[r][nc] == '0' && d[r][nc] == -1) {
                d[r][nc] = dist + 1;
                q.push({r, nc});
            }
        }
        
        // Inward neighbor (r -> r-1)
        if(r > 0) {
            int nc = c / 2;
            if(g[r - 1][nc] == '0' && d[r - 1][nc] == -1) {
                d[r - 1][nc] = dist + 1;
                q.push({r - 1, nc});
            }
        }
        
        // Outward neighbors (r -> r+1)
        if(r < n - 1) {
            int out[] = {2 * c, 2 * c + 1};
            for(int nc : out) {
                if(g[r + 1][nc] == '0' && d[r + 1][nc] == -1) {
                    d[r + 1][nc] = dist + 1;
                    q.push({r + 1, nc});
                }
            }
        }
    }
    return 0;
}