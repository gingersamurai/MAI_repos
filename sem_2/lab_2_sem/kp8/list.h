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