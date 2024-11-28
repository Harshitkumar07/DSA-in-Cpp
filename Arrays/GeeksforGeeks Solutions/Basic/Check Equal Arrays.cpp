** Problem :- **

Given two arrays arr1 and arr2 of equal size, the task is to find whether the given arrays are equal.
Two arrays are said to be equal if both contain the same set of elements, arrangements (or permutations) of elements may be different though.
Note: If there are repetitions, then counts of repeated elements must also be the same for two arrays to be equal.

Examples:

1. Input: arr1[] = [1, 2, 5, 4, 0], arr2[] = [2, 4, 5, 0, 1]
Output: true
Explanation: Both the array can be rearranged to [0,1,2,4,5]

2. Input: arr1[] = [1, 2, 5], arr2[] = [2, 4, 15]
Output: false
Explanation: arr1[] and arr2[] have only one common value.

** Code :- **

class Solution {
  public:
    // Function to check if two arrays are equal or not.
    bool check(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        for(int i=0;i<arr1.size();i++) {
            if(arr1[i]==arr2[i]) {
                ans++;
            }
        } 
        if(ans == arr1.size()) {
            return true;
        }
        return false;
    }
};

** Time Complexity :- **
  
Sorting arr1 and arr2:
Both arrays are sorted using the sort function. Sorting an array of size n has a time complexity of O(nlogn).
Since both arr1 and arr2 are of the same size n, sorting contributes: O(nlogn)+O(nlogn)=O(nlogn)
Comparing elements of arr1 and arr2:
After sorting, the algorithm iterates through the arrays to compare corresponding elements.
This loop runs n times, resulting in a time complexity of O(n).
Overall Time Complexity:
The sorting step dominates, so the overall time complexity is: O(nlogn)
  
** Space Complexity :- **
  
In-place sorting:
The sort function sorts the arrays in place, requiring O(1) extra space.
No additional arrays or data structures are used in the code.
Auxiliary variables:
The algorithm uses a few integer variables (ans, i) for the loop and conditions, which require constant space: O(1).
Overall Space Complexity:
The total space complexity is: O(1)
