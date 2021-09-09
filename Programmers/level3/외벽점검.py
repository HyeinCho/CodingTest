import itertools

def solution(n, weak, dist):
    answer = 0
    
    dist.sort(reverse=True)
    for i in range(len(dist)):
        # 1. 이동할 수 있는 거리의 조합
        # i + 1개의 dist를 사용했을 때
        permu = list(itertools.permutations(dist[:i+1]))
        for p in permu: # 각 조합을 돈다
            for j in range(len(weak)):
                circle_list = weak[j:] + [x + n for x in weak[:j]] # j번(시작)을 기준으로 취약지점 거리들
                
                c_idx = 0
                p_idx = 0
                while c_idx < len(weak) and p_idx < len(p):
                    now_location = circle_list[c_idx]
                    possible_dist = p[p_idx]
                    while c_idx < len(weak) and circle_list[c_idx] - now_location <= possible_dist:
                        c_idx += 1
                    
                    p_idx += 1
                
                if c_idx >= len(weak):
                    return i + 1
    
    return -1
