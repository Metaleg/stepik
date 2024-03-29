Задача на программирование: последняя цифра большого числа Фибоначчи

Дано число 1≤n≤107, необходимо найти последнюю цифру n-го числа Фибоначчи.

Как мы помним, числа Фибоначчи растут очень быстро, поэтому при их вычислении нужно быть аккуратным с переполнением. 
В данной задаче, впрочем, этой проблемы можно избежать, поскольку нас интересует только последняя цифра числа Фибоначчи: если 0≤a,b≤9
— последние цифры чисел Fi и Fi+1 соответственно, то (a+b)mod10 — последняя цифра числа Fi+2.

Sample Input:
317457

Sample Output:
2



def fib_digit(n):
    arr = [0, 1]
    for i in range(n - 1):
        arr.append((arr[i] + arr[i + 1]) % 10)
    return arr[-1]


def main():
    n = int(input())
    print(fib_digit(n))


if __name__ == "__main__":
    main()


