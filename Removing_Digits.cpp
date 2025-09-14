#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

long long solve(long long b, vector<long long> &dp) {
    if (b == 0)
        return 0;
    if (dp[b] != -1)
        return dp[b];
    long long mini = INT_MAX;
    long long j = b;
    vector<long long> digits;
    while (j) {
        long long d = j % 10;
        if (d != 0) digits.push_back(d);
        j /= 10;
    }
    for (long long d : digits) {
        mini = min(mini, 1 + solve(b - d, dp));
    }
    return dp[b] = mini;
}
const long long MOD = 1e9+7;
int main() {
    long long b;
    cin >> b;
    vector<long long> dp(b + 1, -1);
    cout << solve(b, dp) << endl;
}