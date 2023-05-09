#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 	tabulation solution;

    int solveTab(int n)
    {

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j * j <= n; j++)
            {

                int temp = j * j;

                if (i - temp >= 0)

                    dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
        return dp[n];
    }

    /*
    // 	memoization solution ;


        int solveMem(int n ,vector<int> &dp){

           // base case;

           if(n==0)
            return 0;

            if(dp[n]!=-1)
                return dp[n];


            int ans =n;

            for(int i=1 ;i*i <= n;i++){

                int temp =i*i;
                ans = min(ans , 1+ solveMem(n- temp ,dp));

            }
            dp[n] =ans;

            return dp[n];
        }

        */

    /*
    // recursive solution;
        int solve(int n){

           // base case;

           if(n==0)
            return 0;


            int ans =n;

            for(int i=1 ;i*i <= n;i++){

                ans = min(ans , 1+ solve(n- i*i));

            }
            return ans;
        }

        */

    int MinSquares(int n)
    {
        // return  solve(n);

        // meoization solution ;

        // vector<int> dp(n+1 ,-1);

        // return solveMem(n , dp);

        return solveTab(n);
    }
};
int main()
{

    return 0;
}