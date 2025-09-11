#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        if (n % 2 == 0 && i == n - 1) {
            val = 2;
        } else {
            if (i % 2 == 0) {
                val = -1;
            } else {
                val = 3;
            }
        }
        std::cout << val << (i == n - 1 ? "" : " ");
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