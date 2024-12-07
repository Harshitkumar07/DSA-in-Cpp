** Problem :- **

Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
Note: The second largest element should not be equal to the largest element.

Examples:

1. Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.

2. Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.

3. Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.

** Code :- **

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest = INT_MIN;
        int secLargest = INT_MIN;
        for (int num : arr) {
            if (num > largest) {
                secLargest = largest;
                largest = num;
            } else if (num > secLargest && num < largest) {
                secLargest = num;
            }
        }
        return (secLargest == INT_MIN) ? -1 : secLargest;
    }
};

** Time Complexity :- **
  
Single Loop:
The algorithm iterates through the arr array once.
For each element, it performs a constant number of comparisons and assignments.
Total time complexity:
O(n) Where n is the size of the arr array.
  
** Space Complexity :- **
  
Auxiliary Variables:
The function uses only two integer variables, largest and secLargest.
These require O(1) space.
No Additional Data Structures:
The algorithm does not allocate memory for additional arrays or structures.
Total space complexity: O(1)
