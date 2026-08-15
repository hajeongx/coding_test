def solution(babbling):
    answer = 0
    for b in babbling:
        if not b.replace("aya","ma").replace("ye","ma").replace("woo","ma").replace("ma",""):
            answer += 1
    return answer
