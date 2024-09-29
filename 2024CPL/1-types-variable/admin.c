//
// Created by 26247 on 2024/9/27.
//
#include <ctype.h>
#include <stdio.h>
#include <math.h>
int main(void) {
    char first_name[] = "Chu";
    char last_name[] = "Zhang";

    char gender = 'm';

    int c_score = 50;
    int music_score = 100;
    int medicine_score = 79;

    double mean = (c_score + music_score + medicine_score)/3.0;
    double sd = sqrt(pow(c_score-mean,2)/3.0 + pow(music_score-mean,2)/3.0+pow(medicine_score-mean,2));

    int rank =10;

    int birth_year = 1999;
    int birth_month = 1;
    int birth_day = 2;
    char weekday[] = "Tuesday";

    printf("%s\t%s\t%c\n"
        "%d\t%d\t%d\n"
        "%.3f\t%.3f\n"
        "%.2d-%.2d-%d\t%.3s\t%d%%\n",
        first_name,last_name,toupper(gender),
        c_score,music_score,medicine_score,
        mean,sd,
        birth_day,birth_month,birth_year,weekday,rank);
    return 0;




}