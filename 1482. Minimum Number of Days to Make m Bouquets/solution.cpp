#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int start = 0, end = 0;
        for (int day : bloomDay)
        {
            end = max(end, day);
        }

        int minDays = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (getNumOfBouquets(bloomDay, mid, k) >= m)
            {
                minDays = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return minDays;
    }

private:
    int getNumOfBouquets(vector<int> &bloomDay, int mid, int k)
    {
        int numOfBouquets = 0;

        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                count++;
            }
            else
            {
                count = 0;
            }

            if (count == k)
            {
                numOfBouquets++;
                count = 0;
            }
        }
        return numOfBouquets;
    }
};

int main()
{
    Solution solution;

    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    int minDays = solution.minDays(bloomDay, m, k);
    cout << "Minimum days required: " << minDays << endl;

    return 0;
}
