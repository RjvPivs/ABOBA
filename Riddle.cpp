#include "Riddle.h"
void Change_Riddle(Riddle* new_riddle, char* answer_external) {
    new_riddle->answer = new char[strlen(answer_external)];
    new_riddle->answer = answer_external;
}