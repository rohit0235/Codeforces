#include <bits/stdc++.h>
using namespace std;

const int M = 1000001;
int u[M];
int fa[M], fb[M];
bool d = false;

void p() {
    if (d) return;
    fill(u, u + M, 0);
    u[1] = 1;
    vector<int> pr;
    vector<bool> is(M, true);
    is[0] = is[1] = false;
    for (int i = 2; i < M; ++i) {
        if (is[i]) {
            pr.push_back(i);
            u[i] = -1;
        }
        for (int j : pr) {
            if (i * j >= M) break;
            is[i * j] = false;
            if (i % j == 0) {
                u[i * j] = 0;
                break;
            }
            u[i * j] = -u[i];
        }
    }
    d = true;
}

long Count_sol(int N, vector<int> A, vector<int> B) {
    p();
    memset(fa, 0, sizeof(fa));
    memset(fb, 0, sizeof(fb));
    
    for (int x : A) fa[x]++;
    for (int x : B) fb[x]++;
    
    long long c = 0;
    for (int i = 1; i < M; ++i) {
        if (u[i] == 0) continue;
        long long ca = 0, cb = 0;
        for (int j = i; j < M; j += i) {
            ca += fa[j];
            cb += fb[j];
        }
        c += u[i] * ca * cb;
    }
    
    return (long)((long long)N * N - c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        cout << Count_sol(n, a, b) << endl;
    }
    return 0;
}