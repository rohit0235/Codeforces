#include <iostream>
#include <string>
#include <deque>
#include <vector>

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;
    std::string a;
    std::cin >> a;

    int m;
    std::cin >> m;
    std::string b;
    std::cin >> b;
    std::string c;
    std::cin >> c;

    // Use a deque for efficient additions to both front and back
    std::deque<char> result_dq(a.begin(), a.end());

    // Iterate through the characters to be added
    for (int i = 0; i < m; ++i) {
        if (c[i] == 'V') {
            // Vlad adds to the beginning
            result_dq.push_front(b[i]);
        } else {
            // Dima adds to the end
            result_dq.push_back(b[i]);
        }
    }

    // Print the final string from the deque
    for (char ch : result_dq) {
        std::cout << ch;
    }
    std::cout << "\n";
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