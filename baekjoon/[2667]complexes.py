import queue
def print_com(com):
    print(f"+++++++COMPLEX+++++++")
    for i in com:
        print(i)
        
def bfs(c, row, col):
    q = queue.Queue()
    
    q.put([row,col])
    count=0
    while not q.empty():
        cur_r, cur_c = q.get()
        if c[cur_r][cur_c] == -1:
            continue
        # north 
        if cur_r:
            if c[cur_r-1][cur_c] == 1:
                q.put([cur_r-1,cur_c])
                
        # east
        if not cur_c>n-2:
            if c[cur_r][cur_c+1] == 1:
                q.put([cur_r,cur_c+1])
                
        # south
        if not cur_r>n-2:
            if c[cur_r+1][cur_c] == 1:
                q.put([cur_r+1,cur_c])
                
        # west
        if cur_c:
            if c[cur_r][cur_c-1] == 1:
                q.put([cur_r,cur_c-1])
        c[cur_r][cur_c]=-1
        count+=1

    return count
    
if __name__=="__main__":
    comps = 0
    h_counts = list()
    n = int(input())
    comp = list()
    for i in range(n):
        comp.append(list(map(int,input())))
    for i in range(n):
        for j in range(n):
            if comp[i][j]==1:
                h_counts.append(bfs(comp,i,j))
                comps+=1

    print(comps)
    for i in sorted(h_counts):
        print(i)
        
