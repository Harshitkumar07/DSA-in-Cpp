** Leetcode Problem 494 :- **

You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1

** Code :- **

class Solution {
public:
    int target;
    int knapsack(vector<int>& nums, int n, int currSum) {
        if (n == 0) {
            if (currSum == target)
                return 1;
            return 0;
        }
        return knapsack(nums, n - 1, currSum + nums[n - 1]) +
               knapsack(nums, n - 1, currSum - nums[n - 1]);
    }
    int findTargetSumWays(vector<int>& nums, int sum) {
        target = sum;
        return knapsack(nums, nums.size(), 0);
    }
};

** Time Complexity :- **
    
Recursive Calls:
At each step of the recursion, the knapsack function considers two options: including the current number as positive or negative.
This creates a binary tree of recursive calls, where each level represents one number in the nums array.
For n numbers, there are 2n total function calls in the worst case.
Work Per Call:
Each recursive call performs O(1) work to compute the new currSum and compare it with the target.
Overall Time Complexity: O(2n)
This is exponential, as the solution explores all possible subsets with positive and negative signs.

** Space Complexity :- **
    
Recursive Stack Space:
The depth of the recursion is equal to the size of the nums array, n.
Each recursive call consumes O(1) space for function variables, resulting in O(n) stack space.
Auxiliary Space:
No additional data structures are used, so the auxiliary space is O(1).
Overall Space Complexity: O(n)
This accounts for the maximum depth of the recursion stack.
