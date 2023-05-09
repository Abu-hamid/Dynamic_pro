#include <iostream>
#include <vector>

using namespace std;
int MOD = 1e9 + 7;

// space optimisation;

int solveTab(int n)
{

    long long int prev2 = 0;
    long long int prev1 = 2;

    for (int i = 3; i <= n; i++)
    {

        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i - 1) * sum) % MOD;

        prev2 = prev1;

        prev1 = ans;
    }
    return prev1;
}

// Tabulaton solton ;

int solveTab(int n)
{
    vector<long long int> dp(n + 1, 0);

    dp[1] = 0;
    dp[1] = 2;

    for (int i = 3; i <= n; i++)
    {

        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i - 1) * sum) % MOD;

        dp[i] = ans;
    }
    return dp[n];
}

/*

// Memoizaton soluton ;

int solveMem(int n, vector<long long int> &dp)
{

    // base case ;
    int MOD = 1e9 + 7;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (dp[n] != -1)

        return dp[n];

    int dp[n] = (((n - 1) % MOD) * ((solveMem(n - 1 ,dp) % MOD) + (solveMem(n - 2 ,dp) % MOD)) % MOD);
    int dp[n];
}
*/

long long int CountDerangement(int n)
{

    // recursive case ;

    /*
        // base case ;

        int MOD = 1e9+7;

        if(n== 1)
        return 0;

        if(n==2)
        return 1;

        int ans  = ((((n-1) % MOD) * (CountDerangement(n-1) %MOD) + (CountDerangement(n-2) % MOD)) %MOD);

        int ans;

        */

    //    memoization ;

    // vector<long long int> dp(n + 1, -1);

    // return solveMem(n, dp);

    // Tabulation Solution ;

    return solveTab(n);
}

int main()
{

    return 0;
}