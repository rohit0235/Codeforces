#include <bits/stdc++.h>
using namespace std;
using ll =long long ;

// // ll solve(vector<ll>&price, vector<ll>&pages , ll i , ll cost, ll n, vector<vector<ll>>&dp){
// //           if (cost==0) return 0;
// //           if (i>=n) return 0;
// //           if (dp[i][cost]!=-1) return dp[i][cost];
// //            ll first = 0;
// //            ll second =0;
// //            if(cost-price[i]>=0){
// //                first = pages[i]+solve(price ,pages ,i+1,cost-price[i],n,dp);
// //                second = solve(price ,pages ,i+1,cost,n,dp);
// //            }
// //            else{
// //                    second = solve(price ,pages ,i+1,cost,n,dp);
// //            }
           
// //            return dp[i][cost]=max(first , second);

      
// // }
// int main (){
     
//     ll n ,x;
//     cin>>n>>x;
//     // n is total element and x is the maximum amount we have 


//     vector<ll>price(n,0);
//     vector<ll>pages(n,0);
//     for(ll i=0;i<n;i++) cin>>price[i];
//     for(ll i=0;i<n;i++) cin>>pages[i];
//     vector<vector<ll>>dp(n+1,vector<ll>(x+1,-1));
//     cout<<solve(price, pages , 0 , x, n,dp);
     
// }

int main () {
    ll n, x;
    cin >> n >> x;
    vector<ll> price(n), pages(n);
    for(ll i = 0; i < n; i++) cin >> price[i];
    for(ll i = 0; i < n; i++) cin >> pages[i];
    vector<ll> dp(x + 1, 0);
    for (ll i = 0; i < n; i++) {
        for (ll j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    cout << dp[x] << endl;
}