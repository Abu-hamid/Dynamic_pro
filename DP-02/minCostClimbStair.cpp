#include <iostream>
#include <vector>

using namespace std;
/*
int solve(vector<int> &cost ,int n){

    // base case ;
    if(n==0)
    return cost[0];

    if(n==1)
    return cost[1];

    int ans =cost[n] + min(solve(cost ,n-1) ,solve(cost ,n-2));

    return ans;
}
*/

/*
int solve(vector<int> &cost ,int n ,vector<int>&dp){

    // base case ;
    if(n==0)
    return cost[0];

    if(n==1)
    return cost[1];

// third case;
if(dp[n]!=-1);
return dp[n];


// second step;

    dp[n]=cost[n] + min(solve(cost ,n-1, dp) ,solve(cost ,n-2 ,dp));

    return dp[n];
}
*/




/*
int solve(vector<int> &cost, int n)
{

    vector<int> dp(n + 1); // create dp;

    // base case analyse;

    dp[0] = cost[0];
    dp[1] = cost[1];

    // third step ;

    for (int i = 2; i < n; i++)
    {

        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}
*/




int solve(vector<int> &cost, int n)
{

    

    // base case analyse;

    int prev2 = cost[0];
    int prev1= cost[1];

    // third step ;

    for (int i = 2; i < n; i++)
    {
        int curr =cost[i]+ min(prev1 ,prev2);

        prev1 =prev2;

        prev1 =curr;
       
    }
    return min(prev1 ,prev2);
}

int mincostClimb(vector<int> &cost)
{

    // int n =cost.size();

    // int ans =min (solve(cost ,n-1) ,solve(cost ,n-2));

    // return ans;



/*
    // dp calling;
        int n = cost.size();
    // step one;

    vector<int> dp(n + 1, -1); // here we inisialised the dp by -1;
    int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));

    */


// tabulation method;
   int n =cost.size();

   return solve(cost ,n);


//space optimization ;

    int n =cost.size();
 return solve(cost ,n);
}
int main()
{

    return 0;
}
