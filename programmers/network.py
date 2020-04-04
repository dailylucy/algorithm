# 알고리즘 문제 url
# https://programmers.co.kr/learn/courses/30/lessons/43162

import queue

def print_info(c):
    for r in c:
        print(r)

def bfs(c,r):
    q = queue.Queue()
    visited = list()
    q.put(r)
    while not q.empty():
        r = q.get()
        if r in visited:
            continue
        visited.append(r)

        for idx, v in enumerate(c[r]):
            if v==1:
                q.put(idx)
                c[r][idx] = -1

    #print("===Terminate bfs===")
    #print_info(c)
    return 1


def solution(n, computers):
    answer = 0
    #print("===Start===")
    #print_info(computers)
    for row, info in enumerate(computers):
        if 1 in info:
            answer+=bfs(computers,row)

    return answer
