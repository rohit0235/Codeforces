#include <iostream>
#include <vector>
#include <algorithm>

// Function to solve a single test case
void solve() {
    long long n;
    std::cin >> n;

    std::vector<long long> solutions;
    long long power_of_10 = 10;

    // Loop for k = 1, 2, 3, ...
    // The loop only needs to run about 18 times since 1 + 10^19 > 10^18 (max n)
    for (int k = 1; k <= 18; ++k) {
        long long divisor = 1 + power_of_10;

        // If the divisor is greater than n, no solution is possible for this or any larger k.
        if (divisor > n) {
            break;
        }

        // Check if n is perfectly divisible by (1 + 10^k)
        if (n % divisor == 0) {
            solutions.push_back(n / divisor);
        }

        // Prepare power_of_10 for the next iteration (k+1)
        // Check for overflow before multiplication to be safe.
        if (power_of_10 > __LONG_LONG_MAX__ / 10) {
            break;
        }
        power_of_10 *= 10;
    }

    if (solutions.empty()) {
        // Case with no solutions
        std::cout << 0 << "\n";
    } else {
        // Sort the found solutions in ascending order as required
        std::sort(solutions.begin(), solutions.end());
        
        // ** FIX: Print count on its own line **
        std::cout << solutions.size() << "\n";
        
        // ** FIX: Print space-separated values on the next line **
        for (size_t i = 0; i < solutions.size(); ++i) {
            std::cout << solutions[i] << (i == solutions.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}