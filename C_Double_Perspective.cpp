#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
// Structure to hold interval information
struct Interval {
    int id;
    int u, v;
};

// Disjoint Set Union (DSU) structure for cycle detection
struct DSU {
   vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

void solve() {
    int n;
   cin >> n;
   vector<Interval> ivls(n);
   set<int> eps;
    int mcd = 0;

    // Read ivls and collect endpoints
    for (int i = 0; i < n; ++i) {
        ivls[i].id = i + 1;
       cin >> ivls[i].u >> ivls[i].v;
        eps.insert(ivls[i].u);
        eps.insert(ivls[i].v);
        mcd =max({mcd, ivls[i].u, ivls[i].v});
    }

    // Create a sorted list of unique endpoints
   vector<int> p(eps.begin(), eps.end());
    int m = p.size();
    if (m == 0) {
       cout << "0\n\n"; // Edge case: no ivls
        return;
    }

    DSU dsu(mcd + 1);
   vector<int> rid;

    // Sweep through elementary ivls
    for (int j = 0; j < m - 1; ++j) {
        int p_start = p[j];
        int p_end = p[j+1];

        int best_len = -1;
        int cid = -1;

        // Find the best candidate interval for the current segment
        // The best candidate is one that does not form a cycle and has the minimum length.
        for (int i = 0; i < n; ++i) {
            if (ivls[i].u <= p_start && ivls[i].v >= p_end) {
                if (dsu.find(ivls[i].u) != dsu.find(ivls[i].v)) {
                    int current_len = ivls[i].v - ivls[i].u;
                    if (cid == -1 || current_len < best_len) {
                        best_len = current_len;
                        cid = i;
                    }
                }
            }
        }
        
        // If a valid candidate is found, use it
        if (cid != -1) {
            dsu.unite(ivls[cid].u, ivls[cid].v);
            rid.push_back(ivls[cid].id);
        }
    }
    
    // Post-process to get unique indices
   sort(rid.begin(), rid.end());
    rid.erase(std::unique(rid.begin(), rid.end()), rid.end());

    // Output the result in the expected format
   cout << rid.size() << "\n";
    if (!rid.empty()) {
        for (size_t i = 0; i < rid.size(); ++i) {
           cout << rid[i] << (i == rid.size() - 1 ? "" : " ");
        }
       cout << "\n";
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