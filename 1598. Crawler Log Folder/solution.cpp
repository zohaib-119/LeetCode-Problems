#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int currentFolder = 0; 
        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "./"){
                // nothing will happen
            }
            else if(logs[i] == "../"){
                currentFolder = currentFolder > 0 ? (currentFolder - 1) : currentFolder;
            }
            else{
                currentFolder++;
            }
        }
        return currentFolder;
    }
};

int main() {
    Solution solution;
    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
    int result = solution.minOperations(logs);
    cout << "Minimum number of operations to reach the main folder: " << result << endl;
    return 0;
}