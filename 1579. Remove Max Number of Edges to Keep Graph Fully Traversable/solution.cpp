#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int component_count;
    
    UnionFind(int n) : parent(n), rank(n, 1), component_count(n) {
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    
    int find(int u){
        if(parent[u] != u){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    bool union_sets(int u, int v){
        int root_u = find(u);
        int root_v = find(v);
        if(root_u != root_v){
            if(rank[root_u] > rank[root_v]){
                parent[root_v] = root_u;
            }
            else if(rank[root_v] > rank[root_u]){
                parent[root_u] = root_v;
            }
            else{
                parent[root_v] = root_u;
                rank[root_u] += 1;
            }
            component_count--;
            return true;
        }
        return false;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
       UnionFind uf_alice(n), uf_bob(n), uf_shared(n);
        
        sort(edges.begin(), edges.end(), [](const vector<int>&a, vector<int>&b){
            return a[0] > b[0];
        });
        
        int removed_edges = 0;
        
        for(const auto& edge : edges){
            int type = edge[0],  u = edge[1] - 1, v = edge[2] - 1;
            
            if(type == 3){
                if(uf_shared.union_sets(u, v)){
                    uf_alice.union_sets(u, v);
                    uf_bob.union_sets(u, v);
                }
                else{
                    removed_edges++;
                }
            }
            else if(type == 1){
                if(!uf_alice.union_sets(u,v)){
                    removed_edges++;
                }
            }
            else if(type == 2){
                if(!uf_bob.union_sets(u, v)){
                    removed_edges++;
                }
            }
        }
        
        if(uf_alice.component_count > 1 || uf_bob.component_count > 1)
            return -1;
        
        return removed_edges;
    }
};


int main() {

    int n = 4;
    vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
    
    Solution sol;
    int result = sol.maxNumEdgesToRemove(n, edges);
    
    cout << "Maximum number of edges removed: " << result << endl;
    
    return 0;
}