** Problem :- **

In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day. 
The second transaction can only start after the first one is complete (buy->sell->buy->sell), the stock prices throughout the day are represented in the form of an array of prices. 
Given an array price of size n, find out the maximum profit that a share trader could have made.

Example 1:
Input: n = 6
prices[] = {10,22,5,75,65,80}
Output: 87
Explanation: Trader earns 87 as sum of 12 and 75. Buy at 10, sell at 22, Buy at 5 and sell at 80.

Example 2:
Input: n = 7
prices[] = {2,30,15,10,8,25,80}
Output: 100
Explanation: Trader earns 100 as sum of 28 and 72. Buy at price 2, sell at 30, Buy at 8 and sell at 80.

Your Task:
Complete the function maxProfit() which takes an integer array price as the only argument and returns an integer, representing the maximum profit, if only two transactions are allowed.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

** Code :- **

class Solution{
    public:
    int maxProfit(vector<int>&prices){
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> leftProfit(n, 0);
        vector<int> rightProfit(n, 0);
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i - 1], prices[i] - minPrice);
        }
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i + 1], maxPrice - prices[i]);
        }
        int maxProfit = 0;
        for (int i = 0; i < n - 1; ++i) { 
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i + 1]);
        }
        maxProfit = max(maxProfit, rightProfit[0]);
        return maxProfit;
    }
};

** Time Complexity :- **

First Pass to Compute leftProfit:
Iterates over the array once: O(n).
Second Pass to Compute rightProfit: Iterates over the array once in reverse: O(n).
Combine Results: Iterates through the array once to calculate the maximum profit: O(n).

Overall Time Complexity: O(n)

** Space Complexity :- **

Auxiliary Arrays: Two arrays, leftProfit and rightProfit, each of size n, are used.
Space used: O(n).
Variables: Uses a constant amount of space for variables like minPrice, maxPrice, and maxProfit.

Overall Space Complexity: O(n)
