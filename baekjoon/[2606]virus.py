#import time

def recur_worm(n, k, v):
    #print(f"[+] RECURSION STARTED {k}")
    sum = 0
    if k in n.keys():
        for i in n[k]:
            if i not in v:
                sum+=recur_worm(n,i,list(set(v + n[k])))
    sum+=1
    return sum


if __name__ == "__main__":
    
    count = 0
    network = dict()
    computers = int(input())
    pairs = int(input())

    # s = time.time()
    # adjecent nodes info
    # 개선1 : elif문으로 요소 중복 없도록 저장하였다가 else문으로 바꾸고 list(set())으로 변경
    # >> 미미한 감소.. 그래도 입력 pair 값이 많아지면 좀 효과가 있지 않을까.
    for i in range(pairs):
        a, b = map(int, input().split())
        
        if a not in network.keys():
            network[a]=[b,]
        #elif b not in network[a]:
        #    network[a].append(b)
        else:
            network[a].append(b)
            network[a] = list(set(network[a]))
        if b not in network.keys():
            network[b]=[a,]
        #elif a not in network[b]:
        #    network[b].append(a)
        else:
            network[b].append(a)
            network[b] = list(set(network[b]))

    # count how many computers are infected 
    # recursion function call
    # 개선2
    count = recur_worm(network, 1, [1])
    print(count)
    #print(time.time()-s)


