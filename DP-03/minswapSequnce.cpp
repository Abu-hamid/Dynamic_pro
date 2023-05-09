#include <iostream>
#include <vector>
using namespace std;
/*

class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2 ,int  index ,bool swaped){

        // base case;
        if(index == nums1.size())
        return 0;

        int ans = INT_MAX;

        int prev1 = nums1[index -1];
        int prev2 = nums2[index -1];

        // Catch;
        if(swaped)
        swap(prev1 ,prev2);

        // no Swaped

        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1 , nums2 , index+1 ,0);

            // SWAPED
            if(nums1[index] > prev2 && nums2[index] > prev1)
             ans = min(ans , 1+solve(nums1 ,nums2 , index+1 , 1));

            return ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.begin() ,-1);
        nums2.insert(nums2.begin() ,-1);

        bool swapped =0;// it means previous valued are swaped or not;
        return solve(nums1 ,nums2 ,1 , swapped);
    }
};


*/
// ADD MEMOIZATION;
/*

class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2 ,int  index ,bool swaped ,vector<vector<int>> &dp){

        // base case;
        if(index == nums1.size())
        return 0;

        if(dp[index][swaped] != -1)
        return dp[index][swaped];

        int ans = INT_MAX;

        int prev1 = nums1[index -1];
        int prev2 = nums2[index -1];

        // Catch;
        if(swaped)
        swap(prev1 ,prev2);

        // no Swaped

        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1 , nums2 , index+1 ,0 ,dp);

            // SWAPED
            if(nums1[index] > prev2 && nums2[index] > prev1)
             ans = min(ans , 1+solve(nums1 ,nums2 , index+1 , 1 ,dp));

            return dp[index][swaped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.begin() ,-1);
        nums2.insert(nums2.begin() ,-1);

        int n = nums1.size();
        bool swapped =0;// it means previous valued are swaped or not;

        vector<vector<int>> dp(n+1 , vector<int>(2 , -1));

        return solve(nums1 ,nums2 ,1 , swapped ,dp);
    }
};

*/

// ADD TABULATION;

/*

class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2){

       int n = nums1.size();
       vector<vector<int>> dp(n+1 , vector<int>(2 , 0));

       for(int index = n-1;index >= 1 ;index--){
           for(int swaped = 1;swaped >=0 ;swaped--){

                    int ans = INT_MAX;

                    int prev1 = nums1[index -1];
                    int prev2 = nums2[index -1];

                    // Catch;
                    if(swaped)
                    swap(prev1 ,prev2);

                    // no Swaped

                    if(nums1[index] > prev1 && nums2[index] > prev2)
                        ans = dp[index+1][0];

                        // SWAPED
                        if(nums1[index] > prev2 && nums2[index] > prev1)
                        ans = min(ans , 1+dp[index+1][1]);

                        dp[index][swaped] = ans;
           }
       }

       return dp[1][0];

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.begin() ,-1);
        nums2.insert(nums2.begin() ,-1);

        bool swapped =0;// it means previous valued are swaped or not;
        return solve(nums1 ,nums2);
    }
};

*/

class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums1.size();

        int swap = 0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;

        for (int index = n - 1; index >= 1; index--)
        {
            for (int swaped = 1; swaped >= 0; swaped--)
            {

                int ans = INT_MAX;

                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // Catch;
                if (swaped)
                {

                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }

                // no Swaped

                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noswap;

                // SWAPED
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + swap);

                if (swaped)
                    currswap = ans;
                else
                    currnoswap = ans;
            }

            swap = currswap;
            noswap = currnoswap;
        }

        return min(swap, noswap);
    }
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        bool swapped = 0; // it means previous valued are swaped or not;
        return solve(nums1, nums2);
    }
};
int main()
{

    return 0;
}