#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

const int MAXN = 200005;

std::vector<int> adj[MAXN];
int degree[MAXN];
int j_count[MAXN];
bool is_junction[MAXN];
int parent[MAXN];

/**
 * @brief Performs a DFS traversal to build a rooted tree and count junctions in each subtree.
 * @param u The current node.
 * @param p The parent of the current node.
 */
void dfs_count(int u, int p) {
    parent[u] = p;
    j_count[u] = is_junction[u];
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_count(v, u);
        j_count[u] += j_count[v];
    }
}

/**
 * @brief Solves a single test case.
 */
void solve() {
    int n;
    std::cin >> n;

    // Clear data structures for the current test case
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        degree[i] = 0;
        is_junction[i] = false;
    }

    if (n == 1) {
        std::cout << 0 << std::endl;
        return;
    }
    
    // Read edges and compute degrees
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // Identify junction nodes (degree >= 3)
    std::vector<int> junctions;
    int max_degree = 0;
    for (int i = 1; i <= n; ++i) {
        max_degree = std::max(max_degree, degree[i]);
        if (degree[i] >= 3) {
            junctions.push_back(i);
            is_junction[i] = true;
        }
    }

    // Case 1: Path graph (max degree <= 2)
    if (max_degree <= 2) {
        std::cout << (n > 2 ? 1 : 0) << std::endl;
        return;
    }
    
    // Case 2: Star-like graph (only one junction)
    if (junctions.size() <= 1) {
        std::cout << 0 << std::endl;
        return;
    }

    // Case 3: General tree with multiple junctions
    dfs_count(1, 0); 

    int total_junctions = junctions.size();
    int core_leaves = 0;

    // For each junction, determine if it's a "core leaf"
    for (int j : junctions) {
        int core_degree = 0;
        
        // Count connections to other junctions via children
        for (int v : adj[j]) {
            if (v == parent[j]) continue;
            if (j_count[v] > 0) {
                core_degree++;
            }
        }
        
        // Count connection to other junctions via parent
        if (parent[j] != 0) {
            if (total_junctions > j_count[j]) {
                core_degree++;
            }
        }
        
        // A junction is a core leaf if it connects to other junctions via at most one path
        if (core_degree <= 1) {
            core_leaves++;
        }
    }
    
    // The minimum operations is ceil(core_leaves / 2)
    std::cout << (core_leaves + 1) / 2 << std::endl;
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