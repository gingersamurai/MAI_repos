# Отчет по курсовому проекту  8 по курсу
# "Фундаментальная информатика"

**студент группы:** М8О-110Б-21, Малышев Назим Бахтиярович\
**Контакты:** nazimmalyshev47@gmail.com\
**работа выполнена:** 30.05.2022\
**Преподаватель:** Никулин Сергей Петрович

## 1. Тема
линейные списки

## 2. Цель работы
Овладеть навыками работы с линейными списками.

## 3. Задание
16 порядковый номер. варианты 3, 3, 2

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
1. барьерный элемент
    + указывает на себя
2. итератор
    + хранит указатель
    + для него реализованы функции для перемещения
3. задание
    + проход и проверка каждого элемента списка с помощью итератора 
    + если какой-то подходит, то удалять все элементы списка по очереди

# 7. Сценарий выполнения работы
1. реализация списка и итераторов в list.c list.h
4. реализация основного файла main.c
5. настройка сборки и запуска проекта в makefile
6. тестирование
7. написание отчета 

# 8. Распечатка протокола

**main.c**
```c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"



int main(){
    list *lst = list_create();
    int q = -1;
    while (1000-7 == 1000-7) {
        printf("----------------\n");
        printf("1) add element\n");
        printf("2) print list\n");
        printf("3) delete element\n");
        printf("4) print list size\n");
        printf("5) solve task\n");
        printf("6) exit\n");
        printf("----------------\n");
        printf("your query: ");
        scanf("%d", &q);
        if (q == 1){
            
            printf("enter data\n(1 - RED, 2 - GREEN, 3 - BLUE) :");
            int dt;
            scanf("%d", &dt);
            enum colors col;
            if (dt == 1) col = RED;
            else if (dt == 2) col = GREEN;
            else col = BLUE;
            node *new_node = node_create(col);

            printf("enter id: ");
            int id;
            scanf("%d", &id);
            list_insert(lst, id, new_node);
        } else if (q == 2) {
            if (lst->head == NULL) {
                return 1;
            }

            list_print(lst);
        } else if (q == 3){
            printf("enter id: ");
            int id;
            scanf("%d", &id);
            list_delete_element(lst, id);
        } else if (q == 4){
            printf("my list size: %d\n", lst->size);
        } else if (q == 5){
            printf("enter data\n(1 - RED, 2 - GREEN, 3 - BLUE) :");
            int dt;
            scanf("%d", &dt);
            enum colors col;
            if (dt == 1) col = RED;
            else if (dt == 2) col = GREEN;
            else col = BLUE;
            task(lst, col);
        } else if (q == 6){
            return 0;
        } else {
            printf("ERROR\n");
        }
    }
}
```

**list.h**
```c
#ifndef LIST_H
#define LIST_H

enum colors{RED, GREEN, BLUE};


typedef struct _node node;
struct _node{
    enum colors data;
    node *next;
};
typedef struct _iterator iterator;
struct _iterator{
    node *val;
};
typedef struct _list list;
struct _list{
    node *head;
    int size;
};

// вывод элемента из перечисления
void color_print(enum colors cur);


// создать вершину
node *node_create(enum colors data);



// создать итератор
iterator *iterator_create(list *cur_list);

// перейти к следующему итератору
void iterator_next(iterator *cur_it);

// для итератора сопоставить вершину
void iterator_set(iterator *cur_it, node *cur_node);

// вернуть вершину итератора
node *iterator_get(iterator *cur_it);




// создать список
list *list_create();

// вставить элемент в список
void list_insert(list *cur_list, int id, node *new_node);

// вывести список
void list_print(list *cur_list);

// удалить элемент из списка
void list_delete_element(list *cur_list, int id);

// очистить список если есть похожие на col
void task(list *cur_list, enum colors col);







#endif
```


