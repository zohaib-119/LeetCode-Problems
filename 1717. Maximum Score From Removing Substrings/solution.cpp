#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        string subString = (x > y) ? "ab" : "ba";
        vector<char> vec;

        for(char c : s){
            if(!vec.empty() && vec.back() == subString[0] && c == subString[1]){
                vec.pop_back();
                score += (subString == "ab") ? x : y;
            }
            else{
                vec.push_back(c);
            }
        }

        s = string(vec.begin(), vec.end());
        vec.clear();
        subString = (subString == "ab") ? "ba" : "ab";

        for(char c : s){
            if(!vec.empty() && vec.back() == subString[0] && c == subString[1]){
                vec.pop_back();
                score += (subString == "ab") ? x : y;
            }
            else{
                vec.push_back(c);
            }
        }
        return score;
    }
};

int main() {
    Solution sol;
    string s;
    int x, y;

    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;

    int result = sol.maximumGain(s, x, y);
    cout << "Maximum gain: " << result << endl;

    return 0;
}