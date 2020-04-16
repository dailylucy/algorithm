# 알고리즘 문제 url
# https://www.acmicpc.net/problem/10974

# 하나씩 배열의 숫자를 shift해서 순열 구하도록 함.
def shiftLeft(arr):
    temp = arr[0]
    arrlen = len(arr)
    for i in range(1,arrlen):
        arr[i-1] = arr[i]
    arr[arrlen-1] = temp
    
def dfs(arr):
    n = len(arr)
    if n==2:
        n1 = arr[0]
        n2 = arr[1]
        ret = [n1+' '+n2, n2+' '+n1]
        return ret

    elif n<2:
        return arr
    
    else:
        data = list()
        tmp = list(arr)
        for i in range(n):
            temp = tmp[0]
            res = dfs(tmp[1:])

            for idx, j in enumerate(res):
                res[idx] = temp+' '+j
            data += res
            shiftLeft(tmp)
        return data

def main():
    n = int(input())
    arr = [str(x+1) for x in range(n)]
    
    result = dfs(arr)
    result = sorted(result)
    for i in result:
        print(i)

main()
