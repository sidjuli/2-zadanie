#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct list_element
{
    int i;
    int j;
    //char a;
    struct list_element* prev;
    struct list_element* next;
} list_element;

list_element* list_new()
{
    list_element* p =(list_element*) malloc(sizeof(list_element));
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void list_deleate(list_element* t)
{
    list_element* Next = t->next;
    while (Next != NULL)
    {
        Next = t->next;
        free(t);
        t = Next;
    }
    free(t);
}

void push(list_element* t, int i, int j)
{
    if (t == NULL)
    {
        t = list_new();
        t->i = i;
        t->j = j;
    }
    else
    {
    while (t->next != NULL)
    {
        t = t->next;
    }

    t->next = list_new();
    t->next->prev = t;
    t->next->i = i;
    t->next->j = j;
    }
}

void pop(list_element* t, int* i, int* j)
{
    if (t == NULL)
    {
        i = NULL;
        j = NULL;
    }
    else
    {
        while (t->next != NULL)
        {
            t = t->next;
        }
        *i = t->i;
        *j = t->j;

    }
}

list_element* unshift (list_element* t, int i, int j)
{
    if (t == NULL)
    {
        t = list_new();
        t->i = i;
        t->j = j;
        return t;
    }
    else
    {
        t->prev = list_new();
        t->prev->next = t;
        t->prev->i = i;
        t->prev->j = j;
        return t->prev;
    }
}

void shift (list_element* t, int* i, int* j)
{
    if (t == NULL)
    {
        i = NULL;
        j = NULL;
    }
    else
    {
        *i = t->i;
        *j = t->j;
    }
}

void print_list (list_element* a)
{
    int i = 0;
    list_element* cel = a;
    while (cel!=NULL)
    {
        printf("[%d,%d]\n",cel->i,cel->j);
        cel = cel->next;
        i++;
    }

}


int tr(int i, int j, char* str, int M, int N)
{
    if (str[i*M + j] == '#')
    {
        return 0;
    }
    else if ((str[i*M + j + 1] == '.') && (j != N-1))
    {
        return 1;
    }
    else if ((str[(i+1)*M + j] == '.') && (i != M-1))
    {
        return 2;
    }
    else if ((str[(i-1)*M + j] == '.') && (i != 0))
    {
        return 4;
    }
    else if ((str[i*M + j - 1] == '.') && (j != 0))
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int N, M, Y, No, step;
    int i = 0;
    scanf("%d %d", &N, &M);
    char* onestr = malloc((M)*sizeof(char));
    char* str = malloc((M*N)*sizeof(char));
    //char matr = malloc(N* sixeof(str));

    scanf("%s", str);

    for (i = 1; i < N; i++)
    {
        scanf("%s", onestr);
        //printf("[%d]  %s", i, onestr);
        strcat(str,onestr);
    }
    //str[M*N+1] = '\0';
    printf("%s",str);
    list_element* t = list_new();
    t->i = 0;
    t->j = 0;
    t->prev = list_new();
    t->prev->next = t;
    t->prev->i = -1;
    No = 0;
    Y = 0;
    while ((Y == 0) && (No == 0))
    {

        //printf("%s\n",str);
        step = tr(t->i, t->j, str, M, N);
        //printf("[%d,%d]\nstep = %d\n",t->i,t->j,step);

        if (step == 0)
        {
            str[t->i*M + t->j] = '#';
            if (t->prev->i == -1)
            {
                No = 1;
            }
            else
            {
                t = t->prev;
            }
        }
        else if ((step == 1) && (t->prev->j != t->j+1))
        {
            push(t,t->i,t->j+1);
            t = t->next;
        }
        else if ((step == 2) && (t->prev->i != t->i+1))
        {
            push(t,t->i+1,t->j);
            t = t->next;
        }
        else if ((step == 3) && (t->prev->j != t->j-1))
        {
            push(t,t->i,t->j-1);
            t = t->next;
        }
        else if ((step == 4) && (t->prev->i != t->i-1))
        {
            push(t,t->i-1,t->j);
            t = t->next;
        }
        else
        {
            return -1;
        }

        if ((t->i == N-1) && (t->j == M-1))
        {
            Y = 1;
        }

    }
    while (t->prev->i != -1)
    {
        t = t->prev;
    }
    if (No == 1)
    {
        printf("NO");
    }
    else
    {
        print_list(r);
    }
    return 0;
}
