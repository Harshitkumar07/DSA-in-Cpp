** Leetcode problem 443:- **

Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters in chars:
If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars.
Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done modifying the input array, return the new length of the array.
You must write an algorithm that uses only constant extra space.

Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

** Code :- **

class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        for (int i = 0; i < chars.size(); i++) {
            char ch = chars[i];
            int cnt = 0;
            while (i < chars.size() && chars[i] == ch) {
                cnt++;
                i++;
            }
            if (cnt == 1) {
                chars[idx++] = ch;
            } else {
                chars[idx++] = ch;
                string str = to_string(cnt);
                for (char digit : str) {
                    chars[idx++] = digit;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};

** Time Complexity :- **
    
Outer Loop (Traversal):
The for loop iterates through all the characters in the input chars vector.
Each character is processed exactly once.
Total iterations: O(n), where n is the size of the input vector.
Inner Loop (Counting Consecutive Characters):
For each group of consecutive identical characters, the inner while loop counts the occurrences. Each character is processed only once across all iterations of the loop.
Total iterations across all groups: O(n).
String Conversion:
If a character is repeated, the count is converted to a string using to_string(cnt). The number of digits in cnt is O(log 10(cnt)). In the worst case, cnt≤n, so this operation is O(logn).
Over all groups, the total cost of string conversion is O(n), since the sum of digits of all counts is bounded by n.
Overall Time Complexity: O(n)

** Space Complexity :- **
    
In-Place Modifications:
The algorithm modifies the input vector chars in place, without using additional space for storing results.
Temporary String for Counts:
A temporary string is used to store the digit representation of the count. This string has at most O(logn) space for any given group.
Overall Space Complexity: O(logn)
