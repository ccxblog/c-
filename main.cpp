#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

void menu();
void input_fun();
void print_fun();
int search_fun();    
void modify_fun();   
void delete_fun();
void insert_fun();
void rank_fun();
void add_fun();

struct staff_type{
	char num[10];
	char name[10];       //定义一个带有员工工号丶姓名丶电话丶地址的结构体 
	char tel[15];
    char address[50];
};
struct staff_type staff[SIZE];

int main()
{
menu();	
}

void menu()
{
char choice;
printf("                                              \n");
printf(" \t\t\t\t|****************请选择*****************|\n");
printf(" \t\t\t\t|             1.输入员工数据            |    \n");
printf(" \t\t\t\t|             2.查找员工数据            |    \n");
printf(" \t\t\t\t|             3.打印员工数据            |    \n");
printf(" \t\t\t\t|             4.修改员工数据            |    \n");
printf(" \t\t\t\t|             5.删除员工数据            |    \n");
printf(" \t\t\t\t|             6.插入员工数据            |    \n");
printf(" \t\t\t\t|             7.员工数据排序            |    \n");
printf(" \t\t\t\t|             8.添加员工数据            |   \n");
printf(" \t\t\t\t|             0.退出                    |\n");
printf(" \t\t\t\t|***************************************|\n");
printf("请选择：");

choice=getchar();getchar();


switch(choice)
{case '1':input_fun();break;
 case '2':search_fun();break;
 case '3':print_fun();break;
 case '4':modify_fun();break;
 case '5':delete_fun();break;   //根据choice调用对应的函数 
 case '6':insert_fun();break;
 case '7':rank_fun();break;
 case '8':add_fun();;break;
 case '0':exit(0);
 default :printf("\n选择错误\n");
}


menu();//递归调用menu函数 
}


//输入员工信息 
void input_fun()
{  FILE *fp;
   int i=0; 
   char c;
  if((fp=fopen("staff.txt","w"))==NULL)
  {
  	printf("不能打开文件");         //只写打开文件 
  	exit(0);
  } 
  
  printf("请输入数据:\n");
   while(i<SIZE)
     {printf("请输入5位数的员工工号:\n");
      gets(staff[i].num);
      while(strlen(staff[i].num)!=5)
      {
      	printf("工号输入错误，请重新输入:\n");
      	gets(staff[i].num);
	  }
      printf("请输入员工姓名:\n");
	  gets(staff[i].name);        //输入员工信息 
	  printf("请输入员工电话:\n");
	  gets(staff[i].tel);
	      while(strlen(staff[i].tel)!=11)
      {
      	printf("电话号码不合法，请重新输入:\n");
      	gets(staff[i].tel);
	  }
	  printf("请输入员工住址:\n");
	  gets(staff[i].address); 
	  i++;
	  
	  printf("输入n结束输入,输入其他继续\n");
	   	c=getchar();
	   	getchar();
	   	if(c=='n')                  //判断是否继续输入 
	   	  break;
	 }
	fwrite(staff,sizeof(staff[0]),i,fp);    //将数据写入文件 
	fclose(fp);
}

void print_fun()
{  FILE *fp;
   int n=0; 
   
	if((fp=fopen("staff.txt","r"))==NULL)
  {
  	printf("不能打开文件");         //只读打开文件 
  	exit(0);
  } 
	
	printf("工号\t姓名\t电话\t\t住址\n");
	while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)        //从文件读出数据并输出到屏幕 
	{printf("%s\t%s\t%s\t%s\t\n",staff[n].num,staff[n].name,staff[n].tel,staff[n].address);  
	 n++;
	}
	 fclose(fp);
}

