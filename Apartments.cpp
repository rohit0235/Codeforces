#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,m,k;
    cin>>n>>m>>k;

    vector<int>a(n,0);
    vector<int>b(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];


    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
int count = 0;
   for(int i=0;i<n;i++){
    
                int l=0;
                int r=m-1;
                int ans =-1;
                    while (l<=r){
                    
                        int mid = l+(r-l)/2;

                        if (b[mid]-a[i]<=5 && b[mid]-a[i]>=0){
                            ans = mid;
                            r=mid-1;
                        }
                        else if (b[mid]-a[i]>5){
                             r=mid-1;
                        }
                        else {
                             l =mid+1;
                        }
                    
                  }
                 cout<<ans<<endl;
                  if (ans!=-1) {
                        count++;
                        b[ans]=INT_MAX;
                  }

   }

   cout<<count<<endl;



    return 0;
}