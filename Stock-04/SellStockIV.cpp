#include<iostream>
#include<vector>
using namespace std;

/*
class Solution {
public:
    int solve(vector<int>& prices ,int k){

        int n = prices.size();
        vector<vector<int>>curr(2,vector<int>(k+1 ,0));
        vector<vector<int>>next(2,vector<int>(k+1 ,0));

        for(int index = n-1;index>=0;index--){
            for(int buy = 0 ; buy <= 1;buy++){

                for(int limit =1;limit<=k;limit++){
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

         return next[1][k];

    }


    int maxProfit(int k, vector<int>& prices) {
        return solve( prices , k);
    }
};

*/

/*
// RECURSION;

class Solution {
public:
    int solve(int index , int operationNo ,int k ,vector<int>& prices){

        if(index == prices.size())
        return 0;

        if(operationNo == 2*k)
        return 0;
        
        int profit = 0;
        if(operationNo%2 == 0){

            int buyKro = -prices[index] + solve(index +1 , operationNo +1 , k ,prices);
            int skipKro = 0 + solve(index +1 , operationNo , k ,prices);
            profit = max(buyKro , skipKro);
        }
        else{
            int sellKro = +prices[index] + solve(index + 1 ,operationNo + 1 ,k ,prices);
            int skipKro = 0 + solve(index + 1 ,operationNo ,k ,prices);
            profit = max(sellKro , skipKro);

        }

        return profit;

    }



    int maxProfit(int k, vector<int>& prices) {
        return solve(0, 0, k , prices);
    }
};
*/


// Dp Solution top Down;

/*
class Solution {
public:
    int solve(int index , int operationNo ,int k ,vector<int>& prices , vector<vector<int>> &dp){

        if(index == prices.size())
        return 0;

        if(operationNo == 2*k)
        return 0;

        if(dp[index][operationNo] != -1)
        return dp[index][operationNo];


        
        int profit = 0;
        if(operationNo%2 == 0){

            int buyKro = -prices[index] + solve(index +1 , operationNo +1 , k ,prices ,dp);
            int skipKro = 0 + solve(index +1 , operationNo , k ,prices ,dp);
            profit = max(buyKro , skipKro);
        }
        else{
            int sellKro = +prices[index] + solve(index + 1 ,operationNo + 1 ,k ,prices ,dp);
            int skipKro = 0 + solve(index + 1 ,operationNo ,k ,prices ,dp);
            profit = max(sellKro , skipKro);

        }

        return dp[index][operationNo] =  profit;

    }



    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>>dp(n , vector<int>( 2*k ,-1));
        return solve(0, 0, k , prices ,dp);
    }
};

*/

// bottom up Solution;

/*
class Solution {
public:
    int solve(int index , int operationNo ,int k ,vector<int>& prices){
        int n = prices.size();  
        vector<vector<int>>dp(n+1 , vector<int>( 2*k+1 ,0));

        for(int index = n-1 ;index >=0;index--){
            for(int operationNo = 0 ;operationNo < 2*k ;operationNo++){

                int profit = 0;
                if(operationNo%2 == 0){

                int buyKro = -prices[index] + dp[index +1][operationNo +1];
                int skipKro = 0 + dp[index +1][operationNo];
                profit = max(buyKro , skipKro);
                }
               else{
                      int sellKro = +prices[index] + dp[index + 1][operationNo + 1];
                      int skipKro = 0 + dp[index + 1][operationNo];
                      profit = max(sellKro , skipKro);

                    }

                     dp[index][operationNo] =  profit;


            }
        }
        return dp[0][0];      
        
    }

    int maxProfit(int k, vector<int>& prices) {
             
        return solve(0, 0, k , prices);
    }
};
*/


class Solution {
public:
    int solve(int index , int operationNo ,int k ,vector<int>& prices){
        int n = prices.size();  
        // vector<vector<int>>dp(n+1 , vector<int>( 2*k+1 ,0));

        vector<int>curr(2*k+1 , 0);
        vector<int>next(2*k+1 , 0);

        for(int index = n-1 ;index >=0;index--){
            for(int operationNo = 0 ;operationNo < 2*k ;operationNo++){

                int profit = 0;
                if(operationNo%2 == 0){

                int buyKro = -prices[index] + next[operationNo +1];
                int skipKro = 0 + next[operationNo];
                profit = max(buyKro , skipKro);
                }
               else{
                      int sellKro = +prices[index] + next[operationNo + 1];
                      int skipKro = 0 + next[operationNo];
                      profit = max(sellKro , skipKro);

                    }

                     curr[operationNo] =  profit;


            }

            next = curr;
        }
        return next[0];      
        
    }

    int maxProfit(int k, vector<int>& prices) {
             
        return solve(0, 0, k , prices);
    }
};





int main(){

return 0;
}