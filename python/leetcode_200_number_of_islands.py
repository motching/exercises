#!/usr/bin/python3

class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        res = 0
        for r in range(len(grid)):
            for c in range(len(grid[r])):
                if ('1' == grid[r][c]):
                    res += 1
                    self.traverse(grid, r, c)
        return res

    def traverse(self, grid, r, c):
        #left
        if c>0 and grid[r][c-1] == '1':
            grid[r][c-1] = '0'
            self.traverse(grid, r, c-1)
        #up
        if r>0 and grid[r-1][c] == '1':
            grid[r-1][c] = '0'
            self.traverse(grid, r-1, c)
        #right
        if c+1<len(grid[r]) and grid[r][c+1] == '1':
            grid[r][c+1] = '0'
            self.traverse(grid, r, c+1)
        #down
        if r+1<len(grid) and grid[r+1][c] == '1':
            grid[r+1][c] = '0'
            self.traverse(grid, r+1, c)

print (Solution().numIslands([['1','1','1','1','0'],
                              ['1','1','0','1','0'],
                              ['1','1','0','0','1'],
                              ['0','0','0','1','1']]))
