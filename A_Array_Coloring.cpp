#include <bits/stdc++.h>
using namespace std;


int main (){
     int t;
         cin>>t;

         while (t--){
                
                        int n;
                        cin>>n;

                        vector<int>a(n,0);
                        for(int i=0;i<n;i++){
                             cin>>a[i];
                        }
                       
                        int sum = accumulate(a.begin(),a.end(),0);
                    //    if (n==1) cout<<"NO"<<endl;
                        if (sum%2==0) cout<<"YES"<<endl;
                        else cout<<"NO"<<endl;

                 
         }


     
}