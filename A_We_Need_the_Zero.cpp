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
                        
                        int ans =0;

                        for(int i:a)ans^=i;
                        int z=0;
                        for(int i:a)if (i==0)z++;
                        if ((n-z)%2==1)cout<<ans<<endl;
                        else  if (n%2==1)cout<<ans<<endl;
                        else cout<<ans-1<<endl;

                        // (a0+x)*(a1*x)*(a2*x);


                  
         }


     
}