def solution(money):
    answer = 0
    size = len(money)
    dp = [[0, 0] for _ in range(size)]
    
    # [첫번째 집을 선택한 경우, 선택하지 않은 경우]
    dp[0] = [money[0], 0]
    dp[1] = [max(money[1], money[0]), money[1]]
    
    for i in range(2, size):
        for j in range(2):
            if i == size - 1 and j == 0:
                dp[i][j] = dp[i-1][j]
                continue
            dp[i][j] = max(dp[i-2][j]+money[i], dp[i-1][j])
    
    answer = max(dp[-1])
            
    return answer
