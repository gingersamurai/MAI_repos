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