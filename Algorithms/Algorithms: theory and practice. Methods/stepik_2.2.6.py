Задача на программирование: небольшое число Фибоначчи

Дано целое число 1≤n≤40, необходимо вычислить n-е число Фибоначчи (напомним, что F0=0, F1=1 и Fn=Fn−1+Fn−2 при n≥2).

Sample Input:
3

Sample Output:
2


def fib(n):
    arr = [0, 1]
    for i in range(2, n + 1):
        arr.append(arr[i - 1] + arr[i - 2])
    return arr[-1]


def main():
    n = int(input())
    print(fib(n))


if __name__ == "__main__":
    main()
