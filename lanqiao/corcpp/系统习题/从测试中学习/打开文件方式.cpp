#include <stdio.h>
typedef struct
{
	char ch;
}Ch;

int main(){
	FILE *fp=NULL;
	fp=fopen("text.dat","ab+");
	Ch t,r;
	r.ch='A';
	if(fp)
	{
		printf("�򿪳ɹ���\n");
		fread(&t,sizeof(Ch),1,fp);
		printf("---%c---",t.ch);
		while(!feof(fp))
		{
			if(r.ch==t.ch)
			printf("---%c----",t.ch);
			fread(&t,sizeof(Ch),1,fp);
		}
		//fwrite(&r,sizeof(Ch),1,fp);
	//	t.ch='B';
	//	fwrite(&t,sizeof(Ch),1,fp);
	//	t.ch='C';
	//	fwrite(&t,sizeof(Ch),1,fp);
	}	
	else 
	printf("��ʧ�ܣ�\n");
	fclose(fp);
	return 0;
} 
