#!/usr/bin/env python2

#Author: Stefan Toman

def dfs(cells, visited, x, y):
    r = 0
    if not visited[x][y] and cells[x][y]:
        r += 1
        visited[x][y] = True
        for i, j in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]:
            if 0 <= x+i < len(cells) and 0 <= y+j < len(cells[x]):
                if not visited[x+i][y+j] and cells[x+i][y+j]:
                    r += dfs(cells, visited, x+i, y+j)
    return r

if __name__ == '__main__':
    #read input
    n = int(raw_input())
    m = int(raw_input())
    cells = []
    for _ in xrange(n):
        cells.append(map(lambda x: x == "1", raw_input().split()))
    visited = [[False for _ in xrange(m)] for _ in xrange(n)]

    #run bfs
    r = 0
    for x in xrange(n):
        for y in xrange(m):
            if cells[x][y] and not visited[x][y]:
                r = max(r, dfs(cells, visited, x, y))

    #print result
    print r