class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Sort banned array to enable binary search
        sort(banned.begin(), banned.end());

        int count = 0;
        for(int i = 1; i <= n; i++){
            if(customBinarySearch(banned, i))
                continue;
            if(maxSum - i >= 0){
                count++;
                maxSum -= i;
            }
        }
        return count;
    }
private:
    // Helper method to check if value exists in sorted array
    bool customBinarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) return true;

            if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};