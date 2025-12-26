#include <iostream>

using namespace std;

#define ll long long

void solve() {
    ll n;
    cin >> n;
 
    if (n == 1 || n == 2 || n == 3 || n == 6 || n % 4 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}