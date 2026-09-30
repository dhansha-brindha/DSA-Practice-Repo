#include <stdio.h>

int main()
{
    int n,i;
    char buf[100];

    while(scanf("%d",&n)!=EOF)
    {
        i=0;

        while(n>=1000){buf[i++]='R';n-=1000;}
        while(n>=900){buf[i++]='B';buf[i++]='R';n-=900;}
        while(n>=500){buf[i++]='G';n-=500;}
        while(n>=400){buf[i++]='B';buf[i++]='G';n-=400;}
        while(n>=100){buf[i++]='B';n-=100;}
        while(n>=90){buf[i++]='Z';buf[i++]='B';n-=90;}
        while(n>=50){buf[i++]='P';n-=50;}
        while(n>=40){buf[i++]='Z';buf[i++]='P';n-=40;}
        while(n>=10){buf[i++]='Z';n-=10;}
        while(n>=9){buf[i++]='B';buf[i++]='Z';n-=9;}
        while(n>=5){buf[i++]='W';n-=5;}
        while(n>=4){buf[i++]='B';buf[i++]='W';n-=4;}
        while(n>=1){buf[i++]='B';n--;}

        buf[i]='\0';
        printf("%s\n",buf);
    }

    return 0;
}