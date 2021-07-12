#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(FILE* amntfile, FILE* logfile, int argvnum, int moneyamnt, char* arg3){
    amntfile = fopen("amnt.txt", "w");
    moneyamnt += argvnum;
    fprintf(amntfile, "%i", moneyamnt);
    fprintf(logfile, "ADDED %i$, Reason: %s\n", argvnum, arg3);
    printf("\033[0;32mADDED\033[0m %i$, Reason: %s\n", argvnum, arg3);
}

void list(FILE* logfile, int argvnum, char* arg2, char* arg3){
    logfile = fopen("events.txt", "r");
    int totallines = 0;
    char line[1000][128];
    int i = 0;
    while(fgets(line[i], 128, logfile)){
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    totallines = i;
    if(argvnum > totallines)
        argvnum = totallines;
    if(strcmp(arg2, "all") == 0){
        for(int i = 0; i <= totallines - 1; i++){
           if(line[i][0] == 'A')
                printf("\033[0;32mEVENT\033[0m# %i: %s\n", i, line[i]);
            else if(line[i][0] == 'R')
                printf("\033[0;31mEVENT\033[0m# %i: %s\n", i, line[i]);
        }
    }
    else if(arg3 == NULL){
        for(int i = totallines; i >= totallines - argvnum; i--){
            if(line[i][0] == 'A')
                printf("\033[0;32mEVENT\033[0m# %i: %s\n", i, line[i]);
            else if(line[i][0] == 'R')
                printf("\033[0;31mEVENT\033[0m# %i: %s\n", i, line[i]);
        }  
    }
    else{
        printf("Usage: .\\main.exe -l [all, list, num]\n");
    }
}

void bal(int moneyamnt){
    printf("Current balance: %i$\n", moneyamnt);
}

void sub(FILE* amntfile, FILE* logfile, int argvnum, int moneyamnt, char* arg3){
    amntfile = fopen("amnt.txt", "w");
    moneyamnt -= argvnum;
    if(moneyamnt < 0){
        printf("You cant have less than 0 dollars\nImagine you have 10 dollars and 11 friends, each friend gets 1 dollar, but the last friend cant get anything so he is sad. I dont want him to be sad\n");
        fprintf(amntfile, "%i", moneyamnt + argvnum);
    }else{
        fprintf(logfile, "REMOVED %i$, Reason: %s\n", argvnum, arg3);
        printf("\033[0;31mREMOVED\033[0m %i$, Reason: %s\n", argvnum, arg3);
        fprintf(amntfile, "%i", moneyamnt); 
    }
}