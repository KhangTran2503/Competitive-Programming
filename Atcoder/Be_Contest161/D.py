from sys import stdin,stdout
from queue import Queue

def solve(K):
    if K < 10: return K
    q = Queue()
    cnt = 0
    for i in range(1,10):
        q.put(i)

    while not q.empty():
        u = q.get()
        cnt += 1
        if cnt == K: return u

        r = u % 10
        if r != 0:
            q.put(10*u + r - 1)

        q.put(10*u + r)
        if r < 9:
            q.put(10*u + r +1)





K = int(stdin.readline())

stdout.write(str(solve(K)))

