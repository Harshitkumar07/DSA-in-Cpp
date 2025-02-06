** Leetcode Problem 3151 :- **

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

Example 1:
Input: nums = [1]
Output: true
Explanation:
There is only one element. So the answer is true.

Example 2:
Input: nums = [2,1,4]
Output: true
Explanation:
There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

Example 3:
Input: nums = [4,3,1,6]
Output: false
Explanation:
nums[1] and nums[2] are both odd. So the answer is false.

** Code :- **

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                return false;
            }
        }
        return true;
    }
};

** Time Complexity :- **
    
Checking Alternating Parity :
The function loops through nums starting from index 1 and checks if adjacent elements have the same parity (both even or both odd).
This requires a single pass through the array of size n.
At each step, we compute nums[i] % 2 == nums[i - 1] % 2, which is an O(1) operation.
Since this check is performed n-1 times, the worst case time complexity is O(n).
Best and Worst Case Analysis :
Best Case (O(1)): If the first two elements have the same parity, the function returns false immediately without further iterations.
Worst Case (O(n)): If all elements have alternating parity, the loop completes all n-1 iterations before returning true.

** Space Complexity :- **
    
In-Place Computation :
The function only uses a single integer (i) for iteration.
No extra arrays or data structures are used, making it an in-place solution.
Total Space Complexity :
Best Case (O(1)): Only a few integer variables are used.
Worst Case (O(1)): Even if the loop runs fully, no additional space is allocated beyond the input array.
Thus, the space complexity is O(1) in all cases.
