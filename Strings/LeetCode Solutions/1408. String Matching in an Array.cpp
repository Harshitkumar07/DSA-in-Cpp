** Leetcode Problem 1408 :- **

Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero". 
["hero","as"] is also a valid answer.

Example 2:
Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".

Example 3:
Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.

** Code :- **

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> str;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    str.push_back(words[i]);
                    break;
                }
            }
        }
        return str;
    }
};

** Time Complexity :- **
    
Outer Loop :
The outer loop iterates over all strings in the words vector. If there are n words, this loop executes n times.
Inner Loop :
For each word i in the outer loop, the inner loop iterates over all n words again. This results in O(n2) iterations in the worst case.
Substring Search :
The find operation checks if words[i] is a substring of words[j].
In the worst case, find has a complexity of O(k×m), where k is the length of words[i] and m is the length of words[j]. If k≈m≈l, this operation is O(l2).
Best Case :
In the best case, the loop breaks early when a match is found (e.g., the first string is matched immediately). The complexity reduces but remains O(n2×l2) in terms of asymptotic bounds.
Worst Case :
The worst case occurs when no strings match, requiring all O(n2) iterations of the find operation to complete.
Total Time Complexity :
Best Case: O(n2×l2), with reduced iterations due to early loop exits.
Worst Case: O(n2×l2), with all comparisons made.

** Space Complexity :- **
    
Output Storage :
The vector str stores the substrings that match the condition.
In the worst case, all n strings are substrings of other strings, so str stores O(n) elements.
Auxiliary Variables :
Only a constant amount of space is used for loop indices and temporary variables.
Best Case :
If no strings are substrings, str remains empty, and the additional space used is O(1).
Worst Case :
The vector str contains all n strings, requiring O(n) space.
Total Space Complexity :
Best Case: O(1), if no matches are found.
Worst Case: O(n), when all strings are stored in str.