//查找函数 
int search_fun()
{FILE *fp;
   int n=0,i; 
   char ch;
   char s[10];
   int flag=0;              //判断是否找到信息，找到flag=1 
	if((fp=fopen("staff.txt","r"))==NULL)
  {
  	printf("不能打开文件");         //打开文件 
  	exit(0);
  } 
	while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)    
	n++;                                                 //将文件中的数据读出到结构体中 
	
	printf("你想通过哪一种方式查找\n");
	printf("1.姓名   2.工号\n");
	ch=getchar();getchar();
	switch(ch)
	{ 
	   case '1':
	   	        printf("请输入你要查找员工的姓名:\n");
	   	        gets(s);
	   	           for(i=0;i<n;)
	   	              {
	   	              	if(strcmp(s,staff[i].name)==0)
	   	              	{                                    //遍历结构体利用字符串比较函数实现姓名丶工号的查找 
	   	              		 flag=1;
							 break;
						}
	   	              	i++;                      
					  }
					  break;
	   case '2':
	   	        printf("请输入你要查找员工的工号\n");
	   	        gets(s);
	   	           for(i=0;i<n;)
	   	              {
	   	              	if(strcmp(s,staff[i].num)==0)
	   	              	   {
	   	              	   	flag=1;
							break;
						   } 
	   	              	i++;
	   	              }
	   	              break;
	}
     if(flag==0)
       {
	   printf("没找到该员工信息\n");
	   return -1;
       }
     if(flag==1)
        {   printf("已找到他的信息是：\n");          //根据flag判断是否找到，并执行对应代码 
        	printf("工号\t姓名\t电话\t\t住址\n");
	        printf("%s\t%s\t%s\t%s\t\n",staff[i].num,staff[i].name,staff[i].tel,staff[i].address);
     	}	
	
fclose(fp);
return i;
}

//修改函数 
void modify_fun()
{
	FILE *fp;
	int n=0,i;
	char c,s[10];
	printf("如果你想修改员工信息,你必须先找到他\n\n");
	i=search_fun();
	if(i!=-1)         //根据调用查找函数获取i，i=-1说明没找到员工信息
	                   //所以不对数据进行修改 
{

 if((fp=fopen("staff.txt","r+"))==NULL)
  {
  	printf("不能打开文件");         //打开文件 
  	exit(0);
  } 
	
	while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)
	n++; 
	              
	printf("你想修改什么信息\n");
	printf("1.姓名  2.工号   3.电话   4.地址\n");
	c=getchar();getchar();
	switch(c)
	{
		case '1':
			     printf("请输入新的姓名:\n");
			     gets(staff[i].name);
			     break;
		case '2':
		         printf("请输入新的工号:\n");   //根据c的指修改对应员工的信息 
				 gets(staff[i].num);
				 break;
		case '3':
		         printf("请输入新的电话:\n");
				 gets(staff[i].tel);
				 break;
		case '4':
		         printf("请输入新的地址:\n");	     
			     gets(staff[i].address);
			     break;
	}
    printf("\n已修改\n"); 
	printf("工号\t姓名\t电话\t\t住址\n");
	printf("%s\t%s\t%s\t%s\t\n",staff[i].num,staff[i].name,staff[i].tel,staff[i].address);
	rewind(fp);
	fwrite(staff,sizeof(staff[0]),n,fp);
	fclose(fp);
}
    else
    printf("没有此员工信息，无法修改，退出此功能\n"); 

}

//删除函数 
void delete_fun()
{
	
	FILE *fp;
	int n=0,i;
	char c,s[10];
	printf("如果你想删除员工信息,你必须先找到他\n");
	i=search_fun();
	if(i!=-1)
{  printf("是否删除改员工数据\t  1.是   2.否\n");
   c=getchar();getchar();
   if(c=='1')
   {
   
 if((fp=fopen("staff.txt","r+"))==NULL)
  {
  	printf("不能打开文件");         //打开文件 
  	exit(0);
  } 
	
	while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)
	n++;
	
	for(;i<n;i++)
	staff[i]=staff[i+1];     //用后面信息覆盖前面信息实现删除 
	
	fp=fopen("staff.txt","w");
	fwrite(staff,sizeof(staff[0]),n-1,fp);   //重新打开文件并写入数据 
	fclose(fp);
	printf("已经删除该员工信息");
}
else
printf("取消删除员工信息");
}
   else
   printf("没有此员工信息\n");
}

