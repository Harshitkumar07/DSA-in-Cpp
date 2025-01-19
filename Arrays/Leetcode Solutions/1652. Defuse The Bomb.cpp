** Leetcode Problem 1652 :- **

You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.
To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.
If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

Example 1:
Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.

Example 2:
Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]
Explanation: When k is zero, the numbers are replaced by 0. 

Example 3:
Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.

** Code :- **

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= k; j++)
                    ans[i] += code[(i + j) % n];
            }
        } else if (k < 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= -k; j++)
                    ans[i] += code[(i - j + n) % n];
            }
        }
        return ans;
    }
};

** Time Complexity :- **

Positive k :
For each index i in code (total n iterations):
A nested loop runs k times to sum the next k elements.
Time complexity: O(n⋅k) where n is the size of the code array.
Negative k :
Similar to the positive case, the nested loop iterates ∣k∣ times for each index.
Time complexity: O(n⋅∣k∣)
Special Case: k = 0 
If k == 0, no iterations of the inner loop are performed, resulting in: O(n)
Total Time Complexity :
Best Case: O(n) when k=0.
Worst Case: O(n⋅∣k∣) for large ∣k∣.
    
** Space Complexity :- **
    
Auxiliary Space :
The algorithm creates an answer array ans of size n: O(n)
In-Place Computation :
The algorithm uses constant space for loop counters and intermediate variables: O(1)
Total Space Complexity :
Best and Worst Case: O(n)
