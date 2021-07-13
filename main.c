#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getopt.h"
#include "helpers.h"
int main(int argc, char* argv[]){
    //Deal with operators
    char *ops = "abls";
    char op = getopt(argc, argv, ops);
    if(op == '?')
        printf("Invalid op\n");
    //declare file and make sure that user inputted valiid format
    FILE *logfile;
    FILE *amntfile;
    //check if null
    if(logfile == NULL || amntfile == NULL)
        return 1;
    //open our files that store data
    int moneyamnt;
    int argvnum = atoi(&argv[2][0]);
    logfile = fopen("events.txt", "a");
    amntfile = fopen("amnt.txt", "r");
    //get current money amount from the amnt.txt file
    fscanf(amntfile, "%i", &moneyamnt);
    //switch statement to handle the possible operator
    switch(op){
        case 'a':
            add(amntfile, logfile, argvnum, moneyamnt, argv[3]);
            break;
        case 'l':
            list(logfile, argvnum, argv[2], argv[3]);
            break;
        case 'b':
            bal(moneyamnt);
            break;
        case 's':
            sub(amntfile, logfile, argvnum, moneyamnt, argv[3]);
            break;
        default:
            return 1;
    }
    //write money amount after actions
    //close files, duh
    fclose(logfile);
    fclose(amntfile);

}