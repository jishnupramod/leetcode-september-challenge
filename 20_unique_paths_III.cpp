/*
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Note:

1 <= grid.length * grid[0].length <= 20
*/



class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void backtrack(vector<vector<int>>& g, int sx, int sy, int ex, int ey, map<pair<int, int>, bool>& seen, int& paths, int spaces) {
        if (sx == ex and sy == ey and seen.size() == spaces) {
            ++paths;
            return;
        }
        for (pair<int, int> p : dirs) {
            int nx = sx + p.first, ny = sy + p.second;
            if (nx >= 0 and nx < g.size() and ny >= 0 and ny < g[0].size() and g[nx][ny] == 0 and !seen[{nx, ny}]) {
                seen[{nx, ny}] = true;
                backtrack(g, nx, ny, ex, ey, seen, paths, spaces);
                seen[{nx, ny}] = false;
                seen.erase({nx, ny});
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx, sy, ex, ey, spaces = 0, paths = 0;
        sx = sy = ex = ey = -1;
        map<pair<int, int>, bool> seen;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                    grid[i][j] = 0;
                } if (grid[i][j] == 2) {
                    ex = i;
                    ey = j;
                    grid[i][j] = 0;
                } if (grid[i][j] == 0)
                    ++spaces;
            }
        }
        seen[{sx, sy}] = true;
        backtrack(grid, sx, sy, ex, ey, seen, paths, spaces);
        return paths;
    }
};
