#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int mini = prices[0];
        int profit = 0 ;

        for(int i=0 ; i<n ; i++){

            int diff = prices[i] - mini;
            profit = max(profit , diff);
            mini = min(mini , prices[i]);
        }

        return profit;
        
    }
};


int main(){

return 0;
}