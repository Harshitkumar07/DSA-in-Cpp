** Leetcode Problem 322:- **

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

** Code :- **

class Solution {
public:
    // Memoization
    int findCoins(vector<int>& coins, int amt, unordered_map<int, int>& memo) {
        if (amt == 0)
            return 0;
        if (amt < 0)
            return INT_MAX;
        if (memo.find(amt) != memo.end()) {
            return memo[amt];
        }
        int minCoins = INT_MAX;
        for (int coin : coins) {
            int ans = findCoins(coins, amt - coin, memo);
            if (ans != INT_MAX) {
                minCoins = min(minCoins, ans + 1);
            }
        }
        memo[amt] = minCoins;
        return minCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        int result = findCoins(coins, amount, memo);
        return result == INT_MAX ? -1 : result;
    }
};

** Time Complexity :- **
The time complexity of this solution depends on the number of subproblems and the work done per subproblem.

Number of Subproblems:
Each unique subproblem corresponds to a unique amount amt. Therefore, there are at most amount+1 subproblems (from 0 to amount).
Work Per Subproblem:
For each subproblem, the algorithm iterates over all the n coins. Hence, the work per subproblem is O(n), where n is the number of coins.

Overall Time Complexity:
The total time complexity is the product of the number of subproblems and the work per subproblem: O(amount⋅n)

** Space Complexity :- **
Memoization Storage:
The memo table stores results for up to amount+1 subproblems, leading to O(amount) space.
Recursive Call Stack:
The maximum depth of the recursion stack is proportional to amount/min(coins), where min(coins) is the smallest denomination of the coins. In the worst case, this depth is O(amount).

Overall Space Complexity:
Combining memoization storage and recursion stack: O(amount)
