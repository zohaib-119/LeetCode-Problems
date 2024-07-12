#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> vec;
        for (char c : s) {
            if (c == ')') {
                vector<char> temp;
                while (vec.back() != '(') {
                    temp.push_back(vec.back());
                    vec.pop_back();
                }
                vec.pop_back(); 
                vec.insert(vec.end(), temp.begin(), temp.end());
            } else {
                vec.push_back(c);
            }
        }
        return string(vec.begin(), vec.end());
    }
};

int main() {
    Solution solution;
    string input = "(u(love)i)";
    string result = solution.reverseParentheses(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << result << endl;

    input = "(ed(et(oc))el)";
    result = solution.reverseParentheses(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << result << endl;

    input = "a(bcdefghijkl(mno)p)q";
    result = solution.reverseParentheses(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << result << endl;

    return 0;
}