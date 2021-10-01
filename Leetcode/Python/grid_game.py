'''
2017 - Grid Game - Medium
Link to the problem: https://leetcode.com/problems/grid-game/
Problem Description:
You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.

The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.

Example 1:
Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.
'''

'''
Approach:
The goal of Robot 1 is to leave the Robot 2 with such a path that it get's the minimum score.

We do a suffix sum of the first row so that we know what is the score we would get if we follow ahead of that path.

We do a prefix sum of the second row so that we keep track of what is the score we scored till now if we followed the path.

Note: we cannot go upwards, once we are down.

While Robot 1 is trying to leave with a path so that it minimizes the score for Robot 2, Robot 2 will try to score the maximum of the available path.
'''

def robotOneStrategy(temp, cS):
    # Doing a suffix sum of first row
    for j in range(cS-1,0,-1):
        temp[0][j] = temp[0][j]+temp[0][j+1] 

    # Doing a prefix sum of the second row
    for i in range(1,cS):
        temp[1][i] = temp[1][i]+temp[1][i-1]

    minVal = float('inf')
    for i in range(cS+1):
        # If robot 1 gets down at the start of the grid
        if i==0:
            minVal = min(minVal, temp[0][i+1])
        # If robot 1 gets down at the end of the grid
        if i==cS:
            minVal = min(minVal, temp[1][i-1])
        else:
            minVal = min(minVal, max(temp[0][i+1],temp[1][i-1]))
    return minVal
    
def gridGame(grid) -> int:
    cS = len(grid[0])-1
    # Making the start and the end point as zero
    grid[0][0], grid[1][cS] = 0,0
    return robotOneStrategy(grid, cS)

def main():
    # Test Case: 1
    grid = [[2,5,4],[1,5,1]]
    sol = gridGame(grid)
    print(sol)

    # Test Case: 2
    grid = [[1,3,1,15],[1,3,3,1]]
    sol = gridGame(grid)
    print(sol)


if __name__ == "__main__":
    main() 