

def main():
    n,k = map(int,input().split())
    ls = map(int,input().split())
    arr = list(ls)
    res = 0
    for i in range(n-1):
        for j in range(i+1,n):
            if (arr[i]+arr[j])%k == 0: res+=1
    print(res)

main()
