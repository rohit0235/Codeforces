// #include <bits/stdc++.h>
// using namespace std;
// int n, m;

// // bool dfs(vector<vector<bool>>&visited, int x , int y ,    vector<vector<char>>&s, string& curr){
        
// //         if (x<0 || y<0 || x>=n || y>=m || s[x][y]=='#' || visited[x][y] ) return false ;
// //         if (s[x][y]=='B') return true;
// //          visited[x][y]=true;
        
// //          curr+='D';
// //          if(dfs(visited,x+1,y,s,curr)) return true;
// //          curr.pop_back();

// //          curr+='U';
// //          if(dfs(visited,x-1,y,s,curr) ) return true;;
// //          curr.pop_back();

// //          curr+='R';
// //           if   (dfs(visited,x,y+1,s,curr)) return true;
// //          curr.pop_back();
         
// //          curr+='L';
// //         if ( dfs(visited,x,y-1,s,curr)) return true;;
// //          curr.pop_back();
// //         return false;
// // }
// int main (){
     
       
//        cin>>n>>m;
       
//        vector<vector<char>>s(n,vector<char>(m,' '));

//        for(int i=0;i<n;i++){
//           for(int j=0;j<m;j++){
//              cin>>s[i][j];
//           }
//        }
       
//        vector<vector<bool>>visited(n,vector<bool>(m,false));
//        int count =0;
//          string curr ="";
//        for(int i=0;i<n;i++){
         
//              for(int j=0;j<m;j++){
//                   // cout<<visited[i][j]<<" "<<s[i][j]<<endl;
//                   if ( s[i][j]=='A'){ 
                       
//                          bfs(visited,i,j,s,curr);
//                         //   cout<<curr;
                        
//                   }
//              }
//        }
//         if (curr.empty()){
//           cout<<"NO"<<endl;
//         }
//         else{
//            cout<<"YES"<<endl;
//            cout<<curr.size()<<endl;
//            cout<<curr<<endl;
//         }
      
// }

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // Faster I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    pair<int, int> start, end;

    // Read the grid and find the start ('A') and end ('B') points
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            } else if (grid[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    // --- BFS Setup ---

    // The queue stores the coordinates of cells to visit.
    queue<pair<int, int>> q;
    q.push(start);

    // To reconstruct the path, we store the parent of each cell.
    // parent[x][y] will store the coordinates of the cell we came from to reach (x, y).
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    
    // A visited array to avoid cycles and redundant processing.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[start.first][start.second] = true;

    // Arrays to help navigate the grid: Down, Right, Up, Left
    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, 1, 0, -1};
    char moves[] = {'D', 'R', 'U', 'L'};

    bool found = false;

    // --- BFS Algorithm ---
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        // If we've reached the end, stop the search.
        if (curr == end) {
            found = true;
            break;
        }

        // Explore all 4 neighbors (Down, Right, Up, Left)
        for (int i = 0; i < 4; ++i) {
            int next_r = curr.first + dr[i];
            int next_c = curr.second + dc[i];

            // Check if the neighbor is a valid move
            if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m &&  // is it within bounds?
                grid[next_r][next_c] != '#' &&                             // is it not a wall?
                !visited[next_r][next_c]) {                                // have we not visited it yet?
                
                visited[next_r][next_c] = true;      // Mark as visited
                parent[next_r][next_c] = curr;       // Set its parent
                q.push({next_r, next_c});            // Add it to the queue to visit later
            }
        }
    }

    // --- Output ---
    if (found) {
        cout << "YES" << endl;
        string path = "";
        pair<int, int> curr = end;

        // Backtrack from the end to the start using the parent pointers
        while (curr != start) {
            pair<int, int> p = parent[curr.first][curr.second];
            // Figure out which move was taken to get from p to curr
            for (int i = 0; i < 4; ++i) {
                if (p.first + dr[i] == curr.first && p.second + dc[i] == curr.second) {
                    path += moves[i];
                    break;
                }
            }
            curr = p; // Move to the parent
        }
        
        // The path is built backward, so we must reverse it
        reverse(path.begin(), path.end()); 
        
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    } 

    return 0;
}