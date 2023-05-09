#include<iostream>
#include<vector>
using namespace std;


/*
class Solution {
public:



 int solve(int index , int buy ,vector<int>& prices , int limit){

        // base case ;
        if(index == prices.size()){
            return 0;
        }

        if(limit == 0)
        return 0;

        int profit = 0;
        if(buy){

            int buyKro = -prices[index] + solve(index + 1 , 0 , prices,limit);
            int skipKro = 0 + solve(index + 1 , 1 , prices , limit);
            profit = max(buyKro , skipKro);
        }

        else{
            int sellKro = +prices[index] + solve(index + 1 , 1 , prices , limit - 1);
            int skipKro = 0 + solve(index + 1 , 0 , prices , limit);
            profit = max(sellKro , skipKro);

        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {

        return solve(0 , 1 , prices , 2);
        
    }
};

*/

// top DOWn dp


/*
class Solution {
public:

    int solve(int index , int buy ,vector<int>& prices , int limit ,vector<vector<vector<int>>> &dp){

        // base case ;
        if(index == prices.size()){
            return 0;
        }
        if(limit == 0)
        return 0;

        if(dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

        int profit = 0;
        if(buy){

            int buyKro = -prices[index] + solve(index + 1 , 0 , prices ,limit, dp);
            int skipKro = 0 + solve(index + 1 , 1 , prices ,limit, dp);
            profit = max(buyKro , skipKro);
        }

        else{
            int sellKro = +prices[index] + solve(index + 1 , 1 , prices ,limit -1,  dp);
            int skipKro = 0 + solve(index + 1 , 0 , prices , limit ,dp);
            profit = max(sellKro , skipKro);

        }
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 ,vector<int>(3 , -1)));
        return solve(0 , 1 , prices ,2, dp);
        
    }
};

*/


// bottom UP Solution;

/*
class Solution {
public:

    int solveTab(int index , int buy ,vector<int>& prices){

        int n = prices.size();
         vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 ,vector<int>(3 , 0)));

        for(int index = n-1;index>=0;index--){
            for(int buy = 0 ; buy <= 1;buy++){
                for(int limit =1 ;limit<=2;limit++){

            int profit = 0;
            if(buy){

            int buyKro = -prices[index] + dp[index +1][0][limit];
            int skipKro = 0 + dp[index +1][1][limit];
            profit = max(buyKro , skipKro);
        }
            
        else{
            int sellKro = +prices[index] + dp[index+1][1][limit-1];
            int skipKro = 0 + dp[index +1][0][limit];
            profit = max(sellKro , skipKro);

        }
         dp[index][buy][limit] = profit;

        }
        }
        }

         return dp[0][1][2];

    }


    int maxProfit(vector<int>& prices) {
        return solveTab(0 , 1 , prices);        
    }
};

*/
// Space Optimization;

class Solution {
public:

    int solveSpace(int index , int buy ,vector<int>& prices){

        int n = prices.size();
        vector<vector<int>>curr(2,vector<int>(3 ,0));
        vector<vector<int>>next(2,vector<int>(3 ,0));

        for(int index = n-1;index>=0;index--){
            for(int buy = 0 ; buy <= 1;buy++){

                for(int limit =1;limit<=2;limit++){
                int profit = 0;
                if(buy){

                    int buyKro = -prices[index] + next[0][limit];
                    int skipKro = 0 + next[1][limit];
                    profit = max(buyKro , skipKro);
                }
            
                    else{
                        int sellKro = +prices[index] + next[1][limit-1];
                        int skipKro = 0 + next[0][limit];
                        profit = max(sellKro , skipKro);

                    }
                          curr[buy][limit] = profit;

                }
            }
              next = curr;

        }

         return next[1][2];

    }


    int maxProfit(vector<int>& prices) {
        return solveSpace(0 , 1 , prices);        
    }
};


int main(){

return 0;
}