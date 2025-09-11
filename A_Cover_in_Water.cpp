

#include <bits/stdc++.h>
using namespace std;

int solve( string s, int n){
        
             
               int maxcount =0;
               int total =0;


               for(int i=0;i<n;i++){
                    //  cout<<maxcount<<" ";
                      if (s[i]=='.') total++;

                      if (s[i]=='.' && i+1<n && s[i+1]=='.' && i+2<n && s[i+2]=='.') {
                            maxcount=true;
                            break;
                      }

                      
                        
                        
               }

               if (maxcount) return 2;

               return total;
}

int main (){
     
     
         int t;
         cin>>t;

         while (t--){
                
                        int n;
                        cin>>n;
                        string s;
                        cin>>s;
                        cout<<solve(s,n)<<endl;
              
         }
     
}