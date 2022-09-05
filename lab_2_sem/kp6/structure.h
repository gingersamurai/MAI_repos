#ifndef passenger_h
#define passenger_h


#define MAXSIZE 64

typedef struct {
    char surname[MAXSIZE];
    char initials[MAXSIZE];
    int count_of_things;
    int total_weight;
    char destination[MAXSIZE];
    char departure_time[MAXSIZE];
    int count_of_transfers;
    char child_data[MAXSIZE];

} passenger;


#endif