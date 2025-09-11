#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{

    string s;
    cin >> s;

    vector<int> c(26, 0);
    for (char i : s)
        c[i - 'A']++;

    int odd = 0;
    for (int i : c)
        if (i % 2 == 1)
            odd++;
    if (odd > 1)
        cout << "NO SOLUTION" << endl;
    else
    {

        string ans = "";
        int idx = -1;

        for (int i = 0; i < 26; i++)
        {

            if (c[i] % 2 == 1)
                idx = i;
            else
            {
                ans += string(c[i] / 2, i + 'A');
            }
        }
        if (idx == -1)
        {

            string ok = ans;
            reverse(ans.begin(), ans.end());
            cout << ok + ans << endl;
        }
        else
        {
            string m = ans;
            reverse(ans.begin(), ans.end());
            string ok = ans;
            // cout<<idx<<" ";
            m += string(c[idx],idx + 'A');
            cout << m + ans << endl;
        }
    }
}