class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        vector<int> adjList[N];
        for(auto edge: edges) {
            vector<bool> visited(N, false);

            if(isConnected(edge[0] - 1, edge[1] - 1, visited, adjList)) {
                return edge;
            }

            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        return {};
    }
private:
    bool isConnected(int src, int target, vector<bool>& visited, vector<int> adjList[]) {
        visited[target] =  true;

        if(src == target) {
            return true;
        }

        int isFound = false;
        for(int adj: adjList[target]) {
            if(!visited[adj]) {
                isFound = isFound || isConnected(src, adj, visited, adjList);
            }
        }

        return isFound;
    }
};