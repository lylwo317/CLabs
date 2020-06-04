#include <stdio.h>
#include <malloc.h>

double PI = 0;
int SLEEP_ON = 0;

struct _people
{
    char *name;
    int age;
};

typedef struct _people People;

void createPeople(People **p){
    *p = malloc(sizeof(People));
    (*p)->name = "Kevin";
    (*p)->age = 20;
}

void destroyPeople(People **p){
    if (p!=NULL && *p!=NULL)
    {
        free(*p);
    }
}

int main(int argc, char const *argv[])
{
    People *p = NULL;
    char sd[] = "Hello";
    printf("%c\n", sd[0]);
    createPeople(&p);
    destroyPeople(&p);
    printf("%s", "Hello");
    return 0;
}
