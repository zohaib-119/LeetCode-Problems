#include <iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int Xor = start ^ goal;
        int output = 0;
        while (Xor > 0) {
            if (Xor % 2 == 0) {
                Xor /= 2;
            } else {
                output += 1;
                Xor /= 2;
            }
        }
        return output;
    }
};

int main() {
    Solution sol;
    int start, goal;
    cin >> start >> goal;
    cout << sol.minBitFlips(start, goal) << endl;
    return 0;
}