/***********************************************************
Copyright(C), 2018, Software Engineering Of 2017 One Class,
File Name: text.cpp
Author: Qin Zhiwei  Version: 0.1  Date: Undetermined
Description: This is a staff salary management system,
it can easily query wages data and calculate them.
Others: This is a test product.
Function List: 
1.read() //Read the data
2.write() //Save the data
3.find() //Find the date
4.list() //Browsing the data
5.modify() //Modify the data
6.del() //Delate the data
7.add() //Add the date
8.grsds() //Calculate the data
9.menu() //The main menu
10.deputy() //The deputy menu
11.main()//The Main function
History: 
1.Date: 
  Author: 
  Modification: 
***********************************************************/
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
using namespace std;
int n=0;
int read(); //读取职工工资数据
void write(); //保存职工工资数据
void find(); //查询职工工资数据
void list(); //浏览职工工资数据
void modify(); //修改职工工资数据
void del(); //删除职工工资数据
int del_ad(int);//删除函数的附件
void add(); //添加职工工资数据
float grsds(float x); //计算个人所得税
void menu(); //主菜单
void deputy(); //副菜单
struct zggz //职工数据
{
    int num;
    char name[10];
    float gwgz,xjgz,zwjt,jxgz,yfgz,grs,sfgz;
};
struct zggz zggz[100];
struct zggz zggz1[100];

/***********************************************************
Function:read
Discription:read the data
Calls:fopen,fseek,ftell,sizeof,fread,fclose
Callde By:menu,deputy,main
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:none
Others:none
***********************************************************/
int read() //读取职工工资数据
{
	FILE*fp;
	fp=fopen("gz.dat","ab+");
    fseek(fp,0,SEEK_SET);
    fseek(fp,0,SEEK_END);
    long x=ftell(fp)/sizeof(struct zggz); // 统计人数
    n=x;
    fseek(fp,0,SEEK_SET);
    if ( fp == NULL )
	{
		return -1 ;
	}
    fread( (char*)zggz , sizeof(struct zggz), n , fp ); //从文件中读n个结构体的数据
	fclose(fp);
}

/***********************************************************
Function:write
Discription:write the data
Calls:fopen,fwrite,sizeof,fclose,printf
Callde By:menu,deputy,modify,del,add
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:none
Others:none
***********************************************************/
void write() //保存职工工资数据
{
	FILE*fp;
	fp=fopen("gz.dat","wb+");
	fwrite(zggz,sizeof(struct zggz),n,fp);
	fclose(fp);
	printf("保存成功...\n");
	deputy();
}

/***********************************************************
Function:find
Discription:find the data
Calls:printf,scanf,deputy
Callde By:menu,deputy
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:none
Others:none
***********************************************************/
void find() //查询职工工资数据
{
	int gonghao,x;
	printf("请输入你要查询的工号(例如:1)");
	scanf("%d",&gonghao);
	for(int i=0;i<n;i++)
	{
		if(gonghao==zggz[i].num)
		{
			printf("职工工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资:\n");
			printf("%-8d %-6s %-8.0f %-8.0f %-8.0f %-8.0f %-8.0f %-10.0f %-8.0f\n",
		    zggz[i].num,
		    zggz[i].name,
		    zggz[i].gwgz,
		    zggz[i].xjgz,
		    zggz[i].zwjt,
		    zggz[i].jxgz,
		    zggz[i].yfgz,
		    zggz[i].grs,
		    zggz[i].sfgz);
			x = 1;
		}
	}
	if (x != 1)
	{
		printf("查无此人...");
	}
	deputy();
}

/***********************************************************
Function:list
Discription:browsing the data
Calls:printf,deputy
Callde By:menu,deputy
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:none
Others:none
***********************************************************/
void list() //浏览职工工资数据
{
	printf("职工工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资:\n");
	for(int i=0;i<n;i++)
	{
		printf("%-8d %-6s %-8.0f %-8.0f %-8.0f %-8.0f %-8.0f %-10.0f %-8.0f\n",
		zggz[i].num,
		zggz[i].name,
		zggz[i].gwgz,
		zggz[i].xjgz,
		zggz[i].zwjt,
		zggz[i].jxgz,
		zggz[i].yfgz,
		zggz[i].grs,
		zggz[i].sfgz);
	}
	printf("输入完成，共%d名职工...\n",n);
	deputy();
}

