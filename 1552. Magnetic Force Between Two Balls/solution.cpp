#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceBalls(const vector<int>& position, int m, int minDist) {
        int count = 1; 
        int lastPosition = position[0];
        
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPosition >= minDist) {
                count++;
                lastPosition = position[i];
                if (count == m) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1;
        int right = position.back() - position[0];
        int result = 0;
        
        while (left <= right) {
            int mid = (right + left) / 2;
            if (canPlaceBalls(position, m, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> position1 = {1, 2, 3, 4, 7};
    int m1 = 3;
    cout << "Output: " << solution.maxDistance(position1, m1) << endl; // Output: 3

    vector<int> position2 = {5, 4, 3, 2, 1, 1000000000};
    int m2 = 2;
    cout << "Output: " << solution.maxDistance(position2, m2) << endl; // Output: 999999999

    return 0;
}