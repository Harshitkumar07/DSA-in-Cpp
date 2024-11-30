** Problem :- **

Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.
Note: If multiple occurrences are there, please return the smallest index.

Examples:

1. Input: arr[] = [1, 2, 3, 4, 5], k = 4
Output: 3
Explanation: 4 appears at index 3.

2. Input: arr[] = [11, 22, 33, 44, 55], k = 445
Output: -1
Explanation: 445 is not present.

3. Input: arr[] = [1, 1, 1, 1, 2], k = 1
Output: 0
Explanation: 1 appears at index 0.
Note: Try to solve this problem in constant space i.e O(1)

** Code :- **

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int start=0 , end = arr.size()-1;
        while(start<=end) {
            int mid=(start+end)/2;
            if(arr[mid]==k) {
                return mid;
            } else {
            if(arr[mid]<k) {
                start = mid+1;
            } else {
                end= mid-1;
            }
            }
        }
        return -1;
    }
};

** Time Complexity :- **
  
Binary Search Logic:
The algorithm repeatedly divides the array into halves to locate the target element k.
In each iteration, it calculates the middle index and compares the middle element with k, which are constant-time operations.
The size of the search space reduces by half in each iteration. This continues until the target is found or the array is fully traversed.
The total number of iterations is at most log 2(n), where n is the size of the array.
Overall Time Complexity:
The total time complexity is: O(logn)

** Space Complexity :- **
  
Auxiliary space:
The algorithm uses a few integer variables (start, end, mid) to manage the indices, which require constant space: O(1).
No recursion or additional data structures:
Since the implementation is iterative and works directly on the input array without additional storage, no extra space is used.
Overall Space Complexity:
The total space complexity is: O(1)
