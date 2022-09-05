# Отчет по курсовому проекту  9 по курсу
# "Фундаментальная информатика"

**студент группы:** М8О-110Б-21, Малышев Назим Бахтиярович\
**Контакты:** nazimmalyshev47@gmail.com\
**работа выполнена:** 30.06.2022\
**Преподаватель:** Никулин Сергей Петрович

## 1. Тема
сортировка и поиск

## 2. Цель работы
Овладеть навыками сортировки и поиска.

## 3. Задание
16 порядковый номер. варианты 5, 5

## 4. Оборудование 
**CPU:** amd ryzen 5 5500U\
**RAM:** 16 GB\
**SSD:** 512 GB\
**MONITOR:** 2560 x 1440

## 5. Программное обеспечивание 
**Операционная система семейства:** ubuntu, **версия** 20.04 LTS\
**Интерпретатор команд:** bash, **версия** 5.0.17(1)-release.\
**Система программирования**: --, **версия**-- \
**Редактор текстов:** vs code, **версия** 1.66.1\
**Утилиты операционной системы:** --\
**Прикладные системы и программы:** --

## 6. Идея, метод, алгоритм
1.  сортировка вставкой
    + перебираю l - длину префикса отсортированной части
    + после l ищу инверсию и меняю элементы местами, пока она есть
2. перемешивание
    + каждый элемент рандомно меняю с другим
3. разворот
    + перебираю первую половину 
    + смимметрично меняю местами со второй
4. бинпоиск
    + l - самый правый с ключем, который меньше или равен
    + r - самый левый, который строго больше
    + сдвигаю l и r друг к другу, пока они не станут соседними
    + если l подходит, возращаю его, иначе -1

# 7. Сценарий выполнения работы
1. реализация сортировки и поиска в sort.c sort.h
4. реализация основного файла main.c
5. настройка сборки и запуска проекта в makefile
6. тестирование
7. написание отчета 

# 8. Распечатка протокола

**main.c**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"


int main(){
    FILE *input = fopen("input", "r");
    item table[100];
    int size = 0;
    while (!feof(input)) {
        fscanf(input, "%f ", &table[size].key);
        fgets(table[size].value, MAXSIZE, input);
        size++;
    }
    size--;
  
    int q = -1;
    while (q != 6) {
        printf("---------------------------\n");
        printf("1 print table\n");
        printf("2 sort insert\n");
        printf("3 rando_shuffle with table\n");
        printf("4 reverse table\n");
        printf("5 binary searh in table\n");
        printf("6 exit\n");
        printf("--------------\n");
        printf("enter query: ");
        scanf("%d", &q);
        printf("---------------------------\n");
        if (q == 1) {
            printf("--------------START:\n");
            print_table(table, size);
            printf("--------------END\n");
        } else if (q == 2) {
            printf("before sort\n\n");
            print_table(table, size);
            sort(table, size);
            printf("after sort:\n\n");
            print_table(table, size);
        } else if (q == 3) {
            random_shuffle(table, size);
        } else if (q == 4) {
            reverse(table, size);
        } else if (q == 5) {
            float key;
            printf("enter key: ");
            scanf("%f", &key);
            int resid = binsearch(table, size, key);
            if (resid == -1) printf("there is no any item with this key\n");
            else printf("[key]: %f  [value]: %s\n", table[resid].key, table[resid].value);
        }
    }
    fclose(input);
}
```

**sort.h**
```c
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
```


**sort.c**
```c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void print_table(item table[], int size){
    for (int i = 0; i < size; i++) {
        printf("[key]: %f  [value]: %s\n", table[i].key, table[i].value);
    }
}

void swap(item *a, item *b){
    item c = *a;
    *a = *b;
    *b = c;
}

void sort(item table[], int size){ 
    for (int l = 0; l < size-1; l++){ 
        int i = l+1; 
        while(i > 0) {
            if (table[i].key < table[i-1].key) {
                // item buff = table[i];
                // table[i] = table[i-1];
                // table[i-1] = buff;
                swap(&table[i], &table[i-1]);
                // printf("%d %d\n", l, i);
                i--;
            } else {
                break;
            }
        }
    }
}

void random_shuffle(item table[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        swap(&table[i], &table[j]);
    }
}

void reverse(item table[], int size){
    for (int i = 0; i < size / 2; i++) {
        swap(&table[i], &table[size-1 - i]);
    }
}

