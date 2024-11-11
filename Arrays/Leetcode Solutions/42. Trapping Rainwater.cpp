** Leetcode Problem 42 :- **

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

** Code :- **

class Solution {
public:
    int trap(vector<int>& height) {
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

** Time Complexity: **

The time complexity is O(n), where n is the number of elements in height.
The function iterates through the height array with two pointers (left and right) that move towards each other.
Each element is processed at most once, and each comparison and update operation takes constant time.
Thus, the overall time complexity is O(n).

** Space Complexity: **

The space complexity is O(1) because we only use a fixed amount of extra space for variables (left, right, leftMax, rightMax, and ans).
No additional data structures are created, so memory usage remains constant regardless of the input size.
