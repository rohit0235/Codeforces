#include <iostream>
#include <vector>
using ll = long long int ;
using namespace std;


int main (){
       
         long long n;
         cin>>n;
        
         vector<long long >s(n,0);
        for(int i=0;i<n;i++) cin>>s[i];
        long long int ans =0;
        for(int i=0;i<n;i++){
               
                 ans+=s[i];
               
        }
        cout<<(n*(n+1))/2 - ans<<endl;




}