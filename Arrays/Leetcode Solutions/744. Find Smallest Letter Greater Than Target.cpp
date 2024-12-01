** Leetcode Problem 744 :- **

You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

Example 1:
Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.

Example 2:
Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.

Example 3:
Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].

** Code :- **

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = letters.size(), start = 0, end = l - 1;
        char ans = letters[0];
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (letters[mid] > target) {
                ans = letters[mid];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Binary Search Logic:
The algorithm uses binary search to locate the smallest character in the array that is greater than the target.
Each iteration divides the search space in half.
The size of the search space decreases exponentially, resulting in at most log 2(n) iterations, where n is the size of the array.
    
Overall Time Complexity:
The total time complexity is: O(logn)

** Space Complexity :- **
Auxiliary space:
The algorithm uses a few integer variables (l, start, end, mid) and a character variable (ans) to track the result, all of which require constant space: O(1).
No recursion or additional data structures:
The algorithm is iterative and modifies the input array directly without additional storage.

Overall Space Complexity:
The total space complexity is: O(1)
