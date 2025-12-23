#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int R, C, M, N, A, B, K;
char g[35][35];
map<char, int> sc;
int dr = -1, dc = 1; 

// BFS to calculate score of falling bricks
void fall(ll &s) {
    bool vis[35][35] = {false};
    queue<pair<int, int>> q;
    
    // Start BFS from ceiling (row 0)
    rep(j, C) {
        if (g[0][j] != '.') {
            q.push({0, j});
            vis[0][j] = true;
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while(!q.empty()){
        auto p = q.front(); q.pop();
        rep(i, 4){
            int nr = p.first + dx[i], nc = p.second + dy[i];
            if(nr >= 0 && nr < R && nc >= 0 && nc < C && g[nr][nc] != '.' && !vis[nr][nc]){
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    rep(i, R) rep(j, C) {
        if(g[i][j] != '.' && !vis[i][j]){
            s += sc[g[i][j]];
            g[i][j] = '.'; // Remove falling brick
        }
    }
}

int main() {
    // Optimize I/O operations
    ios::sync_with_stdio(0); cin.tie(0);

    if(!(cin >> R >> C)) return 0;
    cin >> M;

    // Initialize grid with empty space
    rep(i, R) rep(j, C) g[i][j] = '.';

    // Read bricks (handles space-separated chars automatically)
    rep(i, M) rep(j, C) cin >> g[i][j];
    
    string cols; cin >> cols;
    vector<int> pts(cols.size());
    rep(i, cols.size()) cin >> pts[i];
    rep(i, cols.size()) sc[cols[i]] = pts[i];
    
    cin >> N >> A >> B >> K;
    
    // Ball start position
    int cr = R - 1, cc = N;
    
    // Initial direction logic
    if(cc == C - 1) dc = -1; 
    
    int h = 0; // Hit counter
    ll len = A; // Current paddle length
    int safe = 0; // Safety break for infinite loops
    
    while(h < K && safe < 100000) {
        safe++;
        
        // Calculate next potential position
        int nr = cr + dr, nc = cc + dc;
        
        // Wall Collisions
        if(nc < 0 || nc >= C) { dc = -dc; nc = cc + dc; }
        if(nr < 0) { dr = -dr; nr = cr + dr; }
        if(nr >= R) { dr = -dr; nr = cr + dr; }
        
        bool hit = false;
        int hr = -1, hc = -1;
        
        // Brick Collision Logic (Vertical -> Horizontal -> Corner)
        if(nr >= 0 && nr < R && nc >= 0 && nc < C) {
             if(g[nr][cc] != '.') { // Vertical Hit
                dr = -dr;
                hr = nr; hc = cc; hit = true;
            } else if(g[cr][nc] != '.') { // Horizontal Hit
                dc = -dc;
                hr = cr; hc = nc; hit = true;
            } else if(g[nr][nc] != '.') { // Corner Hit
                dr = -dr; dc = -dc;
                hr = nr; hc = nc; hit = true;
            }
        }
        
        if(hit) {
            h++;
            ll s = sc[g[hr][hc]];
            g[hr][hc] = '.'; // Break hit brick
            fall(s); // Add falling bricks score
            
            // Greedy Paddle Maximization
            if(s > 0) {
                len += 2;
                if(len > C) len = C; 
            }
            // If s < 0, we choose to decrease by 0 (do nothing) to maximize length.
        } else {
            // Move ball if no brick hit
            cr = nr; cc = nc;
        }
    }
    
    cout << len;
    return 0;
}