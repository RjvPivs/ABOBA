#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "Wisdom.h"
#include "Error_Informing.h"
// Отключение предупреждений относительно устаревания библиотек и использования небезопасных структур.
#pragma warning(disable : 4996)
// Размер массива Wisdom`ов.
int size = 0;
// aboba
extern "C" double CountPunc(void* str, int len);
extern "C" void BinSort(void* arr, void* arr2, int len);
// Фиксированное число для работы со случайными заполнениями.
int random_num = 57;
// Массив для определения знаков пунктуации.
const char* punctuation = ".,!?-():;";
// Массив для формирования строки со случайным заполнением.
const char* alphabet = "abc-(def g.,hujk lmn!?opqrstuv:;wxyz)";
// Путь для дефолтного вывода.
const char* default_output_file1 = "output1.txt";
// Путь для дефолтного вывода.
const char* default_output_file2 = "output2.txt";
// Массив с экземплярами класса Wisdom.
Wisdom* arr = new Wisdom[10000];
int* ind = new int[10000];
double* keys = new double[10000];

void FillInd(){
    for (int i = 0; i < size; i++){
        ind[i] = i;
    }
}
// Функция проверки сущ-я файла.
bool File_Exists(char* filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}
// Функция формирования случайного типа сущностей.
int Random_type() {
    srand(time(NULL) + random_num++);
    return rand() % 3 + 1;
}
// Функция заполнения строки случайными значениями.
char* Random_Filling() {
    // Строка для заполнения.
    char* inp = new char[26];
    for (int i = 0; i < 25; i++) {
        // Позиция в массиве.
        int b = rand() % (strlen(alphabet));
        inp[i] = alphabet[b];
    }
    inp[25] = '\0';
    return inp;
}
// Метод заполнения массива из файла.
int Reading_the_data(char* input_file) {
    // Поток на считывание.
    FILE* fp = fopen(input_file, "r");
    fscanf(fp, "%d%*c", &size);
    if (size < 1 || size > 10000) {
        Error_Info6();
        fclose(fp);
        return 3;
    }
    for (int i = 0; i < size; i++) {
        // Переменная для хранения считываемых строк из файла.
        char* temp = new char[500];
        // переменная для хранения считываемого типа структуры.
        int status = 0;
        fscanf(fp, "%d%*c", &status);
        // Экземпляр структуры Кладезь мудрости.
        Wisdom wisd;
        if (status <= 0 || status > 3) {
            Error_Info7();
            fclose(fp);
            return 3;
        }
        switch (status) {
            case 1:
                fscanf(fp, "%[^\n]%*c", temp);
                if (strlen(temp) > 501) {
                    Error_Info8();
                    fclose(fp);
                    return 3;
                }
                wisd.content = temp;
                temp = new char[500];
                wisd.val = APHORISM;
                fscanf(fp, "%[^\n]%*c", temp);
                if (strlen(temp) > 501) {
                    Error_Info8();
                    fclose(fp);
                    return 3;
                }

                wisd.aph = new Aphorism;
                Change_Aphorism(wisd.aph, temp);
                arr[i] = wisd;
                temp = new char[500];
                break;
            case 2:
                fscanf(fp, "%[^\n]%*c", temp);
                if (strlen(temp) > 501) {
                    Error_Info8();
                    fclose(fp);
                    return 3;
                }
                wisd.content = temp;
                temp = new char[500];
                wisd.val = PROVERB;
                fscanf(fp, "%[^\n]%*c", temp);
                if (strlen(temp) > 501) {
                    Error_Info8();
                    fclose(fp);
                    return 3;
                }
                wisd.prov = new Proverb;
                Change_Proverb(wisd.prov, temp);
                arr[i] = wisd; temp = new char[500];
                break;
            case 3:
                fscanf(fp, "%[^\n]%*c", temp);
                if (strlen(temp) > 501) {
                    Error_Info8();
                    fclose(fp);
                    return 3;
                }
                wisd.content = temp;
                temp = new char[500];
                wisd.val = RIDDLE;
                fscanf(fp, "%[^\n]%*c", temp);
                if (strlen(temp) > 501) {
                    Error_Info8();
                    fclose(fp);
                    return 3;
                }
                wisd.rid = new Riddle;
                Change_Riddle(wisd.rid, temp);
                arr[i] = wisd;
                temp = new char[500];
                break;
        }
    }
    fclose(fp);
    return 1;
}
// Метод случайного заполнения массива.
void Random_Forming(){
    for (int i = 0; i < size; i++) {
        int type = Random_type();
        // Экземпляр структуры Кладезь мудрости.
        Wisdom wisd;
        wisd.content = Random_Filling();
        switch (type) {
            case 1:
                wisd.val = APHORISM;
                wisd.aph = new Aphorism;
                Change_Aphorism(wisd.aph, Random_Filling());
                arr[i] = wisd;
                break;
            case 2:
                wisd.val = PROVERB;
                wisd.prov = new Proverb;
                Change_Proverb(wisd.prov, Random_Filling());
                arr[i] = wisd;
                break;
            case 3:
                wisd.val = RIDDLE;
                wisd.rid = new Riddle;
                Change_Riddle(wisd.rid, Random_Filling());
                arr[i] = wisd;
                break;
        }
    }
}
// Метод вычисления значения для сортировки. Ф-ия, общая для всех альтернатив.
void AltFun() {
    for (int i = 0; i < size; i++) {
        Wisdom wis = arr[i];
        // Длина строки.
        int nn = strlen(wis.content);
        keys[i] = CountPunc(wis.content, nn);
    }
}
// Метод заполнения первого выходного файла.
void File_Inp(char* output_file){
    // Файловый поток на вывод.
    FILE* fpp = fopen(output_file, "w+");
    fprintf(fpp, "There are ");
    fprintf(fpp, "%d", size);
    fprintf(fpp, " examples in array.");
    fprintf(fpp, "\n");
    for (int i = 0; i < size; i++) {
        switch (arr[i].val)
        {
            case APHORISM:
                fprintf(fpp, arr[ind[i]].content);
                fprintf(fpp, "\n");
                fprintf(fpp, arr[ind[i]].aph->author);
                break;
            case PROVERB:
                fprintf(fpp, arr[ind[i]].content);
                fprintf(fpp, "\n");
                fprintf(fpp, arr[ind[i]].prov->origin_country);
                break;
            case RIDDLE:
                fprintf(fpp, arr[ind[i]].content);
                fprintf(fpp, "\n");
                fprintf(fpp, arr[ind[i]].rid->answer);
                break;
        }
        fprintf(fpp, "\n");
    }
    fclose(fpp);
}
int main(int argc, char* argv[]) {
    // Значения для определения поведения программы.
    int checker;
    if (argc != 5) {
        Error_Info1();
        return 1;
    }
    printf("%s", "Now we are ready to start!");
    // Файл ввода.
    char* input_file = new char[300];
    // Файл вывода.
    char* output_file1 = new char[300];
    // Файл вывода.
    char* output_file2 = new char[300];
    if (strcmp(argv[1], "file") == 0) {
        if (File_Exists(argv[2])) {
            printf("\nInput file does exist");
            strcpy(input_file, argv[2]);
            checker = 1;
        }
        else {
            Error_Info2();
            checker = 2;
        }
    }
    else if (strcmp(argv[1], "random") == 0) {
        printf("\nThe program will execute the random filling method.");
        size = atoi(argv[2]);
        if (size <= 0 || size > 10000) {
            srand(time(NULL));
            size = rand() % 10 + 1;
        }
        checker = 2;
    }
    else {
        Error_Info3();
        checker = 2;
        srand(time(NULL));
        size = rand() % 10 + 1;
    }
    if (File_Exists(argv[3])) {
        printf("\nOutput file 1 does exist");
        strcpy(output_file1, argv[3]);
    }
    else {
        Error_Info4();
        strcpy(output_file1, default_output_file1);
    }
    if (File_Exists(argv[4])) {
        printf("\nOutput file 2 does exist");
        strcpy(output_file2, argv[4]);
    }
    else {
        Error_Info5();
        strcpy(output_file2, default_output_file2);
    }
    if (checker == 1) {
        checker = Reading_the_data(input_file);
    }
    if (checker != 1) {
        if (checker == 3) {
            srand(time(NULL));
            size = rand() % 10 + 1;
            arr = new Wisdom[size];
        }
        Random_Forming();
    }
    File_Inp(output_file1);
    BinSort(arr, keys, size);
    File_Inp(output_file2);
    printf("\nThis is the end of our journey. Thank you for joining us today!");
    free(arr);
}