def Answer(s):
    n = len(s)
    a = list(s)
    for i in range(1,n + 1):
        if n % i == 0:
            a[:i] = a[:i][::-1]
    return ''.join(a)

if __name__ == '__main__':
    n = int(input())
    s = input()
    print(Answer(s))
