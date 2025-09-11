#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Define a maximum power of 3 to consider; 3^19 is just over 10^9
const int MAX_X = 20;
long long p3[MAX_X + 2];
long long costs[MAX_X];

// Precompute powers of 3 and the cost for each deal type for efficiency
void precompute() {
    p3[0] = 1;
    for (int i = 1; i < MAX_X + 2; ++i) {
        p3[i] = p3[i - 1] * 3;
    }

    // Cost for a deal of size 3^0
    costs[0] = 3; 
    // Cost for a deal of size 3^x is C(x) = 3^(x+1) + x * 3^(x-1)
    for (int x = 1; x < MAX_X; ++x) {
        costs[x] = p3[x + 1] + (long long)x * p3[x - 1];
    }
}

// Function to solve a single test case
void solve() {
    long long n, k;
    std::cin >> n >> k;

    // Use a long long vector for digits, as counts can grow large after trades
    std::vector<long long> digits(MAX_X, 0); 
    long long temp_n = n;
    long long min_deals = 0;
    long long current_cost = 0;

    // 1. Get base-3 representation and calculate initial cost and minimum deals
    for (int x = 0; x < MAX_X; ++x) {
        if (temp_n == 0) break;
        digits[x] = temp_n % 3;
        min_deals += digits[x];
        current_cost += digits[x] * costs[x];
        temp_n /= 3;
    }

    // 2. Corrected Feasibility Check
    // It's impossible only if the minimum required deals exceed the budget k.
    if (min_deals > k) {
        std::cout << -1 << std::endl;
        return;
    }

    // 3. Corrected Greedy Optimization
    // Each trade (1 large -> 3 small) uses up 2 "extra" deals.
    long long trades_available = (k - min_deals) / 2;

    // Iterate from largest deals downwards to maximize savings
    for (int x = MAX_X - 1; x >= 1; --x) {
        if (trades_available == 0) {
            break;
        }

        // The saving for one trade at level x is 3^(x-1)
        long long saving_per_trade = p3[x - 1];

        // Number of trades to perform is limited by deals available at this level
        // and the total trades we can still afford.
        long long num_trades_at_x = std::min(digits[x], trades_available);

        current_cost -= num_trades_at_x * saving_per_trade;
        trades_available -= num_trades_at_x;
        
        // **FIX:** Propagate the change. The new smaller deals are now available for future trades.
        digits[x - 1] += 3 * num_trades_at_x;
    }

    std::cout << current_cost << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute();

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}