#include <iostream>
#include <vector>
#include <numeric>

void solve(int case_num) {
    int n, a, b;
    std::cin >> n >> a >> b;

    int p1 = 0;
    // Find the largest integer <= A that divides B
    for (int i = a; i >= 1; --i) {
        if (b % i == 0) {
            p1 = i;
            break;
        }
    }
    // Since a solution is guaranteed, p1 will be found (at worst, p1=1).

    int p2 = b / p1;

    std::cout << "Case #" << case_num << ": " << p1;

    // First N multipliers
    for (int i = 0; i < n - 1; ++i) {
        std::cout << " " << 1;
    }

    // Last N multipliers
    std::cout << " " << p2;
    for (int i = 0; i < n - 1; ++i) {
        std::cout << " " << 1;
    }
    std::cout << std::endl;
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