#include <bits/stdc++.h>
using namespace std;



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
                 
                        sort(a.rbegin(),a.rend());
         
                       if (a[0]==a[n-1]){
                             cout<<-1<<endl;
                       }   
                       else{
                          
                                    vector<int>ans;
                                    ans.push_back(a[0]);
                                     int i;
                                    for( i=1;i<n-1;i++){
                                          if (a[i]==a[0]) ans.push_back(a[0]);
                                          else break;
                                    }
                                    vector<int>b;
                                   
                                    while (i<n){ 
                                         b.push_back(a[i]);
                                         i++;
                                    }

                                    cout<<b.size()<<" "<<ans.size();
                                    cout<<endl;

                                  
                                    for(int i:b)cout<<i<<" ";
                                    cout<<endl;
                                      for(int i:ans)cout<<i<<" ";
                                    cout<<endl;
                              
                       }
                  }
                
     
}