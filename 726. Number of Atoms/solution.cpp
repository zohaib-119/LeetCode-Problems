#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<unordered_map<string, int>> stk;
        unordered_map<string, int> current;
        stk.push(current);
        
        string currentAtom = "";
        string currentCount = "";
        
        for (int i = 0; i < n; i++) {
            if (formula[i] == '(') {
                if (!currentAtom.empty()) {
                    current[currentAtom] += currentCount.empty() ? 1 : stoi(currentCount);
                    currentAtom = "";
                    currentCount = "";
                }
                stk.push(current);
                current.clear();
            }
            else if (formula[i] == ')') {
                if (!currentAtom.empty()) {
                    current[currentAtom] += currentCount.empty() ? 1 : stoi(currentCount);
                    currentAtom = "";
                    currentCount = "";
                }
                unordered_map<string, int> top = stk.top();
                stk.pop();
                int j = i + 1;
                while (j < n && isdigit(formula[j])) {
                    currentCount += formula[j];
                    j++;
                }
                i = j - 1;
                int multiplier = currentCount.empty() ? 1 : stoi(currentCount);
                for (const auto& pair : current) {
                    top[pair.first] += pair.second * multiplier;
                }
                current = top;
                currentCount = "";
            }
            else if (isalpha(formula[i])) {
                if (isupper(formula[i])) {
                    if (!currentAtom.empty()) {
                        current[currentAtom] += currentCount.empty() ? 1 : stoi(currentCount);
                        currentAtom = "";
                        currentCount = "";
                    }
                    currentAtom += formula[i];
                } else {
                    currentAtom += formula[i];
                }
            }
            else if (isdigit(formula[i])) {
                currentCount += formula[i];
            }
        }
        
        if (!currentAtom.empty()) {
            current[currentAtom] += currentCount.empty() ? 1 : stoi(currentCount);
        }
        
        unordered_map<string, int> finalCount = stk.top();
        for (const auto& pair : current) {
            finalCount[pair.first] += pair.second;
        }
        
        vector<pair<string, int>> elements(finalCount.begin(), finalCount.end());
        sort(elements.begin(), elements.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.first < b.first;
        });
        
        string result;
        for (const auto& [elem, count] : elements) {
            result += elem;
            if (count > 1) {
                result += to_string(count);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.countOfAtoms("K4(ON(SO3)2)2") << endl;  // Expected: "K4N2O14S4"
    return 0;
}