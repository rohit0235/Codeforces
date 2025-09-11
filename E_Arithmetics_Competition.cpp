#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// A helper function to get the sum for a given split of cards.
// v_count is the number of cards Vadim takes.
long long get_sum(long long v_count, long long z, const std::vector<long long>& pref_a, const std::vector<long long>& pref_b) {
    long long k_count = z - v_count;
    // Note: The search range calculation ensures k_count is valid.
    return pref_a[v_count] + pref_b[k_count];
}

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    std::vector<long long> b(m);
    for (int i = 0; i < m; ++i) std::cin >> b[i];

    // Step 1: Sort cards in descending order for greedy picking.
    std::sort(a.rbegin(), a.rend());
    std::sort(b.rbegin(), b.rend());

    // Step 2: Pre-calculate prefix sums for O(1) sum lookups.
    std::vector<long long> pref_a(n + 1, 0);
    for (int i = 0; i < n; ++i) pref_a[i + 1] = pref_a[i] + a[i];

    std::vector<long long> pref_b(m + 1, 0);
    for (int i = 0; i < m; ++i) pref_b[i + 1] = pref_b[i] + b[i];

    for (int i = 0; i < q; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;

        // Determine the valid search range [l, r] for v_count.
        long long l = std::max({0LL, (long long)z - y, (long long)z - m});
        long long r = std::min({(long long)x, (long long)n, (long long)z});

        if (l > r) {
            std::cout << 0 << "\n";
            continue;
        }

        // Step 4: Ternary search for the optimal v_count.
        while (r - l >= 3) {
            long long m1 = l + (r - l) / 3;
            long long m2 = r - (r - l) / 3;
            if (get_sum(m1, z, pref_a, pref_b) < get_sum(m2, z, pref_a, pref_b)) {
                l = m1;
            } else {
                r = m2;
            }
        }
        
        long long max_sum = 0;
        // Final linear scan over the small remaining range [l, r] to find the true maximum.
        for (long long v_count = l; v_count <= r; ++v_count) {
             max_sum = std::max(max_sum, get_sum(v_count, z, pref_a, pref_b));
        }

        std::cout << max_sum << "\n";
    }
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