# 알고리즘 문제 url
# https://programmers.co.kr/learn/courses/30/lessons/42583/solution_groups?language=python3&type=all

def solution(bridge_length, weight, truck_weights):
    answer = 0
    running = [[],[]]
    # fifo
    truck_weights.reverse()
    # print(truck_weights)

    # queue empty?
    # 
    while len(running[0]) or len(truck_weights):
        answer+=1

        # running trucks go to the next cell
        running[1] = list(map(lambda x: x+1, running[1]))

        #print(f"[+]answer = {answer}")        
        #print(f"[+]running[0] = {running[0]}")
        #print(f"[+]running[1] = {running[1]}")

        # if running value is over bridge_length, del
        if len(running[0]) and running[1][0]>bridge_length:
            del running[1][0]
            del running[0][0]

        if len(truck_weights):
            # pull out of the next waiting truck 
            next = truck_weights.pop()
            # running weights sum
            if sum(running[0])+next<=weight:
                running[0].append(next)
                running[1].append(1)
                #print("===running===")
                #print(running[0])
                #print(running[1])
                #print(next)
            else:
                truck_weights.append(next) 
    return answer
