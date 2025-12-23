#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll =  long long  ;
int main (){
     
        ll n;
        cin>>n;
        vector<ll>s(n,0);
        for(ll i=0;i<n;i++){
              cin>>s[i];
        }
        ll ans =0;
        for(ll i=0;i<n;i++){
              int k =   __builtin_popcount(s[i]);
              ans +=pow(1,i+1);
        }
        cout<<ans<<endl;
 
}