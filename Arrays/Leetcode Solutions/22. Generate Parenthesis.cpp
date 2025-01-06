** Leetcode Problem 22:- **

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

** Code :- **

class Solution {
public:
    void backtrack(vector<string>& ans, string& curr, int open, int close,
                   int max) {
        if (curr.length() == max * 2) {
            ans.push_back(curr);
            return;
        }
        if (open < max) {
            curr += '(';
            backtrack(ans, curr, open + 1, close, max);
            curr.pop_back();
        }
        if (close < open) {
            curr+= ')';
            backtrack(ans, curr, open, close + 1, max);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        backtrack(ans, curr, 0, 0, n);
        return ans;
    }
};

** Time Complexity :- **
    
Recursive Backtracking :
The function generates all possible valid combinations of parentheses.
For n pairs of parentheses, there are Cn(Catalan number) valid combinations, where: Cn=1/n+1(n2n)= (n+1)!⋅n!(2n)!
The growth of Cn is approximately exponential for large n, specifically O(4n/n).
Each valid combination requires O(n) time to construct because it has 2n characters.
Total Time Complexity :
Best Case: O(1) (for n=0, there are no parentheses to generate).
Worst Case: O(4n/n), as all valid combinations are generated and processed.

** Space Complexity :- **
    
Recursive Stack :
The depth of the recursion corresponds to the maximum number of recursive calls, which is 2n (adding either an opening or closing parenthesis at each step).
Space Used by Recursive Stack: O(n)
Storage for curr and ans :
curr is a string of length 2n, requiring O(n) space during recursive calls.
ans stores all valid combinations. The size of ans is proportional to the number of valid combinations Cn, and each combination has a length 2n.
Space Used for ans: O(Cn⋅n)=O(4n/n⋅n)
Total Space Complexity :
Best Case: O(1) (for n=0, no recursion or storage is needed).
Worst Case: O(4n/n⋅n), dominated by the storage for the result array ans.
