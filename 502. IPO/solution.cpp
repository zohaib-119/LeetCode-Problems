#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int, int>> projects;
        
        for (int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Sort projects based on capital (ascending)
        sort(projects.begin(), projects.end());
        
        priority_queue<int> max_heap;
        
        int i = 0;
        for (int count = 0; count < k; ++count) {
            while (i < n && projects[i].first <= w) {
                max_heap.push(projects[i].second);
                ++i;
            }
            
            if (max_heap.empty()) break;
            
            w += max_heap.top();
            max_heap.pop();
        }
        
        return w;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    int k = 2;
    int w = 0;

    int maxCapital = sol.findMaximizedCapital(k, w, profits, capital);
    cout << "Maximum capital after investing in " << k << " projects: " << maxCapital << endl;

    return 0;
}