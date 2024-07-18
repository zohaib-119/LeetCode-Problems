#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions,
                                      vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<int> indices(n), result;
        stack<int> stack;

        for (int i = 0; i < n; i++)
        {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int l, int r)
             { return positions[l] < positions[r]; });

        for (int currentIndex : indices)
        {
            if (directions[currentIndex] == 'R')
            {
                stack.push(currentIndex);
            }
            else
            {
                while (!stack.empty() && healths[currentIndex] > 0)
                {
                    int topIndex = stack.top();
                    stack.pop();

                    if (healths[topIndex] > healths[currentIndex])
                    {
                        healths[topIndex]--;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    }
                    else if (healths[topIndex] < healths[currentIndex])
                    {
                        healths[currentIndex]--;
                        healths[topIndex] = 0;
                    }
                    else
                    {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (healths[i] > 0)
            {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};

int main() {
    vector<int> positions = {3, 1, 5, 2, 4};
    vector<int> healths = {5, 3, 7, 2, 4};
    string directions = "RLRRL";

    Solution solution;
    vector<int> survivedHealths = solution.survivedRobotsHealths(positions, healths, directions);

    cout << "Healths of surviving robots: ";
    for (int health : survivedHealths) {
        cout << health << " ";
    }
    cout << endl;

    return 0;
}