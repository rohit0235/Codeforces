#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int total_twos = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 2) {
            total_twos++;
        }
    }

    if (total_twos % 2 != 0) {
        std::cout << -1 << std::endl;
        return;
    }

    int target_twos = total_twos / 2;
    int current_twos = 0;
    int ans = -1;

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == 2) {
            current_twos++;
        }
        if (current_twos == target_twos) {
            ans = i + 1;
            break;
        }
    }

    std::cout << ans << std::endl;
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