//插入函数 
void insert_fun()
{
	FILE *fp;
	int n=0,i,j;
	printf("如果你想插入员工信息,请先找到你要插入之前的位置\n");
	i=search_fun();
	if(i!=-1)
	{
 if((fp=fopen("staff.txt","r+"))==NULL)
  {
  	printf("不能打开文件");         //打开文件 
  	exit(0);
  } 
	
	while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)
	n++;

	for(j=n-1;j>i-1;j--)
	staff[j+1]=staff[j];   //将员工数据往后移一个 
	
	printf("请输入新的员工工号\n");
      gets(staff[i].num);
      printf("请输入员工姓名\n");
	  gets(staff[i].name);        //输入员工信息 
	  printf("请输入新的员工电话\n");
	  gets(staff[i].tel);
	  printf("请输入新的员工住址\n");
	  gets(staff[i].address); 
	  printf("\n已插入\n");
	  rewind(fp);
	  fwrite(staff,sizeof(staff[0]),n+1,fp);//写入员工信息 
      fclose(fp);
    }
else
printf("没找到插入位置");
    
}

//排序函数 
void rank_fun()
{   char c;
    int n=0,j,k;
	FILE *fp;
	int i;
	struct staff_type temp; //定义中间变量来交换数据 
	
	 if((fp=fopen("staff.txt","r+"))==NULL)
  {
  	printf("不能打开文件");         //打开文件 
  	exit(0);
  } 
	
		while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)
     	n++;
     	
     printf("你想通过那种方式进行排序\n");
	 printf("1.姓名   2.工号\n");
	 	c=getchar();getchar();
	 	if(c=='1')
	 	{
	 		for(i=0;i<n-1;i++)
	 		  { int k=i;
				for(j=i+1;j<n;j++)
	 		      if(strcmp(staff[j].name,staff[k].name)<0)
	 		        {
	 		        	k=j;
					}
					if(i!=k)
					{
						temp=staff[i];
	 		         staff[i]=staff[k];
	 		         staff[k]=temp;	
					}
	 		 	}
		}                                  //利用冒泡法排序 
		if(c=='2')
		{
		for(i=0;i<n-1;i++)
	 		  { int k=i;
				for(j=i+1;j<n;j++)
	 		      if(strcmp(staff[j].num,staff[k].num)<0)
	 		        {
	 		        	k=j;
					}
					if(i!=k)
					{
						temp=staff[i];
	 		         staff[i]=staff[k];
	 		         staff[k]=temp;	
					}
	 		 	}	
		}    		    
	  rewind(fp);
	  fwrite(staff,sizeof(staff[0]),n,fp);
      fclose(fp);
      printf("已排序：\n");
      print_fun(); 
}

//添加函数 
void add_fun()
{   FILE *fp;
    int n=0;
	if((fp=fopen("staff.txt","a"))==NULL)
  {
  	printf("不能打开文件");         //以追加形式打开文件 
  	exit(0);
  } 
	
		while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)
     	n++;
    fclose(fp); 	
    if((fp=fopen("staff.txt","a"))==NULL)
  {
  	printf("不能打开文件");         //以追加形式打开文件 
  	exit(0);
  } 
	  printf("请输入新的员工工号\n");
      gets(staff[n].num);
      printf("请输入员工姓名\n");
	  gets(staff[n].name);        //输入员工信息 
	  printf("请输入新的员工电话\n");
	  gets(staff[n].tel);
	  printf("请输入新的员工住址\n");
	  gets(staff[n].address); 
	  printf("已添加\n");
	 fwrite(staff,sizeof(staff[0]),1,fp);
     fclose(fp);
	
}
