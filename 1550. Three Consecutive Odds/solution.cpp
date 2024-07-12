#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3){
            return false;
        }
        int oddCount = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] % 2 != 0)
                oddCount++;
            else
                oddCount = 0;
            if(oddCount == 3)
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {2, 6, 4, 1};
    cout << "Test case 1: " << (sol.threeConsecutiveOdds(arr1) ? "true" : "false") << endl;  // Output: false

    return 0;
}