#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h> 
int main ()
{
     double line[60][60];
     double n,m;
     int i,j;
     memset(line,0,sizeof(line));
     freopen("C:\\Users\\ÎÒµÄµçÄÔ\\Desktop\\in.txt","r",stdin);
     for(i=1;i<=29;i++){
         for(j=1;j<=i;j++){
             scanf("%lf",&line[i][j]);
         }
     }
     for(i=1;i<=29;i++){
         for(j=1;j<=i;j++){
             line[i+1][j]+=line[i][j]/2;
             line[i+1][j+1]+=line[i][j]/2;
         }
     }
     /*for(i=1;i<=30;i++){
         for(j=1;j<=i;j++){
             printf("%.2lf ",line[i][j]);
         }
         printf("\n");
     }*/
     n=m=line[30][1];
     for(i=1;i<=30;i++){
         if(n<line[30][i])
             n=line[30][i];
         if(m>line[30][i])
             m=line[30][i];
     }
     printf("n=m== %lf %lf\n",n,m);
     printf("%lf\n",n*2086458231/m);
     return 0;
 }
