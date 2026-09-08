#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students
{
    int id, zip;
    char firstname[21];
    char lastname[21];
    double score;
    struct students* left;
    struct students* right;
};

struct students* newNode(int data)
{
    struct students* node=(struct students*)malloc(sizeof(struct students));
    node->id=data;
    fgets(node->firstname, 21, stdin);
    printf("First name: ");
    fgets(node->firstname, 21, stdin);
    printf("Last name: ");
    fgets(node->lastname, 21, stdin);
    printf("Score: ");
    scanf("%lf", &node->score);
    printf("ZIP code: ");
    scanf("%d", &node->zip);
    node->firstname[strcspn(node->firstname, "\n")]=0;
    node->lastname[strcspn(node->lastname, "\n")]=0;
    node->left=node->right=NULL;
    printf("\n");

    return node;
}

void printRec(struct students* root)
{
    if(root==NULL)
    {
        return;
    }
    printRec(root->left);
    printf("%d \n", root->id);
    printf("Name: %s %s, Score: %.1lf, ZIP code: %d\n", root->firstname, root->lastname, root->score, root->zip);
    printRec(root->right);
}

int check(struct students* root, int data)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(data==root->id)
    {
        return 1;
    }
    else if(data<root->id)
    {
        return check(root->left, data);
    }
    else if(data>root->id)
    {
        return check(root->right, data);
    }
    return 0;
}

struct students* add(struct students* root, int data)
{
    if(root==NULL)
    {
        root=newNode(data);
    }
    else if(data<root->id)
    {
        root->left=add(root->left, data);
    }
    else
    {
        root->right=add(root->right, data);
    }
    return root;
}

struct students* findMin(struct students* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct students* deleteID(struct students* root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(key<root->id)
    {
        root->left=deleteID(root->left, key);
    }
    else if(key>root->id)
    {
        root->right=deleteID(root->right, key);
    }
    else
    {
        if(root->left==NULL)
        {
            struct students *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct students *temp=root->left;
            free(root);
            return temp;
        }
        struct students* temp=findMin(root->right);
        root->id=temp->id;
        strcpy(root->firstname, temp->firstname);
        strcpy(root->lastname, temp->lastname);
        root->score=temp->score;
        root->zip=temp->zip;
        root->right=deleteID(root->right, temp->id);
    }
    return root;
}

struct students* deleteNode(struct students* root, char* last)
{
    if(root==NULL)
    {
        return root;
    }
    root->left=deleteNode(root->left, last);
    root->right=deleteNode(root->right, last);

    if(strcmp(root->lastname, last)==0)
    {
        if(root->left==NULL)
        {
            struct students *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct students *temp=root->left;
            free(root);
            return temp;
        }
        struct students *temp=findMin(root->right);
        root->id=temp->id;
        strcpy(root->firstname, temp->firstname);
        strcpy(root->lastname, temp->lastname);
        root->score=temp->score;
        root->zip=temp->zip;
        root->right=deleteID(root->right, temp->id);
    }
    return root;
}

void searchZIP(struct students* root, int ZIP)
{
    if(root==NULL)
    {
        return;
    }
    searchZIP(root->left, ZIP);
    if(ZIP==root->zip)
    {
        printf("Name: %s %s, Score: %.1lf, ZIP code: %d\n", root->firstname, root->lastname, root->score, root->zip);
    }
    searchZIP(root->right, ZIP);
}

void searchScore(struct students* root, int min, int max)
{
    if(root==NULL)
    {
        return;
    }
    searchScore(root->left, min, max);
    if((root->score>=min)&&(root->score<=max))
    {
        printf("Name: %s %s, Score: %.1lf, ZIP code: %d\n", root->firstname, root->lastname, root->score, root->zip);
    }
    searchScore(root->right, min, max);
}

int count(struct students* root)
{
    int c=1;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        c+=count(root->left);
        c+=count(root->right);
        return c;
    }
}

int arrayConvert(struct students* root, double array[], int i)
{
    if(root==NULL)
    {
        return i;
    }
    array[i]=root->score;
    i++;
    if(root->left!=NULL)
    {
        i=arrayConvert(root->left, array, i);
    }
    if(root->right!=NULL)
    {
        i=arrayConvert(root->right, array, i);
    }
    return i;
}

void median(struct students* root)
{
    int x, i, j, temp;
    double med;
    x=0;
    x=count(root);
    double *array;
    array=(double*)calloc(x, sizeof(double));
    arrayConvert(root, array, 0);
    for(i=0; i<x-1; i++)
    {
        for(j=0; j<x-1-i; j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
    }
    if(x%2==0)
    {
        med=(array[x/2]+array[(x/2)+1])/2;
        printf("%.1lf\n", med);
        searchScore(root, med, 100);
    }
    else
    {
        med=array[x/2];
        printf("%.1lf\n", med);
        searchScore(root, med, 100);
    }
}

int main()
{
    int i, m, n, x, y, z, ID, ZIP;
    char last [21];
    struct students* root=NULL;
    printf("Enter a minimum of 5 student records: \n");
    z=1;
    for(i=0; i<5; i++)
    {
        z=1;
        printf("ID: ");
        scanf("%d", &ID);
        while(z)
        {
            if(ID<1000||ID>1100)
            {
                printf("Invalid ID, enter again: ");
                scanf("%d", &ID);
            }
            else if(check(root, ID))
            {
                printf("Invalid ID, enter again: ");
                scanf("%d", &ID);
            }
            else
            {
                z=0;
            }
        }
        root=add(root, ID);
    }
    printRec(root);
    printf("What would you like to do?\n");
    y=1;
    while(y)
    {
        z=1;
        printf("\n");
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
            printRec(root);
            break;
        case 2:
            printf("ID: ");
            scanf("%d", &ID);
            while(z)
            {
                if(ID<1000||ID>1100)
                {
                    printf("Invalid ID, enter again: ");
                    scanf("%d", &ID);
                }
                else if(check(root, ID))
                {
                    printf("Invalid ID, enter again: ");
                    scanf("%d", &ID);
                }
                else
                {
                    z=0;
                }
            }
            root=add(root, ID);
            break;
        case 3:
            fgets(last, 21, stdin);
            printf("Enter last name: ");
            fgets(last, 21, stdin);
            last[strcspn(last, "\n")]=0;
            root=deleteNode(root, last);
            break;
        case 4:
            printf("Enter ZIP code: ");
            scanf("%d", &ZIP);
            searchZIP(root, ZIP);
            break;
        case 5:
            printf("Enter min score: ");
            scanf("%d", &m);
            printf("Enter max score: ");
            scanf("%d", &n);
            searchScore(root, m, n);
            break;
        case 6:
            median(root);
            break;
        }
    }
    return 0;
}
