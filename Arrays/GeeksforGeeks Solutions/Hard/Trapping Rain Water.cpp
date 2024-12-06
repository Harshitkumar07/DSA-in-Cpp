** Problem :- **

Given an array arr[] with non-negative integers representing the height of blocks. 
If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Examples:

1. Input: arr[] = [3, 0, 0, 2, 0, 4]
Output: 10
Explanation: 

2. Input: arr[] = [7, 4, 0, 9]
Output: 10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.

3. Input: arr[] = [6, 9, 9]
Output: 0
Explanation:
No water will be trapped.

** Code :- 

class Solution {
  public:
    int trappingWater(vector<int> &height) {
        int n = height.size(), ans = 0;
        int left = 0, right = n - 1, leftMax = 0, rightMax = 0;
        if (n == 0)
            return 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    ans += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    ans += rightMax - height[right];
                }
                right--;
            }
        }

        return ans;
    }
};

** Time Complexity :- **
  
Single Loop:
The algorithm uses a while loop that moves the pointers (left and right) toward each other.
Each pointer moves exactly once for every element in the height array, making the traversal linear.

Overall time complexity: O(n)
Where n is the size of the height array.

** Space Complexity :- **

Auxiliary Variables:
The function uses only a constant number of variables: left, right, leftMax, rightMax, and ans.
These require O(1) space.
No Additional Data Structures:
No extra arrays or data structures are used in the computation.

Overall space complexity: O(1)
