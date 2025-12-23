#include <iostream>
#include <vector>   
#include <algorithm>   

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    int find(int u, vector<int>& parent) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u], parent);
    }

    void unite(int u, int v, vector<int>& parent, vector<int>& rank) {
        int rootU = find(u, parent);
        int rootV = find(v, parent);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    int getMST(int V, vector<vector<int>>& edges, int excludeEdgeIndex, vector<int>& mstEdgesIndices) {
        vector<int> parent(V);
        vector<int> rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        int mstWeight = 0;
        int edgesCount = 0;

        for (int i = 0; i < edges.size(); i++) {
            if (i == excludeEdgeIndex) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (find(u, parent) != find(v, parent)) {
                unite(u, v, parent, rank);
                mstWeight += w;
                edgesCount++;
                if (excludeEdgeIndex == -1) {
                    mstEdgesIndices.push_back(i);
                }
            }
        }

        if (edgesCount < V - 1) return -1;
        return mstWeight;
    }

    int secondMST(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), cmp);

        vector<int> mstEdgesIndices;
        int firstMST = getMST(V, edges, -1, mstEdgesIndices);

        if (firstMST == -1) return -1; 

        int secondMST = 2147483647; 
        bool found = false;

        for (int index : mstEdgesIndices) {
            vector<int> dummy;
            int currentMST = getMST(V, edges, index, dummy);
            if (currentMST != -1) {
                if (currentMST < secondMST) {
                    secondMST = currentMST;
                    found = true;
                }
            }
        }

        return found ? secondMST : -1;
    }
};

int main (){ 

       int V;
       cin>>V;

       int e;
       cin>>e;

       vector<vector<int>>edges(e,vector<int>(3,0));
      
       for(int i=0;i<e;i++){
              
             int u,v,w;
             cin>>u>>v>>w;
             edges[i] = {u,v,w};
           
       } 
        Solution ob;

        cout<< ob.secondMST(V,edges);

      
}