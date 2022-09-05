#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "io.h"

int read_txt(passenger *now_passenger, FILE *in){
    fscanf(in, "%s %s %d %d %s %s %d %s",
        now_passenger->surname,
        now_passenger->initials,
        &now_passenger->count_of_things,
        &now_passenger->total_weight,
        now_passenger->destination,
        now_passenger->departure_time,
        &now_passenger->count_of_transfers,
        now_passenger->child_data
    );
    return !feof(in);
}

void write_bin(passenger *now_passenger, FILE *out){
    fwrite(
        now_passenger->surname,
        sizeof(now_passenger->surname[0]),
        sizeof(now_passenger->surname) / sizeof(now_passenger->surname[0]),
        out
    );
    fwrite(
        now_passenger->initials,
        sizeof(now_passenger->initials[0]),
        sizeof(now_passenger->initials) / sizeof(now_passenger->initials[0]),
        out
    );
    fwrite(
        &now_passenger->count_of_things,
        sizeof(now_passenger->count_of_things),
        1,
        out
    );
    fwrite(
        &now_passenger->total_weight,
        sizeof(now_passenger->total_weight),
        1,
        out
    );
    fwrite(
        now_passenger->destination,
        sizeof(now_passenger->destination[0]),
        sizeof(now_passenger->destination) / sizeof(now_passenger->destination[0]),
        out
    );
    fwrite(
        now_passenger->departure_time,
        sizeof(now_passenger->departure_time[0]),
        sizeof(now_passenger->departure_time) / sizeof(now_passenger->departure_time[0]),
        out
    );
    fwrite(
        &now_passenger->count_of_transfers,
        sizeof(now_passenger->count_of_transfers),
        1,
        out
    );
    fwrite(
        now_passenger->child_data,
        sizeof(now_passenger->child_data[0]),
        sizeof(now_passenger->child_data) / sizeof(now_passenger->child_data[0]),
        out
    );

}

int read_bin(passenger *now_passenger, FILE *in){
    fread(
        now_passenger->surname,
        sizeof(now_passenger->surname[0]),
        sizeof(now_passenger->surname) / sizeof(now_passenger->surname[0]),
        in
    );
    fread(
        now_passenger->initials,
        sizeof(now_passenger->initials[0]),
        sizeof(now_passenger->initials) / sizeof(now_passenger->initials[0]),
        in
    );
    fread(
        &now_passenger->count_of_things,
        sizeof(now_passenger->count_of_things),
        1,
        in
    );
    fread(
        &now_passenger->total_weight,
        sizeof(now_passenger->total_weight),
        1,
        in
    );
    fread(
        now_passenger->destination,
        sizeof(now_passenger->destination[0]),
        sizeof(now_passenger->destination) / sizeof(now_passenger->destination[0]),
        in
    );
    fread(
        now_passenger->departure_time,
        sizeof(now_passenger->departure_time[0]),
        sizeof(now_passenger->departure_time) / sizeof(now_passenger->departure_time[0]),
        in
    );
    fread(
        &now_passenger->count_of_transfers,
        sizeof(now_passenger->count_of_transfers),
        1,
        in
    );
    fread(
        now_passenger->child_data,
        sizeof(now_passenger->child_data[0]),
        sizeof(now_passenger->child_data) / sizeof(now_passenger->child_data[0]),
        in
    );
    return !feof(in);
}

void print_one(passenger* now_passenger, FILE *out){
    fprintf( 
        out,
        "| %-15s | %-4s | %-5d | %-5d | %-15s | %-5s | %-1d | %-20s |\n", 
        now_passenger->surname,
        now_passenger->initials,
        now_passenger->count_of_things,
        now_passenger->total_weight,
        now_passenger->destination,
        now_passenger->departure_time,
        now_passenger->count_of_transfers,
        now_passenger->child_data
    );
}

void print_db(FILE *db){
    passenger now_passenger;
    for (int i = 0; i < 95; i++) printf("-");
    printf("\n");
    while (read_bin(&now_passenger, db)){
        print_one(&now_passenger, stdout);
        for (int i = 0; i < 95; i++) printf("-");
        printf("\n");
    }
}

