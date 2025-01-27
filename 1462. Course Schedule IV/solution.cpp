class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for(auto edge: prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<bool> answer;
        for(auto q: queries) {
            answer.push_back(isPrerequisite(adjList, q[0], q[1]));
        }

        return answer;
    }

private: 
    bool isPrerequisite(unordered_map<int, vector<int>>& adjList, int src, int target) {
        unordered_set<int> visited;
        stack<int> stk;
        stk.push(src);

        while(!stk.empty()) {
            int node = stk.top();
            stk.pop();

            if(visited.find(node) == visited.end()) {
                visited.insert(node);
            }

            if(node == target){
                return true;
            }

            for(auto adj : adjList[node]) {
                if(visited.find(adj) == visited.end()) {
                    stk.push(adj);
                }
            }
        }
        return false;
    }
};