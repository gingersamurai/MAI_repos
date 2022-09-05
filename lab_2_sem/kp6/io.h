#ifndef io_h
#define io_h


#include <stdio.h>
#include "structure.h"

// считывает данные из текстового файла в указанную структуру
int read_txt(passenger *now_passenger, FILE *in);

// записывает данные из указанной структуры в бинарный файл
void write_bin(passenger *now_passenger, FILE *out);

// считывает данные из бинарного файла
int read_bin(passenger *now_passenger, FILE *in);

// красиво выводит одну одного пассажира
void print_one(passenger* now_passenger, FILE *out);

// красиво выводит базу данны
void print_db(FILE *db);
#endif