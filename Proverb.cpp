#include "Proverb.h"
void Change_Proverb(Proverb* new_proverb, char* origin_external) {
    new_proverb->origin_country = new char[strlen(origin_external)];
    new_proverb->origin_country = origin_external;
}