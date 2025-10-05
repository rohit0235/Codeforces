#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Using std namespace for cleaner code
using namespace std;

// Maximum expected value of n
const int MAXN = 200005;
// Maximum expected value for log2(n), ceil(log2(200005)) is 18
const int K = 18;

// st[i][j] will store the minimum value in the range starting at i having length 2^j
int st[MAXN][K];

// log_table[i] will store the value of floor(log2(i))
int log_table[MAXN];

// Precomputes the logarithm values for O(1) lookup
void precompute_log(int n) {
    log_table[1] = 0;
    for (int i = 2; i <= n; i++) {
        log_table[i] = log_table[i / 2] + 1;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    // Precompute logarithms up to n
    precompute_log(n);

    // Initialize the first column of the sparse table (ranges of length 2^0 = 1)
    for (int i = 0; i < n; i++) {
        cin >> st[i][0];
    }

    // --- Build the Sparse Table ---
    // Iterate over powers of 2 (j represents the power)
    for (int j = 1; j < K; j++) {
        // Iterate over each starting index i
        // i + (1 << j) <= n ensures the range [i, i + 2^j - 1] is within bounds
        for (int i = 0; i + (1 << j) <= n; i++) {
            // The minimum of a range of size 2^j is the minimum of its two halves,
            // each of size 2^(j-1).
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    // --- Process Queries ---
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; 
        b--;

        int len = b - a + 1;
        int j = log_table[len];
        int minimum = min(st[a][j], st[b - (1 << j) + 1][j]);
        cout << minimum << "\n";
    }

    return 0;
}