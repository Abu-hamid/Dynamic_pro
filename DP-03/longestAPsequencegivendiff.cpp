#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// **** longest increasing subsequence  V V V. i. m.;


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int n = arr.size();

        int ans =0;
        unordered_map<int, int> dp;

        for(int i =0;i<n;i++){

            int temp = arr[i] - difference;
            int tempAns = 0;

            // check for the ans not presnt in the temp array already;

            if(dp.count(temp))
            tempAns = dp[temp];

            // update current answer;

            dp[arr[i]] = 1 + tempAns;

            // update ans
            ans = max(ans , dp[arr[i]]);
        } 

        return ans;
    }
};
int main(){

return 0;
}