#include <bits/stdc++.h>
using namespace std;

using ll = long long ;

int main (){
      
        ll a,b;
        cin>>a>>b;
        vector<ll>s(a,0);
        for(ll i=0;i<a;i++) cin>>s[i];
        for(ll i=1;i<a;i++){
             s[i]+=s[i-1];
        }
        while (b--){
             
               ll l,  r ;
               cin>>l>>r;
               if (l-1<=0){
                   cout<<s[r-1]<<endl;
               }

               else{
                    cout<<s[r-1]-s[l-2]<<endl;
               }

             
        }
     
}