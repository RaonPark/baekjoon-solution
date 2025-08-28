n = int(input())

cards = list(map(int, input().split(" ")))

dp = [[-1 for _ in range(n)] for _ in range(len(cards))]

def solve(selected: int, count: int) -> int:
    if(count == n):
        return 0
    elif(selected >= len(cards)):
        return 98754321
    
    if(dp[selected][count] != -1):
        return dp[selected][count]
    
    dp[selected][count] = solve(selected + 1, count)

    if(count + selected + 1 <= n):
        dp[selected][count] = min(dp[selected][count], solve(selected + 1, count + selected + 1) + cards[selected], solve(selected, count + selected + 1) + cards[selected])

    return dp[selected][count]

print(solve(0, 0))
