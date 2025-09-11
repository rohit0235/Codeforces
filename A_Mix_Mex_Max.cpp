#include <iostream>

// Solves a single test case
void solve() {
    int n;
    std::cin >> n;
    

    int v = -2; 
    
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        if (a != -1) {
            if (v == -2) {
        
                v = a;
            } else if (v != a) {

                v = -3; 
            }
        }
    }
    

    if (v == -3 || v == 0) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}