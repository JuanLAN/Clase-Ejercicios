#include <stdio.h>

using namespace std;

void aordenarxd(char *A[])
{
    char **q=A;
    printf("%c\n",**q);

    //int **q=p;
    char temp;
    char **punt=q;
    printf("%c\n",**punt);
    char **aux;
    for(int j=0;j<sizeof(A);j++){
        **punt=**q;
        printf("%c\n",**punt);
        **aux=**punt;
        for(int i=j;i<sizeof(A);i++,punt++)
            if(*aux<*punt)
                **aux=**punt;
        
        q++;
    }
}

void lowerttt(char *s)
{
    if(*s>='A'&&*s<='Z')
        *s = *s-'A'+'a';
}

void strcatt(char *s,char *t)
{
    for(;*s!='\0';s++)
        ;
    for(;*t!='\0';t++,s++)
        *s=*t;
}

int strend(char *s,char *t)
{
    for(;*s!=*t;s++)
        ;
    for(;*s==*t&&*s!='\0'&&*t!='\0';s++,t++)
        ;
    if(*s==*t)
        return 1;
    else
        return 0;
}

void strncpy(char *s,char *t,int n)
{
    int i;
    for(i=0;i<n;s++,t++,i++)
        *s=*t;
}

void strncat(char *s,char *t,int n)
{
    int i;
    for(i=0;i<n;s++,i++)
        ;
    for(;*t!='\0';s++,t++)
        *s=*t;
}

int strncmp(char *s,char *t,int n)
{
    int i;
    for(i=0;i<n&&*s==*t;s++,t++,i++)
        if(i==n-1||*s=='\0')
            return 0;
    return *s-*t;
}

int atoii(char *s)
{
    int resultado=0;
    for(;*s!='\0';s++)
        resultado=resultado*10+*s-'0';
    return resultado;
}

int strindex(char *s,char *t)
{
    char *p,*q;
    for(;*s!='\0';s++){
        p=s;
        q=t;
        for(;*p==*q;p++,q++)
            ;
        if(q-1!=t&&*q=='\0'){
            return *p-*s;
        }
    }
}

int main()
{
    char a='M';
    printf("%c\n",a);
    lowerttt(&a);
    printf("%c\n",a);

    char b[15]="hola ";
    char c[8]="mundo";
    printf("%s\n",b);
    printf("%s\n",c);
    strcatt(b,c);
    printf("%s\n",b);
    printf("%d\n",strend(b,c));

    char d[10]="HOLAS";
    char e[10]="MUNDO";
    printf("%s\n",d);
    printf("%s\n",e);
    strncpy(d,e,2);
    printf("%s\n",d);

    char f[10]="HOLAS";
    char g[10]="MUNDO";
    printf("%s\n",f);
    printf("%s\n",g);
    strncat(f,g,2);
    printf("%s\n",f);

    char h[10]="TUGFA";
    char i[10]="TUHMNA";
    printf("%s\n",h);
    printf("%s\n",i);
    int result=strncmp(h,i,2);
    printf("%d\n",result);

    char j[10]="15632";
    printf("%s\n",j);
    int atoint=atoii(j);
    printf("%d\n",atoint);
    
    char k[15]="hola mundo";
    char l[10]="la mu";
    printf("%d\n",strindex(k,l));
    
    return 0;
}
