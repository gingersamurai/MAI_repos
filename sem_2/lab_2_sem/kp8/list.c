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