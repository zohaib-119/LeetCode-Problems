#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int> circle;
        for(int i = 1; i <= n ; i++){
            circle.push(i);
        }

        while(circle.size() > 1) {
            for(int i = 0; i < k - 1; i++){
                circle.push(circle.front());
                circle.pop();
            }

            circle.pop();
        }

        return circle.front();
    }
};

int main() {
    Solution solution;
    int n = 5;
    int k = 2;
    int winner = solution.findTheWinner(n, k);
    cout << "The winner is: " << winner << endl;
    return 0;
}