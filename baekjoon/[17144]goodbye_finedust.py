import copy

def print_area(a):
    for l in a:
        print(l)


def upper_shift(a, idx1):
    for r in reversed(range(idx1-1)):
        a[r+1][0]=a[r][0]
    for i in range(1,len(a[0])):
        a[0][i-1]=a[0][i]
    for r in range(idx1):
        max_c = len(a[0])-1
        a[r][max_c] = a[r+1][max_c]
    for i in range(2,len(a[0])):
        a[idx1][i]=a[idx1][i-1]
    a[idx1][1]=0

    
def lower_shift(a, idx2):
    max_r = len(a) -1 
    max_c = len(a[0])-1
    for r in range(idx2+1, max_r):
        a[r][0] = a[r+1][0]    
    for i in range(0,max_c):
        a[max_r][i]=a[max_r][i+1]
    for r in reversed(range(idx2,max_r)):
        a[r+1][max_c]=a[r][max_c]        
    for i in range(1,max_c):
        a[idx2][i+1]=a[idx2][i]
    a[idx2][1]=0           


def aircleaner(a, lo_idx):
    upper_shift(a, lo_idx)
    lower_shift(a, lo_idx+1)


def finedust_spreads(area, r, c, acidx1, acidx2):
    result = copy.deepcopy(area)
    # finedust spreads 
    for i in range(r):
        for j in range(c):

            # if the area is for the air cleaner -> continue
            if area[i][j] < 1:
                continue
            count = 4
            spread = 0
            spread = area[i][j]//5
            #points = [[],[],[],[]]
            # bottom row    
            if i==r-1:
                count -= 1
            elif i<r-1:
                if not (area[i+1][j]==-1):
                    result[i+1][j] = result[i+1][j] + spread
                    #1. south
                    print("[1] RESULT")
                    print_area(result)
            if not i:
                count -= 1
            else:
                if not (area[i-1][j]==-1):
                    result[i-1][j]= result[i-1][j] + spread
                    #2. north
                    print("[2] RESULT")
                    print_area(result)
                
            # last col
            if j==c-1:    
                count -= 1
                result[i][j-1] = result[i][j-1] + spread
            else:
                if not j:
                    count-=1
                    if i==acidx1-1:
                        count-=1
                    else:
                        if i<r-1:
                            print("debug")
                            result[i+1][j] = result[i+1][j] + spread
                            #3.
                            print("[3] RESULT")
                            print_area(result)
                        
                    if i==acidx2-1:
                        count-=1
                    else:
                        if i>0:
                            result[i-1][j] = result[i-1][j] + spread
                            #4.
                            print("[4] RESULT")
                            print_area(result)
                        

                elif j==1:
                    if i==acidx1 or i==acidx2:
                        count-=1
                    else:
                        result[i][j-1] = result[i][j-1] + spread
                        #5.
                        print("[5] RESULT")
                        print_area(result)
                
                result[i][j+1] = result[i][j+1] + spread


                
            print(f"area[{i}][{j}] = {area[i][j]}\nspread = {spread}\ncount = {count}")
            print_area(result)
            result[i][j] = result[i][j] - spread*count
            print(f"area[{i}][{j}] = {area[i][j]}\n")

    print(f"+++ INPUT +++")
    print_area(area)
            
    print(f"+++ BEFORE calling aircleaner  +++")
    print_area(result)
    aircleaner(result, acidx1)
    

    print(f"+++ RESULT +++")
    print_area(result)
    return result


if __name__=="__main__":
    r, c, t = map(int, input().split())
    area = list()
    sum_area = 0 
#    result = list()
    for i in range(r):
        area.append(list(map(int, input().split())))

#    result = copy.deepcopy(area)
    acidx1 = -1
    acidx2 = -1
    #result = list(area)
    print_area(area)
    # check where air cleaner is located
    for k in range(r):
        if area[k][0]==-1:
            acidx1 = k
            acidx2 = k+1
            break

    for i in range(t):
        area = copy.deepcopy(finedust_spreads(area,r,c,acidx1,acidx2))

    for i in range(r):
        sum_area += sum(area[i])

    print(f"finedust_sum = {sum_area+2}")
