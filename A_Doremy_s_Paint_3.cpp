#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&a , int n ){
        
                    unordered_map<int , int>mp;

                    for(int i:a) mp[i]++;
                     
                    
                    if (mp.size()>=3) return false;
                    if (mp.size()==1) return true;
                    int diff =0;
                    for(auto i:mp){
                          diff = abs(diff -i.second);
                    }
                    return diff <=1;


}

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
                      
                     if (solve(a,n)){
                            cout<<"Yes"<<endl;
                     }
                     else{
                             cout<<"No"<<endl;
                     }
         }
     
}