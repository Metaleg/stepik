// Напишите функцию поиска первого вхождения шаблона в текст. В качестве первого параметра функция принимает текст (C-style строка), в которой нужно 
// искать шаблон. В качестве второго параметра строку-шаблон (C-style строка), которую нужно найти. Функция возвращает позицию первого вхождения 
// строки-шаблона, если он присутствует в строке (помните, что в C++ принято считать с 0), и -1, если шаблона в тексте нет.

// Учтите, что пустой шаблон (строка длины 0) можно найти в любом месте текста.

// Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции, если они вам нужны. Вводить или выводить 
// что-либо не нужно. Реализовывать функцию main не нужно.

int strstr(const char *text, const char *pattern) {
    if (pattern == "" || *pattern == '\0')
        return 0;

    const char *src = text;
    for (; *text != '\0'; ++text) {
        const char * temp_pattern = pattern;
        const char * temp_text = text;
        bool flag = false;

        for (; *temp_pattern != '\0'; ++temp_pattern, ++temp_text) {
            if (*temp_pattern != *temp_text) {
                flag = false;
                break;
            }
            else
                flag = true;
        }
        if (flag)
            return text - src;
    }

    return -1;
}
