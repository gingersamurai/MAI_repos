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