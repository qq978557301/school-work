/***********************************************************
Copyright(C), 2018, Software Engineering Of 2017 One Class,
File Name: text.cpp
Author: Qin Zhiwei  Version: 0.1  Date: Undetermined
Description: This is a staff salary management system,
it can easily query wages data and calculate them.
Others: This is a test product.
Function List: 
1.read() //��ȡְ����������
2.write() //����ְ����������
3.write1() //����ɾ����ְ����������
4.find() //��ѯְ����������
5.list() //���ְ����������
6.modify() //�޸�ְ����������
7.del() //ɾ��ְ����������
8.add() //���ְ����������
9.grsds() //�����������˰
10.main() //���˵�1
11.main2() //���˵�2
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
void write1(); //����ɾ����ְ����������
void find(); //��ѯְ����������
void list(); //���ְ����������
void modify(); //�޸�ְ����������
void del(); //ɾ��ְ����������
void add(); //���ְ����������
float grsds(float x); //�����������˰
void menu1(); //���˵�1
void menu2(); //���˵�2
struct zggz //ְ������
{
    char num[10];
    char name[10];
    float gwgz,xjgz,zwjt,jxgz,yfgz,grs,sfgz;
};
struct zggz zggz[100];
struct zggz zggz1[100];

int read() //��ȡְ����������
{
	FILE*fp;
	fp=fopen("gz.dat","a+b");
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

void write() //����ְ����������
{
	FILE*fp;
	fp=fopen("gz.dat","wb+");
	fwrite(zggz,sizeof(struct zggz),n,fp);
	fclose(fp);
	//cout<<"����ɹ�...\n";
	printf("����ɹ�...\n");
	menu2();
}

void write1() //����ɾ����ְ����������
{
	FILE*fp;
	fp=fopen("gz.dat","wb+");
	fwrite(zggz1,sizeof(struct zggz),n-1,fp);
	fclose(fp);
	//cout<<"����ɹ�...\n";
	printf("����ɹ�...\n");
	menu2();
}

void find() //��ѯְ����������
{
	int x,gonghao;
	//cout<<"��������Ҫ��ѯ�Ĺ���(����:1)";
	printf("��������Ҫ��ѯ�Ĺ���(����:1)");
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

void list() //���ְ����������
{
	//cout<<"ְ������ ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������:\n";
	printf("ְ������ ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������:\n");
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
	//cout<<"������ɣ���"<<n<<"��ְ��...\n";
	printf("������ɣ���%d��ְ��...\n",n);
	menu2();
}

void modify() //�޸�ְ����������
{
	int gonghao,x,y;
	char num1[10];
    char name1[10];
	//cout<<"������ְ������(����1):";
	printf("������ְ������(����1):");
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
	//cout<<"����������ְ���������:\n";
	printf("����������ְ���������:\n");
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
	//cout<<"�Ƿ񱣴��޸�(����ѡ��1,����ѡ��2,�񽫹رճ���)\n";
	printf("�Ƿ񱣴��޸�(����ѡ��1,����ѡ��2,�񽫹رճ���)\n");
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

void del()//ɾ��ְ����������
{
	int gonghao,x,y,i;
	//cout<<"������Ҫɾ��������(����1):";
	printf("������Ҫɾ����ְ������(����1):");
	//cin>>x;
	scanf("%d",&x);
	gonghao=x-1;
	for(i=0;i<n-1;i++)
	{
		if(i<gonghao) //�����Ҫɾ��������ǰ,��ֱ�ӽ�zggz�����λ���ϵ����ݸ�ֵ��zggz1������Ӧλ��
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
		else //�����Ҫɾ�������ݺ�,�ͽ�zggz�����һ��λ�õ����ݸ���zggz1�����ǰһ��λ��
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
	//cout<<"�Ƿ񱣴��޸�(����ѡ��1,����ѡ��2,�񽫹رճ���)\n";
	printf("�Ƿ񱣴��޸�(����ѡ��1,����ѡ��2,�񽫹رճ���)\n");
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

void add() //���ְ����������
{
	int i,j,k;
    char num1[10];
    char name1[10];
	//cout<<"����������Ҫ��ӵ�ְ������(�������Ϊ100��):";
	printf("����������Ҫ��ӵ�ְ������(�������Ϊ100��):");
	//cin>>j;
	scanf("%d",&j);
	for(i=n;i<n+j;i++)
	{
	    //cout<<"������ְ�����š���������λ���ʡ�н�����ʡ�ְ���������Ч����:\n";
		printf("������ְ�����š���������λ���ʡ�н�����ʡ�ְ���������Ч����:\n");
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
	//cout<<"�Ƿ񱣴��޸�(����ѡ��1,����ѡ��2,�񽫹رճ���)\n";
	printf("�Ƿ񱣴��޸�(����ѡ��1,����ѡ��2,�񽫹رճ���)\n");
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

void menu1()//���˵�
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
    /*cout<<"               <----------���ʹ���ϵͳ---------->          "<<endl;
    cout<<"               <            1.��ѯ              >          "<<endl;
    cout<<"               <            2.���              >          "<<endl;
    cout<<"               <            3.�޸�              >          "<<endl;
    cout<<"               <            4.���              >          "<<endl;
    cout<<"               <            5.ɾ��              >          "<<endl;
    cout<<"               <            6.����              >          "<<endl;
    cout<<"               <            7.�˳�              >          "<<endl;
    cout<<"               <-------------------------------->          "<<endl;
	cout<<"����������ѡ����Ҫʹ�õĹ���(�س�ȷ��):";*/
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
			//cout<<"��лʹ��...\n";
			printf("��лʹ��...\n");
			exit(1);
		}
	}
	//cout<<"����������1-7��ѡ�����蹦��...\n";
	menu2();
}
void menu2()
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
	/*cout<<"          <            1.��ѯ              >          "<<endl;
    cout<<"          <            2.���              >          "<<endl;
    cout<<"          <            3.�޸�              >          "<<endl;
    cout<<"          <            4.���              >          "<<endl;
    cout<<"          <            5.ɾ��              >          "<<endl;
    cout<<"          <            6.����              >          "<<endl;
    cout<<"          <            7.�˳�              >          "<<endl;
	cout<<"����������ѡ����Ҫʹ�õĹ���(�س�ȷ��):";*/
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
			//cout<<"��лʹ��...\n";
			printf("��лʹ��...\n");
			exit(1);
		}
	}
	//cout<<"����������1-7��ѡ�����蹦��...\n";
	menu2();
}

int main()
{
	read();
	menu1();
	system("pause");
    return 0;
}
