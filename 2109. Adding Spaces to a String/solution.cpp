class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str = s;
        for(int i = 0; i < spaces.size(); i++){
            str = str.substr(0, spaces[i]+i) + ' ' + str.substr(spaces[i]+i);
        }
        return str;
    }
};

// below is solution to avoid memory limit exceed

// class Solution {
// public:
//     string addSpaces(string s, vector<int>& spaces) {
//         // Stream to dynamically construct the string
//         stringstream result;
//         int spaceIndex = 0;

//         for (int stringIndex = 0; stringIndex < s.size(); ++stringIndex) {
//             if (spaceIndex < spaces.size() &&
//                 stringIndex == spaces[spaceIndex]) {
//                 // Insert space at the correct position
//                 result << ' ';
//                 ++spaceIndex;
//             }
//             // Append the current character
//             result << s[stringIndex];
//         }
//         // Convert the stream to a string
//         return result.str();
//     }
// };