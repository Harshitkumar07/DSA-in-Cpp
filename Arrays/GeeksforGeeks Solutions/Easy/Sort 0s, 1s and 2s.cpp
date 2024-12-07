** Problem :- **

Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:

1. Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.

2. Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.

** Code :- **

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                mid++;
                low++;
            } else if (arr[mid] == 1) {
                mid++;
            } else {
                swap(arr[high], arr[mid]);
                high--;
            }
        }
    }
};

** Time Complexity :- **

Single Pass Through Array:
The algorithm uses a while loop that iterates at most n times, where n is the size of the array.
Each iteration involves a constant-time operation (comparison and swapping).
Total time complexity: O(n)

** Space Complexity :- **
  
Auxiliary Space:
The function uses only a few integer variables: low, mid, and high.
Swapping elements does not require additional memory.
Total space complexity: O(1)
