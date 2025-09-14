#include <bits/stdc++.h>
using namespace std;

int main() {
        long long n;
        cin>>n;
        vector<long long>s(n,0);
        for(long long i=0;i<n;i++) cin>>s[i];

        // unordered_set<long long>st(s.begin(),s.end());
        sort(s.begin(),s.end());
        long long ans =1;
        for(int i=1;i<n;i++){
               if (s[i-1]!=s[i]){
                 ans++;
               }
        }
        cout<<ans;

    return 0;
}