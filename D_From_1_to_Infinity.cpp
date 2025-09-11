#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

// Using a map for memoization as values of n can be sparse.
std::map<long long, long long> memo;

// Calculates the sum of digits of all numbers from 1 to n.
long long sum_digits_up_to(long long n) {
    if (n < 0) return 0;
    if (n < 10) {
        return n * (n + 1) / 2;
    }
    if (memo.count(n)) {
        return memo[n];
    }

    long long p10 = 1;
    while (p10 * 10 <= n) {
        p10 *= 10;
    }

    long long msd = n / p10; // Most significant digit
    long long rem = n % p10; // Remainder of the number
    
    // The recursive formula is derived by considering numbers in ranges based on their most significant digit.
    // 1. Sum for prefixes smaller than msd (e.g., for n=345, this handles 100-199, 200-299)
    // 2. Sum for the prefix equal to msd (e.g., for n=345, this handles 300-345)
    long long result = msd * sum_digits_up_to(p10 - 1) + 
                       msd * (msd - 1) / 2 * p10 + 
                       msd * (rem + 1) + 
                       sum_digits_up_to(rem);

    return memo[n] = result;
}

void solve() {
    long long k;
    std::cin >> k;

    long long total_sum = 0;
    long long d = 1;      // number of digits
    long long count = 9;  // count of numbers with 'd' digits
    long long p10 = 1;    // 10^(d-1)

    // Step 1 & 2: Find the target block and sum the full blocks
    while (true) {
        long long digits_in_block = d * count;
        if (k <= digits_in_block) {
            break;
        }

        k -= digits_in_block;
        
        // Sum of digits for all d-digit numbers is sum(1..10^d-1) - sum(1..10^(d-1)-1)
        total_sum += sum_digits_up_to(p10 * 10 - 1) - sum_digits_up_to(p10 - 1);

        d++;
        count *= 10;
        p10 *= 10;
    }

    // Step 3: Handle the remainder within the target block
    long long first_num_in_block = p10;
    long long num_full_numbers = (k - 1) / d;
    
    // Add sum of digits for the full numbers in the partial block
    if (num_full_numbers > 0) {
        long long last_full_number = first_num_in_block + num_full_numbers - 1;
        total_sum += sum_digits_up_to(last_full_number) - sum_digits_up_to(first_num_in_block - 1);
    }
    
    // Add sum of digits from the final, partially-included number
    long long partial_digits_count = k - num_full_numbers * d;
    if (partial_digits_count > 0) {
        long long partial_number = first_num_in_block + num_full_numbers;
        std::string s = std::to_string(partial_number);
        for (int i = 0; i < partial_digits_count; ++i) {
            total_sum += s[i] - '0';
        }
    }

    std::cout << total_sum << std::endl;
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