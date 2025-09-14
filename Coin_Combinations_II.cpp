#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// long long solve(vector<long long> &s, long long b, vector<long long> &dp)
// {

//     if (b == 0)
//         return 1;
//     if (b < 0)
//         return 0;

//     long long mini = 0;
//     for (long long i = 0; i < s.size(); i++)
//     {

//         long long st =  solve(s, b - s[i], dp);
//         mini += st;
//     }

//     return dp[b] = mini;
// }
const long long MOD = 1e9+7;
int main()
{

    long long a, b;
    cin >> a >> b;
    vector<long long > dp(b + 1, 0);
    vector<long long > s(a, 0);
    for (long long i = 0; i < a; i++)
        cin >> s[i];

    // cout << solve(s, b, dp);

     dp[0]=1;
    //  for(long long  i=1;i<=b;i++){
            
             for(long long  coin:s){
                 for(long long i = 0 ;i<=b ;i++){
                          if(i-coin>=0 ){ 
                              dp[i] = (dp[i] + dp[i-coin]) % MOD;
                        }
                 }
             
              
             }
    //  }
     cout<<dp[b]%MOD<<endl;






}