** Problem :- **

Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation.
If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 
Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

Examples:

1. Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.

2. Input: arr = [3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation, the next permutation is the lowest one.

3. Input: arr = [3, 4, 2, 5, 1]
Output: [3, 4, 5, 1, 2]
Explanation: The next permutation of the given array is {3, 4, 5, 1, 2}.

** Code :- **

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int piv = -1, n = arr.size();
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                piv = i;
                break;
            }
        }
        if (piv == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }
        for (int i = n - 1; i > piv; i--) {
            if (arr[i] > arr[piv]) {
                swap(arr[i], arr[piv]);
                break;
            }
        }
        reverse(arr.begin() + piv + 1, arr.end());
    }
};

** Time Complexity :- **

Finding the Pivot Element:
A single traversal from the end of the array to the start:O(n)
Finding the Next Larger Element:
Another traversal (from the end of the array to piv):O(n)
Reversing the Subarray:
Reversing the subarray takes O(k), where k is the size of the subarray. In the worst case, k=n.

Overall Time Complexity:
Combining all steps: O(n)

** Space Complexity :- **

In-Place Modifications:
The algorithm modifies the input array directly, using no additional data structures.

Overall Space Complexity: O(1)
