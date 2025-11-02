from collections import deque

class Solution:
    def numIslands(self, grid):
        if not grid:
            return 0

        r, c = len(grid), len(grid[0])
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        def valid(i, j):
            return 0 <= i < r and 0 <= j < c

        count = 0
        for i in range(r):
            for j in range(c):
                if grid[i][j] == '1':
                    count += 1
                    queue = deque([(i, j)])
                    grid[i][j] = '0'  # mark visited

                    while queue:
                        x, y = queue.popleft()
                        for dx, dy in directions:
                            new_x, new_y = x + dx, y + dy
                            if valid(new_x, new_y) and grid[new_x][new_y] == '1':
                                grid[new_x][new_y] = '0'
                                queue.append((new_x, new_y))

        return count
