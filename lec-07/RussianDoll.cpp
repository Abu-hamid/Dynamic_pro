#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>> &env)
    {
        int n = env.size();
        // sorting by height & if we encounter same height
        // sort by descending order of width
        sort(env.begin(), env.end(), cmp);

        vector<int> ans;

        for (int i = 0; i < env.size(); i++)
        {
            int ele = env[i][1];

            int idx = lower_bound(ans.begin(), ans.end(), ele) - ans.begin();

            if (idx >= ans.size())
                ans.push_back(ele);

            else
                ans[idx] = ele;
        }

        return ans.size();
    }
};
int main()
{

    return 0;
}