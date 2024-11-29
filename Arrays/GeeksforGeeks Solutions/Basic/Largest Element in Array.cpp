** Problem :- **

Given an array arr[]. The task is to find the largest element and return it.

Examples:

1. Input: arr = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.

2. Input: arr = [5, 5, 5, 5]
Output: 5
Explanation: The largest element of the given array is 5.

3. Input: arr = [10]
Output: 10
Explanation: There is only one element which is the largest.

** Code :- **

class Solution {
  public:
    int largest(vector<int> &arr) {
        int max = arr[0];
        int size = arr.size();
        for(int i=1;i<size;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }
};

** Time Complexity :- **
  
Finding the largest element:
The algorithm iterates through the array starting from the second element.
For each element, it compares the current element with the max value, which is a constant-time operation.
This requires n−1 iterations for an array of size n.
Time complexity: O(n).
Overall Time Complexity:
The total time complexity is: O(n)
  
** Space Complexity :- **
  
Auxiliary space:
The algorithm uses only a few integer variables (max, size, and the loop counter i) to store intermediate results.
These require constant space: O(1).
No additional data structures:
The algorithm uses the input array directly and does not create any additional data structures.
Overall Space Complexity:
The total space complexity is: O(1)
