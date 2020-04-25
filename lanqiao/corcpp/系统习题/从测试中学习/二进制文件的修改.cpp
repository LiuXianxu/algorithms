#include <stdio.h>
#include <string.h>
typedef struct{
	char sn[20];
	int num;
}student;
int main(){
	FILE *fp=NULL;
	student s1,s2,s3,t;
//	scanf("%s%d",s1.sn,&s1.num);
//	scanf("%s%d",s2.sn,&s2.num);
//	scanf("%s%d",s3.sn,&s3.num);
	fp=fopen("test.dat","rb+");
	fread(&t,sizeof(student),1,fp);
	while(!feof(fp)){
	if(fp){
		if(strcmp(t.sn,"Hehe")){
			printf("%s %d\n",t.sn,t.num);
			t.num=0;
			fseek(fp,-(long)sizeof(student),1);
			fwrite(&t,sizeof(student),1,fp);
			printf("–¥»Î≥…π¶£°"); 
			break;
		}
		
	}
	else
		printf("It can't open this file.\n ");
}
	fclose(fp);
	return 0;
}
