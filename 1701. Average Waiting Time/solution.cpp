#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avgWaitTime = 0;
        int startTime = 0;
        for(int i = 0; i < customers.size(); i++){
            if(startTime < customers[i][0])
                startTime = customers[i][0];
            startTime += customers[i][1];
            avgWaitTime +=  startTime - customers[i][0];
        }
        avgWaitTime = avgWaitTime / customers.size();
        return avgWaitTime;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
    double result = solution.averageWaitingTime(customers);
    cout << "Average Waiting Time: " << result << endl;
    return 0;
}