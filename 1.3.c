#include<stdio.h>
#include<stdlib.h>

typedef struct list_element
{
    int a;
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

void push(list_element* t, int a)
{
    if (t == NULL)
    {
        t = list_new();
        t->a = a;
    }
    else
    {
    while (t->next != NULL)
    {
        t = t->next;
    }

    t->next = list_new();
    t->next->prev = t;
    t->next->a = a;

    }
}

void pop(list_element* t, int* x)
{
    if (t == NULL)
    {
        x = NULL;
    }
    else
    {
        while (t->next != NULL)
        {
            t = t->next;
        }
        *x = t->a;

    }
}

list_element* unshift (list_element* t, int a)
{
    if (t == NULL)
    {
        t = list_new();
        t->a = a;
        return t;
    }
    else
    {
        t->prev = list_new();
        t->prev->next = t;
        t->prev->a = a;
        return t->prev;

    }

}

void shift (list_element* t, int* x)
{
    if (t == NULL)
    {
        x = NULL;
    }
    else
    {
        *x = t->a;
    }
}


int main()
{

}
