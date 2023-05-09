#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int solve(string &a, string &b, int i, int j)
    {
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);
        for (i = a.length() - 1; i >= 0; i--)
        {
            for (j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 1 + next[j + 1];
                }
                else
                {
                    ans = max(next[j], curr[j + 1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int longestPalindromeSubseq(string s)
    {

        string revStr = s;
        reverse(revStr.begin(), revStr.end());// reverse the string and find the longest common Sunsqeunce by given string and reverse string this will give the longest palindrom;
        int ans = solve(s, revStr, 0, 0);
        return ans;
    }
};
int main()
{

    return 0;
}