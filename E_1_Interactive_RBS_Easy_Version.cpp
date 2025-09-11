#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

map<std::vector<int>, int> memo;

int ask(std::vector<int>& indices) {
    if (indices.empty()) {
        return 0;
    }
    // Sort indices to make the key consistent for memoization.
    std::sort(indices.begin(), indices.end());
    if (memo.count(indices)) {
        return memo[indices];
    }

    std::cout << "? " << indices.size();
    for (int index : indices) {
        std::cout << " " << index;
    }
    std::cout << std::endl;

    int result;
    std::cin >> result;
    memo[indices] = result;
    return result;
}

// Stores the final pairs, e.g., pair_map[i] = j and pair_map[j] = i
std::vector<int> pair_map;

void find_pairs(std::list<int>& indices) {
    if (indices.empty()) {
        return;
    }

    // The first element `p` must be an open bracket.
    int p = indices.front();
    indices.pop_front();

    std::vector<int> candidates(indices.begin(), indices.end());
    int match_idx_in_candidates = -1;

    // Binary search for the matching bracket for `p`.
    int low = 0, high = candidates.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        std::vector<int> query_indices;
        query_indices.push_back(p);
        for(int i = 0; i <= mid; ++i) {
            query_indices.push_back(candidates[i]);
        }

        if (ask(query_indices) * 2 == query_indices.size()) {
            match_idx_in_candidates = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    int j = candidates[match_idx_in_candidates];
    pair_map[p] = j;
    pair_map[j] = p;

    // The indices between p and j form a new subproblem.
    std::list<int> inner_problem;
    for (int i = 0; i < match_idx_in_candidates; ++i) {
        inner_problem.push_back(candidates[i]);
    }
    
    // The indices after j form another subproblem.
    std::list<int> outer_problem;
    for (int i = match_idx_in_candidates + 1; i < candidates.size(); ++i) {
        outer_problem.push_back(candidates[i]);
    }

    // Recursively solve for the subproblems.
    find_pairs(inner_problem);
    find_pairs(outer_problem);
}


void solve() {
    int n;
    std::cin >> n;
    
    memo.clear();
    pair_map.assign(n + 1, 0);

    std::list<int> all_indices;
    for (int i = 1; i <= n; ++i) {
        all_indices.push_back(i);
    }
    
    find_pairs(all_indices);

    std::string final_s(n, ' ');
    for (int i = 1; i <= n; ++i) {
        if (pair_map[i] > i) {
            final_s[i - 1] = '(';
            final_s[pair_map[i] - 1] = ')';
        }
    }

    std::cout << "! " << final_s << std::endl;
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