#include <iostream>
#include <vector>
using namespace std;

/*

class Solution {
public:

    bool  solve(int index ,vector<int>& nums, int n , int target){

        // base case;
        if(index >= n)
        return 0;

        if(target < 0)
        return 0;

        if(target == 0)
        return 1;

        bool incl = solve(index+1 , nums , n , target - nums[index]);
        bool excl = solve(index+1 , nums , n , target);

        return incl || excl;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int total =0 ;

        for(int i =0 ;i<n;i++){
            total+=nums[i];
        }

        if(total & 1)
        return 0;

        int target = total/2;

        return solve(0 , nums , n , target);
    }
};

*/

// ADD MEMOIZATION;

/*
class Solution {
public:

    bool  solve(int index ,vector<int>& nums, int n , int target ,vector<vector<int>> &dp){

        // base case;
        if(index >= n)
        return 0;

        if(target < 0)
        return 0;

        if(target == 0)
        return 1;

        if(dp[index][target] != -1)
        return dp[index][target];

        bool incl = solve(index+1 , nums , n , target - nums[index] ,dp);
        bool excl = solve(index+1 , nums , n , target ,dp);

        return dp[index][target] = incl || excl;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int total =0 ;

        for(int i =0 ;i<n;i++){
            total+=nums[i];
        }

        if(total & 1)
        return 0;

        int target = total/2;
        vector<vector<int>> dp(n , vector<int>(target+1 , -1));
        return solve(0 , nums , n , target ,dp);
    }
};

*/

// ADD TABULATION IN THE SOLUTION;

/*
class Solution {
public:

    bool  solve(vector<int>& nums, int n , int total){

        vector<vector<int>> dp(n+1 , vector<int>(total+1 , 0));

        for(int i =0 ;i<=n ;i++){
            dp[i][0] = 1;
        }

        for(int index = n-1 ;index >=0;index--){
            for(int target = 0 ;target <=total/2;target++){

                    bool incl =0;
                    if(target - nums[index] >= 0)
                     incl = dp[index+1][target - nums[index]];

                    bool excl = dp[index+1][target];
                    dp[index][target] = incl || excl;

            }
        }

        return dp[0][total /2];
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int total =0 ;

        for(int i =0 ;i<n;i++){
            total+=nums[i];
        }

        if(total & 1)
        return 0;

        int target = total/2;

        return solve( nums , n , total);
    }
};
*/

// SPACE OPTIMIZATION;

class Solution
{
public:
    bool solve(vector<int> &nums, int n, int total)
    {

        vector<int> curr(total + 1, 0);
        vector<int> next(total + 1, 0);

        curr[0] = 1;
        next[0] = 1;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 0; target <= total / 2; target++)
            {

                bool incl = 0;
                if (target - nums[index] >= 0)
                    incl = next[target - nums[index]];

                bool excl = next[target];
                curr[target] = incl || excl;
            }
            next = curr;
        }

        return next[total / 2];
    }
    bool canPartition(vector<int> &nums)
    {

        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }

        if (total & 1)
            return 0;

        int target = total / 2;

        return solve(nums, n, total);
    }
};
int main()
{

    return 0;
}