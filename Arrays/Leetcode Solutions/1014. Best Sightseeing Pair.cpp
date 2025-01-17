** Leetcode Problem 1014 :- **

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
Return the maximum score of a pair of sightseeing spots.

Example 1:
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

Example 2:
Input: values = [1,2]
Output: 2

** Code :- **

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, prev = values[0];
        for (int j = 1; j < values.size(); j++) {
            ans = max(ans, prev + values[j] - j);
            prev = max(prev, values[j] + j);
        }
        return ans;
    }
};

** Time Complexity :- **

Single Loop:
The algorithm uses a single loop to traverse the array values once. This contributes O(n), where n is the size of the values array.
Operations Inside the Loop:
The operations inside the loop (calculating ans and updating prev) take constant time, O(1), for each iteration.
Overall Time Complexity: O(n)
This is because the algorithm iterates through the array once.

** Space Complexity :- **

Auxiliary Variables:
The algorithm uses a few scalar variables: ans and prev. These consume O(1) space.
Input Storage:
The values array is provided as input and does not contribute to additional space complexity.
Overall Space Complexity: O(1)
This is because the algorithm does not use any additional data structures that scale with the size of the input.
