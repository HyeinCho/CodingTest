T = int(input())
for test_case in range(1, T + 1):
    a, b = map(int, input().split())
    c = ''
    if a < b:
        c = '<'
    elif a == b:
        c = '='
    else:
        c = '>'
    print(f'#{test_case} {c}')
