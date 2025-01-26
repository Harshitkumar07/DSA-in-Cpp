** Leetcode Problem 1089:- **

Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

Example 1:
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:
Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]

** Code :- **

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int cntZeros = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0)
                cntZeros++;
        }
        for (int i = n - 1, j = n + cntZeros - 1; i >= 0; --i) {
            if (j < n)
                arr[j] = arr[i];
            if (arr[i] == 0) {
                j--;
                if (j < n) {
                    arr[j] = arr[i];
                }
            }
            j--;
        }
    }
};

** Time Complexity :- **
    
Counting Zeros :
The first loop iterates through the array to count zeros, taking: O(n) where n is the length of arr.
Shifting Elements :
The second loop iterates backward through the array, potentially shifting elements up to 2n times due to duplication.
In the worst case (all elements are zeros), the loop still runs in : O(n)
Total Time Complexity :
Best Case: O(n)
when there are no zeros in the array.
Worst Case: O(n)
since every zero requires an additional shift, effectively iterating the array twice.

** Space Complexity :- **
    
In-Place Computation :
The algorithm modifies the input array without using extra space, apart from a few integer variables (cntZeros, i, j).
This results in: O(1)
Input Array :
The input array arr does not contribute to additional space complexity as it is modified in place.
Total Space Complexity :
Best and Worst Case: O(1)
