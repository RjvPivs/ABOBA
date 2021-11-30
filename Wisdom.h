#ifndef ACS_TFW_SAVENKO_WISDOM_H
#define ACS_TFW_SAVENKO_WISDOM_H
#include "Aphorism.h"
#include "Proverb.h"
#include "Riddle.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
// Перечисление для определения типа сущности.
enum value {
    APHORISM, PROVERB, RIDDLE
};
// Структура Кладезь мудрости.
struct Wisdom {
    // Значение для удобства "распаковки".
    enum value val;
    union {
        // Хранящаяся внутри кладезя афоризма.
        Aphorism* aph;
        // Хранящаяся внутри кладезя полговорка.
        Proverb* prov;
        // Хранящаяся внутри кладезя загадка.
        Riddle* rid;
    };
    // Содержимое кладезя.
    char* content;
};
#endif //ACS_TFW_SAVENKO_WISDOM_H
