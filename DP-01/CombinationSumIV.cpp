#include<iostream>
#include<vector>

using namespace std;

class Solution {  
public:
  
 /* 
  int solve(vector<int>& nums, int target){
    
//     base case 
    
    if(target < 0)
      return 0;
    
    if(target ==0)
      return 1;
    int ans =0;
    for(int i=0;i<nums.size();i++){
      
      ans+=solve(nums , target -nums[i]);
    }
    return ans;
    
  }
  
  */
  
  
  /*
  
  int solveMem(vector<int>& nums, int target ,vector<int> &dp){
    
//     base case 
    
    if(target < 0)
      return 0;
    
    if(target ==0)
      return 1;
    
    if(dp[target]!=-1)
      return dp[target];
    int ans =0;
    for(int i=0;i<nums.size();i++){
      
      ans+=solveMem(nums , target -nums[i] ,dp);
    }
    dp[target] = ans;
    return dp[target] ;
    
  }
  
  */
  
  int solveTab(vector<int>& nums, int target){
    
/*  This is because the final answer dp[target] surely fits in the 32 bit range of the integer. But the intermediate results dp[target-1] or dp[target-2] .... or dp[target-k] could be greater than INT_MAX and would be causing the overflow.

One way to solve this could be to have a check before adding that if dp[target-k] is greater than INT_MAX.
The easiest way is to use unsigned_int since it wraps around after the overflow.*/  
    
    
  vector< unsigned int> dp(target+1 ,0);
    
    dp[0] =1;
    
//     traverse into 1 to n of the target;
    for(int i=1;i<=target;i++){
      
//       traverse in the nums array;
      for(int j=0;j< nums.size();j++){
        
        if(i- nums[j] >= 0)
           dp[i] += dp[i- nums[j]];
      }
    }
    return dp[target];
  }
  
  
    int combinationSum4(vector<int>& nums, int target) {
       
      
      // return solve(nums ,target);
      
//       memoization function;
      
//       vector<int> dp(target + 1 ,-1);
      
//       return solveMem(nums ,target ,dp);
      
      
      return solveTab(nums ,target);
    }
};

int main(){

return 0;
}