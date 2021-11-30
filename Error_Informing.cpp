#include "Error_Informing.h"
void Error_Info1() {
    printf("%s", "\nIncorrect input in command line.\nIt should consist of:");
    printf("%s", "\nfile input.txt output1.txt output2.txt");
    printf("%s", "\nor:");
    printf("%s", "\nrandom number_of_instances output1.txt output2.txt");
}
void Error_Info2() {
    printf("\nThe input file does not exist. Please check the spelling.");
    printf("\nIn this time the program will execute the random filling method to continue the current launch.");
}
void Error_Info3() {
    printf("\nThe first argument was sent in an incorrect form.");
    printf("\nIn this time the program will execute the random filling method to continue the current launch.");
}
void Error_Info4() {
    printf("\nThe first output file does not exist. Please check the spelling.");
    printf("\nIn this time the program will continue with the default output file placed in debug folder.");
}
void Error_Info5() {
    printf("\nThe second output file does not exist. Please check the spelling.");
    printf("\nIn this time the program will continue with the default output file placed in debug folder.");
}
void Error_Info6() {
    printf("\nThe size data was incorrect. The size should be less than 10000 and greater than 1.");
    printf("\nIn this time the program will execute the random filling method to continue the current launch.");
}
void Error_Info7() {
    printf("\nThe type of structure was incorrect.");
    printf("\nIn this time the program will execute the random filling method to continue the current launch.");
}
void Error_Info8() {
    printf("\nThere was a mistake during reading the lines. One of them was empty or larger than the specified size.");
    printf("\nIn this time the program will execute the random filling method to continue the current launch.");
}