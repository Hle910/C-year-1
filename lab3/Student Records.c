#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char array[][46], int num);
void searchFirst(char array[][46], int num);
void searchLast(char array[][46], int num);
void sortScore(char array[][46], int num);
void sortLast(char array[][46], int num);
void findMax(char array[][46], int num);
void findMin(char array[][46], int num);

int main()
{
    int x, y, i, n;
    float score;
    char * pch;
    char * tempstr;
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
    char record [x][46];
    fgets(record[0], 46, stdin);
    printf("Please input records of students (enter a new line after each record), with the following format\nfirstname lastname score\n");
    for(i=0; i<x; i++)
    {
        printf("%d\n", i+1);
        y=1;
        fgets(record[i], 46, stdin);
        while(y)
        {
            tempstr=calloc(strlen(record[i])+1, sizeof(char));
            strcpy(tempstr, record[i]);
            pch=strtok(tempstr, " ");
            if(strlen(pch)>20)
            {
                printf("First name exceeds 20 characters\n");
                fgets(record[i], 46, stdin);
            }
            else
            {
                pch=strtok(NULL, " ");
                if(strlen(pch)>20)
                {
                    printf("Last name exceeds 20 characters\n");
                    fgets(record[i], 46, stdin);
                }
                else
                {
                    pch=strtok(NULL, " ");
                    score=strtof(pch, NULL);
                    if(score<0||score>100)
                    {
                        printf("Invalid score\n");
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
        printf("Search by first name (press 2)\n");
        printf("Search by last name (press 3)\n");
        printf("Sort by score (press 4)\n");
        printf("Sort by last name (press 5)\n");
        printf("Find max score (press 6)\n");
        printf("Find min score (press 7)\n");
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
                searchFirst(record, x);
                break;
            case 3:
                searchLast(record, x);
                break;
            case 4:
                sortScore(record, x);
                break;
            case 5:
                sortLast(record, x);
                break;
            case 6:
                findMax(record, x);
                break;
            case 7:
                findMin(record, x);
                break;
        }
    }
    return 0;
}

void print(char array[][46], int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        printf("%s\n", array[i]);
    }
}

void searchFirst(char array[][46], int num)
{
    int i, y;
    char first[21];
    char * pch;
    char * tempstr;
    printf("Enter first name of student(s): \n");
    fgets(first, 21, stdin);
    fgets(first, 21, stdin);
    y=1;
    while(y)
    {
        if(strlen(first)>20)
        {
            printf("Invalid name\n");
            fgets(first, 21, stdin);
        }
        else
        {
            y=0;
        }
    }
    for(i=0; i<num; i++)
    {
        tempstr=calloc(strlen(array[i])+1, sizeof(char));
        strcpy(tempstr, array[i]);
        pch=strtok(tempstr, " ");
        if(strcmp(pch, first)!=0)
        {
            printf("%s\n", array[i]);
        }
    }
}

void searchLast(char array[][46], int num)
{
    int i, y;
    char last[21];
    char * pch;
    char * tempstr;
    printf("Enter last name of student(s): \n");
    fgets(last, 21, stdin);
    fgets(last, 21, stdin);
    y=1;
    while(y)
    {
        if(strlen(last)>20)
        {
            printf("Invalid name\n");
            fgets(last, 21, stdin);
        }
        else
        {
            y=0;
        }
    }
    for(i=0; i<num; i++)
    {
        tempstr=calloc(strlen(array[i])+1, sizeof(char));
        strcpy(tempstr, array[i]);
        pch=strtok(tempstr, " ");
        pch=strtok(NULL, " ");
        if(strcmp(pch, last)!=0)
        {
            printf("%s\n", array[i]);
        }
    }
}

void sortScore(char array[][46], int num)
{
    int i, j;
    char tmp[46];
    char * pch;
    char * pch2;
    char * tempstr;
    char * tempstr2;
    float score, score2;
    for(i=0; i<num-1; i++)
    {
        for(j=0; j<num-i-1; j++)
        {
            tempstr=calloc(strlen(array[j])+1, sizeof(char));
            strcpy(tempstr, array[j]);
            pch=strtok(tempstr, " ");
            pch=strtok(NULL, " ");
            pch=strtok(NULL, " ");
            score=strtof(pch, NULL);
            tempstr2=calloc(strlen(array[j+1])+1, sizeof(char));
            strcpy(tempstr2, array[j+1]);
            pch2=strtok(tempstr2, " ");
            pch2=strtok(NULL, " ");
            pch2=strtok(NULL, " ");
            score2=strtof(pch2, NULL);
            if(score>score2)
            {
                strcpy(tmp, array[j+1]);
                strcpy(array[j+1], array[j]);
                strcpy(array[j], tmp);
            }
        }
    }
    print(array, num);
}

void sortLast(char array[][46], int num)
{
    int i, j;
    char tmp[46];
    char * pch;
    char * pch2;
    char * tempstr;
    char * tempstr2;
    for(i=0; i<num-1; i++)
    {
        for(j=0; j<num-i-1; j++)
        {
            tempstr=calloc(strlen(array[j])+1, sizeof(char));
            strcpy(tempstr, array[j]);
            pch=strtok(tempstr, " ");
            pch=strtok(NULL, " ");
            tempstr2=calloc(strlen(array[j+1])+1, sizeof(char));
            strcpy(tempstr2, array[j+1]);
            pch2=strtok(tempstr2, " ");
            pch2=strtok(NULL, " ");
            if(strcmp(pch, pch2)<0)
            {
                strcpy(tmp, array[j+1]);
                strcpy(array[j+1], array[j]);
                strcpy(array[j], tmp);
            }
        }
    }
    for(i=num-1; i>=0; i--)
    {
        printf("%s\n", array[i]);
    }
}

void findMax(char array[][46], int num)
{
    int i, j, y;
    char * pch;
    char * pch2;
    char * tempstr;
    char * tempstr2;
    float score, score2;
    y=0;
    for(i=0; i<num-1; i++)
    {
        tempstr=calloc(strlen(array[i])+1, sizeof(char));
        strcpy(tempstr, array[i]);
        pch=strtok(tempstr, " ");
        pch=strtok(NULL, " ");
        pch=strtok(NULL, " ");
        score=strtof(pch, NULL);
        for(j=i+1; j<num; j++)
        {
            tempstr2=calloc(strlen(array[j])+1, sizeof(char));
            strcpy(tempstr2, array[j]);
            pch2=strtok(tempstr2, " ");
            pch2=strtok(NULL, " ");
            pch2=strtok(NULL, " ");
            score2=strtof(pch2, NULL);
            if(score<score2)
            {
                score=score2;
            }
        }
        y=score;
    }
    for(i=0; i<num; i++)
    {
        tempstr=calloc(strlen(array[i])+1, sizeof(char));
        strcpy(tempstr, array[i]);
        pch=strtok(tempstr, " ");
        pch=strtok(NULL, " ");
        pch=strtok(NULL, " ");
        score=strtof(pch, NULL);
        if(score==y)
        {
            printf("%s\n", array[i]);
        }
    }
}

void findMin(char array[][46], int num)
{
    int i, j, y;
    char * pch;
    char * pch2;
    char * tempstr;
    char * tempstr2;
    float score, score2;
    y=0;
    for(i=0; i<num-1; i++)
    {
        tempstr=calloc(strlen(array[i])+1, sizeof(char));
        strcpy(tempstr, array[i]);
        pch=strtok(tempstr, " ");
        pch=strtok(NULL, " ");
        pch=strtok(NULL, " ");
        score=strtof(pch, NULL);
        for(j=i+1; j<num; j++)
        {
            tempstr2=calloc(strlen(array[j])+1, sizeof(char));
            strcpy(tempstr2, array[j]);
            pch2=strtok(tempstr2, " ");
            pch2=strtok(NULL, " ");
            pch2=strtok(NULL, " ");
            score2=strtof(pch2, NULL);
            if(score>score2)
            {
                score=score2;
            }
        }
        y=score;
    }
    for(i=0; i<num; i++)
    {
        tempstr=calloc(strlen(array[i])+1, sizeof(char));
        strcpy(tempstr, array[i]);
        pch=strtok(tempstr, " ");
        pch=strtok(NULL, " ");
        pch=strtok(NULL, " ");
        score=strtof(pch, NULL);
        if(score==y)
        {
            printf("%s\n", array[i]);
        }
    }
}
