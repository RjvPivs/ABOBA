#ifndef ACS_TFW_SAVENKO_APHORISM_H
#define ACS_TFW_SAVENKO_APHORISM_H
#include <string.h>
// Структура Афоризма.
struct Aphorism {
    // Автор афоризма.
    char* author;
};
// Замена содержимого афоризма.
void Change_Aphorism(Aphorism* new_aphorism, char* author_external);
#endif //ACS_TFW_SAVENKO_APHORISM_H
