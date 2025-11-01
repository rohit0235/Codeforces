#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void solve(int case_num) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n <= 1) {
        std::cout << "Case #" << case_num << ": 0" << std::endl;
        return;
    }

    int max_height = 0;
    for (int i = 0; i < n - 1; ++i) {
        int diff = std::abs(a[i] - a[i+1]);
        if (diff > max_height) {
            max_height = diff;
        }
    }

    std::cout << "Case #" << case_num << ": " << max_height << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }

    return 0;
}