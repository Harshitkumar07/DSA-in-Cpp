** Problem :- **

Given an array arr[], check whether it is sorted in non-decreasing order. Return true if it is sorted otherwise false.

Examples:

1. Input: arr[] = [10, 20, 30, 40, 50]
Output: true
Explanation: The given array is sorted.

2. Input: arr[] = [90, 80, 100, 70, 40, 30]
Output: false
Explanation: The given array is not sorted.

** Code :- **

class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        for(int i=1;i<arr.size();i++){
            if (arr[i]<arr[i-1]) {
                return false;
            }
        }
        return true;
    }
};

** Time Complexity :- **
  
Loop Iteration:
The loop runs from index i=1 to i=n−1, where n is the size of the input array.
In the worst case (when the array is sorted), the loop will iterate n−1 times.
Time Cost: O(n).
Comparison Operations:
Each iteration involves one comparison operation arr[i]<arr[i−1], which is constant time O(1).
Since there are n−1 iterations, the total cost of comparisons is O(n−1)=O(n).
Early Exit: If the array is unsorted, the loop may terminate early. In the best case, where the first two elements are out of order, the loop exits after one iteration.
However, the complexity is analyzed for the worst case.
Total Time Complexity:O(n)

** Space Complexity :- **
  
Auxiliary Space:
No extra data structures or arrays are used; the function operates directly on the input array.
Space Cost: O(1).
Other Variables:
The only additional space used is for the loop counter and function arguments, which are constant.
Space Cost: O(1).
Total Space Complexity: O(1)
