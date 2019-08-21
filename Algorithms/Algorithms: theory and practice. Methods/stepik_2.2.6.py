Задача на программирование: небольшое число Фибоначчи

Дано целое число 1≤n≤40

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