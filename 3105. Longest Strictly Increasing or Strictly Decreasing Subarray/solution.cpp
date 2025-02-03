class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 1, currentLength = 1;
        bool increasing = false;
        for(int i = 1; i < nums.size(); i++) {
            cout << nums[i] << currentLength;
            if(nums[i] > nums[i-1]) {
                if(increasing) {
                    currentLength++;
                }
                else {
                    maxLength = max(maxLength, currentLength);
                    currentLength = 2;
                    increasing = !increasing;
                }
            }
            else if(nums[i] < nums[i-1]) {
                if(increasing) {
                    maxLength = max(maxLength, currentLength);
                    currentLength = 2;
                    increasing = !increasing;
                }
                else {
                    currentLength++;
                }
            }
            else {
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        maxLength = max(maxLength, currentLength);
        return maxLength;
    }
};