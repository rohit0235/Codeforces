#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
template<typename T>
struct FWT {
    int size;
    std::vector<T> tree;

    FWT(int n) : size(n), tree(n + 1, 0) {}

    void update(int idx, T delta) {
        for (; idx <= size; idx += idx & -idx) {
            tree[idx] += delta;
        }
    }

    T query(int idx) {
        T sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    std::vector<long long> llg(n);
    FWT<int> bit1(n);
    for (int i = 0; i < n; ++i) {
        llg[i] = i - bit1.query(p[i]);
        bit1.update(p[i], 1);
    }
    std::vector<long long> rlg(n);
    FWT<int> bit2(n);
    for (int i = n - 1; i >= 0; --i) {
        rlg[i] = (n - 1 - i) - bit2.query(p[i]);
        bit2.update(p[i], 1);
    }
    long long biver = 0;
    for (long long val : llg) {
        biver += val;
    }
    long long delta = 0;
    for (int i = 0; i < n; ++i) {
        long long c_i = rlg[i] - llg[i];
        if (c_i < 0) {
            delta += c_i;
        }
    }
    
    std::cout << biver + delta << std::endl;
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