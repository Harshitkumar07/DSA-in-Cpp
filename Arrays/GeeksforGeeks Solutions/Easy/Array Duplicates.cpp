** Problem :- **

Given an array arr of integers, find all the elements that occur more than once in the array. If no element repeats, return an empty array.

Examples:

1. Input: arr[] = [2, 3, 1, 2, 3]
Output: [2, 3] 
Explanation: 2 and 3 occur more than once in the given array.

2. Input: arr[] = [0, 3, 1, 2] 
Output: [] 
Explanation: There is no repeating element in the array, so the output is empty.

3. Input: arr[] = [2]
Output: [] 
Explanation: There is single element in the array. Therefore output is empty.

** Code :- **

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                if(ans.empty()) {
                    ans.push_back(arr[i]);
                } else {
                    if(ans.back()!=arr[i]) ans.push_back(arr[i]);
                }
            }
        }
        return ans;
    }
};

** Time Complexity :- **
  
1. Sorting the Array
The array is sorted in ascending order using sort. The time complexity of sorting is: O(nlogn)
where n is the size of the input array.

2. Iteration and Comparison
The loop iterates through the array once, performing a constant-time comparison for adjacent elements and O(1) operations for checking and updating the ans vector.
The time complexity for this loop is O(n)
Overall Time Complexity
The dominant term is the sorting step. Therefore, the overall time complexity is: O(nlogn)

** Space Complexity :- **
  
In-place Sorting:
The sort function is an in-place algorithm, so no additional space is used for sorting.
Result Vector:
The ans vector stores duplicate elements. In the worst case, if all elements in the array are duplicates, the ans vector will use O(n) space.
Additional Variables:
Constant space is used for loop variables and temporary checks.
Overall Space Complexity : O(n)
