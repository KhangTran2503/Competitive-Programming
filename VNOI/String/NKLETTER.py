def Answer(s1,s2):
    l = min(len(s1),len(s2))
    intersect_len = 0
    for i in range(l,0,-1):
       #print(s1[-i:],s2[:i])
        if s1[-i:] == s2[:i]:
            intersect_len = i
            break
    return len(s1) + len(s2) - intersect_len



if __name__ == '__main__':
    Sb = input()
    Se = input()
    print(Answer(Sb,Se))
