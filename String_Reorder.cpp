#include <bits/stdc++.h>
using namespace std;

int main() {
       string s;
       cin>>s;

       int n = s.size();
       char ch ='*';
         string a(n,ch);
        sort(s.begin(),s.end());
  
         map<char,int>mp;
         for(char ch:s)mp[ch]++;
         int idx=0;
         for(auto i:mp){
                  
                  int range = i.second;
                  int k =idx;
                  for(int j=0;j<range;j++){
                               if (a[k]!='*') k++;
                                a[k]=i.first;
                                k+=2;
                  }

                  idx++;
              
         }

         cout<<a<<endl;
      

    return 0;
}