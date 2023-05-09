#include<iostream>
#include<vector>
using namespace std;

#define MOD 1e9 + 7
/*
class Solution {
public:

    int solve(int dice , int faces , int target){

        // base case

        if(target < 0)
        return 0;

        if(dice == 0 && target != 0)
        return 0;

        if(target == 0 && dice == 0)
        return 1;

        if(target == 0 && dice != 0)
        return 0;

        int ans =0;
        for(int i =0 ;i<faces;i++){

            ans = ans + solve(dice -1 , faces , target -i);

        }
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        return solve(n , k , target);
    }
};

*/

/*

// Memoization;
class Solution {
public:

    int solveMem(int dice , int faces , int target, vector<vector<int>> &dp){

        // base case

        if(target < 0)
        return 0;

        if(dice == 0 && target != 0)
        return 0;

        if(target == 0 && dice == 0)
        return 1;

        if(target == 0 && dice != 0)
        return 0;

        if(dp[dice][target] != -1)
        return dp[dice][target];

        int  ans =0;
        for(int i =1 ;i<=faces;i++){

            ans = (ans + solveMem(dice -1 , faces , target-i , dp)) % int(MOD);

        }
        return dp[dice][target] = ans;
    }


    int  numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1 ,vector<int>(target + 1 , -1));
        return solveMem(n , k , target ,dp);
    }
};

*/

/*
// Tabulation solution ;
class Solution {
public:

    int solveTab(int d , int f , int t){

        vector<vector<int>> dp(d+1 , vector<int>(t + 1 , 0));
       
        // by analysing the base case;
        dp[0][0] = 1;

        
        for(int dice = 1 ;dice <=d ;dice++){
            for(int target = 1 ;target <= t ;target++){
            
            int  ans =0;
             for(int i =1 ;i<=f;i++){

                    if(target - i >= 0)
                   ans = (ans + dp[dice - 1][target -i]) % int(MOD);

                }
                  dp[dice][target] = ans;

            }
        }   
        return dp[d][t]; 
        
        
    }
    int  numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>> dp(n+1 ,vector<int>(target + 1 , -1));
        return solveTab(n , k , target);
    }
};
*/


// space Optimization;

class Solution {
public:

    int solveTab(int d , int f , int t){

       
       vector<int> prev( t+1 ,0);
       vector<int> curr( t+1 ,0);

        // by analysing the base case;
        prev[0] = 1;

        
        for(int dice = 1 ;dice <=d ;dice++){
            for(int target = 1 ;target <= t ;target++){
            
            int  ans =0;
             for(int i =1 ;i<=f;i++){

                    if(target - i >= 0)
                   ans = (ans + prev[target -i]) % int(MOD);

                }
                  curr[target] = ans;

            }
            prev = curr;
        }   
        return prev[t]; 
        
        
    }
    int  numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>> dp(n+1 ,vector<int>(target + 1 , -1));
        return solveTab(n , k , target);
    }
};
int main(){

return 0;
}