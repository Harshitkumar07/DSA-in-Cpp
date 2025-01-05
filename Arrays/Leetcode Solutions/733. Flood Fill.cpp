** Leetcode Problem 733:- **

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. 
You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill: Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel). 
All pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation:
The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

** Code :- **

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int row, int col, int source, int color) {
        if (sr < 0 || sr >= row || sc < 0 || sc >= col)
            return;
        if (image[sr][sc] != source)
            return;
        image[sr][sc] = color;
        // left
        dfs(image, sr - 1, sc, row, col, source, color);
        // right
        dfs(image, sr + 1, sc, row, col, source, color);
        // top
        dfs(image, sr, sc + 1, row, col, source, color);
        // bottom
        dfs(image, sr, sc - 1, row, col, source, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int source = image[sr][sc];
        if (image[sr][sc] == color)
            return image;
        int row = image.size(), col = image[0].size();
        dfs(image, sr, sc, row, col, source, color);
        return image;
    }
};

** Time Complexity :- **
    
Depth-First Search (DFS) :
The dfs function is called recursively for each pixel in the connected region that matches the source color.
In the worst case, the entire grid may need to be visited if all pixels have the same color as the starting pixel. For a grid of size row×col, this means: O(row×col)
Best Case: The region to be filled is minimal, such as a single pixel or an already correctly filled area, resulting in fewer recursive calls. O(1)
Only the starting pixel is processed.
Boundary Checks and Coloring :
Each recursive call involves boundary checks and comparisons, both of which are O(1). These operations are performed for each visited pixel, contributing linearly to the overall time complexity.
Total Time Complexity :
Best Case: O(1)
If no recursion occurs (e.g., the starting pixel already has the target color).
Worst Case: O(row×col)
If all pixels in the grid are part of the connected region and need to be visited.

** Space Complexity :- **
    
Recursive Stack :
The depth of the recursion corresponds to the size of the connected region. In the worst case, the entire grid is part of the connected region, resulting in a stack depth of O(row×col).
Best Case: For minimal recursion, such as when only a single pixel is filled, the recursion depth is: O(1)
Input Storage :
The image grid is modified in place, so no additional space is required to store a copy of the grid.
Space Used for Input: O(1)
Other Storage :
Constant space is used for variables such as row, col, source, and color.
Space Used for Variables: O(1)
Total Space Complexity :
Best Case: O(1)
Minimal recursion depth and constant space usage.
Worst Case: O(row×col)
Maximum recursion depth due to visiting all pixels.
