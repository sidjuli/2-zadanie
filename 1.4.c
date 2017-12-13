#include<stdio.h>
#include<stdlib.h>

typedef struct list_element
{
    char a;
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

int main()
{
    char s;
    int i,F;
    int n = 0;
    list_element* t = list_new();
    t->a = 'h';
    list_element* dub;
    list_element* head = t;
    scanf("%c",&s);
    while (s != '\n')
    {
        push(t,s);
        n++;
        scanf("%c",&s);
    }
    F = 1;
    while (F == 1)
    {
        F = 0;
        t = head;
        i = 0;
        while (i < n)
        {
            t = t->next;
            if (t->next == NULL)
            {
                i = n;
            }
            else if (((t->a == '(') && (t->next->a == ')')) | ((t->a == '{') && (t->next->a == '}')))
            {
                    dub = t->next->next;
                    if (t->next->next != NULL)
                    {
                        t->next->next->prev = t->prev;
                    }
                    free(t->next);
                    t = t->prev;
                    free(t->next);
                    t->next = dub;
                    n = n-2;
                    F = 1;
            }
            i++;
        }

    }
    if ((t->next != NULL) | (t->a != 'h'))
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    list_deleate(t);
    return 0;
}
