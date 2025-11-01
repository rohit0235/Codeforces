#include <bits/stdc++.h>
using namespace std;

int main (){
     
     string s ;
     cin>>s;

     string pre ="";
     string suff ="";
     int n= s.size()-1;
     int i=0;
     int k = n;
     while (i<k){
           pre+=s[i];
           i++;
           suff+=s[n];
        //    cout<<pre<<" "<<suff<<" ";
           string ok = suff;
           reverse(ok.begin(),ok.end());
           if (pre==ok) cout<<pre.size()<<" ";
           n--;
     }
     

     
}