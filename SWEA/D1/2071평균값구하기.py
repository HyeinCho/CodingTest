T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    total = 0
    a = input()
    ls = a.split()
    for i in ls:
        total += int(i)
    print(f'#{test_case} {round((total / 10))}')
