#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main (){
       
       string s;
       cin>>s;

       unordered_map<char,int>mp;
        int n = s.size();
        int l =0;  
        int ans =0;
       for(int r=0;r<n;r++){
               mp[s[r]]++;
              while (l<r && mp.size()>1){
                   mp[s[l]]--;
                   if (mp[s[l]]==0) mp.erase(s[l]);
                   l++;
              }
               int c =mp.begin()->second;
               ans = max(ans , c);
       }
       
       cout<<ans<<endl;




}