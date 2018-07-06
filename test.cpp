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
int read(); //��ȡְ����������
void write(); //����ְ����������
void find(); //��ѯְ����������
void list(); //���ְ����������
void modify(); //�޸�ְ����������
void del(); //ɾ��ְ����������
int del_ad(int);//ɾ�������ĸ���
void add(); //���ְ����������
float grsds(float x); //�����������˰
void menu(); //���˵�
void deputy(); //���˵�
struct zggz //ְ������
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
int read() //��ȡְ����������
{
	FILE*fp;
	fp=fopen("gz.dat","ab+");
    fseek(fp,0,SEEK_SET);
    fseek(fp,0,SEEK_END);
    long x=ftell(fp)/sizeof(struct zggz); // ͳ������
    n=x;
    fseek(fp,0,SEEK_SET);
    if ( fp == NULL )
	{
		return -1 ;
	}
    fread( (char*)zggz , sizeof(struct zggz), n , fp ); //���ļ��ж�n���ṹ�������
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
void write() //����ְ����������
{
	FILE*fp;
	fp=fopen("gz.dat","wb+");
	fwrite(zggz,sizeof(struct zggz),n,fp);
	fclose(fp);
	printf("����ɹ�...\n");
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
void find() //��ѯְ����������
{
	int gonghao,x;
	printf("��������Ҫ��ѯ�Ĺ���(����:1)");
	scanf("%d",&gonghao);
	for(int i=0;i<n;i++)
	{
		if(gonghao==zggz[i].num)
		{
			printf("ְ������ ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������:\n");
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
		printf("���޴���...");
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
void list() //���ְ����������
{
	printf("ְ������ ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������:\n");
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
	printf("������ɣ���%d��ְ��...\n",n);
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
void modify() //�޸�ְ����������
{
	int gonghao,i,j,x,y,z;
	int num1;
    char name1[10];
	printf("������ְ������(����1):");
	scanf("%d",&gonghao);
	for(i=0;i<n;i++)
	{
		if(gonghao==zggz[i].num)
		{
			printf("ְ������ ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������:\n");
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
			printf("��ѡ���޸ķ�ʽ(�����޸���ѡ1�����������޸���ѡ2):");
			scanf("%d", &y);
			switch (y)
			{
		    case 1:
			    {
				    printf("����������ְ������,����,��λ����,н������,ְ�����,��Ч����:\n");
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
				    printf("(�޸�ְ������ѡ1,����2,��λ����3,н������4,ְ�����5,��Ч����6)\n");
				    printf("������Ҫ�޸ĵ�����:");
					scanf("%d",&z);
					switch (z)
					{
					case 1:
						{
							printf("�����빤��:");
							scanf("%d", &num1);
							zggz[i].num = num1;
						    break;
						}
					case 2:
						{
							printf("����������:");
							scanf("%s", &name1);
							strcpy_s(zggz[i].name, name1);
							break;
						}
					case 3:
						{
							printf("�������λ����:");
							scanf("%f", &zggz[i].gwgz);
							break;
						}
					case 4:
						{
							printf("������н������:");
							scanf("%f", &zggz[i].xjgz);
							break;
						}
					case 5:
						{
							printf("������ְ�����:");
							scanf("%f", &zggz[i].zwjt);
							break;
						}
					case 6:
						{
							printf("�����뼨Ч����:");
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
	printf("�Ƿ񱣴��޸ĵ��ļ���(����ѡ��1,����ѡ��2)\n");
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
void del()//ɾ��ְ����������
{
	int gonghao,x,y,i;
	printf("������Ҫɾ����ְ������(����001):");
	scanf("%d",&gonghao);
	if (n == 0)
	{
		printf("Ŀǰû���κ�ְ������");
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
	printf("�Ƿ񱣴��޸ĵ��ļ���(����ѡ��1,����ѡ��2)\n");
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
void add() //���ְ����������
{
	int i,j,k,x,y;
    int num1;
    char name1[10];
	printf("����������Ҫ��ӵ�ְ������(�������Ϊ100��):");
	scanf("%d",&j);
	for(i=n;i<j+n;i++)
	{
		printf("������ְ�����š���������λ���ʡ�н�����ʡ�ְ���������Ч����:\n");
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
	printf("��ӳɹ��������ѱ���\n");
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
float grsds(float x) //�����������˰
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
void menu()//���˵�
{
	printf("###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###\n");
	printf("\n��ѡ��<1 - 7> :\n");
	printf("================================================================\n");
	printf("|         1. ��ѯְ�����ʼ�¼                                  |\n");
	printf("|         2. �޸�ְ�����ʼ�¼                                  |\n");
	printf("|         3. ���ְ�����ʼ�¼                                  |\n");
	printf("|         4. ɾ��ְ�����ʼ�¼                                  |\n");
	printf("|         5. �������ݵ��ļ�                                    |\n");
	printf("|         6. ���ְ������                                      |\n");
	printf("|         7. �˳�ϵͳ                                          |\n");
	printf("================================================================\n");
	printf("\n     ���ѡ����:");
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
			printf("��лʹ��...\n");
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
void deputy()//���˵�
{
	read();
	printf("\n��ѡ��<1 - 7> :\n");
	printf("================================================================\n");
	printf("|         1. ��ѯְ�����ʼ�¼                                  |\n");
	printf("|         2. �޸�ְ�����ʼ�¼                                  |\n");
	printf("|         3. ���ְ�����ʼ�¼                                  |\n");
	printf("|         4. ɾ��ְ�����ʼ�¼                                  |\n");
	printf("|         5. �������ݵ��ļ�                                    |\n");
	printf("|         6. ���ְ������                                      |\n");
	printf("|         7. �˳�ϵͳ                                          |\n");
	printf("================================================================\n");
	printf("\n     ���ѡ����:");
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
			printf("��лʹ��...\n");
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