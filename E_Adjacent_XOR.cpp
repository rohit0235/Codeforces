#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::vector<long long> pa(n), pb(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        pa[i] = a[i];
        if (i > 0) {
            pa[i] ^= pa[i - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        pb[i] = b[i];
        if (i > 0) {
            pb[i] ^= pb[i - 1];
        }
    }

    if (a[n - 1] != b[n - 1]) {
        std::cout << "NO\n";
        return;
    }

    long long diff = 0;
    for (int i = 0; i < n - 1; ++i) {
        long long current_pa = pa[i] ^ diff;
        long long needed_change = current_pa ^ pb[i];

        if (needed_change == 0) {
            // No operation needed at index i
        } else if (needed_change == a[i + 1]) {
            // Operation at index i is needed
            diff ^= a[i + 1];
        } else {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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