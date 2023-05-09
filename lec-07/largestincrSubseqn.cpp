#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:

    int solve(int n,vector<int>& nums , int curr , int prev){

        // base case;
        if(curr == n)
        return 0;

        // include;

        int take =0;
        if(prev == -1 || nums[curr] > nums[prev])
            take = 1 + solve(n , nums , curr+1 , curr);

        // exclude;

        int notTake  = 0+ solve(n , nums , curr +1 ,prev);

        return max(take , notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        return solve(n , nums , 0 , -1);
    }
};
*/

/*
class Solution {
public:

    int solve(int n,vector<int>& nums , int curr , int prev, vector<vector<int>> &dp){

        // base case;
        if(curr == n)
        return 0;
        if(dp[curr][prev+1] != -1)
        return dp[curr][prev+1];

        // include;

        int take =0;
        if(prev == -1 || nums[curr] > nums[prev])
            take = 1 + solve(n , nums , curr+1 , curr ,dp);

        // exclude;

        int notTake  = 0+ solve(n , nums , curr +1 ,prev ,dp);

        return  dp[curr][prev+1] = max(take , notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 ,-1));
        return solve(n , nums , 0 , -1 ,dp);
    }
};

*/

/*
class Solution {
public:

    int solve(int n,vector<int>& nums){

        vector<vector<int>> dp(n+1 , vector<int>(n+1 ,0));

        for(int curr = n-1; curr >= 0;curr--){
            for(int prev = curr-1;prev >=-1;prev--){

                    // include;

                    int take =0;
                    if(prev == -1 || nums[curr] > nums[prev])
                        take = 1 + dp[curr+1][curr+1];

                        // exclude;

                        int notTake  = 0+ dp[curr +1][prev+1];

                         dp[curr][prev+1] = max(take , notTake);

            }
        }

        return dp[0][-1+1];

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(n , nums);
    }
};

*/

/*
class Solution
{
public:
    int solve(int n, vector<int> &nums)
    {

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {

                // include;

                int take = 0;
                if (prev == -1 || nums[curr] > nums[prev])
                    take = 1 + nextRow[curr + 1];

                // exclude;

                int notTake = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(take, notTake);
            }

            nextRow = currRow;
        }

        return nextRow[-1 + 1];
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return solve(n, nums);
    }
};

*/

// more optimal code;

class Solution
{
public:
    int solve(int n, vector<int> &nums)
    {

        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {

            if (nums[i] > ans.back())
                ans.push_back(nums[i]);

            else
            {
                // find the index of the just largest element int the ans arr;
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return solve(n, nums);
    }
};

int main()
{

    return 0;
}