**Leetcode Problem 11:-**

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

**Example 1:**
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

**Example 2:**
Input: height = [1,1]
Output: 1

**Code:-**
    
class Solution {
public:
    int maxArea(vector<int>& height) {
        //Two pointer solutions
        int lp = 0; //left pointer
        int rp = height.size() - 1; //right pointer
        int maxWater = 0;
        while (lp < rp) {
            int water = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currWater = water * ht;
            maxWater = max(maxWater, currWater);
            //Ternary operator
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};

**Time Complexity:**
The time complexity is O(n) because we only traverse the array once. Each iteration either increments lp or decrements rp, meaning we only perform n - 1 comparisons and moves,
where n is the number of elements in height.

**Space Complexity:**
The space complexity is O(1) since we use only a fixed amount of extra space for pointers (lp, rp) and variables (maxWater, water, ht, currWater).
No additional data structures are needed.
