#!/usr/bin/python
direct = ['LEFT','DOWN','UP','RIGHT']

def displayPathtoPrincess(n,grid):

    move = n//2
    if grid[0][0] == 'p':
        for i in range(move): print(direct[2])
        for i in range(move): print(direct[0])

    if grid[0][n - 1] == 'p':
        for i in range(move): print(direct[2])
        for i in range(move): print(direct[3])

    if grid[n - 1][0] == 'p':
        for i in range(move): print(direct[1])
        for i in range(move): print(direct[0])

    if grid[n - 1][n - 1] == 'p':
        for i in range(move): print(direct[1])
        for i in range(move): print(direct[3])

    
    

m = int(input())
grid = [] 
for i in range(0, m): 
    grid.append(input().strip())

displayPathtoPrincess(m,grid)