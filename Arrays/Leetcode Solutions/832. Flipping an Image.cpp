** Leetcode Problem 832 :- **

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
To flip an image horizontally means that each row of the image is reversed.
For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
For example, inverting [0,1,1] results in [1,0,0].

Example 1:
Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

Example 2:
Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

** Code :- **

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> ans = image;
        for (int i = 0; i < image.size(); i++) {
            reverse(ans[i].begin(), ans[i].end());
            for (int j = 0; j < image.size(); j++) {
                if (ans[i][j] == 0) {
                    ans[i][j] = 1;
                } else {
                    ans[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Reversing Rows :
For each row, the algorithm calls reverse() to flip the row horizontally.
Each reversal operation is O(n), where n is the number of columns in the row.
Over m rows, this operation takes: O(m⋅n)
Inverting Elements :
After reversing, the algorithm iterates through each element in the row to invert its value.
This operation is also O(n) for each row and O(m⋅n) for the entire matrix.
Total Time Complexity :
Best Case: O(m⋅n)
Every row must be reversed and inverted.
Worst Case: O(m⋅n)
The algorithm always processes every element of the matrix.

** Space Complexity :- **

Output Matrix :
The algorithm creates a new matrix ans to store the flipped and inverted image, which requires: O(m⋅n)
Auxiliary Variables :
The algorithm uses a constant amount of extra space for temporary variables during operations like reversing rows and inverting elements.
Total Space Complexity :
Best Case: O(m⋅n) (when a new matrix is used).
Worst Case: O(m⋅n) (same as the best case).
