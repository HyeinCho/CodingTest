from collections import deque

N, d, k, c = map(int, input().split())  # 접시 수, 초밥 가짓수, 연속해서먹는접시 수, 쿠펀번호
sushi = [int(input()) for _ in range(N)]

answer = 0
cnt = 0
nums = [0] * (d + 1)
dq = deque()
for i in range(k):
    dq.append(sushi[i])
    if not nums[sushi[i]]:
        cnt += 1
    nums[sushi[i]] += 1

if answer < cnt:
    answer = cnt

for i in range(N - 1):
    dq.popleft()
    nums[sushi[i]] -= 1
    if not nums[sushi[i]]:  # 뺀 스시가 dq에 없으면 => 해당 종류는 없음
        cnt -= 1

    dq.append((i + k) % N)
    nums[sushi[(i + k) % N]] += 1
    if nums[sushi[(i + k) % N]] == 1:
        cnt += 1

    if nums[c]:
        answer = max(answer, cnt)
    else:
        answer = max(answer, cnt + 1)

print(answer)
