#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        int index1 = 0, index2 = 0;
        while(index1 < nums1.size() && index2 < nums2.size()){
            if(nums1[index1] == nums2[index2]){
                result.push_back(nums1[index1]);
                index1++;
                index2++;
            } else if(nums1[index1] > nums2[index2]){
                index2++;
            } else {
                index1++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = solution.intersect(nums1, nums2);

    return 0;
}