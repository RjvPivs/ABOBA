#include "Aphorism.h"
void Change_Aphorism(Aphorism* new_aphorism, char* author_external) {
    new_aphorism->author = new char[strlen(author_external)];
    new_aphorism->author = author_external;
}