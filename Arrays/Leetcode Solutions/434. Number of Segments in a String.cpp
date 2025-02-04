** Leetcode Problem 434 :- **

Given a string s, return the number of segments in the string.
A segment is defined to be a contiguous sequence of non-space characters.

Example 1:
Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

Example 2:
Input: s = "Hello"
Output: 1

** Code :- **

class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        bool segment = false;
        for (char c : s) {
            if (c != ' ') {
                if (!segment) {
                    segment = true;
                    cnt++;
                }
            } else {
                segment = false;
            }
        }
        return cnt;
    }
};

** Time Complexity :- **

Breaking Down the Iteration :
The function iterates through the entire string s once using a for loop.
Inside each iteration:
Checking if c != ' ' → O(1)
Checking segment flag and updating count → O(1)
Updating segment flag when encountering space → O(1)
Since all operations inside the loop are constant time O(1), the overall complexity depends only on the length of s, making it:
O(n) where n is the length of the input string.

Best Case Complexity :
O(n) in all cases since every character needs to be checked at least once.
Worst Case Complexity :
O(n), even if there are no segments (e.g., s = " "), as the function still iterates through all characters.

** Space Complexity :- **

In-Place Computation
The function only uses a few integer and boolean variables:
cnt → Stores the number of segments.
segment → Tracks whether we are in a segment.
No additional data structures are used.
The function does not modify the input string s.
Total Space Complexity : O(1)
The space used remains constant, independent of the length of s.
Best Case Complexity : O(1)
Since only a fixed number of variables are used.
Worst Case Complexity : O(1)
The space usage does not change with the size of s.
