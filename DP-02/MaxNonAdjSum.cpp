#include <iostream>
#include <vector>
using namespace std;

// Space ptimization ;

int solveSpaceOptimize(vector<int> &nums)
{

    int n = nums.size();
    int prev1 = 0;

    int prev2 = nums[0];

    for (int i = 1; i < n; i++)
    {

        int incl = prev2 + nums[i];

        int excl = prev1 + 0;

        int ans = max(incl, excl);

        prev2 = prev1;

        prev1 = ans;
    }

    return prev1;
}
//  Using Tabulation ;

/*
int solveTab(vector<int> & nums){


    int n =nums.size();
    vector<int> dp(n ,0);

    dp[0]= nums[0];

    for(int i=1;i<n;i++){

        int incl = dp[i-2] + nums[i];

        int excl = dp[i-1] + 0;

        dp[i] =  max(incl ,excl);
    }

    return dp[n-1];

}
*/

/*

//UsingMemoization;

int solveMem(vector<int> & nums ,int n ,vector<int> &dp){

    // base case ;

    if(n<0)
    return 0;

    if(n == 1)
    return  nums[0];
    if(dp[n]!=-1)

    return dp[n];

    int incl = solveMem(nums ,n-2) + nums[n];

    int excl = solveMem(nums ,n-1) + 0;

    dp[n]=max(incl ,excl);

     return dp[n];
}
*/

/*

  recursive ;

int solveRec(vector<int> & nums ,int n){

    // base case ;

    if(n<0)
    return 0;

    if(n == 1)
    return  nums[0];

    int incl = solveRec(nums ,n-2) + nums[n]; // for inclution move i = i-2; ans for exclution i =i-1; // we move  from last index;to first index ;


    int excl = solveRec(nums ,n-1) + 0;

     return max(incl ,excl);
}
*/

int maxNonAdjSum(vector<int> &nums)
{

    /*

    //recursive solution;

        int n =nums.size();

        int ans = solveRec(nums ,n-1);

        return ans;

        */

    // Memoaization ;

    /*
       int n =nums.size();

       vector<int>dp(n , -1);

       return solveMem(nums ,n-1, dp);
    */

    // Tabulation ;

    //  return solveTab(nums);

    // Space Optimization ;

    return solveSpaceOptimize(nums);
}
int main()
{

    return 0;
}