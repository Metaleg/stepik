В первой строке дано три числа, соответствующие некоторой дате date -- год, месяц и день.
Во второй строке дано одно число days -- число дней.

Вычислите и выведите год, месяц и день даты, которая наступит, когда с момента исходной даты date пройдет число дней, равное days.

Примечание:
Для решения этой задачи используйте стандартный модуль datetime.
Вам будут полезны класс datetime.date для хранения даты и класс datetime.timedelta﻿ для прибавления дней к дате.

Sample Input 1:
2016 4 20
14

Sample Output 1:
2016 5 4

Sample Input 2:
2016 2 20
9

Sample Output 2:
2016 2 29

Sample Input 3:
2015 12 31
1

Sample Output 3:
2016 1 1



import datetime

year, month, day = map(int, input().split())
d = datetime.date(year, month, day)
dd = datetime.timedelta(int(input()))

print((d + dd).year, (d + dd).month, (d + dd).day)
