#include <iostream>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int completeCycles = time / (n-1);
        int remainingTime = time % (n-1);
        if(completeCycles % 2 == 0)
            return (remainingTime + 1);
        return (n - remainingTime);
    }
};

int main() {
    Solution solution;
    int n = 5;
    int time = 7;
    int result = solution.passThePillow(n, time);
    cout << "The pillow is with person: " << result << endl;
    return 0;
}
