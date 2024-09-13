#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer;
        for (int i = 0; i < queries.size(); i++) {
            int ans = 0;
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                ans ^= arr[j];
            }
            answer.push_back(ans);
        }
        return answer;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    
    vector<int> result = sol.xorQueries(arr, queries);

    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
