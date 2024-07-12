#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinkBottles = numBottles;
        while(numBottles >= numExchange){
            int temp = numBottles / numExchange;
            numBottles = numBottles % numExchange;
            numBottles += temp;
            drinkBottles += temp;
        }
        return drinkBottles;
    }
};

int main() {
    Solution solution;
    int numBottles = 9;
    int numExchange = 3;
    int result = solution.numWaterBottles(numBottles, numExchange);
    cout << "Maximum number of water bottles that can be drunk: " << result << endl;
    return 0;
}
