// a simple solution but it exceeds time limit

// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         for (int i = 0; i < shifts.size(); i++) {
//             for (int j = shifts[i][0]; j <= shifts[i][1]; j++) {  
//                 if (shifts[i][2] == 0) {
//                     s[j] = ((s[j] - 'a' - 1 + 26) % 26) + 'a';
//                 } else {
//                     s[j] = ((s[j] - 'a' + 1) % 26) + 'a';
//                 }
//             }
//         }
//         return s;
//     }
// };


// another approach that is time efficient

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArray(n, 0);

        for(auto shift: shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if(direction == 1) {
                diffArray[start]++;
                
                if(end + 1 < n){
                    diffArray[end+1]--;
                }
            } else {
                diffArray[start]--;

                if(end + 1 < n) {
                    diffArray[end + 1]++; 
                }
            }
        }

        
        int numberOfShifts = 0;
        for(int i = 0; i < n; i++) {
            numberOfShifts = (numberOfShifts + diffArray[i])  % 26;

            s[i] = 'a' + (s[i] - 'a' + numberOfShifts + 26) % 26;
        }

        return s;
    }
};
