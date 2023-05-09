#include<iostream>
#include<vector>
using namespace std;


/*
class Solution {
public:

    int solve(int index , int buy ,vector<int>& prices ){

        // base case ;
        if(index == prices.size()){
            return 0;
        }

        int profit = 0;
        if(buy){

            int buyKro = -prices[index] + solve(index + 1 , 0 , prices);
            int skipKro = 0 + solve(index + 1 , 1 , prices);
            profit = max(buyKro , skipKro);
        }

        else{
            int sellKro = +prices[index] + solve(index + 1 , 1 , prices);
            int skipKro = 0 + solve(index + 1 , 0 , prices);
            profit = max(sellKro , skipKro);

        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {

        return solve(0 , 1 , prices);
        
    }
};

*/


/* convert into DP / Memoization;
class Solution {
public:

    int solve(int index , int buy ,vector<int>& prices , vector<vector<int>> &dp){

        // base case ;
        if(index == prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1)
        return dp[index][buy];

        int profit = 0;
        if(buy){

            int buyKro = -prices[index] + solve(index + 1 , 0 , prices , dp);
            int skipKro = 0 + solve(index + 1 , 1 , prices , dp);
            profit = max(buyKro , skipKro);
        }

        else{
            int sellKro = +prices[index] + solve(index + 1 , 1 , prices , dp);
            int skipKro = 0 + solve(index + 1 , 0 , prices ,dp);
            profit = max(sellKro , skipKro);

        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2 ,-1));
        return solve(0 , 1 , prices , dp);
        
    }
};

*/

/*

// convert into buttom up Aproach;
class Solution {
public:

    int solveTab(int index , int buy ,vector<int>& prices){

        int n = prices.size();
        vector<vector<int>> dp(n + 1 , vector<int>(2 ,0));

        for(int index = n-1;index>=0;index--){
            for(int buy = 0 ; buy <= 1;buy++){

            int profit = 0;
            if(buy){

            int buyKro = -prices[index] + dp[index +1][0];
            int skipKro = 0 + dp[index +1][1];
            profit = max(buyKro , skipKro);
        }
            
        else{
            int sellKro = +prices[index] + dp[index+1][1];
            int skipKro = 0 + dp[index +1][0];
            profit = max(sellKro , skipKro);

        }
         dp[index][buy] = profit;

        }
        }

         return dp[0][1];

    }


    int maxProfit(vector<int>& prices) {
        return solveTab(0 , 1 , prices);        
    }
};

*/


// Space optimization;

class Solution {
public:

    int solveTab(int index , int buy ,vector<int>& prices){

        int n = prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);

        for(int index = n-1;index>=0;index--){
            for(int buy = 0 ; buy <= 1;buy++){

            int profit = 0;
            if(buy){

            int buyKro = -prices[index] + next[0];
            int skipKro = 0 + next[1];
            profit = max(buyKro , skipKro);
        }
            
        else{
            int sellKro = +prices[index] + next[1];
            int skipKro = 0 + next[0];
            profit = max(sellKro , skipKro);

        }
         next[buy] = profit;

        }
        }

         return next[1];

    }


    int maxProfit(vector<int>& prices) {
        return solveTab(0 , 1 , prices);        
    }
};

int main(){

return 0;
}