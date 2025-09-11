#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<long long> s(n, 0);

    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(s.begin(), s.end());

    long long sum = accumulate(s.begin(), s.end(), 0LL);

    int i = 0;
    int j = n - 1;
    long long ans = sum;
    long long leftsum = 0;
    long long rightsum = 0;

    //  long long sums =0;
    while (i <= j)
    {

        // //    if (sums+s[j]<=(sum-sums-s[j])){
        //          sums+=s[j];
        //          j--;
        // //    }
        //    ans = min(ans , abs(sum-sums-sums));

        //     // if (sums+s[i]<=(sum-sums-s[i])){
        //          sums+=s[i];
        //          i++;
        // //    }
        // //    cout<<sums<<endl;

        if (leftsum < rightsum)
        {
            leftsum += s[i];
            ans = min(ans, abs(leftsum - rightsum));
            i++;
        }
        else
        {
            rightsum += s[j];
            ans = min(ans, abs(leftsum - rightsum));
            j--;
        }

  
    }

          cout << ans << endl;

}