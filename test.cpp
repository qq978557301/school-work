/***********************************************************
Copyright(C), 2018, Software Engineering Of 2017 One Class,
File Name: text.cpp
Author: Qin Zhiwei  Version: 0.1  Date: Undetermined
Description: This is a staff salary management system,
it can easily query wages data and calculate them.
Others: This is a test product.
Function List:
1.read()
2.write()
3.find()
4.list()
5.modify()
6.del()
7.add()
8.grsds
9.main
History:
1.Date:
Author:
Modification:
***********************************************************/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int i;
int n = 0;
void read();//读取职工工资数据
void write();//保存职工工资数据
void find();//查询职工工资数据
void list();//浏览职工工资数据
void modify();//修改职工工资数据
void del();//删除职工工资数据
void add();//添加职工工资数据
float grsds(float x);//计算个人所得税
void menu1();//主菜单1
void menu2();//主菜单2
struct zggz//职工数据
{
	char num[10];
	char name[10];
	float gwgz, xjgz, zwjt, jxgz, yfgz, grs, sfgz;
};
struct zggz zggz[100];
int main()
{
	menu1();
	system("pause");
	return 0;
}

void read()//读取职工工资数据
{
	ifstream fin("gz.dat", ios::in);//以输入形式打开gz.dat
	if (!fin)
	{
		cout << "Cannot open the file.\n";
		exit(1);
	}
	fin.seekg(0, ios::end);
	long longBytes = fin.tellg() / sizeof(zggz);
	n = longBytes;
	fin.read((char*)&::zggz, sizeof(zggz));
	fin.close();
}

void write()//保存职工工资数据
{}

void find()//查询职工工资数据
{}

void list()//浏览职工工资数据
{
	ifstream fin("gz.dat", ios::in);//以输入形式打开gz.dat
	if (!fin)
	{
		cout << "Cannot open the file.\n";
		exit(1);
	}
	cout << "职工工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资:\n";
	char str[sizeof(zggz)];
	while (fin)
	{
		fin.getline(str, sizeof(zggz));
		cout << str << endl;
	}
	fin.close();
	cout << "输入完成，共" << n << "名职工...\n";
	menu2();
}

void modify()//修改职工工资数据
{}

void del()//删除职工工资数据
{}

void add()//添加职工工资数据
{
	int j;
	char num1[10];
	char name1[10];
	cout << "请输入您想要添加的职工人数(最大容量为100人):";
	cin >> j;
	for (i=n; i<j; i++)
	{
		cout << "请输入职工工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资:\n";
		cin >> num1 >> name1 >> zggz[i].gwgz >> zggz[i].xjgz >> zggz[i].zwjt >> zggz[i].jxgz;
		cout << endl;
		zggz[i].yfgz = zggz[i].gwgz + zggz[i].xjgz + zggz[i].zwjt + zggz[i].jxgz;
		strcpy_s(zggz[i].num, num1);
		strcpy_s(zggz[i].name, name1);
		zggz[i].grs = grsds(zggz[i].gwgz + zggz[i].xjgz + zggz[i].zwjt + zggz[i].jxgz);
		zggz[i].sfgz = zggz[i].yfgz - zggz[i].grs;
		if (i == 0)
		{
			ofstream fout("gz.dat", ios::out || ios::binary);//以输出形式打开gz.dat
			if (!fout)
			{
				cout << "Cannot open the file.\n";
				exit(1);
			}
			fout << zggz[i].num << " " << zggz[i].name << " " << zggz[i].gwgz << " " << zggz[i].xjgz << " " << zggz[i].zwjt << " " << zggz[i].jxgz << " " << zggz[i].yfgz << " " << zggz[i].grs << " " << zggz[i].sfgz << endl;
			fout.close();
		}
		else
		{
			ofstream fout("gz.dat", ios::app || ios::binary);//以追加形式打开gz.dat
			if (!fout)
			{
				cout << "Cannot open the file.\n";
				exit(1);
			}
			fout << zggz[i].num << " " << zggz[i].name << " " << zggz[i].gwgz << " " << zggz[i].xjgz << " " << zggz[i].zwjt << " " << zggz[i].jxgz << " " << zggz[i].yfgz << " " << zggz[i].grs << " " << zggz[i].sfgz << endl;
			fout.close();
		}
	}
	cout << "添加成功...\n";
	menu2();
}

