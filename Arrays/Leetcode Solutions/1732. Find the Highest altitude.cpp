** Leetcode Problem 1732:- **

There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.
You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

Example 1:
Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

Example 2:
Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.

** Code :- **

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = gain[0], prevsum = gain[0];
        if (ans < 0)
            ans = 0;
        for (int i = 1; i < gain.size(); i++) {
            prevsum += gain[i];
            ans = max(ans, prevsum);
        }
        return ans;
    }
};

** Time Complexity :- **

Initialization of variables (ans and prevsum):
These operations take constant time: O(1).
Iterating through the gain array:
The algorithm loops through the array once, updating the cumulative altitude (prevsum) and checking the maximum altitude (ans) at each step.
Each iteration involves simple arithmetic and a constant-time max operation.
Time complexity of this loop: O(n), where n is the size of the gain array.

Overall Time Complexity:
The initialization is O(1), and the iteration is O(n). Therefore:O(1)+O(n)=O(n)

** Space Complexity :- **

Auxiliary space:
The algorithm uses a few integer variables (ans, prevsum, and i) for calculations, requiring constant space: O(1).
No additional data structures:
The algorithm modifies and operates on the input array directly without allocating extra memory.

Overall Space Complexity:
The total space complexity is: O(1)
