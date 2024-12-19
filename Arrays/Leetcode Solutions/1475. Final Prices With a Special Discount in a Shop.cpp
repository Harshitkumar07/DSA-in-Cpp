** Leetcode Problem 1475 :- **

You are given an integer array prices where prices[i] is the price of the ith item in a shop.
There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. 
Otherwise, you will not receive any discount at all.
Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.

Example 1:
Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation: 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.

Example 2:
Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.

Example 3:
Input: prices = [10,1,1,6]
Output: [9,0,1,6]

** Code :- **

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int i = 0, j = 1;
        while (j < prices.size()) {
            if (i < j && prices[j] <= prices[i]) {
                prices[i] -= prices[j];
                i++;
                j = i + 1;
            } else if (j == (prices.size() - 1) && i != (prices.size() - 1)) {
                i++;
                j = i + 1;
            } else {
                j++;
            }
        }
        return prices;
    }
};

** Time Complexity :- **

Outer Loop (Pointer i):
Pointer i traverses each element in the prices array exactly once. Therefore, it executes O(n) iterations in the worst case.
Inner Loop (Pointer j):
Pointer j iterates through the array from i+1 to the end. In the worst case, j can also traverse the array once for every increment of i, leading to O(n2) total iterations.
Total Time Complexity: O(n2)

** Space Complexity :- **

Auxiliary Space:
The algorithm does not use any extra data structures, as all operations are performed in place on the prices array.
Space for Output:
The space required for the prices vector is already accounted for in the input.
Total Space Complexity: O(1)
