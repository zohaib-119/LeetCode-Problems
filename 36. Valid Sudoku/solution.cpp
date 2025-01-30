class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char number = board[i][j];
                if(number != '.') {
                    if (seen.find(string(1, number) + " in row " + to_string(i)) != seen.end() || seen.find(string(1, number) + " in column " + to_string(j)) != seen.end() || seen.find(string(1, number) + " in block " + to_string(i / 3) + "-" + to_string(j / 3)) != seen.end())  {
                        return false;
                    }

                    // Insert the current number into the set
                    seen.insert(string(1, number) + " in row " + to_string(i));
                    seen.insert(string(1, number) + " in column " + to_string(j));
                    seen.insert(string(1, number) + " in block " + to_string(i / 3) + "-" + to_string(j / 3));

                }
            }
        }
        return true;
    }
};