#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        int patches = 0;
        int i = 0;
        int size = nums.size();
        
        while (miss <= n) {
            if (i < size && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                patches++;
            }
        }
        
        return patches;
    }
};

int main() {
    
    Solution sol;

    vector<int> nums1 = {1, 3};
    int n1 = 6;
    int result1 = sol.minPatches(nums1, n1);
    cout << "Minimum patches required for nums1: " << result1 << endl;

    return 0;
}
