#include<iostream>
#include<vector>
using namespace std;


/*

class Solution {
public:

    int solve(int n){
          //base case;
        if(n <= 1)
        return 1;

        int ans =0;
        // making the root node of the each iterated value;
        for(int i =1;i<=n;i++){

            ans+= numTrees(i-1)*numTrees(n-i);
        } 
        return ans;

    }
    int numTrees(int n) {
        
        return solve(n);
      
    }
};

*/

// ADD MEMOIZATION;

/*
class Solution {
public:

    int solve(int n ,vector<int> &dp){
          //base case;
        if(n <= 1)
        return 1;

        if(dp[n] != -1)
        return dp[n];

        int ans =0;
        // making the root node of the each iterated value;
        for(int i =1;i<=n;i++){

            ans+= solve(i-1 ,dp)*solve(n-i ,dp);
        } 
        return dp[n] = ans;

    }
    int numTrees(int n) {
        vector<int> dp(n+1 ,-1);
        return solve(n ,dp);
      
    }
};

*/


// ADD TABULATION;

/*
class Solution {
public:

    int solve(int n){
        
        vector<int> dp(n+1 ,0); 

        dp[0] = dp[1] = 1;

            // i--> use for the number of the nodes
        for(int i=2;i<=n;i++){
            // j-->think about the root node;
            for(int j =1;j<=i;j++){

                dp[i]+= dp[j-1]*dp[i-j];

            }

        }
        return dp[n];   
       
    }
    int numTrees(int n) {
        
        return solve(n);
      
    }
};

*/

// SPACE OPTIMIZATION;

// printing the catalan number using recursion;
class Solution {
public:

    int solve(int n){
        
    //    base case;
    if(n <= 1)
    return 1;

    int ans =0;

    // by this loop we make the root of the tree; first i th number are left part ans rest are right part
    for(int i=0;i<n;i++){

        ans+=solve(i)*solve(n-i-1);
    }

    return ans;
    }
    int numTrees(int n) {
        
        return solve(n);
      
    }
};




int main(){

return 0;
}