#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
        vector<pair<int, int>> jobProfile;
        jobProfile.push_back({0,0});
        for(int i = 0; i < difficulty.size(); i++){
            jobProfile.push_back({difficulty[i], profit[i]});
        }
        
        sort(jobProfile.begin(), jobProfile.end());
        for(int i = 0; i < jobProfile.size() - 1; i++){
            jobProfile[i+1].second = max(jobProfile[i].second, jobProfile[i+1].second);
        }
        
        int netProfit = 0;
        for(int i = 0; i < worker.size(); i++){
            
            int l = 0, r = jobProfile.size() - 1, jobProfit = 0;
            while(l <= r){
                int mid = (l + r) / 2;
                if(jobProfile[mid].first <= worker[i]) {
                    jobProfit = jobProfile[mid].second;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            
            netProfit += jobProfit;
        }
        return netProfit;
    }
};

int main() {
    Solution solution;
    
    vector<int> difficulty1 = {2, 4, 6};
    vector<int> profit1 = {10, 20, 30};
    vector<int> worker1 = {1, 3, 5, 7};
    
    cout << "Result: " << solution.maxProfitAssignment(difficulty1, profit1, worker1) << endl;

    return 0;
}