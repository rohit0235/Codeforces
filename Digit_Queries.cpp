#include <bits/stdc++.h>
using namespace std;

long long solve(long long idx){
      
           string check ="";
           int count =1;
           while (check.size()<=idx){
                 check+=to_string(count);
                 count++;
           }  
           
        //    cout<<
        
         
          
}

int main (){

        long long q;
        cin>>q;
        while (q--){
               
                 long long idx ;
                 cin>>idx;

                           string check ="";
                            int count =1;
                            while (check.size()<=idx+1){
                                    check+=to_string(count);
                                    count++;
                            }  

                            cout<<check[idx-1]<<endl;

                //  cout<<solve(idx)<<endl;
               
        }
      
           
      
}