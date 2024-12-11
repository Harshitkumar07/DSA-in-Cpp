** Problem :- **

Given an unsorted array arr[] of integers and a key which is present in this array. You need to write a program to find the start index( index where the element is first found from left in the array ) and end index( index where the element is first found from right in the array ).
Return an array of length 2 with elements start index and end index.(0 based indexing is used)
If the key does not exist in the array then return -1 for both start and end index in this case.

Examples:

1. Input: arr[] = [1, 2, 3, 4, 5, 5] , key = 5
Output:  [4, 5]
Explanation: 5 appears first time at index 4 and appears last time at index 5(0 based indexing)

2. Input: arr = [6, 5, 4, 3, 1, 2] , key = 4
Output: [2, 2]
Explanation: 4 appears first time and last time at index 2.

3. Input: arr = [7, 8, 6] , key = 2
Output: [-1, -1]
Explanation: Since 2 does not appear in the array, we will return -1 for both the start and end indices..

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1).

** Code :- **


class Solution {
  public:
    vector<int> findIndex(vector<int>& arr, int key) {
         int start = -1, end = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == key) {
                if (start == -1) {
                    start = i;
                }
                end = i;
            }
        }
        if (start == -1) {
            return {-1, -1};
        }
        return {start, end};
    }
};

** Time Complexity :- **
  
Loop Iteration:
The loop runs from i=0 to i=n−1, where n is the size of the input array.
In the worst case, every element is visited once, resulting in n iterations.
Time Cost: O(n).
Conditional Checks:
Inside the loop, there are comparisons to check whether arr[i]==key and start==−1. These are constant time operations, O(1).
Each iteration performs O(1) operations, and since there are n iterations, the total cost for these checks is O(n).
Return Statement:
The return operation, which constructs a vector, is O(1), as it only involves returning two integers.
Total Time Complexity: O(n)
  
** Space Complexity :- **
  
Auxiliary Space:
The function uses a constant amount of additional space for variables like start, end, and the loop counter.
Space Cost: O(1).
Output Space:
The function returns a vector of size 2, which is constant.
Space Cost: O(1).
Total Space Complexity: O(1)
