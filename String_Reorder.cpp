#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
// Function to solve the problem
void solve() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    // 1. Count character frequencies
    vector<int> counts(26, 0);
    for (char c : s) {
        counts[c - 'A']++;
    }

    // Use sets for efficient lookups
    // freq_set stores {-count, char} to find max frequency character quickly
    set<pair<int, char>> freq_set;
    // available_chars stores characters with count > 0 to find smallest char quickly
    set<char> available_chars;

    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
            freq_set.insert({-counts[i], (char)('A' + i)});
            available_chars.insert((char)('A' + i));
        }
    }

    // 2. Initial impossibility check
    if (!freq_set.empty()) {
        int max_freq = -freq_set.begin()->first;
        if (2 * max_freq > n + 1) {
            cout << -1 << endl;
            return;
        }
    }

    // 3. Build the result string greedily
    vector<char> res_vec;
    res_vec.reserve(n);
    char last_char = 0; // Represents no last character
    int rem_len = n;

    for (int i = 0; i < n; ++i) {
        int max_freq = 0;
        if (!freq_set.empty()) {
            max_freq = -freq_set.begin()->first;
        }

        // Check if we are in a "critical state"
        bool is_critical = (2 * max_freq > rem_len);
        char chosen_char;

        if (is_critical) {
            // Must pick the most frequent character
            chosen_char = freq_set.begin()->second;
        } else {
            // Safe to pick the lexicographically smallest valid character
            chosen_char = *available_chars.begin();
            if (chosen_char == last_char) {
                // If the smallest is the same as the last, pick the next smallest.
                // This is safe because in a non-critical state, there are at least two distinct characters available.
                auto it = available_chars.begin();
                ++it;
                chosen_char = *it;
            }
        }
        
        res_vec.push_back(chosen_char);
        
        // --- Update state for the next iteration ---
        int c_idx = chosen_char - 'A';
        
        // Update freq_set by removing the old entry
        if (counts[c_idx] > 0) {
            freq_set.erase({-counts[c_idx], chosen_char});
        }
        
        counts[c_idx]--;
        
        // If character is still available, re-insert with new count.
        // Otherwise, remove it from the set of available characters.
        if (counts[c_idx] > 0) {
            freq_set.insert({-counts[c_idx], chosen_char});
        } else {
            available_chars.erase(chosen_char);
        }
        
        last_char = chosen_char;
        rem_len--;
    }

    // Print the final result
    for (char c : res_vec) {
        cout << c;
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}