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
                         
                         int neg =0;
                         int pos =0;
                        for(int i:a){
                             if (i==-1) neg++;
                             else pos++;
                        }
                       int op=0;
                        while (pos<neg || neg%2==1){ 
                                  pos++;
                                  neg--;
                                  op++;
                                
                        }

                        cout<<op<<endl;

                 
         }


     
}