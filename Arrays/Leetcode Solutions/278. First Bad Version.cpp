** Leetcode Problem 278 :- **

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. 
You should minimize the number of calls to the API.

Example 1:
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

Example 2:
Input: n = 1, bad = 1
Output: 1

** Code :- **

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

** Time Complexity :- **

Binary Search Process:
The algorithm reduces the search space by half in each iteration.
The number of iterations required is approximately log 2(n), where n is the total number of versions.
Time Complexity: O(logn)

** Space Complexity :- **

Constant Space Usage:
The algorithm uses a few integer variables (start, end, and mid) to track the search space and return the result.
No additional data structures or recursive calls are used.
Space Complexity: O(1)
