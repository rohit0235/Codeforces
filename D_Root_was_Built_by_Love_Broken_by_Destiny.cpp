#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    
    x--; 
    int lw = 0, le = 0;
    int rw = 0, re = 0;
    
    for (int i = 0; i < x; i++) {
        if (s[i] == '#') lw++;
        else le++;
    }
    
    for (int i = x + 1; i < n; i++) {
        if (s[i] == '#') rw++;
        else re++;
    }
    
    if (lw == 0 || rw == 0) {
        return 1;
    }
    
    int lt = lw + min(rw, le);
    int drt = rw + min(lw, re);
    
    return min(lt, rightTotal) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        cout << solve() << "\n";
    }
    
    return 0;
}



//CF D