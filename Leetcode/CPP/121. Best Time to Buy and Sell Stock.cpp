/*
    Solution Added By: Anish Kumar
    Github Profile: https://github.com/KmrAnish04

    Question: Best Time to Buy and Sell Stock (Leetcode: 121. Best Time to Buy and Sell Stock)
    Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


    Optimized Approach:
    Time Complexity: O(N)
    Space Complexity: O(1)

    Algorithm:
    1. Here, we will keep track of two variables, that is "minPriceToBuy" and "maxProfit" to check minimum price of stocks so far and max profit so far.
    2. While iterating through the array, we will check the minimum price so far at every iteration, if price is minimum at current iteration then we will update the 
       variable "minimumPriceToBuy" with that value, otherwise keep iteration.
    3. In every iteration, we will check for max profit so far, that is "prices[i] - minPriceToBuy", whenever we will get max profit, we will update variable 
       "maxProfit" with that value.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceToBuy = prices[0];
        int maxProfit = 0;
            
        for(int i=0;i<prices.size(); i++){
            if(prices[i]<minPriceToBuy){
                minPriceToBuy = prices[i];
            }
            else if(prices[i]-minPriceToBuy > maxProfit){
                maxProfit = prices[i]-minPriceToBuy;
            }
        }
        
        return maxProfit;
    }
};

