// Вам требуется реализовать функцию конкатенации (склейки) двух C-style строк. Функция конкатенации принимает на вход две C-style строки и дописывает 
// вторую в конец первой так, чтобы первая строка представляла из себя одну C-style строку равную конкатенации двух исходных.

// Не забудьте, что в результирующей строке должен быть только один нулевой символ — тот, что является маркером конца строки.

// Гарантируется, что в первой строке достаточно памяти (т.е. она располагается в массиве достаточной длины), чтобы разместить конкатенацию обеих строк, 
// но не больше.

// Требования к реализации: при выполнении задания вы можете определять любые вспомогательные функции, если они вам нужны. Выводить или вводить что-либо 
// не нужно. Функцию main определять не нужно.

void strcat(char *to, const char *from) {
    for (; *to != '\0'; ++to);
    for (; *to++ = *from++; );
}