/***********************************************************
Function:modify
Discription:modify the data
Calls:printf,deputy,grsds
Callde By:menu,deputy
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:none
Others:none
***********************************************************/
void modify() //修改职工工资数据
{
	int gonghao,i,j,x,y,z;
	int num1;
    char name1[10];
	printf("请输入职工工号(例如1):");
	scanf("%d",&gonghao);
	for(i=0;i<n;i++)
	{
		if(gonghao==zggz[i].num)
		{
			printf("职工工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资:\n");
			printf("%-8d %-6s %-8.0f %-8.0f %-8.0f %-8.0f %-8.0f %4.0f %-8.0f\n",
			    zggz[i].num,
			    zggz[i].name,
			    zggz[i].gwgz,
			    zggz[i].xjgz,
			    zggz[i].zwjt,
			    zggz[i].jxgz,
			    zggz[i].yfgz,
			    zggz[i].grs,
			    zggz[i].sfgz);
			printf("请选择修改方式(整体修改请选1，单个数据修改请选2):");
			scanf("%d", &y);
			switch (y)
			{
		    case 1:
			    {
				    printf("请重新输入职工工号,姓名,岗位工资,薪级工资,职务津贴,绩效工资:\n");
				    scanf("%d %s %f %f %f %f",
					    &num1,
					    &name1,
					    &zggz[i].gwgz,
					    &zggz[i].xjgz,
					    &zggz[i].zwjt,
					    &zggz[i].jxgz);
					zggz[i].num = num1;
					strcpy_s(zggz[i].name, name1);
				    break;
			    }
			case 2:
			    {
				    printf("(修改职工工号选1,姓名2,岗位工资3,薪级工资4,职务津贴5,绩效工资6)\n");
				    printf("请输入要修改的数据:");
					scanf("%d",&z);
					switch (z)
					{
					case 1:
						{
							printf("请输入工号:");
							scanf("%d", &num1);
							zggz[i].num = num1;
						    break;
						}
					case 2:
						{
							printf("请输入姓名:");
							scanf("%s", &name1);
							strcpy_s(zggz[i].name, name1);
							break;
						}
					case 3:
						{
							printf("请输入岗位工资:");
							scanf("%f", &zggz[i].gwgz);
							break;
						}
					case 4:
						{
							printf("请输入薪级工资:");
							scanf("%f", &zggz[i].xjgz);
							break;
						}
					case 5:
						{
							printf("请输入职务津贴:");
							scanf("%f", &zggz[i].zwjt);
							break;
						}
					case 6:
						{
							printf("请输入绩效工资:");
							scanf("%f", &zggz[i].jxgz);
						}
					}
				}
			}
		}
		zggz[i].yfgz = zggz[i].gwgz + zggz[i].xjgz + zggz[i].zwjt + zggz[i].jxgz;
		zggz[i].grs = grsds(zggz[i].gwgz + zggz[i].xjgz + zggz[i].zwjt + zggz[i].jxgz);
		zggz[i].sfgz = zggz[i].yfgz - zggz[i].grs;
	}
	printf("是否保存修改到文件中(是请选择1,否请选择2)\n");
	scanf("%d",&x);
    switch(x)
	{
	case 1:
	    {
		    write();
		}
	case 2:
		{
		    break;
		}
	}
}

/***********************************************************
Function:del
Discription:delate the data
Calls:printf,,scanf,write,deputy,del_ad,
Callde By:menu,deputy
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:none
Others:none
***********************************************************/
void del()//删除职工工资数据
{
	int gonghao,x,y,i;
	printf("请输入要删除的职工数据(例如001):");
	scanf("%d",&gonghao);
	if (n == 0)
	{
		printf("目前没有任何职工数据");
	}
	else
	{
		for (i = 0; i < n - 1; i++)
		{
			if (gonghao == zggz[i].num)
			{
				del_ad(i);
			}
		}
	}
	printf("是否保存修改到文件中(是请选择1,否请选择2)\n");
	scanf("%d",&y);
    switch(y)
	{
	case 1:
		{
			write();
		}
	case 2:
		{
            deputy();
		}
	}
}

/***********************************************************
Function:del_ad
Discription:del's extra function
Calls:none
Callde By:del
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:0
Others:none
***********************************************************/
int del_ad(int x)
{
	int i=x;
	for(;i<n-1;i++)
	{
		zggz[i].num = zggz[i + 1].num;
	    strcpy_s(zggz1[i].name, zggz[i + 1].name);
	    zggz[i].gwgz = zggz[i + 1].gwgz;
	    zggz[i].xjgz = zggz[i + 1].xjgz;
	    zggz[i].zwjt = zggz[i + 1].zwjt;
	    zggz[i].jxgz = zggz[i + 1].jxgz;
	    zggz[i].yfgz = zggz[i + 1].yfgz;
	    zggz[i].grs = zggz[i + 1].grs;
	    zggz[i].sfgz = zggz[i + 1].sfgz;
	}
	n--;
	return 0;
};

