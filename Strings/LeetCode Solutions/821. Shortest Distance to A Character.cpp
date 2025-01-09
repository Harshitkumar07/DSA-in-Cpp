** Leetcode Problem 821:- **

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.
The distance between two indices i and j is abs(i - j), where abs is the absolute value function.

Example 1:
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.

Example 2:
Input: s = "aaab", c = "b"
Output: [3,2,1,0]

** Code :- **

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> vec;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c)
                vec.push_back(i);
        }
        vector<int> ans(s.size(), INT_MAX);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < vec.size(); j++)
                ans[i] = min(ans[i], abs(vec[j] - i));
        }
        return ans;
    }
};

** Time Complexity :- **
    
First Loop: Finding All Indices of c
The function iterates over the string s of size n to find all indices of the character c and stores them in the vector vec.
This operation takes O(n) time.
Second Loop: Calculating Shortest Distances
The outer loop iterates over each character of the string s, i.e., O(n).
The inner loop iterates over the indices stored in vec. Let k be the size of vec, which depends on the frequency of c in the string.
For each pair of string character and vec index, the distance is calculated and the minimum is updated.
This results in O(n×k) time in the worst case.
Best Case :
If c appears frequently, k is large, and many characters are equidistant from their nearest c.
Despite frequent appearances, each character's nearest c is quickly identified, reducing the need to evaluate all k indices.
Time complexity remains O(n×k), though the actual number of comparisons may be reduced.
Worst Case :
If c appears sparsely (e.g., only once), k=1, and every character in s needs to compute its distance from this lone index of c.
Time complexity is O(n×k), where k=1.
Total Time Complexity :
Best Case: O(n+n×k)=O(n×k), where k is the size of vec.
Worst Case: 
O(n×k), number of occurrences of k=number of occurrences of c.

** Space Complexity :- **
    
Vector vec for Indices of c :
Stores the indices of all occurrences of c. If k is the number of occurrences of c, vec requires O(k) space.
Vector ans for Result : 
Stores the shortest distances for each character in s. This requires O(n) space.
Auxiliary Variables :
Uses constant space for loop indices and temporary variables.
Best Case :
Space complexity is O(n+k), with k as the number of occurrences of c.
Worst Case :
Space complexity remains O(n+k), as the size of vec depends on the frequency of c.
Total Space Complexity :
Best Case: O(n+k).
Worst Case: O(n+k).
