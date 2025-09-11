#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

const int INF = 1e9 + 7;

// Global-like variables to be cleared for each test case
std::vector<std::vector<std::pair<int, int>>> adj;
std::vector<int> disc, low, tin, tout, parent;
std::vector<int> edge_idx_to_parent;
int timer;

// DFS to find bridges and gather subtree information (tin/tout)
void dfs_bridges(int u, int p, int edge_idx) {
    disc[u] = low[u] = ++timer;
    tin[u] = timer;
    parent[u] = p;
    edge_idx_to_parent[u] = edge_idx;

    for (auto const& edge_pair : adj[u]) { // MODIFIED LINE
        int v = edge_pair.first;
        int idx = edge_pair.second;
        if (v == p) continue;
        if (disc[v] != 0) { // Back edge
            low[u] = std::min(low[u], disc[v]);
        } else { // Tree edge
            dfs_bridges(v, u, idx);
            low[u] = std::min(low[u], low[v]);
        }
    }
    tout[u] = ++timer;
}

// Helper to check if node v is in the DFS subtree of node u
bool is_in_subtree(int u, int v) {
    if (tin[u] == 0 || tin[v] == 0) return false;
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    adj.assign(n + 1, {});
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    // Step 1: DFS to find bridges and subtree info
    timer = 0;
    disc.assign(n + 1, 0);
    low.assign(n + 1, 0);
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    edge_idx_to_parent.assign(n + 1, 0);
    dfs_bridges(1, 0, -1);

    // Step 2: Identify suitable lanes (bridges on the 1 -> n path)
    std::vector<std::tuple<int, int, int>> suitable_lanes;
    int curr = n;
    while (curr != 0 && curr != 1) {
        int p = parent[curr];
        if (low[curr] > disc[p]) {
            suitable_lanes.emplace_back(p, curr, edge_idx_to_parent[curr]);
        }
        curr = p;
    }

    // Step 3: Multi-Source BFS preprocessing
    std::vector<int> dist(n + 1, INF);
    std::vector<int> ans_idx(n + 1, INF);
    std::queue<int> q_bfs;

    // Initialize sources for MS-BFS from endpoints of suitable lanes
    for (const auto& lane_tuple : suitable_lanes) { // MODIFIED LINE
        int u = std::get<0>(lane_tuple);
        int v = std::get<1>(lane_tuple);
        int idx = std::get<2>(lane_tuple);
        ans_idx[u] = std::min(ans_idx[u], idx);
        ans_idx[v] = std::min(ans_idx[v], idx);
    }

    for (int i = 1; i <= n; ++i) {
        if (ans_idx[i] != INF) {
            dist[i] = 0;
            q_bfs.push(i);
        }
    }

    // Run the MS-BFS
    while (!q_bfs.empty()) {
        int u = q_bfs.front();
        q_bfs.pop();

        for (auto const& edge_pair : adj[u]) { // MODIFIED LINE
            int v = edge_pair.first;
            // int edge_idx = edge_pair.second; // Not needed here
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                ans_idx[v] = ans_idx[u];
                q_bfs.push(v);
            } else if (dist[v] == dist[u] + 1) {
                ans_idx[v] = std::min(ans_idx[v], ans_idx[u]);
            }
        }
    }

    // Step 4: Process queries
    int q_count;
    std::cin >> q_count;
    for (int i = 0; i < q_count; ++i) {
        int c;
        std::cin >> c;
        int result = ans_idx[c];
        if (result == INF) {
            std::cout << -1 << (i == q_count - 1 ? "" : " ");
        } else {
            std::cout << result << (i == q_count - 1 ? "" : " ");
        }
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}