float grsds(float x)//计算个人所得税
{
	float grs;
	if (x <= 500)
	{
		grs = x * 0.05;
	}
	else if (x>500 && x <= 2000)
	{
		grs = 500 * 0.05 + (x - 500)*0.1;
	}
	else if (x>2000 && x <= 5000)
	{
		grs = 500 * 0.05 + 1500 * 0.1 + (x - 2000)*0.15;
	}
	else if (x>5000 && x <= 20000)
	{
		grs = 500 * 0.05 + 1500 * 0.1 + 3000 * 0.15 + (x - 5000)*0.2;
	}
	else if (x>20000 && x <= 40000)
	{
		grs = 500 * 0.05 + 1500 * 0.1 + 3000 * 0.15 + 15000 * 0.2 + (x - 20000)*0.25;
	}
	else if (x>40000 && x <= 60000)
	{
		grs = 500 * 0.05 + 1500 * 0.1 + 3000 * 0.15 + 15000 * 0.2 + 20000 * 0.25 + (x - 40000)*0.3;
	}
	else if (x>60000 && x <= 80000)
	{
		grs = 500 * 0.05 + 1500 * 0.1 + 3000 * 0.15 + 15000 * 0.2 + 20000 * 0.25 + 20000 * 0.3 + (x - 60000)*0.35;
	}
	else if (x>80000 && x <= 100000)
	{
		grs = 500 * 0.05 + 1500 * 0.1 + 3000 * 0.15 + 15000 * 0.2 + 20000 * 0.25 + 20000 * 0.3 + 20000 * 0.35 + (x - 80000)*0.4;
	}
	else
	{
		grs = 500 * 0.05 + 1500 * 0.1 + 3000 * 0.15 + 15000 * 0.2 + 20000 * 0.25 + 20000 * 0.3 + 20000 * 0.35 + 20000 * 0.4 + (x - 100000)*0.45;
	}
	return grs;
}

void menu1()//主菜单
{
	int x = 0;
	cout << "          <----------工资管理系统---------->          " << endl;
	cout << "          <            1.查询              >          " << endl;
	cout << "          <            2.浏览              >          " << endl;
	cout << "          <            3.修改              >          " << endl;
	cout << "          <            4.添加              >          " << endl;
	cout << "          <            5.删除              >          " << endl;
	cout << "          <            6.保存              >          " << endl;
	cout << "          <            7.退出              >          " << endl;
	cout << "          <-------------------------------->          " << endl;
	cout << "请输入数字选择需要使用的功能(回车确定):";
	cin >> x;
	switch (x)
	{
	    case 1:
	    {
		    read();
		    find(); break;
	    }
	    case 2:
	    {
		    read();
		    list(); break;
	    }
	    case 3:
	    {
		    read();
		    modify(); break;
	    }
	    case 4:
	    {
			read();
		    add(); break;
	    }
	    case 5:
	    {
		    read();
		    del(); break;
	    }
	    case 6:
	    {
		    read();
		    write(); break;
	    }
	    case 7:
	    {
		    cout << "感谢使用...\n";
			exit(1);
	    }
	}
	cout << "请输入数字1-7以选择所需功能...\n";
	menu2();
}
void menu2()
{
	cout << "          <            1.查询              >          " << endl;
	cout << "          <            2.浏览              >          " << endl;
	cout << "          <            3.修改              >          " << endl;
	cout << "          <            4.添加              >          " << endl;
	cout << "          <            5.删除              >          " << endl;
	cout << "          <            6.保存              >          " << endl;
	cout << "          <            7.退出              >          " << endl;
	int x;
	cout << "请输入数字选择需要使用的功能(回车确定):";
	cin >> x;
	switch (x)
	{
	case 1:
	{
		read();
		find(); break;
	}
	case 2:
	{
		read();
		list(); break;
	}
	case 3:
	{
		read();
		modify(); break;
	}
	case 4:
	{
		read();
		add(); break;
	}
	case 5:
	{
		read();
		del(); break;
	}
	case 6:
	{
		read();
		write(); break;
	}
	case 7:
	{
		cout << "感谢使用...\n";
		exit(1);
	}
	}
	cout << "请输入数字1-7以选择所需功能...\n";
	menu2();
}