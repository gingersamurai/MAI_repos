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