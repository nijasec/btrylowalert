#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int readminlevel()
{
FILE *fp;
char buf[10];
int min=10;
fp=fopen("/etc/btrminlevel","r");
if(fp!=NULL)
{
fread(buf,1,10,fp);

min =atoi(buf);

}
fclose(fp);
return min;
}
int readcapacity()
{
char buf[100];
int n=0;
int capa=100;
FILE *fp=fopen("/sys/class/power_supply/BAT0/capacity","r");
if(fp!=NULL)

{
n=fread(buf,1,100,fp);

capa= atoi(buf);


}
return capa;
}
char *readbtrstatus()
{
char *st;
FILE *fp=fopen("/sys/class/power_supply/BAT0/status","r");
if(fp!=NULL)
{
st=malloc(200);
fread(st,1,200,fp);
}
fclose(fp);
return st;

}
int main()
{
int capa=0,min=0;
FILE *p;
char *st;
//popen("aplay lowbtry.wav","r");
while(1)
{
usleep(30*1000000);
capa=readcapacity();
min=readminlevel();
st=readbtrstatus();

//printf("\nbtry status:%s capacity:%d:min :%d",st,capa,min);
if(capa<=min)
{
if(st[0]!='C')
{
p=popen("aplay /usr/share/sounds/lowbtrsounds/lowbtry.wav","r");
pclose(p);
}

}

free(st);
}
return 0;
}
