** Problem :- **

Given an array arr[]. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements. 
Do the mentioned change in the array in place.

Examples:

1. Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.

2. Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: No change in array as there are no 0s.

3. Input: arr[] = [0, 0]
Output: [0, 0]
Explanation: No change in array as there are all 0s.

** Code :- **

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int ptr = 0;
        for(int i = 0;i < arr.size();i++){
            if(arr[i] != 0){
                swap(arr[i],arr[ptr]);
            ptr++;
            }
        }
    }
};

** Time Complexity :- **

Single Pass Through Array:
The algorithm iterates through the array of size n exactly once using a loop.
Each iteration either swaps two elements (if the current element is non-zero) or moves the pointer ptr.
Swapping operations and pointer updates are constant-time operations.
Time Complexity: O(n)

** Space Complexity :- **

Constant Extra Space:
The algorithm uses only a single pointer variable ptr and performs swaps in-place.
No additional data structures are used.
Space Complexity: O(1)
