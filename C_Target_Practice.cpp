#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        vector<string> grid(10);
        for (int i = 0; i < 10; i++) {
            cin >> grid[i];
        }
        
        int totalScore = 0;
        
        // Calculate score for each position
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (grid[i][j] == 'X') {
                        
                     if (j==0 || j==9  || i==0 || i==9) totalScore+=1;
                     else  if (j==1 || j==8  || i==1 || i==8) totalScore+=2;
                     else  if (j==2 || j==7  || i==2 || i==7) totalScore+=3;
                     else  if (j==3 || j==6  || i==3 || i==6) totalScore+=4;
                     else  if (j==4 || j==5  || i==4 || i==5) totalScore+=5;
                     
                 
                }
            }
        }
        
        cout << totalScore << "\n";
    }
    
    return 0;
}
