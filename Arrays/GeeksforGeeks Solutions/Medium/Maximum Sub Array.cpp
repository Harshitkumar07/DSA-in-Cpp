** Problem :- **

Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
a = [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length.
If there is still a tie, then return the segment with minimum starting index.
If no such subarray is present return "-1"

Examples:

1. Input:n = 3
a[] = {1, 2, 3}
Output: 1 2 3
Explanation: In the given array every
element is non-negative.

2. Input: n = 2
a[] = {-1, 2}
Output: 2
Explanation: The only subarray [2] is
the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

** Code :- **

class Solution {
  public:
    vector<int> findSubarray(int n, int a[]) {
        int Max = 0;
	    int sum=0;
	    int ansStart =-1;
	    int ansEnd = -1;
	    int start =0;
	    for(int i=0;i<n;i++){
	        if(a[i] <0)
	        {
	            sum =0;
	            start = i+1;
	            continue;
	        }
	        sum = sum+a[i];
	        if(sum>Max){
	            Max = sum;
	            ansStart = start;
	            ansEnd = i;
	        }
	        else if(sum == Max){
	            if((i - start) > (ansEnd - ansStart))
	            {
	                ansStart = start;
	                ansEnd = i;
	            }
	        }
	    }
	    vector<int> ans;
	    for(int  i=ansStart;i<=ansEnd;i++){
	        ans.push_back(a[i]);
	    }
	    if(ans.size() ==0){
	        return {-1};
	    }
	    return ans;
    }
};

** Time Complexity :- **
	
Iterating Through the Array:
The loop iterates through all n elements, performing constant-time operations for each element.
Complexity:O(n)
Constructing the Result Subarray:
If a valid subarray exists, the loop runs over the indices from ansStart to ansEnd. In the worst case, this involves all n elements.
Complexity: O(n)

Overall Time Complexity: O(n)
	
** Space Complexity :- **
	
Auxiliary Variables:
Uses a constant amount of space for variables (Max, sum, start, ansStart, ansEnd).
Complexity: O(1)
Result Vector:
Stores the resulting subarray, which can have at most n elements in the worst case.
Complexity: O(n)
	
Overall Space Complexity: O(n)
