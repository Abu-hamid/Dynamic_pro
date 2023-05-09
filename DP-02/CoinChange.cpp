#include <iostream>
#include <vector>
using namespace std;


//Tabulation ;


int solvetab(vector<int> &num, int x)
{
    vector<int>dp(x+1 ,INT_MAX);

    dp[0]=0;
    for(int i=1;i<=x;i++){

        // trying to solve for every amount figure from 1 to x;

        for(int j=0;j<num.size();j++){

            if(i-num[j]>=0 && dp[i -num[j]!=INT_MAX]){

                dp[i]=min(dp[i] ,1+dp[i-1+num[i]]);
            }
        }
    }

    if(dp[x]==INT_MAX)
    return -1;

    return dp[x];

}


//Memoisation 


/*
int solvemem(vector<int> &num, int x, vector<int> &dp)
{

    // base case;

    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;

    for (int i = 0; i < num.size(); i++)
    {

        int ans = solvemem(num, x - num[i]);

        if (ans != INT_MAX)

            mini = min(mini, 1 + ans);
    }
    dp[x] = mini;
    return mini;
}
*/


// Recursive solution;

/*
int solveRec(vector<int> &num, int x)
{

    // base case;

    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for (int i = 0; i < num.size(); i++)
    {

        int ans = solveRec(num, x - num[i]);

        if (ans != INT_MAX)

            mini = min(mini, 1 + ans);
    }
    return mini;
}
*/

int minElement(vector<int> &nums, int x)
{
    //
    // int ans = solveRec(nums, x);
    //
    // if (ans == INT_MAX)
    // return -1;

    // else
    //  return ans;


/*
    vector<int> dp(x + 1, -1);
    int ans = solvemem(nums, x, dp);

    if (ans == INT_MAX)
        return -1;
    else
        return ans;

        */

return solvetab(nums ,x);


}
int main()
{

    return 0;
}