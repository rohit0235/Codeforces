#include <iostream>

// This function solves a single test case.
void solve() {
    long long n;
    std::cin >> n;

    long long total_cost = 0;
    int x = 0; // Represents the power in the deal size 3^x

    // We will keep track of the necessary powers of 3 iteratively for efficiency.
    // p3_xm1 corresponds to 3^(x-1)
    // p3_x   corresponds to 3^x
    // p3_xp1 corresponds to 3^(x+1)
    
    // Initial values for x=0 are based on 3^-1, 3^0, and 3^1.
    // Note: 3^-1 is only used in the formula when x > 0.
    long long p3_xm1 = 0; // Placeholder, only relevant for x >= 1
    long long p3_x = 1;   // 3^0
    long long p3_xp1 = 3; // 3^1

    // Process n by converting it to base 3 on the fly.
    while (n > 0) {
        int digit = n % 3; // Get the rightmost digit in base 3

        // If the digit is not zero, we need to make 'digit' number of deals.
        if (digit > 0) {
            long long current_deal_cost;
            if (x == 0) {
                // For x=0, cost C(0) = 3^(0+1) + 0 * 3^(-1) = 3
                current_deal_cost = 3;
            } else {
                // For x > 0, cost C(x) = 3^(x+1) + x * 3^(x-1)
                current_deal_cost = p3_xp1 + (long long)x * p3_xm1;
            }
            total_cost += (long long)digit * current_deal_cost;
        }

        // Move to the next digit (equivalent to n = n / 3)
        n /= 3;
        x++;
        
        // Update powers of 3 for the next iteration
        p3_xm1 = p3_x;
        p3_x = p3_xp1;
        p3_xp1 *= 3;
    }
    std::cout << total_cost << std::endl;
}

int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}