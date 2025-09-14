// #include <bits/stdc++.h>
// using namespace std;
// const long long mod = 1e9+7;

// long long solve(long long n, long long sum,vector<long long >&dp){
         
//         if (sum==n) return 1;
//          if (sum>n) return 0;
//          if (dp[sum]!=-1) return dp[sum];
//         long long first = solve(n, sum+1,dp)%mod;
//         long long sec= solve(n, sum+2,dp)%mod;
//         long long thir= solve(n, sum+3,dp)%mod;
//         long long four = solve(n, sum+4,dp)%mod;
//         long long five = solve(n, sum+5,dp)%mod;
//         long long six= solve(n, sum+6,dp)%mod;
       
//         return dp[sum]=(first+sec+thir+five+four+six)%mod;
      
// }
// int main() {

    
//     long long n;
//     cin>>n;
//    vector<long long >dp(n+1,-1);
//     long long ans =  solve(n,0,dp) %mod;
//    cout<<ans;

//     return 0;
// }



// approach 2 
// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     long long n;
//     cin >> n;

//     const long long mod = 1e9 + 7;

//     // dp[i] stores the number of ways to get a sum of i
//     vector<long long> dp(n + 1, 0);

//     // Base case: There is one way to make a sum of 0 (by doing nothing)
//     dp[0] = 1;

//     // Iterate from 1 to n to fill the dp table
//     for (int i = 1; i <= n; ++i) {
//         // Look back at the last 6 possible outcomes
//         for (int j = 1; j <= 6; ++j) {
//             if (i - j >= 0) {
//                 dp[i] = (dp[i] + dp[i - j]) % mod;
//             }
//         }
//     }

//     cout << dp[n] << endl;

//     return 0;
// }



// approach 3
#include <iostream>
#include <vector>

using namespace std;

// Define the modulus and matrix size
const long long mod = 1e9 + 7;
const int K = 6;

// A helper function to multiply two KxK matrices
vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
    vector<vector<long long>> C(K, vector<long long>(K, 0));
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int l = 0; l < K; ++l) {
                C[i][j] = (C[i][j] + A[i][l] * B[l][j]) % mod;
            }
        }
    }
    return C;
}

// A function to compute matrix exponentiation (T^p)
vector<vector<long long>> power(vector<vector<long long>> T, long long p) {
    // Create an identity matrix
    vector<vector<long long>> result(K, vector<long long>(K, 0));
    for (int i = 0; i < K; ++i) {
        result[i][i] = 1;
    }

    // Use exponentiation by squaring
    while (p > 0) {
        if (p % 2 == 1) {
            result = multiply(result, T);
        }
        T = multiply(T, T);
        p /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }

    // Step 1: Calculate the initial DP values to form the base vector S_5
    // dp_base[i] will store DP[i]
    vector<long long> dp_base(K);
    dp_base[0] = 1; // DP[0] = 1
    for (int i = 1; i < K; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp_base[i] = (dp_base[i] + dp_base[i - j]) % mod;
            }
        }
    }
    
    // If n is small, we already have the answer
    if (n < K) {
        cout << dp_base[n] << endl;
        return 0;
    }

    // Our base state vector S_5 is [DP[5], DP[4], ..., DP[0]]
    // Let's call it F1
    vector<long long> F1(K);
    for(int i = 0; i < K; ++i) {
        F1[i] = dp_base[K - 1 - i];
    }
    
    // Step 2: Define the Transformation Matrix T
    vector<vector<long long>> T(K, vector<long long>(K, 0));
    for (int i = 0; i < K; ++i) {
        T[0][i] = 1;
    }
    for (int i = 1; i < K; ++i) {
        T[i][i - 1] = 1;
    }

    // Step 3: Raise T to the power of (n-5), which is n-(K-1)
    T = power(T, n - (K - 1));

    // Step 4: The answer is the top element of (T * S_5)
    // This is the dot product of the first row of T and the vector F1
    long long ans = 0;
    for (int i = 0; i < K; ++i) {
        ans = (ans + T[0][i] * F1[i]) % mod;
    }
    
    // Ensure the result is non-negative
    if (ans < 0) {
        ans += mod;
    }

    cout << ans << endl;

    return 0;
}