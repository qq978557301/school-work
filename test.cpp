/***********************************************************
Copyright(C), 2018, Software Engineering Of 2017 One Class,
File Name: text.cpp
Author: Qin Zhiwei  Version: 0.1  Date: Undetermined
Description: This is a staff salary management system,
it can easily query wages data and calculate them.
Others: This is a test product.
Function List: 
1.read() //读取职工工资数据
2.write() //保存职工工资数据
3.write1() //保存删除后职工工资数据
4.find() //查询职工工资数据
5.list() //浏览职工工资数据
6.modify() //修改职工工资数据
7.del() //删除职工工资数据
8.add() //添加职工工资数据
9.grsds() //计算个人所得税
10.main() //主菜单1
11.main2() //主菜单2
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
void write1(); //保存删除后职工工资数据
void find(); //查询职工工资数据
void list(); //浏览职工工资数据
void modify(); //修改职工工资数据
void del(); //删除职工工资数据
void add(); //添加职工工资数据
float grsds(float x); //计算个人所得税
void menu1(); //主菜单1
void menu2(); //主菜单2
struct zggz //职工数据
{
    char num[10];
    char name[10];
    float gwgz,xjgz,zwjt,jxgz,yfgz,grs,sfgz;
};
struct zggz zggz[100];
struct zggz zggz1[100];

int read() //读取职工工资数据
{
	FILE*fp;
	fp=fopen("gz.dat","a+b");
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

void write() //保存职工工资数据
{
	FILE*fp;
	fp=fopen("gz.dat","wb+");
	fwrite(zggz,sizeof(struct zggz),n,fp);
	fclose(fp);
	//cout<<"保存成功...\n";
	printf("保存成功...\n");
	menu2();
}

void write1() //保存删除后职工工资数据
{
	FILE*fp;
	fp=fopen("gz.dat","wb+");
	fwrite(zggz1,sizeof(struct zggz),n-1,fp);
	fclose(fp);
	//cout<<"保存成功...\n";
	printf("保存成功...\n");
	menu2();
}

void find() //查询职工工资数据
{
	int x,gonghao;
	//cout<<"请输入你要查询的工号(例如:1)";
	printf("请输入你要查询的工号(例如:1)");
	//cin>>x;
	scanf("%d",&x);
	gonghao=x-1;
	//cout<<zggz[gonghao].num<<" "<<zggz[gonghao].name<<" "<<zggz[gonghao].gwgz<<" "<<zggz[gonghao].xjgz<<" "<<zggz[gonghao].zwjt<<" "<<zggz[gonghao].jxgz<<" "<<zggz[gonghao].yfgz<<" "<<zggz[gonghao].grs<<" "<<zggz[gonghao].sfgz<<endl;
	printf("%s %s %.0f %.0f %.0f %.0f %.0f %.0f %.0f\n",
		zggz[gonghao].num,
		zggz[gonghao].name,
		zggz[gonghao].gwgz,
		zggz[gonghao].xjgz,
		zggz[gonghao].zwjt,
		zggz[gonghao].jxgz,
		zggz[gonghao].yfgz,
		zggz[gonghao].grs,
		zggz[gonghao].sfgz);
	menu2();
}

void list() //浏览职工工资数据
{
	//cout<<"职工工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资:\n";
	printf("职工工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资:\n");
	for(int i=0;i<n;i++)
	{
		//cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwgz<<" "<<zggz[i].xjgz<<" "<<zggz[i].zwjt<<" "<<zggz[i].jxgz<<" "<<zggz[i].yfgz<<" "<<zggz[i].grs<<" "<<zggz[i].sfgz<<endl;
		printf("%s %s %.0f %.0f %.0f %.0f %.0f %.0f %.0f\n",
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
	//cout<<"输入完成，共"<<n<<"名职工...\n";
	printf("输入完成，共%d名职工...\n",n);
	menu2();
}

void modify() //修改职工工资数据
{
	int gonghao,x,y;
	char num1[10];
    char name1[10];
	//cout<<"请输入职工工号(例如1):";
	printf("请输入职工工号(例如1):");
    //cin>>x;
	scanf("%d",&x);
	gonghao=x-1;
	//cout<<zggz[gonghao].num<<" "<<zggz[gonghao].name<<" "<<zggz[gonghao].gwgz<<" "<<zggz[gonghao].xjgz<<" "<<zggz[gonghao].zwjt<<" "<<zggz[gonghao].jxgz<<" "<<zggz[gonghao].yfgz<<" "<<zggz[gonghao].grs<<" "<<zggz[gonghao].sfgz<<endl;
	printf("%s %s %.0f %.0f %.0f %.0f %.0f %.0f %.0f\n",
		zggz[gonghao].num,
		zggz[gonghao].name,
		zggz[gonghao].gwgz,
		zggz[gonghao].xjgz,
		zggz[gonghao].zwjt,
		zggz[gonghao].jxgz,
		zggz[gonghao].yfgz,
		zggz[gonghao].grs,
		zggz[gonghao].sfgz);
	//cout<<"请重新输入职工相关数据:\n";
	printf("请重新输入职工相关数据:\n");
	//cin>>num1>>name1>>zggz[gonghao].gwgz>>zggz[gonghao].xjgz>>zggz[gonghao].zwjt>>zggz[gonghao].jxgz;
	scanf("%s %s %f %f %f %f",
		&num1,
		&name1,
		&zggz[gonghao].gwgz,
		&zggz[gonghao].xjgz,
		&zggz[gonghao].zwjt,
		&zggz[gonghao].jxgz);
	zggz[gonghao].yfgz=zggz[gonghao].gwgz+zggz[gonghao].xjgz+zggz[gonghao].zwjt+zggz[gonghao].jxgz;
    strcpy(zggz[gonghao].num,num1);
    strcpy(zggz[gonghao].name,name1);
    zggz[gonghao].grs=grsds(zggz[gonghao].gwgz+zggz[gonghao].xjgz+zggz[gonghao].zwjt+zggz[gonghao].jxgz);
    zggz[gonghao].sfgz=zggz[gonghao].yfgz-zggz[gonghao].grs;
	//cout<<"是否保存修改(是请选择1,否请选择2,否将关闭程序)\n";
	printf("是否保存修改(是请选择1,否请选择2,否将关闭程序)\n");
	//cin>>y;
	scanf("%d",&y);
    switch(y)
	{
	case 1:
		{
			write();
		}
	case 2:
		{
            exit(1);
		}
	}
	menu2();
}

void del()//删除职工工资数据
{
	int gonghao,x,y,i;
	//cout<<"请输入要删除的数据(例如1):";
	printf("请输入要删除的职工数据(例如1):");
	//cin>>x;
	scanf("%d",&x);
	gonghao=x-1;
	for(i=0;i<n-1;i++)
	{
		if(i<gonghao) //如果在要删除的数据前,就直接将zggz数组该位置上的数据赋值给zggz1数组相应位置
		{
		    strcpy(zggz1[i].num,zggz[i].num);
		    strcpy(zggz1[i].name,zggz[i].name);
		    zggz1[i].gwgz=zggz[i].gwgz;
		    zggz1[i].xjgz=zggz[i].xjgz;
		    zggz1[i].zwjt=zggz[i].zwjt;
		    zggz1[i].jxgz=zggz[i].jxgz;
		    zggz1[i].yfgz=zggz[i].yfgz;
		    zggz1[i].grs=zggz[i].grs;
		    zggz1[i].sfgz=zggz[i].sfgz;
		}
		else //如果在要删除的数据后,就将zggz数组后一个位置的数据赋给zggz1数组的前一个位置
		{
			strcpy(zggz1[i].num,zggz[i+1].num);
		    strcpy(zggz1[i].name,zggz[i+1].name);
		    zggz1[i].gwgz=zggz[i+1].gwgz;
		    zggz1[i].xjgz=zggz[i+1].xjgz;
		    zggz1[i].zwjt=zggz[i+1].zwjt;
		    zggz1[i].jxgz=zggz[i+1].jxgz;
		    zggz1[i].yfgz=zggz[i+1].yfgz;
		    zggz1[i].grs=zggz[i+1].grs;
		    zggz1[i].sfgz=zggz[i+1].sfgz;
		}
	}
	//cout<<"是否保存修改(是请选择1,否请选择2,否将关闭程序)\n";
	printf("是否保存修改(是请选择1,否请选择2,否将关闭程序)\n");
	//cin>>y;
	scanf("%d",&y);
    switch(y)
	{
	case 1:
		{
			write1();
		}
	case 2:
		{
            exit(1);
		}
	}
}

void add() //添加职工工资数据
{
	int i,j,k;
    char num1[10];
    char name1[10];
	//cout<<"请输入您想要添加的职工人数(最大容量为100人):";
	printf("请输入您想要添加的职工人数(最大容量为100人):");
	//cin>>j;
	scanf("%d",&j);
	for(i=n;i<n+j;i++)
	{
	    //cout<<"请输入职工工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资:\n";
		printf("请输入职工工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资:\n");
        //cin>>num1>>name1>>zggz[i].gwgz>>zggz[i].xjgz>>zggz[i].zwjt>>zggz[i].jxgz;
		scanf("%s %s %f %f %f %f",
		&num1,
		&name1,
		&zggz[i].gwgz,
		&zggz[i].xjgz,
		&zggz[i].zwjt,
		&zggz[i].jxgz);
	    zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz;
        strcpy(zggz[i].num,num1);
        strcpy(zggz[i].name,name1);
	    zggz[i].grs=grsds(zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz);
	    zggz[i].sfgz=zggz[i].yfgz-zggz[i].grs;
	}
	n+=j;
	//cout<<"是否保存修改(是请选择1,否请选择2,否将关闭程序)\n";
	printf("是否保存修改(是请选择1,否请选择2,否将关闭程序)\n");
	//cin>>k;
	scanf("%d",&k);
    switch(k)
	{
	case 1:
		{
			write();
		}
	case 2:
		{
            exit(1);
		}
	}
}

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

void menu1()//主菜单
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
    /*cout<<"               <----------工资管理系统---------->          "<<endl;
    cout<<"               <            1.查询              >          "<<endl;
    cout<<"               <            2.浏览              >          "<<endl;
    cout<<"               <            3.修改              >          "<<endl;
    cout<<"               <            4.添加              >          "<<endl;
    cout<<"               <            5.删除              >          "<<endl;
    cout<<"               <            6.保存              >          "<<endl;
    cout<<"               <            7.退出              >          "<<endl;
    cout<<"               <-------------------------------->          "<<endl;
	cout<<"请输入数字选择需要使用的功能(回车确定):";*/
	int x;
    //cin>>x;
	scanf("%d",&x);
	switch(x)
	{
	case 1:
		{
			find();break;
		}
	case 2:
		{
			modify();break;
		}
	case 3:
		{
			add();break;
		}
	case 4:
		{
			del();break;
		}
	case 5:
		{
			write();break;
		}
	case 6:
		{
			list();break;
		}
	case 7:
		{
			//cout<<"感谢使用...\n";
			printf("感谢使用...\n");
			exit(1);
		}
	}
	//cout<<"请输入数字1-7以选择所需功能...\n";
	menu2();
}
void menu2()
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
	/*cout<<"          <            1.查询              >          "<<endl;
    cout<<"          <            2.浏览              >          "<<endl;
    cout<<"          <            3.修改              >          "<<endl;
    cout<<"          <            4.添加              >          "<<endl;
    cout<<"          <            5.删除              >          "<<endl;
    cout<<"          <            6.保存              >          "<<endl;
    cout<<"          <            7.退出              >          "<<endl;
	cout<<"请输入数字选择需要使用的功能(回车确定):";*/
	int x;
    cin>>x;
	switch(x)
	{
	case 1:
		{
			find();break;
		}
	case 2:
		{
			modify();break;
		}
	case 3:
		{
			add();break;
		}
	case 4:
		{
			del();break;
		}
	case 5:
		{
			write();break;
		}
	case 6:
		{
			list();break;
		}
	case 7:
		{
			//cout<<"感谢使用...\n";
			printf("感谢使用...\n");
			exit(1);
		}
	}
	//cout<<"请输入数字1-7以选择所需功能...\n";
	menu2();
}

int main()
{
	read();
	menu1();
	system("pause");
    return 0;
}
