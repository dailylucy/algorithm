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
    #s = time.time()
    network = dict()
    computers = int(input())
    pairs = int(input())
        
    # adjecent nodes info 
    for i in range(pairs):
        a, b = map(int, input().split())
        
        if a not in network.keys():
            network[a]=[b,]
        elif b not in network[a]:
            network[a].append(b)
            
        if b not in network.keys():
            network[b]=[a,]
        elif a not in network[b]:
            network[b].append(a)

    # count how many computers are infected 
    # recursion function call
    result=recur_worm(network, 1, [1])
    print(result)
    #print(time.time()-s)
