

#include <bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2){
      
          if (s1==s2) return 0;
          int  k  =s2.size();
          int count =0;
          while (s1.size()<k){
             
                  s1=s1+s1;
                  count++;
               
          }

          if (s1.find(s2)!=string::npos){
                 return count;
          }
          s1=s1+s1;
          count++;

          
          if (s1.find(s2)!=string::npos){
                 return count;
          }

          return -1;

}

int main (){
     
     
         int t;
         cin>>t;

         while (t--){
                
                        int n,x;
                        cin>>n>>x;
                        string s1;
                        string s2;
                        cin>>s1>>s2;
                       cout<<solve(s1,s2)<<endl;
         }
     
}