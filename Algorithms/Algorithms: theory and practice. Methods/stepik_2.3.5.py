Задача на программирование: наибольший общий делитель

По данным двум числам 1≤a,b≤2⋅10^9 найдите их наибольший общий делитель.

def gcd(a, b):
    if a == 0:
        return b
    elif b == 0:
        return a
    elif a >= b:
        return gcd(a % b, b)
    elif b >= a:
        return gcd(a, b % a)


def main():
    a, b = map(int, input().split())
    print(gcd(a, b))


if __name__ == "__main__":
    main()
