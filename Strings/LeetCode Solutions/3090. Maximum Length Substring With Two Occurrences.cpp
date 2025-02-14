** Leetcode Problem 3090 :- **

Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.

Example 1:

Input: s = "bcbbbcba"
Output: 4
Explanation :
The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".

Example 2:

Input: s = "aaaa"
Output: 2
Explanation:
The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".

** Code :- **

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length(), left = 0, right = 0, count = INT_MIN;
        unordered_map<char, int> map;
        while (right < n) {
            if (map.find(s[right]) == map.end()) {
                map[s[right]]++;
                right++;
            } else if (map[s[right]] < 2) {
                map[s[right]]++;
                right++;
            } else {
                count = max(count, (right - left));
                left++;
                right = left;
                map.clear();
            }
        }
        count = max(count, right - left);
        return count;
    }
};

** Time Complexity :- **
    
Sliding Window Traversal :
The right pointer iterates through s, and left moves forward when necessary.
In the worst case, both pointers traverse s entirely, leading to O(n) + O(n) = O(n) complexity.
Updating the Frequency Map :
Each character is inserted, updated, or removed from map at most once, taking O(1) per operation.
Over n characters, this results in O(n) operations.
Total Time Complexity :
Best Case: O(n) → If all characters appear at most twice, a single pass suffices.
Worst Case: O(n) → The algorithm iterates through s with at most 2n pointer moves.
    
** Space Complexity :- **

Hash Map Storage (unordered_map<char, int>) :
Stores at most 26 keys (lowercase letters), leading to O(1) space.
Auxiliary Variables (left, right, count, etc.)
A few integer variables contribute O(1) space.

Total Space Complexity :
Best Case: O(1) → If the input string has only unique characters.
Worst Case: O(1) → The hash map never exceeds 26 entries.
Overall, the space complexity remains O(1).