**list.c**
```c
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void color_print(enum colors cur){
    if (cur == RED) {
        printf("RED");
    } else if (cur == GREEN) {
        printf("GREEN");
    } else {
        printf("BLUE");
    }
}

// NODE

node *node_create(enum colors data){
    node *resnode = (node *) malloc(sizeof(node));
    resnode->data = data;
    resnode->next = NULL;
    return resnode;
}


// ITERATOR

iterator *iterator_create(list *cur_list){
    iterator *res_it = (iterator *) malloc(sizeof(iterator));
    res_it->val = cur_list->head;
    return res_it;
}

void iterator_next(iterator *cur_it){
    if (cur_it->val != cur_it->val->next) {
        cur_it->val = cur_it->val->next;
    }
}

void iterator_set(iterator *cur_it, node *cur_node){
    cur_it->val = cur_node;
}

node *iterator_get(iterator *cur_it){
    return cur_it->val;
}


// LIST

list *list_create(){
    list *reslist = (list *) malloc(sizeof(list));
    reslist->head = NULL;
    reslist->size = 0;
    return reslist;
}

void list_insert(list *cur_list, int id, node *new_node){
    
    iterator *now_it = iterator_create(cur_list);
    if (cur_list->size == 0) {
        printf("FIRSTLY\n");
        cur_list->head = new_node;
        new_node->next = new_node;
        iterator_set(now_it, cur_list->head);
    } else if (id == 0) {
        printf("TOSTART\n");
        new_node->next = iterator_get(now_it);
        cur_list->head = new_node;
        iterator_set(now_it, cur_list->head);
    } else if (id == cur_list->size){
        printf("TOEND\n");
        while (iterator_get(now_it)->next != iterator_get(now_it)) {
            iterator_next(now_it);
            printf("ster\n");
        }
        iterator_get(now_it)->next = new_node;
        new_node->next = new_node;
    } else {
        for (int i = 0; i < id-1; i++) iterator_next(now_it);
        new_node->next = iterator_get(now_it)->next;
        iterator_get(now_it)->next = new_node;
    }
    cur_list->size++;
}

void list_print(list *cur_list){
    if (cur_list->size == 0) {
        printf("[ ]\n");
        return;
    }
    iterator *now_it = iterator_create(cur_list);
    printf("\nmy list : [ ");
    while(iterator_get(now_it)->next != iterator_get(now_it)) {
        color_print(iterator_get(now_it)->data);
        printf(" ");
        iterator_next(now_it);
    }
    color_print(iterator_get(now_it)->data);
    printf(" ]\n");
}

void list_delete_element(list *cur_list, int id){
    
    if (id > cur_list->size) return;
    iterator *now_it = iterator_create(cur_list);
    if (id == cur_list->size-1) {
        for (int i = 0; i < id-1; i++) iterator_next(now_it);
        free(iterator_get(now_it)->next);
        iterator_get(now_it)->next = iterator_get(now_it);
    } else if (id == 0) {
        cur_list->head = iterator_get(now_it)->next;
        free(iterator_get(now_it));
    } else {
        for (int i = 0; i < id-1; i++) iterator_next(now_it);
        node *buff = iterator_get(now_it)->next;
        iterator_get(now_it)->next = iterator_get(now_it)->next->next;
        free(buff);
    }
    cur_list->size--;
}

void task(list *cur_list, enum colors col){
    iterator *now_it = iterator_create(cur_list);
    int have = 0;
    while (iterator_get(now_it)->next != iterator_get(now_it)){
        if (iterator_get(now_it)->data == col) {
            have = 1;
            break;
        }
        iterator_next(now_it);
    }
    if (have == 1) {
        while (cur_list->size > 0) list_delete_element(cur_list, 0);
    }
}
```



**makefile**
```make
run : main
	./main
main : list.o main.o
	gcc main.o list.o -o main
list.o : list.c
	gcc -c list.c -o list.o
main.o : main.c 
	gcc -c main.c -o main.o

clean : 
	rm -rf main main.o list.o


```

### пример работы
```
gingersamurai@matebook14:~/coding/lab/kp8$ make 
gcc -c main.c -o main.o
gcc main.o list.o -o main
./main
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 1
enter data
(1 - RED, 2 - GREEN, 3 - BLUE) :1
enter id: 0
FIRSTLY
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 1
enter data
(1 - RED, 2 - GREEN, 3 - BLUE) :1
enter id: 0
TOSTART
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 1
enter data
(1 - RED, 2 - GREEN, 3 - BLUE) :3
enter id: 2
TOEND
ster
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 2

my list : [ RED RED BLUE ]
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 1
enter data
(1 - RED, 2 - GREEN, 3 - BLUE) :2
enter id: 1
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 2

my list : [ RED GREEN RED BLUE ]
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 3
enter id: 1
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 3
enter id: 0
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 2

my list : [ RED BLUE ]
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 1
enter data
(1 - RED, 2 - GREEN, 3 - BLUE) :1
enter id: 2
TOEND
ster
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 2

my list : [ RED BLUE RED ]
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 4
my list size: 3
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 5
enter data
(1 - RED, 2 - GREEN, 3 - BLUE) :2
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 2

my list : [ RED BLUE RED ]
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 5
enter data
(1 - RED, 2 - GREEN, 3 - BLUE) :1
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 2
[ ]
----------------
1) add element
2) print list
3) delete element
4) print list size
5) solve task
6) exit
----------------
your query: 6
gingersamurai@matebook14:~/coding/lab/kp8$ 

```


## 9. Дневник отладки
--

## 10. Замечания автора
--
## 11. Выводы
Мной была изучена такая структура, как разреженные матрицы.\
Разреженные матрицы – очень полезная структура,
которая может решать различные задачи
