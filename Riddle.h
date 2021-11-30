#ifndef ACS_TFW_SAVENKO_RIDDLE_H
#define ACS_TFW_SAVENKO_RIDDLE_H
#include <string.h>
// Структура Загадка.
struct Riddle {
    // Ответ на загадку.
    char* answer;
};
// Замена содержимого загадки.
void Change_Riddle(Riddle* new_riddle, char* answer_external);
#endif //ACS_TFW_SAVENKO_RIDDLE_H