int binsearch(item table[], int size, float key){
    int l = 0, r = size;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if (table[mid].key <= key) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (table[l].key != key) return -1;
    else return l;
}
```

**makefile**
```make
run : main
	./main
main : sort.o main.o
	gcc main.o sort.o -o main
sort.o : sort.c
	gcc -c sort.c -o sort.o
main.o : main.c 
	gcc -c main.c -o main.o

clean : 
	rm -rf main main.o sort.o

```

### пример работы
```
gingersamurai@matebook14:~/coding/lab/kp9$ make 
gcc -c sort.c -o sort.o
gcc -c main.c -o main.o
gcc main.o sort.o -o main
./main
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 1
---------------------------
--------------START:
[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

[key]: 6.453000  [value]: Там на неведомых дорожках 

[key]: 2.010000  [value]: И днём и ночью кот учёный

--------------END
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 2
---------------------------
before sort

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

[key]: 6.453000  [value]: Там на неведомых дорожках 

[key]: 2.010000  [value]: И днём и ночью кот учёный

after sort:

[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 2.010000  [value]: И днём и ночью кот учёный

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 6.453000  [value]: Там на неведомых дорожках 

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 3
---------------------------
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 1
---------------------------
--------------START:
[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 2.010000  [value]: И днём и ночью кот учёный

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

[key]: 6.453000  [value]: Там на неведомых дорожках 

--------------END
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 2
---------------------------
before sort

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 2.010000  [value]: И днём и ночью кот учёный

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

[key]: 6.453000  [value]: Там на неведомых дорожках 

after sort:

[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 2.010000  [value]: И днём и ночью кот учёный

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 6.453000  [value]: Там на неведомых дорожках 

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 4
---------------------------
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 1
---------------------------
--------------START:
[key]: 9.870000  [value]: Русалка на ветвях сидит; 

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 6.453000  [value]: Там на неведомых дорожках 

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 2.010000  [value]: И днём и ночью кот учёный

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

--------------END
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 2
---------------------------
before sort

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 6.453000  [value]: Там на неведомых дорожках 

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 2.010000  [value]: И днём и ночью кот учёный

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

after sort:

[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 2.010000  [value]: И днём и ночью кот учёный

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 6.453000  [value]: Там на неведомых дорожках 

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 1
---------------------------
--------------START:
[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 2.010000  [value]: И днём и ночью кот учёный

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 6.453000  [value]: Там на неведомых дорожках 

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

--------------END
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 4
---------------------------
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 4
---------------------------
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 1
---------------------------
--------------START:
[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 2.010000  [value]: И днём и ночью кот учёный

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 6.453000  [value]: Там на неведомых дорожках 

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

--------------END
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 5
---------------------------
enter key: 4.4
[key]: 4.400000  [value]: Идёт направо — песнь заводит,

---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 5
---------------------------
enter key: 4.5
there is no any item with this key
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 1
---------------------------
--------------START:
[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

[key]: 1.320000  [value]: Златая цепь на дубе том: 

[key]: 2.010000  [value]: И днём и ночью кот учёный

[key]: 3.500000  [value]: Всё ходит по цепи кругом; 

[key]: 4.400000  [value]: Идёт направо — песнь заводит,

[key]: 5.500000  [value]: Налево — сказку говорит. 

[key]: 6.453000  [value]: Там на неведомых дорожках 

[key]: 7.600000  [value]: Следы невиданных зверей;

[key]: 8.567000  [value]: Там чудеса: там леший бродит, 

[key]: 9.870000  [value]: Русалка на ветвях сидит; 

--------------END
---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 5
---------------------------
enter key: 5.5
[key]: 5.500000  [value]: Налево — сказку говорит. 

---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 5
---------------------------
enter key: 9.87
[key]: 9.870000  [value]: Русалка на ветвях сидит; 

---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 5
---------------------------
enter key: 0.002
[key]: 0.002000  [value]: У лукоморья дуб зелёный;  

---------------------------
1 print table
2 sort insert
3 rando_shuffle with table
4 reverse table
5 binary searh in table
6 exit
--------------
enter query: 6
---------------------------
```


## 9. Дневник отладки
--

## 10. Замечания автора
--
## 11. Выводы
В ходе выполнения данной лабораторной работы я составил программу на языке Си с 
использованием процедур и функций для сортировки таблицы заданным методом и двоичного 
поиска по ключу в таблице.