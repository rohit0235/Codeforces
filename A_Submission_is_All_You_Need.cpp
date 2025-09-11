#include <bits/stdc++.h>
using namespace std;
int mp(vector<int>&s){
     
     sort(s.begin(), s.end());

     int score = 0;
     int n =s.size();
     int total =0;
     for(int i=0;i<n;i++){
         
           if (s[i]==0) score+=1;
           else total+=s[i];
         
     }

     return total+score;
     

}

int main (){
     
    int t;
    cin>>t;
while (t--)
{
    /* code */


        int n;
    cin>>n;

    vector<int>s(n,0);
  
    for(int i=0;i<n;i++) cin>>s[i];


    cout<<mp(s)<<endl;

}


     
     
}