/***********************************************************
Function:add
Discription:add the data
Calls:printf,scanf,write,grsds
Callde By:menu,deputy
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:none
Others:none
***********************************************************/
void add() //添加职工工资数据
{
	int i,j,k,x,y;
    int num1;
    char name1[10];
	printf("请输入您想要添加的职工人数(最大容量为100人):");
	scanf("%d",&j);
	for(i=n;i<j+n;i++)
	{
		printf("请输入职工工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资:\n");
		scanf("%d %s %f %f %f %f",
		&num1,
		&name1,
		&zggz[i].gwgz,
		&zggz[i].xjgz,
		&zggz[i].zwjt,
		&zggz[i].jxgz);
	    zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz;
        zggz[i].num=num1;
        strcpy_s(zggz[i].name,name1);
	    zggz[i].grs=grsds(zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz);
	    zggz[i].sfgz=zggz[i].yfgz-zggz[i].grs;
	}
	n += j;
	write();
	printf("添加成功，数据已保存\n");
}

/***********************************************************
Function:grsds
Discription:Calculate the data
Calls:
Callde By:menu,deputy
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:grs
Others:none
***********************************************************/
float grsds(float x) //计算个人所得税
{
    float grs;
    if(x<=500)
	{
	    grs=x*0.05;
	}
	else if(x>500&&x<=2000)
	{
	    grs=500*0.05+(x-500)*0.1;
	}
	else if(x>2000&&x<=5000)
	{
	    grs=500*0.05+1500*0.1+(x-2000)*0.15;
	}
	else if(x>5000&&x<=20000)
	{
	    grs=500*0.05+1500*0.1+3000*0.15+(x-5000)*0.2;
	}
	else if(x>20000&&x<=40000)
	{
	    grs=500*0.05+1500*0.1+3000*0.15+15000*0.2+(x-20000)*0.25;
	}
	else if(x>40000&&x<=60000)
	{
	    grs=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+(x-40000)*0.3;
	}
	else if(x>60000&&x<=80000)
	{
	    grs=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.3+(x-60000)*0.35;
	}
	else if(x>80000&&x<=100000)
	{
	    grs=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.3+20000*0.35+(x-80000)*0.4;
	}
	else
	{
	    grs=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.3+20000*0.35+20000*0.4+(x-100000)*0.45;
	}
    return grs;
}

/***********************************************************
Function:menu
Discription://The main menu
Calls:write,find,list,modify,del,add
Callde By:main
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:
Others:none
***********************************************************/
void menu()//主菜单
{
	printf("###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统  ###\n");
	printf("\n请选择<1 - 7> :\n");
	printf("================================================================\n");
	printf("|         1. 查询职工工资记录                                  |\n");
	printf("|         2. 修改职工工资记录                                  |\n");
	printf("|         3. 添加职工工资记录                                  |\n");
	printf("|         4. 删除职工工资记录                                  |\n");
	printf("|         5. 保存数据到文件                                    |\n");
	printf("|         6. 浏览职工数据                                      |\n");
	printf("|         7. 退出系统                                          |\n");
	printf("================================================================\n");
	printf("\n     你的选择是:");
	int x;
	scanf("%d",&x);
	switch(x)
	{
	case 1:
		{
		    system("cls");
			find();break;
		}
	case 2:
		{
		    system("cls");
			modify();break;
		}
	case 3:
		{
		    system("cls");
			add();break;
		}
	case 4:
		{
		    system("cls");
			del();break;
		}
	case 5:
		{
		    system("cls");
			write();break;
		}
	case 6:
		{
		    system("cls");
			list();break;
		}
	case 7:
		{
			printf("感谢使用...\n");
			exit(1);
		}
	}
}

/***********************************************************
Function:deputy
Discription://The deputy menu
Calls:write,find,list,modify,del,add
Callde By:write,find,list,modify,del
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:
Others:none
***********************************************************/
void deputy()//副菜单
{
	read();
	printf("\n请选择<1 - 7> :\n");
	printf("================================================================\n");
	printf("|         1. 查询职工工资记录                                  |\n");
	printf("|         2. 修改职工工资记录                                  |\n");
	printf("|         3. 添加职工工资记录                                  |\n");
	printf("|         4. 删除职工工资记录                                  |\n");
	printf("|         5. 保存数据到文件                                    |\n");
	printf("|         6. 浏览职工数据                                      |\n");
	printf("|         7. 退出系统                                          |\n");
	printf("================================================================\n");
	printf("\n     你的选择是:");
	int x;
    cin>>x;
	switch(x)
	{
	case 1:
		{
		    system("cls");
			find();break;
		}
	case 2:
		{
		    system("cls");
			modify();break;
		}
	case 3:
		{
		    system("cls");
			add();break;
		}
	case 4:
		{
		    system("cls");
			del();break;
		}
	case 5:
		{
		    system("cls");
			write();break;
		}
	case 6:
		{
		    system("cls");
			list();break;
		}
	case 7:
		{
			printf("感谢使用...\n");
			exit(1);
		}
	}
	deputy();
}

/***********************************************************
Function:deputy
Discription://The main function
Calls:read,menu
Callde By:none
Table Accessed:none
Table Update:none
Input:Please look at the function
Output:Please look at the function
Return:0
Others:none
***********************************************************/
int main()
{
	read();
	menu();
	system("pause");
    return 0;
}