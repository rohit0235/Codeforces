// #include <bits/stdc++.h>
// using namespace std;

// bool ispos(vector<int>&a, int current, int i){
//            int n =a.size();
//         if (i>=n-1) return false;
//         if (i<0) return false;
        
//         if (current==0) return true;
//         if (current<0) return false;

//         int first  =  ispos(a, current-a[i], i+1);
//         int second =  ispos(a, current-a[i], i-1);
      
//         return first || second;
         
     
// }

// int main (){
      
//          ios::sync_with_stdio(false);
//          cin.tie(nullptr);


//     int t;
//     cin>>t;
//     while (t--)
//     {
//         int n, s;
//         cin >> n >> s;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
//          bool flag = false;
//         for(int i=0;i<n;i++){
               
//               int current = s-a[i];
//               swap(a[i],a[n-1]);
//               if (!ispos(a,current, 0 )){
//                flag = true;
//                break;
//               }
//               swap(a[i],a[n-1]);
//         }

//         if (!flag) cout<<-1;
//         else {
//              for(int i:a) cout<<i<<" ";
//         }
//         cout<<endl;
        
         
//     }

//     return 0;


     
// }
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    long long s;
    std::cin >> n >> s;

    std::vector<int> oa(n);
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> oa[i];
        if (oa[i] == 0) c0++;
        else if (oa[i] == 1) c1++;
        else c2++;
    }

    long long total_sum = (long long)c1 * 1 + (long long)c2 * 2;

    if (s < total_sum) {

        std::sort(oa.begin(), oa.end());
        for (int i = 0; i < n; ++i) {
            std::cout << oa[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
        return;
    }
    long long V = s - total_sum;

    std::vector<bool> dp(V + 1, false);
    dp[0] = true;

    std::vector<int> coins;
    coins.push_back(2); 
    coins.push_back(3); 
    if (c2 > 1) {
        coins.push_back(4); 
    }
    
    for (long long i = 1; i <= V; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin]) {
                dp[i] = true;
                break;
            }
        }
    }

    if (dp[V]) {

        std::cout << -1 << std::endl;
    } else {

        for (int i = 0; i < c0; ++i) std::cout << 0 << " ";
        for (int i = 0; i < c2; ++i) std::cout << 2 << " ";
        for (int i = 0; i < c1; ++i) std::cout << 1 << (i == c1 - 1 ? "" : " ");
        std::cout << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}