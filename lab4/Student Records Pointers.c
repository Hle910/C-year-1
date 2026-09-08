#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print( char **array, int num);
char **addr(char **array, int *num);
char **deleter(char **array, int *num);
void searchLast(char **array, int num);
char **sortScore(char **array, int *num);
char **sortLast(char **array, int *num);
void findMedian(char **array, int num);

int main()
{
    int x, y, i, n;
    float score;
    char * pch;
    char * tempstr;
    char **record;
    printf("Please indicate the number of records you want to enter (min 5, max 15): ");
    scanf("%d", &x);
    y=1;
    while(y)
    {
        if(x>=5&&x<=15)
        {
            y=0;
        }
        else
        {
            printf("This is not a valid number\n");
            scanf("%d", &x);
        }
    }
    record=(char **)calloc(x, sizeof(char *));
    for(i=0; i<x; i++)
    {
        record[i]=(char *)calloc(46, sizeof(char));
    }
    printf("Please input records of students (enter a new line after each record), with the following format\nfirstname lastname score\n");
    fgets(record[0], 46, stdin);
    //fflush(stdin);
    for(i=0; i<x; i++)
    {
        y=1;
        printf("%d\n", i+1);
        fgets(record[i], 46, stdin);
        while(y)
        {
            tempstr=(char *)calloc(strlen(record[i])+1, sizeof(char));
            strcpy(tempstr, record[i]);
            pch=strtok(tempstr, " ");
            if(strlen(pch)>20)
            {
                printf("First name exceeds 20 characters\n");
                realloc(record[i], 46);
                fgets(record[i], 46, stdin);
            }
            else
            {
                pch=strtok(NULL, " ");
                if(strlen(pch)>20)
                {
                    printf("Last name exceeds 20 characters\n");
                    realloc(record[i], 46);
                    fgets(record[i], 46, stdin);
                }
                else
                {
                    pch=strtok(NULL, " ");
                    score=strtof(pch, NULL);
                    if(score<0||score>100)
                    {
                        printf("Invalid score\n");
                        realloc(record[i], 46);
                        fgets(record[i], 46, stdin);
                    }
                    else
                    {
                        y=0;
                    }
                }
            }
        }
    }
    y=1;
    while(y)
    {
        printf("Enter an option:\n");
        printf("Print records (press 1)\n");
        printf("Add a new record (press 2)\n");
        printf("Delete record(s) (press 3)\n");
        printf("Search by last name (press 4)\n");
        printf("Sort by score (press 5)\n");
        printf("Sort by last name (press 6)\n");
        printf("Find median score (press 7)\n");
        printf("Exit the program (press 0)\n");
        scanf("%d", &n);
        switch(n)
        {
            case 0:
                y=0;
                break;
            case 1:
                print(record, x);
                break;
            case 2:
                record=addr(record, &x);
                break;
            /*case 3:
                remover(record, x);
                break;*/
            case 4:
                searchLast(record, x);
                break;/*
            case 5:
                sortScore(record, x);
                break;
            case 6:
                sortLast(record, x);
                break;*/
            case 7:
                findMedian(record, x);
                break;
        }
    }
    return 0;
}

void print(char **array, int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        printf("%s\n", array[i]);
    }
}

char **addr(char **array, int *num)
{
    int y, i;
    char *temp;
    char *test;
    char **array2;
    float score;
    *num+=*num;
    printf("Add a new record: \n");
    array2=(char **)realloc(array, *num*sizeof(char));
    fgets(array2[*num-1], 46, stdin);
    fgets(array2[*num-1], 46, stdin);
    y=1;
    /*while(y)
        {
            temp=(char *)calloc(strlen(array2[*num])+1, sizeof(char));
            strcpy(temp, array2[*num]);
            test=strtok(temp, " ");
            if(strlen(test)>20)
            {
                printf("First name exceeds 20 characters\n");
                realloc(array2[*num], 46);
                fgets(array2[*num], 46, stdin);
            }
            else
            {
                test=strtok(NULL, " ");
                if(strlen(test)>20)
                {
                    printf("Last name exceeds 20 characters\n");
                    realloc(array2[*num], 46);
                    fgets(array2[*num], 46, stdin);
                }
                else
                {
                    test=strtok(NULL, " ");
                    score=strtof(test, NULL);
                    if(score<0||score>100)
                    {
                        printf("Invalid score\n");
                        realloc(array2[*num], 46);
                        fgets(array2[*num], 46, stdin);
                    }
                    else
                    {
                        y=0;
                    }
                }
            }
        }*/
        return array2;
}
void searchLast(char **array, int num)
{
    int i;
    char *tempstr;
    char *pch;
    char *last;
    last=(char *)calloc(46, sizeof(char));
    printf("Enter a name: ");
    //fgets(last, 46, stdin);
    fflush(stdin);
    fgets(last, 21, stdin);
    for(i=0; i<num; i++)
    {
        tempstr=(char *)calloc(strlen(array[i])+1, sizeof(char));
        strcpy(tempstr, array[i]);
        pch=strtok(tempstr, " ");
        pch=strtok(NULL, " ");
        if(last==pch)
        {
            printf("%s\n", array[i]);
        }
    }
}
void findMedian(char **array, int num)
{
    char *tempstr;
    char *pch;
    float score, n, m, median;
    if(num%2==0)
    {
        tempstr=(char *)calloc(strlen(array[0])+1, sizeof(char));
        strcpy(tempstr, array[num/2]);
        pch=strtok(tempstr, " ");
        pch=strtok(NULL, " ");
        pch=strtok(NULL, " ");
        score=strtof(pch, NULL);
        n=score;
        tempstr=(char *)calloc(strlen(array[0])+1, sizeof(char));
        strcpy(tempstr, array[(num/2)-1]);
        pch=strtok(tempstr, " ");
        pch=strtok(NULL, " ");
        pch=strtok(NULL, " ");
        score=strtof(pch, NULL);
        m=score;
        median=(m+n)/2;
        printf("%f\n", median);
    }
    if(num%2==1)
    {
        tempstr=(char *)calloc(strlen(array[0])+1, sizeof(char));
        strcpy(tempstr, array[num/2]);
        pch=strtok(tempstr, " ");
        pch=strtok(NULL, " ");
        pch=strtok(NULL, " ");
        score=strtof(pch, NULL);
        median=score;
        printf("%f\n", median);
    }

}

