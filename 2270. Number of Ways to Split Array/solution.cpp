class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefixSum(nums.size());
        long long sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefixSum[i] = sum; 
        }
        for(int i = 0; i < nums.size() - 1; i++) {
            if(prefixSum[i] >= (prefixSum[prefixSum.size() - 1] - prefixSum[i])) 
                ans++;
        }

        return ans;
    }
};