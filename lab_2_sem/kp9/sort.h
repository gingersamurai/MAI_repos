#ifndef SORT_H
#define SORT_H

#define MAXSIZE 1000 

typedef struct _item item;
struct _item{
   float key;
   char value[MAXSIZE];
};

// напечатать таблицу
void print_table(item table[], int size);

// поменять местами
void swap(item *a, item *b);

// сортировка вставкой
void sort(item table[], int size);

// перемешать элементы таблицы
void random_shuffle(item table[], int size);

// развернуть таблицу
void reverse(item table[], int size);

// бинарный поиск по ключу
int binsearch(item table[], int size, float key);





#endif