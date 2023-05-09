#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
  
/*

    int solve(vector<int>& satisfaction , int index , int time){
      
//       base case;
      
      if(index == satisfaction.size())
        return 0;
      
      
      int include = satisfaction[index] * (time+1 ) + solve(satisfaction , index + 1 , time + 1);
      int exclude = 0 + solve(satisfaction , index + 1 , time);
      
      return max(include , exclude);
    }
    
    */
  
  
/*

//   memization;
  
  int solveMem(vector<int>& satisfaction , int index , int time ,vector<vector<int>> &dp){
      
//       base case;
      
      if(index == satisfaction.size())
        return 0;
    
      if(dp[index][time] != -1)
        return dp[index][time];
      
      
      int include = satisfaction[index] * (time+1 ) + solveMem(satisfaction , index + 1 , time + 1 ,dp);
      int exclude = 0 + solveMem(satisfaction , index + 1 , time ,dp);
      
      return  dp[index][time] = max(include , exclude);
    }
  
  */
  
//   tabulation;
  
  int solveTab(vector<int>& satisfaction){
      
      int n = satisfaction.size();
      vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));
    
      for(int index = n-1 ; index >= 0; index--){
        
        for(int time = index ; time >= 0 ; time--){
          
      int include = satisfaction[index] * (time+1 ) + dp[index + 1][time + 1];
      int exclude = 0 + dp[index + 1][time];
      
           dp[index][time] = max(include , exclude);
          
        }
      }
    return dp[0][0];
    }
  
  
//   space optimization;
  
   int solveSO(vector<int>& satisfaction){
      
      int n = satisfaction.size();
      
      vector<int> curr(n+1 ,0);
      vector<int> next(n+1 ,0);
     
      for(int index = n-1 ; index >= 0; index--){
        
        for(int time = index ; time >= 0 ; time--){
          
      int include = satisfaction[index] * (time+1 ) + next[time + 1];
      int exclude = 0 + next[time];
      
           curr[time] = max(include , exclude);
          
        }
        next = curr;
      }
    return next[0];
    }
  
  
    int maxSatisfaction(vector<int>& satisfaction) {
        
      sort(satisfaction.begin() , satisfaction.end());
      int n = satisfaction.size();

      // return solve(satisfaction ,0 , 0);
      
//   memoizaton;
      
//       vector<vector<int>> dp(n+1 ,vector<int> ( n+1 , -1));
//       return solveMem(satisfaction , 0 , 0 , dp);
      
      
      
      // return solveTab(satisfaction);
      
      return solveSO(satisfaction);
      
    }
};
int main(){

return 0;
}