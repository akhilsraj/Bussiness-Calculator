#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
 char str[100],str1[100],str2[100];char *token; const char s[]="+-*/";
 int a[100],i=0,z=0,k=0,j=0,n=0,h=0,len;
 int t=0;

 printf("Enter the arithmetic expression\n");
 gets(str);
 strcpy(str1,str);
 token = strtok(str,s);
 while(token!=NULL)
{
 a[i]=*token - '0';
 i++;
 token=strtok(NULL,s);
}
n=i;
for(z=0;str1[z]!='\0';z++)
{
 if(str1[z]=='+')
 {
  str2[t]=str1[z];
  t++;
 }
 else if(str1[z]=='-')
{
 str2[t]=str1[z];
 t++;
}
else if(str1[z]=='*')
{
 str2[t]=str1[z];
 t++;
}
else if(str1[z]=='/')
{
 str2[t]=str1[z];
 t++;
}
else
continue;
}
str2[t]='\0';
len=strlen(str2);
t=0;
for(k=0;str2[k]!='\0';k++)
{
 if(str2[k]=='*')
 {
  if(k==0)
  {
   a[k+1]=a[k+1]*a[k];
  }
  else if(k>0)
 {
  a[k]=a[k+1]*a[k];
  for(j=k+1;j<n;j++)
  {
   a[j]=a[j+1];
  }
  n--;
  h=k;
  while(h<=len)
  {
   str2[h]=str2[h+1];
   h++;
  }
  len--;
 }
}
 else if(str2[k]=='/')
 {
  if(k==0)
  {
  a[k+1]=a[k]/a[k+1];
  }
  else if(k>0)
  {
   a[k]=a[k]/a[k+1];
  for(j=k+1;j<n;j++)
  {
   a[j]=a[j+1];
  }
  n--;
  h=k;
  while(h<len)
  {
   str2[h]=str2[h+1];
   h++;
  }
  len--;
 }
}
 else
 {
 continue;
 }
}
for(t=0;t<len;t++)
{
 if(str2[t]=='+')
 {
  a[t+1]=a[t]+a[t+1];
 }
 else if(str2[t]=='-')
 {
  a[t+1]=a[t]-a[t+1];
 }
 else
 {
  continue;
 }
}
printf("The answer is = %d",a[t]);
getch();
}
