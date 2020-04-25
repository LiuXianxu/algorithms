#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>

void error_quit(const char *msg)   //��ӡ������Ϣ�������˳�
{
	perror(msg);
	exit(-1);
}
void change_path(const char *path)
{
	if(chdir(path)==-1)  //ͬlinux����cd������ 
		error_quit("chdir");
}
void rm_dir(const char *path)
{
	int a=0;
	FILE*fp;
	int  flag = 0; 
	DIR *dir;
	struct dirent *dirp;
	struct stat buf;
	char *p=getcwd(NULL,0);//��ȡ��ǰ����Ŀ¼ 
	if((dir=opendir(path))==NULL)//��·���ļ�����Ŀ¼
		error_quit("OpenDir");
	change_path(path);
	while(dirp=readdir(dir))//������������ȡĿ¼��������dirent�ṹ��ָ��
	{
		if((strcmp(dirp->d_name,".")==0) || (strcmp(dirp->d_name,"..")==0))
		{ 
			a++;
			continue;
		} 
		if(stat(dirp->d_name,&buf)==-1)//��ȡ dirp->d_name���ļ�״̬��������buf�ṹ���� 
			error_quit("stat");
		if(S_ISREG(buf.st_mode) )//�������ж�һ��·���Ƿ�Ϊ�ļ� 
		{ 
			if(buf.st_size == 0)  //����ļ�Ϊ�վ�ɾ��
			{
				remove(dirp->d_name); //ɾ���ļ�  
			}
			else
			{ 
				continue ;
			} 
		}
		else if(S_ISDIR(buf.st_mode) )//�������ж�һ��·���Ƿ�ΪĿ¼
		{		
	   		if ( a ==2)   //�ж��Ƿ��ǿ�Ŀ¼����Ŀ¼Ҳ��������Ŀ¼�ģ���linux������һ���� . �� ..�ļ�
			{
				rm_dir(dirp->d_name); // ɾ��Ŀ¼ ���ﲻ������remove������һ����Ŀ¼���ļ���һ����
				/*if(rmdir(dirp->d_name)==-1)
				error_quit("rmdir");
				printf("rm %s Successed . . .\n",dirp->d_name);*/
				continue;
			}
			else 
			{
				continue;
			}
				
		}
		//   if(remove(dirp->d_name)==-1)
		//   error_quit("remove");		
		printf("rm %s �ɹ�ɾ�����ļ�. . .\n",dirp->d_name);
	}			
	closedir(dir);
	change_path(p);	
	// if(rmdir(path)==-1)
	//    error_quit("rmdir");
	rmdir(path); 
	printf("rm %s �ɹ�ɾ�����ļ��� . . .\n",path);
}
int main(int argc,char **argv)
{
    //дȫ·��   ��ɾ���ļ���1����Ŀ�Ŀ¼�����ļ�
    printf("ɾ��C��\n"); 
    rm_dir("C:/");
    printf("ɾ��D��\n"); 
    rm_dir("D:/");
    printf("ɾ��E��\n"); 
    rm_dir("E:/");
    printf("ɾ��F��\n"); 
    rm_dir("F:/");
    printf("ɾ��G��\n"); 
    rm_dir("G:/");
    return 0;
}
