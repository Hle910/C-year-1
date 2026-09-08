#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students
{
  char firstname[21];
  char lastname[21];
  double score;
  int zip;
  struct students* next;
};
struct students* head;

void print()
{
    struct students* temp=head;
    printf("Student records: \n");
    while(temp!=NULL)
    {
        temp->firstname[strcspn(temp->firstname, "\n")]=0;
        temp->lastname[strcspn(temp->lastname, "\n")]=0;
        printf("Name: %s %s, Score: %.1lf, ZIP code: %d\n", temp->firstname, temp->lastname, temp->score, temp->zip);
        temp=temp->next;
    }
    printf("\n");
}

void add()
{
    struct students* new_node=(struct students*)malloc(sizeof(struct students));
    struct students *past=head;
    new_node->next=NULL;
    printf("Enter data: \n");
    fflush(stdin);
    printf("First name: ");
    fgets(new_node->firstname, 21, stdin);
    printf("Last name: ");
    fgets(new_node->lastname, 21, stdin);
    printf("Score: ");
    scanf("%lf", &new_node->score);
    printf("ZIP code: ");
    scanf("%d", &new_node->zip);
    if(head==NULL)
    {
        head=new_node;
        return;
    }
    while(past->next!=NULL)
    {
        past=past->next;
    }
    past->next=new_node;
    return;
}

void delrec()
{
    char last[21];
    printf("Enter last name: ");
    fflush(stdin);
    fgets(last, 21, stdin);
    struct students* temp=head;
    last[strcspn(last, "\n")]=0;
    if(strcmp(temp->lastname, last)==0)
    {
        struct students *next=temp->next;
        free(temp);
        temp=next;
        head=temp;
    }
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            return;
        }
        if(strcmp(temp->next->lastname, last)==0)
        {
            struct students *next=temp->next->next;
            free(temp->next);
            temp->next=next;
        }
        temp=temp->next;
    }
}

void searchZIP()
{
    int ZIP;
    printf("Enter ZIP code: ");
    scanf("%d", &ZIP);
    struct students* temp=head;
    while(temp!=NULL)
    {
        if(temp->zip==ZIP)
        {
            temp->firstname[strcspn(temp->firstname, "\n")]=0;
            temp->lastname[strcspn(temp->lastname, "\n")]=0;
            printf("Name: %s %s, Score: %.1lf, ZIP code: %d\n", temp->firstname, temp->lastname, temp->score, temp->zip);
        }
        temp=temp->next;
    }
}

void searchScore()
{
    int min, max;
    printf("Enter min: ");
    scanf("%d", &min);
    printf("Enter max: ");
    scanf("%d", &max);
    struct students* temp=head;
    while(temp!=NULL)
    {
        if((temp->score>=min)&&(temp->score<=max))
        {
            temp->firstname[strcspn(temp->firstname, "\n")]=0;
            temp->lastname[strcspn(temp->lastname, "\n")]=0;
            printf("Name: %s %s, Score: %.1lf, ZIP code: %d\n", temp->firstname, temp->lastname, temp->score, temp->zip);
        }
        temp=temp->next;
    }
}

void median()
{
    int x, i, j;
    double med, y;
    struct students* temp=head;
    struct students *hold=temp;
    x=0;
    while(hold!=NULL)
    {
        x++;
        hold=hold->next;
    }
    hold=temp;
    double sort[x];
    for(i=0; i<x; i++)
    {
        sort[i]=hold->score;
        hold=hold->next;
    }
    for(i=0; i<x-1; i++)
    {
        for(j=0; j<x-i-1; j++)
        {
            if(sort[j]>sort[j+1])
            {
                y=sort[j];
                sort[j]=sort[j+1];
                sort[j+1]=y;
            }
        }
    }
    if(x%2==0)
    {
        med=(sort[x/2]+sort[(x/2)+1])/2;
        printf("%.1lf\n", med);
    }
    else
    {
        med=sort[x/2];
        printf("%.1lf\n", med);
    }
    while(temp!=NULL)
    {
        if(temp->score>med)
        {
            temp->firstname[strcspn(temp->firstname, "\n")]=0;
            temp->lastname[strcspn(temp->lastname, "\n")]=0;
            printf("Name: %s %s, Score: %.1lf, ZIP code: %d\n", temp->firstname, temp->lastname, temp->score, temp->zip);
        }
        temp=temp->next;
    }

}

int main()
{
    head=NULL;
    int i, x, y;
    printf("Enter 5 records:\n");
    for(i=0; i<5; i++)
    {
        add();
    }
    print();
    printf("What would you like to do?\n");
    y=1;
    while(y)
    {
        printf("Print records (press 1)\n");
        printf("Add new record (press 2)\n");
        printf("Delete record (press 3)\n");
        printf("Search by ZIP code (press 4)\n");
        printf("Search by score range (press 5)\n");
        printf("Find median score (press 6)\n");
        printf("Exit the program (press 0)\n");
        scanf("%d", &x);
        switch(x)
        {
        case 0:
            y=0;
            break;
        case 1:
            print();
            break;
        case 2:
            add();
            break;
        case 3:
            delrec();
            break;
        case 4:
            searchZIP();
            break;
        case 5:
            searchScore();
            break;
        case 6:
            median();
            break;
        }
    }
    return 0;
}
