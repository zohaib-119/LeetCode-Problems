#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        
        int result = 0;
        
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        for(int i = 0; i < students.size(); i++){
            result += abs(students[i] - seats[i]);
        }
        
        return result;
    }
};

int main() {

    vector<int> seats = {4, 1, 5, 9};
    vector<int> students = {1, 3, 2, 6};

    Solution solution;
    int result = solution.minMovesToSeat(seats, students);

    cout << "Minimum number of moves to seat the students: " << result << endl;

    return 0;
}
