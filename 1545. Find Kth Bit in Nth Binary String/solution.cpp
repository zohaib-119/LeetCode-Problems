#include <iostream>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1)
            return '0';
        
        int len = 1 << n;
        if(k < len/2){
            return findKthBit(n-1, k);
        }
        else if(k == len/2){
            return '1';
        }
        else{
            char correspondingBit = findKthBit(n-1, len-k);
            return (correspondingBit == '1' ? '0' : '1');
        }
    }
};

int main() {
    Solution solution;

    int n = 3, k = 5;
    cout << "The " << k << "th bit of S_" << n << " is: " 
              << solution.findKthBit(n, k) << endl;

    n = 4, k = 11;
    cout << "The " << k << "th bit of S_" << n << " is: " 
              << solution.findKthBit(n, k) << endl;

    return 0;
}
