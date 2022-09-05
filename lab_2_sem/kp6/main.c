#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "io.h"

void generate(){
    FILE *in_txt = fopen("input.txt", "r");
    FILE *db = fopen("database", "wb");

    passenger me;
    while (read_txt(&me, in_txt)) {
        write_bin(&me, db);
    }
    
    fclose(in_txt);
    fclose(db);
}

void solve(FILE *db, int p){
    // find mid count of things
    fseek (db, 0 , SEEK_SET);
    passenger now;
    int cnt = 0, mid = 0;
    while(read_bin(&now, db)){
        mid += now.count_of_things;
        cnt++;
    }
    mid /= cnt;
    
    // find more p
    cnt = 0;
    fseek (db, 0 , SEEK_SET);    
    for (int i = 0; i < 95; i++) printf("-");
    printf("\n");

    while(read_bin(&now, db)){
        if (now.count_of_things - mid >= p){
            cnt++;
            print_one(&now, stdout);
            for (int i = 0; i < 95; i++) printf("-");
            printf("\n");
        }
    }
    if (cnt == 0){
        printf("Nothing was found\n");
    }
}


int main(int argc, char *argv[]){
    
    generate(); 

    
    

    FILE *db = fopen("database", "rb");
    if (!db) {
        printf("unable to find file\n");
        return 2;
    }

    if (argc != 2 && argc != 3){
        printf("keys:\n -f to print database \n -p to solve task\n\n");
        return 1;
    }
    if (!strcmp(argv[1], "-f")){
        
        print_db(db);
    } else if (!strcmp(argv[1], "-p")){
        solve(db, atoi(argv[2]));
    } else {
        printf("keys:\n -f to print database \n -p to solve task\n\n");
        return 1;
    }

    

    fclose(db);
}
