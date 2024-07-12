#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int minDiff = nums[n] - nums[3];
        minDiff = min(minDiff, (nums[n - 1] - nums[2]));
        minDiff = min(minDiff, (nums[n - 2] - nums[1]));
        minDiff = min(minDiff, (nums[n - 3] - nums[0]));
        return minDiff;
    }
};

int main()
{
    Solution solution;

    vector<int> array = {1,5,0,10,14};

    int minDiff = solution.minDifference(array);
    cout << "Minimum Difference: " << minDiff << endl;

    return 0;
}
