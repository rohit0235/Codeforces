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
                       
                       
                         int mindiff =INT_MAX;

                         for(int i=1;i<n;i++){
                               mindiff = min(mindiff, a[i]-a[i-1]);
                         }

                         if (mindiff<0) cout<<0<<endl;
                         else{
                                 cout<<mindiff/2+1<<endl;
                         }
                        

                 
         }


     
}