#include <iostream>

long long power_of_two_mod(int n) {
    long long mod = 1e9 + 7;
    long long result = 1;
    long long base = 2;

    while (n > 0) {
        // If n is odd, multiply result by the current base
        if (n % 2 == 1) {
            result = (result * base) % mod;
        }

        // Square the base for the next iteration
        base = (base * base) % mod;

        // Halve the exponent
        n = n / 2;
    }

    return result;
}

int main() {
    int exponent;
       std::cin>>exponent;
    long long result = power_of_two_mod(exponent);
        std::cout<<result<<   std::endl;
    // The result for 2^1000 mod 10^9+7 will be a large number

    return 0;
}