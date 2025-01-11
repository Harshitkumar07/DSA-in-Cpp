** Leetcode Problem 2185:- **

You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.

Example 1:
Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

Example 2:
Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.

** Code :- **

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        int i = 0, j = 0;
        while (i < words.size()) {
            if (pref[j] == words[i][j] && j != pref.length()) {
                j++;
            } else if (j == pref.length()) {
                cnt++;
                i++;
                j = 0;
            } else {
                i++;
                j = 0;
            }
        }
        return cnt;
    }
};

** Time Complexity :- **
    
Outer Loop (Iterating Through Words) :
The while loop iterates through the vector words. For each word, the prefix is checked character by character against pref.
Time Complexity: Let w be the number of words in the list words and l be the average length of the words. Each word comparison has a complexity proportional to l.
Overall Complexity: O(w⋅l).
Inner Character Comparisons :
The comparison continues character by character until either a mismatch is found or the prefix is fully matched.
In the best case, the prefix matches early (or mismatches early). In the worst case, it traverses all characters of each word up to the prefix length p.
Best Case: O(w⋅p) (mismatches early).
Worst Case: O(w⋅p) (checks full prefix).
Total Time Complexity :
Best Case: O(w⋅p).
Worst Case: O(w⋅p).

** Space Complexity :- **
    
In-Place Operations :
The function uses constant space for variables (cnt, i, j) and does not allocate additional memory proportional to the input size.
Best and Worst Cases :
The space usage is constant in all cases.
Total Space Complexity: O(1).
