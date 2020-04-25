#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>

void error_quit(const char *msg)   //打印错误信息，并且退出
{
	perror(msg);
	exit(-1);
}
void change_path(const char *path)
{
	if(chdir(path)==-1)  //同linux里面cd的作用 
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
	char *p=getcwd(NULL,0);//获取当前工作目录 
	if((dir=opendir(path))==NULL)//打开路径文件或是目录
		error_quit("OpenDir");
	change_path(path);
	while(dirp=readdir(dir))//本函数用来读取目录。返回是dirent结构体指针
	{
		if((strcmp(dirp->d_name,".")==0) || (strcmp(dirp->d_name,"..")==0))
		{ 
			a++;
			continue;
		} 
		if(stat(dirp->d_name,&buf)==-1)//获取 dirp->d_name的文件状态，保存在buf结构体中 
			error_quit("stat");
		if(S_ISREG(buf.st_mode) )//功能是判断一个路径是否为文件 
		{ 
			if(buf.st_size == 0)  //如果文件为空就删掉
			{
				remove(dirp->d_name); //删除文件  
			}
			else
			{ 
				continue ;
			} 
		}
		else if(S_ISDIR(buf.st_mode) )//功能是判断一个路径是否为目录
		{		
	   		if ( a ==2)   //判断是否是空目录，空目录也是有两个目录的，与linux里面是一样的 . 和 ..文件
			{
				rm_dir(dirp->d_name); // 删除目录 这里不可以用remove，还不一样，目录和文件不一样的
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
		printf("rm %s 成功删除空文件. . .\n",dirp->d_name);
	}			
	closedir(dir);
	change_path(p);	
	// if(rmdir(path)==-1)
	//    error_quit("rmdir");
	rmdir(path); 
	printf("rm %s 成功删除空文件夹 . . .\n",path);
}
int main(int argc,char **argv)
{
    //写全路径   ，删除文件夹1下面的空目录及空文件
    printf("删除C盘\n"); 
    rm_dir("C:/");
    printf("删除D盘\n"); 
    rm_dir("D:/");
    printf("删除E盘\n"); 
    rm_dir("E:/");
    printf("删除F盘\n"); 
    rm_dir("F:/");
    printf("删除G盘\n"); 
    rm_dir("G:/");
    return 0;
}
