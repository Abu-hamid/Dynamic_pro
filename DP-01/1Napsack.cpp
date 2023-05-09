#include <iostream>
#include <vector>
using namespace std;

// More Space Optimisation;
int solveTab(vector<int> &weight, vector<int> &value, int n, vector<int> capacity)
{
    // step 1;

    // vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // step 2;

    for (int w = weight[0]; w < capacity; w++)
    {

        if (weight[0] <= capacity)

            curr[w] = value[0];

        else
            curr[w] = 0;
    }

    // step 3 take care all about in all value;
    for (int index = 1; index < n; index++)
    {

        for (int w = capacity; w >= 0; w--)
        {

            int incl = 0;
            int excl = 0;
            if (weight[index] <= w)
            {
                incl = value[index] + curr[w - weight[index]];
                excl = 0 + curr[w];

                curr[w] = max(incl, excl);
            }
        }
    }
    return curr[capacity];
}

/*
// Space Optimisation;
int solveTab(vector<int> &weight, vector<int> &value, int n, vector<int> capacity)
{
    // step 1;

    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);



    // step 2;

    for (int w = weight[0]; w < capacity; w++)
    {

        if (weight[0] <= capacity)

            prev[w] = value[0];

        else
            prev[w] = 0;
    }



// step 3 take care all about in all value;
    for (int index = 1; index < n; index++)
    {

        for (int w = 0; w <= capacity; w++)
        {

            int incl = 0;
            int excl = 0;
            if (weight[index] <= w)
            {
                incl = value[index] + prev[w - weight[index]];
                excl = 0 + prev[w];

                curr[w] = max(incl, excl);
            }

        }
         prev  =curr;

    }
    return prev[capacity];
}
*/

/*
// solution in Tabulation;

int solveTab(vector<int> &weight, vector<int> &value, int n, vector<int> capacity)
{
    // step 1;

    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // step 2;

    for (int w = weight[0]; w < capacity; w++)
    {

        if (weight[0] <= capacity)

            dp[0][w] = value[0];

        else
            dp[0][w] = 0;
    }



// step 3 take care all about in all value;
    for (int index = 1; index < n; index++)
    {

        for (int w = 0; w <= capacity; w++)
        {

            int incl = 0;
            int excl = 0;
            if (weight[index] <= w)
            {
                incl = value[index] + dp[index - 1][w - weight[index]];
                excl = 0 + dp[index - 1][w];


            }
            dp[index][w] = max(incl, excl);
        }

    }
    return dp[n - 1][capacity];
}

*/

/*
// mem soluton ;

int solve(vector<int> &weight, vector<int> &value, int indx, vector<int> capacity, vector<vector<n>> &dp)
{

    // base case;
    // if one element to steal then campare wth the napsaxk and put n napsak;
    if (indx == 0)
    {

        if (weight[0] <= capacity)

            return value[0];

        else
            return 0;
    }

    if (dp[indx][capacity] != -1)
        return dp[indx][capacity];
    int incl = 0;
    int excl = 0;

    if (weight[indx] <= capacity)
    {

        incl = value[indx] + solve(weight, value, indx - 1, capacity - weight[indx], dp);

        excl = 0 + solve(weight, value, indx - 1, capacity, dp);

        dp[indx][capacity] = max(incl, excl);
    }

    return dp[indx][capacity];
}
*/

/*
int solve(vector<int> &weight, vector<int> &value, int indx, vector<int> capacity)
{

    // base case;
    // if one element to steal then campare wth the napsaxk and put n napsak;
    if (indx == 0)
    {

        if (weight[0] <= capacity)

            return value[0];

        else
            return 0;
    }
    int incl = 0;
    int excl = 0;
    int ans;
    if (weight[indx] <= capacity)
    {

        incl = value[indx] + solve(weight, value, indx - 1, capacity - weight[indx]);

        excl = 0 + solve(weight, value, indx - 1, capacity ;

        ans = max(incl, excl);
    }

    return ans;
}
*/

int NapSack(vector<int> weight, vector<int> value, int n, vector<int> maxweight)
{
    // return solve(weight, value, n - 1, maxweight);

    // solution in memoization;
    /*
        vector<vector<n>> dp(n, vector<int>(maxweight + 1, -1));

        return solveMem(weight, value, n - 1, maxweight, dp);
        */

    //    solution in Tabulation;

    return solveTab(weight, value, n - 1, maxweight);
    * /
}
int main()
{

    return 0;
}