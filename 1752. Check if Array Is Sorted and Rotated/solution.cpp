class Solution {
public:
    bool check(vector<int>& nums) {
        bool rotated = false;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) {
                if(!rotated)
                    rotated = true;
                else
                    return false;
            }
            if(rotated && nums[i] > nums[0]) {
                return false;
            }
        }
        return true;
    }
};