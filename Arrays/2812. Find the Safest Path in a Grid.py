from collections import deque

class Solution:
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    def canReachEnd(self,distance,safeness):
        n = len(distance)
        if distance[0][0] < safeness:
            return False
        visited = [[False] * n for _ in range(n)]
        queue = deque([(0, 0)])
        visited[0][0] = True
            
        while queue:
            r, c = queue.popleft()
            if r == n - 1 and c == n - 1:
                return True
            for dr, dc in Solution.directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc] and distance[nr][nc] >= safeness:
                    visited[nr][nc] = True
                    queue.append((nr, nc))
        return False    
    
    
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
    
        # Step 1: Multi-source BFS to find minimum distances to any thief
        distance = [[float('inf')] * n for _ in range(n)]
        queue = deque()
        
        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    queue.append((r, c))
                    distance[r][c] = 0
        
        
        while queue:
            r, c = queue.popleft()
            for dr, dc in Solution.directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and distance[nr][nc] == float('inf'):
                    distance[nr][nc] = distance[r][c] + 1
                    queue.append((nr, nc))
        
        # Step 2: Binary search to find the maximum safeness factor
        low, high = 0, n + n - 2
        result = 0
        
        while low <= high:
            mid = (low + high) // 2
            if self.canReachEnd(distance,mid):
                result = mid
                low = mid + 1
            else:
                high = mid - 1
        
        return result
