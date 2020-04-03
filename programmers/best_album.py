from collections import defaultdict

def solution(genres, plays):
    answer = []

    album = defaultdict(list)
    g_plays = defaultdict(int)
    songs = len(genres)

    # arrange k-v with album
    for i in range(songs):
        album[genres[i]].append([plays[i],i])
        g_plays[genres[i]]+=plays[i]
    #print(f"[Before]album = {album}")
    #print(f"[Before]g_plays = {g_plays}")

    g_plays = sorted(g_plays.items(), key=(lambda x:x[1]), reverse=True)

    #print(f"[After]album = {album}")
    #print(f"[After]g_plays = {g_plays}")

    for i in g_plays:
        if len(album[i[0]])>1:
            max1 = max(album[i[0]])
            for it in album[i[0]]:
                if max1[0] in it and max1[1]>it[1]:
                     max1 = it
            answer.append(max1[1])
            album[i[0]].remove(max1)

            max2 = max(album[i[0]])

            for it in album[i[0]]:
                if max2[0] in it and max2[1]>it[1]:
                     max2 = it
            answer.append(max2[1])
        else:
            max1 = max(album[i[0]])
            for it in album[i[0]]:
                if max1[0] in it and max1[1]>it[1]:
                     max1 = it            
            answer.append(max1[1])
            album[i[0]].remove(max1)

    #print(album)
    #print(answer)
    return answer
