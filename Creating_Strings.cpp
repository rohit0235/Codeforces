#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s;

    std::cin >> s;


    std::sort(s.begin(), s.end());

    int count = 0;
    std::vector<std::string> uniquePermutations;
    do {
        count++;
        uniquePermutations.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));

    // Step 3: Print the results.
    std::cout << count << std::endl;
    for (const std::string& perm : uniquePermutations) {
        std::cout << perm << std::endl;
    }

    return 0;
}