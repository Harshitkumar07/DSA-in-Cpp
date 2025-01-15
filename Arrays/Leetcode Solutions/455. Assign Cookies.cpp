** Leetcode Problem 455 :- **

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
Your goal is to maximize the number of your content children and output the maximum number.

Example 1: 
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.

Example 2:
Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

** Code :- **

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childIdx = 0, cookieIdx = 0;
        while (childIdx < g.size() && cookieIdx < s.size()) {
            if (s[cookieIdx] >= g[childIdx]) 
                childIdx++;
            cookieIdx++;
        }
        return childIdx;
    }
};

** Time Complexity :- **
    
Sorting Phase :
The sort() function is called twice:
Once for the g array (greed factors of children).
Once for the s array (sizes of cookies).
The time complexity of sorting each array is: O(glogg)andO(slogs)
where g and s are the sizes of g and s, respectively.
Two-Pointer Traversal :
A while loop traverses the sorted arrays g and s using two pointers.
Each pointer moves at most once through its respective array.
The time complexity for this traversal is: O(max(g,s))
Total Time Complexity: O(glogg+slogs)
This is dominated by the sorting step.

** Space Complexity :- **
    
Sorting :
The sort() function operates in-place, so no additional memory is required for sorting.
Two-Pointer Approach :
A constant number of variables (childIdx and cookieIdx) are used for traversal.
Input Arrays :
The input arrays g and s are modified in-place during sorting but do not require extra memory.
Total Space Complexity: O(1)
