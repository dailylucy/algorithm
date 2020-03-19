#import time
import queue

if __name__ == "__main__":
    
    computers = int(input())
    network = [[]]*computers
    pairs = int(input())
    q = queue.Queue()
    
    #s = time.time()
    for i in range(pairs):
        a, b = map(int, input().split())
        network[a-1] = list(set(network[a-1]+[b]))
        network[b-1] = list(set(network[b-1]+[a]))

    visited = list()
    q.put(1)
    cur_node = 1
    
    while not q.empty():
        cur_node = q.get()
        #print(f"[=>]current node {cur_node}")
        for i in network[cur_node-1]:
            #print(f"[+] {i} >> Queue")
            q.put(i)
            
        if cur_node not in visited:
            visited.append(cur_node)
            #del network[cur_node-1][:]
            network[cur_node-1].clear()

    #print(network)

    print(len(visited)-1)
#    print(time.time()-s)
    
