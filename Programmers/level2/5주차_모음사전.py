answer = 0

def recur(s, word):
    if s == word:
        return True
    if len(s) >= 5:
        return False
    
    global answer
    for alphabet in 'AEIOU':
        answer += 1
        if recur(s + alphabet, word):
            return True

def solution(word):
    recur('', word)
    global answer
    return answer
