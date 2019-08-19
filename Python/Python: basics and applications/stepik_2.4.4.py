#Вам дается текстовый файл, содержащий некоторое количество непустых строк.
#На основе него сгенерируйте новый текстовый файл, содержащий те же строки в обратном порядке.

#Пример входного файла:
#ab
#c
#dde
#ff

#﻿Пример выходного файла:
#ff
#dde
#c
#ab


with open("input.txt", "r") as inp, open("out.txt", "w") as out:
    body = [i for i in inp.read().splitlines()]
    body.reverse()
    out.write("\n".join(body))
