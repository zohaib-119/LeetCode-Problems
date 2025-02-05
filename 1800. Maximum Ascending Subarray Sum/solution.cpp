class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currentSum = nums[0], maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                currentSum += nums[i];
            }
            else {
                maxSum = max(currentSum, maxSum);
                currentSum = nums[i];
            }
        }
        maxSum = max(currentSum, maxSum);
        return maxSum;
    }
};