** Leetcode Problem 374 :- **

We are playing the Guess Game. The game is as follows: I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
You call a pre-defined API int guess(int num), which returns three possible results:
-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.

Example 1:
Input: n = 10, pick = 6
Output: 6

Example 2:
Input: n = 1, pick = 1
Output: 1

Example 3:
Input: n = 2, pick = 1
Output: 1

** Code :- **

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid = left + (right - left) / 2;
        while (left < right) {
            int ans = guess(mid);
            if (ans == 0)
                return mid;
            else if (ans == -1)
                right = mid - 1;
            else
                left = mid + 1;
            mid = left + (right - left) / 2;
        }
        return mid;
    }
};

** Time Complexity :- **
    
Binary Search Iterations :
The binary search algorithm halves the search range in each iteration.
For a search range from 1 to n, the number of iterations is proportional to log 2(n).
Each iteration involves one call to the guess function, which is assumed to operate in O(1).
Best Case :
The best case occurs when the target number is found in the first iteration. This happens when mid matches the target on the first check, requiring O(1) iterations.
Worst Case :
The worst case occurs when the target number is found after exhausting all iterations of the binary search, requiring O(logn) iterations.
Total Time Complexity :
Best Case: O(1), if the target is found immediately.
Worst Case: O(logn), if the search range is halved repeatedly until the target is found.

** Space Complexity :- **
    
Auxiliary Variables :
The algorithm uses a constant amount of extra space for variables like left, right, mid, and ans.
Recursive Stack (if recursive implementation) :
Since the implementation is iterative, no additional space is used for recursion.
Total Space Complexity :
Best Case: O(1), as the space usage is independent of n.
Worst Case: O(1), as no additional space is consumed regardless of the input size.
