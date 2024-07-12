#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        int result = 0;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                result += (nums[i - 1] - nums[i] + 1);
                nums[i] = nums[i - 1] + 1;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {3, 2, 1, 2, 1, 7}; 
    int result = solution.minIncrementForUnique(nums);
    
    cout << "The minimum number of increments needed is: " << result << endl;
    
    return 0;
}
