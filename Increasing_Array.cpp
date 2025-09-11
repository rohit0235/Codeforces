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
        for(int i=1;i<n;i++){
               
                 if(s[i-1]>s[i]){
                      ans+=s[i-1]-s[i];
                      s[i]=s[i-1]; 
                      
                 }
               
        }
        cout<<ans<<endl;




}