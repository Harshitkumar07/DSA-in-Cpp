** Leetcode Problem 387 :- **

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0
Explanation:
The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

** Code :- **

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> frequency(26, 0);
        for (char ch : s) {
            frequency[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (frequency[s[i] - 'a'] == 1) 
                return i;
        }
        return -1;
    }
};

** Time Complexity :- **
    
Character Frequency Count :
The algorithm scans the string s once, maintaining a frequency count of each character.
Using a fixed-size array vector<int> frequency(26, 0), each character is processed in O(1) time.
Let n be the length of s.
This traversal takes O(n) time.
Finding the First Unique Character :
The function iterates through s a second time, checking each character's frequency in constant O(1) time.
In the worst case, all n characters must be checked.
This results in an additional O(n) time.
Total Time Complexity :
Best Case: O(1) if the first character is unique and found immediately.
Worst Case: O(n) if the function needs to scan the entire string twice.

** Space Complexity :- **
    
Fixed-Size Frequency Array :
The function uses a vector<int> of size 26 to store character frequencies.
Since the array size is constant, this takes O(1) space.
Total Space Complexity :
Best Case: O(1) (only a few integer variables used).
Worst Case: O(1) (no additional space allocated apart from the array).
