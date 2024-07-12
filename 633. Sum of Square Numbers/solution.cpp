#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; i <= sqrt(c); i++) {
            int i2 = i * i;
            int j = sqrt(c - i2);
            if (j * j + i2 == c) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    int c1 = 5;
    
    cout << "judgeSquareSum(" << c1 << ") = " << (sol.judgeSquareSum(c1) ? "true" : "false") << endl;
    
    return 0;
}
