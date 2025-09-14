#include <iostream>
#include <vector>
#include <queue>
using ll= long long ;
using namespace std;

vector<ll>solve(vector<ll>&a, ll n , ll m){
            
         priority_queue<ll>maxpq;
         priority_queue<ll,vector<ll>,greater<ll>>minpq;
         for(ll i:a){
             maxpq.push(i);
             minpq.push(i);
         }
         ll first=0;
         for(ll i=0;i<n;i++){
              ll top = maxpq.top();
              maxpq.pop();
                 first+=top;
              if (top-1>0) maxpq.push(top-1);
           
         }
         ll second=0;
         for(ll i=0;i<n;i++){
              ll tops = minpq.top();
              minpq.pop();
              second+=tops;
              if (tops-1>0) minpq.push(tops-1);
           
         }

         return {first,second};
      
}
int main (){
     
        ll n,m;
        cin>>n>>m;

        vector<ll>a(m,0);
        for(ll i=0;i<m;i++) cin>>a[i];

        cout<<solve(a,n,m)[0]<<" "<<solve(a,n,m)[1]<<endl;
      
}