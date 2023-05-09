#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(int index, int buy, vector<int> &prices, int fee)
    {

        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {

                int profit = 0;
                if (buy)
                {

                    int buyKro = -prices[index] + next[0];// we can paid fee here also;
                    int skipKro = 0 + next[1];
                    profit = max(buyKro, skipKro);
                }

                else
                {
                    int sellKro = +prices[index] + next[1] - fee;
                    int skipKro = 0 + next[0];
                    profit = max(sellKro, skipKro);
                }
                curr[buy] = profit;
            }

            next = curr;
        }

        return curr[1];
    }

    int maxProfit(vector<int> &prices, int fee)
    {

        return solve(0, 0, prices, fee);
    }
};
int main()
{

    return 0;
}