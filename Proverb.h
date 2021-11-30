#ifndef ACS_TFW_SAVENKO_PROVERB_H
#define ACS_TFW_SAVENKO_PROVERB_H
#include <string.h>
// Структура Поговорка.
struct Proverb {
    // Страна происхождения загадки.
    char* origin_country;
};
// Замена содержимого поговорки.
void Change_Proverb(Proverb* new_proverb, char* origin_external);
#endif //ACS_TFW_SAVENKO_PROVERB_H
