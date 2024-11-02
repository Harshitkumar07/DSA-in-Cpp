**Leetcode Problem 121:-**

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. 

**Example 1:**
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

**Example 2:**
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

**Code:-**

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > bestBuy)
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};

**Time Complexity:**
The time complexity is O(n) because we only traverse the prices array once. Each iteration either updates maxProfit or bestBuy, meaning we only perform n−1 comparisons and updates, 
where n is the number of elements in prices.

**Space Complexity:**
The space complexity is O(1) since we use only a fixed amount of extra space for variables (maxProfit and bestBuy). No additional data structures are needed.
