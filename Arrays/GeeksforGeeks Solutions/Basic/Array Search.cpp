** Problem :- **

Given an array, arr of n integers, and an integer element x, find whether element x is present in the array. 
Return the index of the first occurrence of x in the array, or -1 if it doesn't exist.

Examples:

1. Input: arr[] = [1, 2, 3, 4], x = 3
Output: 2
Explanation: There is one test case with array as [1, 2, 3 4] and element to be searched as 3. Since 3 is present at index 2, the output is 2.

2. Input: arr[] = [10, 8, 30, 4, 5], x = 5
Output: 4
Explanation: For array [1, 2, 3, 4, 5], the element to be searched is 5 and it is at index 4. So, the output is 4.

3. Input: arr[] = [10, 8, 30], x = 6
Output: -1
Explanation: The element to be searched is 6 and its not present, so we return -1.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1). 

** Code :- **

class Solution {
  public:
    int search(vector<int>& arr, int x) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x){
                return i;
            }
        }
        return -1;
    }
};

** Time Complexity :- **

Iterating through the Array:
The algorithm performs a linear search, iterating through each element in the array until x is found or the end of the array is reached.
In the worst case, the entire array of size n is traversed.
Time Complexity: O(n)

** Space Complexity :- **

The algorithm uses a constant amount of extra space for the loop index i and other variables.
No additional data structures are used.
Space Complexity: O(1)
