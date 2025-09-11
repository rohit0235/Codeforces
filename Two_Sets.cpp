#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main (){
       
         long long n;
         cin>>n;
         long long total = ((n)*(n+1)*1LL)/2;

          if (total%2!=0) cout<<"NO"<<endl;
          else{
                   cout<<"YES"<<endl;
                   vector<long long>ans;
                   
                   long long i=1;
                   long long j=n;
                   long long sum =0;
                   while (sum<total/2){
                         
                             if (sum+i+j<=total/2){
                                 sum+=i+j;
                                 ans.push_back(i);
                                 ans.push_back(j);  
                                   i++;
                             }
                             else {
                                       sum+= j;
                                       ans.push_back(j);
                             }
                             
                         
                             j--;
                      
                   }
                   cout<<ans.size()<<endl;
                   sort(ans.rbegin(),ans.rend());
                   for(long long i:ans) cout<<i<<" ";
                    cout<<endl;
                
                    cout<<n-ans.size()<<endl;
                    ans.clear();
                    while (i<j){
                        //  cout<<i<<" "<<j<<" ";
                         ans.push_back(i);
                         ans.push_back(j);
                         i++;
                         j--;
                    }
                     sort(ans.rbegin(),ans.rend());
                     for(long long i:ans) cout<<i<<" ";


                 
                //    cout<<endl;
          }
          
          // 1 2 4 7 
          // 3 5 6 8

          // 1  2  4   7  11 
          //  3  5  6  8  9  10 

          // 12 + 12 + 9 
          // 1   11   2   10  9

          

          



}