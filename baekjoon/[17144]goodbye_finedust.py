def print_area(a):
    for l in a:
        print(l)

if __name__=="__main__":
    r, c, t = map(int, input().split())
    area = list()
    result = list()
    for i in range(r):
        area.append(list(map(int, input().split())))
        result.append([0 for x in range(c)])

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
                    result[i+1][j] = area[i+1][j] + spread
                    #1.
                    print_area(result)
            if not i:
                count -= 1
            else:
                if not (area[i-1][j]==-1):
                    result[i-1][j]= area[i-1][j] + spread
                    #2.
                    print_area(result)
                
            # last col
            if j==c-1:    
                count -= 1
            else:
                if not j:
                    count-=1
                    if i==acidx1-1:
                        count-=1
                    else:
                        if i<r-1:
                            print("debug")
                            result[i+1][j] = area[i+1][j] + spread
                            #3.
                            print_area(result)
                        
                    if i==acidx2-1:
                        count-=1
                    else:
                        if i>0:
                            result[i-1][j] = area[i-1][j] + spread
                            #4.
                            print_area(result)
                        

                elif j==1:
                    if i==acidx1 or i==acidx2:
                        count-=1
                    else:
                        result[i][j-1] = area[i][j-1] + spread
                        #5.
                        print_area(result)
                
                result[i][j+1] = area[i][j+1] + spread


                
            print(f"area[{i}][{j}] = {area[i][j]}\nspread = {spread}\ncount = {count}")
            print_area(result)
            result[i][j] = area[i][j] - spread*count
            print(f"area[{i}][{j}] = {area[i][j]}\n")

    print(f"+++ INPUT +++")
    print_area(area)
    print(f"+++ RESULT +++")
    print_area(result)
    # air cleaner works


#    print(area)

