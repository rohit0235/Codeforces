#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
const ll INF = 1e18;
const int MOD = 998244353;


struct Mat {
    ll m[2][2];
    Mat() {
        m[0][0] = m[0][1] = m[1][0] = m[1][1] = -INF;
    }
    static Mat id() {
        Mat res;
        res.m[0][0] = res.m[1][1] = 0;
        return res;
    }
};

struct Vec {
    ll v[2];
    Vec() { v[0] = v[1] = -INF; }
};

// Matrix * Matrix
Mat mul(const Mat& A, const Mat& B) {
    Mat C;
    for(int i=0; i<2; ++i) {
        for(int k=0; k<2; ++k) {
            if(A.m[i][k] == -INF) continue;
            for(int j=0; j<2; ++j) {
                if(B.m[k][j] == -INF) continue;
                if (A.m[i][k] + B.m[k][j] > C.m[i][j]) {
                    C.m[i][j] = A.m[i][k] + B.m[k][j];
                }
            }
        }
    }
    return C;
}

// Matrix * Vector
Vec mul(const Mat& A, const Vec& b) {
    Vec c;
    for(int i=0; i<2; ++i) {
        for(int j=0; j<2; ++j) {
            if(A.m[i][j] == -INF || b.v[j] == -INF) continue;
            if (A.m[i][j] + b.v[j] > c.v[i]) {
                c.v[i] = A.m[i][j] + b.v[j];
            }
        }
    }
    return c;
}

int N;
vector<ll> A;
ll total_ans = 0;

void solve(int l, int r) {
    if (l == r) {
        total_ans = (total_ans + max(0LL, A[l])) % MOD;
        return;
    }
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);

    // Left side processing: Calculate state vectors for all suffixes of [l, mid]
    vector<Vec> left_vecs;
    Vec curr; 
    curr.v[0] = 0; curr.v[1] = -INF;
    
    Mat acc = Mat::id();
    // Iterate backwards from mid to l
    for (int i = mid; i >= l; --i) {
        Mat m;
        ll val = A[i];
        ll k = i + 1; // 1-based index for day
        
        // Transitions for day k
        m.m[0][0] = max(0LL, val); // Stay 0 (or buy-sell immediately)
        m.m[0][1] = k;             // Sell (1 -> 0)
        m.m[1][0] = val - k;       // Buy (0 -> 1)
        m.m[1][1] = 0;             // Hold (1 -> 1)
        
        acc = mul(acc, m); // Accumulate: M_mid * ... * M_i
        left_vecs.push_back(mul(acc, curr));
    }


    vector<pair<ll, int>> diffs; 
    for(int i=0; i<left_vecs.size(); ++i) {
        diffs.push_back({left_vecs[i].v[1] - left_vecs[i].v[0], i});
    }
    sort(diffs.begin(), diffs.end());

    vector<ll> sumX(left_vecs.size() + 1, 0);
    vector<ll> sumY(left_vecs.size() + 1, 0);
    
    for(int i=0; i<diffs.size(); ++i) {
        int idx = diffs[i].second;
        sumX[i+1] = (sumX[i] + left_vecs[idx].v[0] % MOD + MOD) % MOD;
        sumY[i+1] = (sumY[i] + left_vecs[idx].v[1] % MOD + MOD) % MOD;
    }

 
    acc = Mat::id();
    for (int j = mid + 1; j <= r; ++j) {
        Mat m;
        ll val = A[j];
        ll k = j + 1;
        
        m.m[0][0] = max(0LL, val); 
        m.m[0][1] = k;
        m.m[1][0] = val - k; 
        m.m[1][1] = 0;
        
        acc = mul(m, acc); // Accumulate: M_j * ... * M_{mid+1}
        
   
        ll A_val = acc.m[0][0];
        ll B_val = acc.m[0][1];
        ll K = B_val - A_val;
        
        // Find split point: diff > -K means B + Y > A + X
        auto it = upper_bound(diffs.begin(), diffs.end(), make_pair(-K, (int)2e9));
        int split = distance(diffs.begin(), it);
        
        ll count1 = split;
        ll count2 = diffs.size() - split;
        
        ll term1 = (count1 % MOD * (A_val % MOD + MOD) % MOD + sumX[split]) % MOD;
        ll term2 = (count2 % MOD * (B_val % MOD + MOD) % MOD + (sumY[diffs.size()] - sumY[split] + MOD) % MOD) % MOD;
        
        total_ans = (total_ans + term1 + term2) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while(T--) {
            cin >> N;
            A.resize(N);
            for(int i=0; i<N; ++i) cin >> A[i];
            
            total_ans = 0;
            solve(0, N-1);
            cout << total_ans << "\n";
        }
    }
    return 0;
}