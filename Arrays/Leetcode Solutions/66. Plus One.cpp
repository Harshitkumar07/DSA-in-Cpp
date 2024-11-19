** Leetcode Problem 66:- **

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

** Code :- **

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 != 10) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;
    }
};

** Time Complexity :- **
Iterating through Digits:
The algorithm iterates through the array in reverse order, which takes O(n), where n is the size of the digits vector.
Insertion at the Start:
In the worst case (e.g., all digits are 9), inserting 1 at the beginning of the vector also takes O(n), as all elements need to be shifted.

Overall Time Complexity:
The worst-case time complexity is: O(n)
    
** Space Complexity :- **
In-place Update:
The algorithm modifies the digits vector in place and does not use any additional storage for intermediate computations.
Insertion in the Worst Case:
If all digits are 9, a new digit (1) is added to the start, increasing the size of the vector by 1. This operation requires additional memory allocation for the extended vector.

Overall Space Complexity:
In the worst case, the space complexity due to resizing is: O(n)
Otherwise, it is: O(1)
