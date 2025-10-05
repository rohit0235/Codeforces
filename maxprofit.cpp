#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main (){
       
        int n;
        cin>>n;
        vector<int>s(n,0);
        for(int i=0;i<n;i++)
        cin>>s[i];


        int buy =s[0];
        int profit=0;

        for(int i=0;i<n;i++){
               
                buy = min(buy,s[i]);
                profit = max(profit , s[i]-buy);
              
        }

        cout<<profit;
}