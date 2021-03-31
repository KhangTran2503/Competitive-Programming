
def main():
    n = int(input())
    mark = {}
    for i in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        mark[name] = (scores[0]+scores[1]+scores[2])/3
    
    query_name=input()
    print('%.2f'%mark[query_name])

if __name__ == '__main__':
	 main()