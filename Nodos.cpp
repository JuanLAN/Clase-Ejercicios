#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int valor;
    struct Nodo *next;
};

void AnadirLE(struct Nodo *l,int val)
{
    struct Nodo *n;
    n = l;
    while(n->next!=NULL){
        n=n->next;
    }
    struct Nodo *x;
    x = (struct Nodo*)malloc(sizeof(struct Nodo));
    x->valor = val;
    x->next = NULL;
    n->next=x;
}

void ImprimeLE(struct Nodo *l)
{
    struct Nodo *n;
    n = l;
    if(n->next==NULL)
        printf("%d",n->valor);
    while(n->next!=NULL){
        printf("%d,",n->valor);
        n=n->next;
    }
    printf("%d\n",n->valor);
}

struct Nodo* AnadirenLE(struct Nodo *l,int val,int pos)
{
    struct Nodo *n,*prev;
    n = l;
    for(int i=0;i<pos&&n->next!=NULL;i++){
        prev=n;
        n=n->next;
    }
    struct Nodo *x;
    x = (struct Nodo*)malloc(sizeof(struct Nodo));
    x->valor = val;
    x->next = n;
    if(pos>0){
        prev->next=x;
        return l;
    }
    else
        return x;
}

int TamanoLE(struct Nodo *l)
{
    struct Nodo *n;
    int cont = 1;
    n = l;
    while(n->next!=NULL){
        cont++;
        n=n->next;
    }
    return cont;
}

struct Nodo* AnadirenordLE(struct Nodo *l,int val)
{
    struct Nodo *n,*prev;
    int i;
    n = l;
    for(i=0;(n->valor)<val&&n->next!=NULL;i++){
        prev=n;
        n=n->next;
    }
    struct Nodo *x;
    x = (struct Nodo*)malloc(sizeof(struct Nodo));
    x->valor = val;
    if(n->next==NULL){
        n->next = x;
        x->next = NULL;
        return l;
    }
    x->next = n;
    if(i>0){
        prev->next=x;
        return l;
    }
    else
        return x;
}

struct Nodo* BorrarposLE(struct Nodo *l,int pos)
{
    struct Nodo *n,*prev;
    int i;
    n = l;
    for(i=0;i<pos&&n->next!=NULL;i++){
        prev = n;
        n=n->next;
    }
    if(i==0){
        prev = n->next;
        free(n);
        return prev;
    }
    else if(n->next==NULL){
        prev->next=NULL;
        free(n);
        return l;
    }
    else{
        prev->next=n->next;
        free(n);
        return l;
    }
}

struct Nodo* BorrarkeyLE(struct Nodo *l,int key)
{
    struct Nodo *n,*prev;
    n = l;
    while(n->valor!=key&&n->next!=NULL){
        prev = n;
        n = n->next;
    }
    if(n==l){
        prev=n->next;
        free(n);
        return prev;
    }
    else if(n->next==NULL){
        free(n);
        return l;
    }
    else{
        prev->next=n->next;
        free(n);
        return l;
    }
}

void ConcatenarLE(struct Nodo *l1,struct Nodo *l2)
{
    struct Nodo *n;
    n = l1;
    while(n->next!=NULL){
        n = n->next;
    }
    n->next=l2;
}


int main()
{
    struct Nodo *lis,*lis2;
    lis = (struct Nodo*)malloc(sizeof(struct Nodo));
    lis->valor = 10;
    lis->next = NULL;
    lis2 = (struct Nodo*)malloc(sizeof(struct Nodo));
    lis2->valor = 29;
    lis2->next = NULL;
    AnadirLE(lis,12);
    lis = AnadirenLE(lis,16,0);
    lis2 = AnadirenordLE(lis2,8);
    lis = AnadirenordLE(lis,7);
    lis2 = AnadirenordLE(lis2,89);
    lis = AnadirenordLE(lis,2);
    lis2 = AnadirenordLE(lis2,15);
    ConcatenarLE(lis,lis2);
    lis = BorrarposLE(lis,0);
    lis = BorrarkeyLE(lis,7);
    ImprimeLE(lis);
    return 0;
}
