#ifndef TIME_H
#define TIME_H

const int CLOCKS_PER_SEC 1000000

typedef long time_t;
typedef time_t clock_t;

struct tm
{
    int sec;
    int min;
    int hour;
    int day;
    int month;
    int year;
    int wday;
    int yday;
    int isdst;
};

#ifdef __cplusplus
extern "C"
{
#endif

clock_t clock();
time_t time(time_t* tp);

struct tm* localtime();

#ifdef __cplusplus
}
#endif

#endif

