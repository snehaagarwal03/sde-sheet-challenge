class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //we are assuming day0 price as minimum price and will compare it with further day's prices and update it whenever we find the lowest price so that we can find the maximum profit
        int buy = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            buy = min(buy, prices[i]);
            int profit = prices[i] - buy;     
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;   
        //basically to maximize the profit on a particular day, we need the minimum price seen before that day 
    }
};