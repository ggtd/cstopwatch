// Stupid-Simple Stopwatch for terminal
// by Tomas Dobrotka
// www.dobrotka.sk
// https://github.com/ggtd/cstopwatch

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


char output_prefix[20]="Elapsed time";

void SecondsToHumanReadable(int n_seconds)
{
    char output_text[100]="";

    int days = n_seconds / (24 * 3600);

    n_seconds = n_seconds % (24 * 3600);
    int hours = n_seconds / 3600;

    n_seconds %= 3600;
    int minutes = n_seconds / 60 ;

    n_seconds %= 60;
    int seconds = n_seconds;

    char human_time_elapsed_d[20]="";
    if (days>0){
        char d_sufix[10]="day";
        if (days>1){
            strcat(d_sufix,"s");
        };

        sprintf(human_time_elapsed_d, "%d %s, ", days,d_sufix);
        strcat(output_text,human_time_elapsed_d);
    };

    char human_time_elapsed_h[20]="";
    if (hours>0){
        char h_sufix[10]="hour";
        if (hours>1){
            strcat(h_sufix,"s");
        };

        sprintf(human_time_elapsed_h, "%d %s, ", hours,h_sufix);
        strcat(output_text,human_time_elapsed_h);
    };

    char human_time_elapsed_m[20]="";
    if (minutes>0){
        char m_sufix[10]="minute";
        if (minutes>1){
            strcat(m_sufix,"s");
        };

        sprintf(human_time_elapsed_m, "%d %s, ", minutes,m_sufix);
        strcat(output_text,human_time_elapsed_m);
    };

    char human_time_elapsed_s[20]="";
    char s_sufix[10]="second";
    if (seconds>1){
        strcat(s_sufix,"s");
    };

    sprintf(human_time_elapsed_s, "%d %s", seconds,s_sufix);
    strcat(output_text,human_time_elapsed_s);

//    printf("%s%s\r",human_time_elapsed_m,human_time_elapsed_s);
    printf("%s : %s\r",output_prefix,output_text);
    fflush(stdout);
};

int main(void) {

    int s_time=time(NULL); //start timestamp
    while (1) {
        int c_time=time(NULL);
        int e_time=c_time-s_time;
        SecondsToHumanReadable(e_time);
        usleep(900000);
    };

    return 0;
};


