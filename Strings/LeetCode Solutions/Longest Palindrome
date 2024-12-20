** Leetcode Problem 409 :- **

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

** Code :- **

class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0;
        sort(s.begin(), s.end());
        for(int i = 0; i < s.length()-1; i++){
            if(s[i] == s[i+1]){
                count++;
                i++;
            }
        }
        int total = (count * 2);
        return total == s.length() ? total : total + 1;
    }
};

** Time Complexity :- **

Sorting:
The sort function sorts the string in O(nlogn), where n is the length of the string s.
Pair Counting:
A single traversal through the string to count pairs runs in O(n).
Overall Time Complexity: O(nlogn)

** Space Complexity :- **

Auxiliary Space:
The algorithm operates directly on the string s, which is modified in place by the sort function.
Only a few integer variables (count, total, i) are used.
Total Space Complexity: O(1)
