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
struct zggz//职工数据
{
    char num[10];
    char name[10];
    float gwgz,xjgz,zwjt,jxgz,yfgz,grs,sfgz;
};

int main()
{
    void read();//读取职工工资数据
    void write();//保存职工工资数据
    void find();//查询职工工资数据
    void list();//浏览职工工资数据
    void modify();//修改职工工资数据
    void del();//删除职工工资数据
    void add();//添加职工工资数据
    float grsds(float x);//计算个人所得税
	void menu();
	menu();
    char num1[10];
    char name1[10];
    struct zggz a;
    cout<<"请输入职工工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资:\n";
    cin>>num1>>name1>>a.gwgz>>a.xjgz>>a.zwjt>>a.jxgz;
	cout<<endl;
	a.yfgz=a.gwgz+a.xjgz+a.zwjt+a.jxgz;
    strcpy(a.num,num1);
    strcpy(a.name,name1);
	a.grs=grsds(a.gwgz+a.xjgz+a.zwjt+a.jxgz);
	a.sfgz=a.yfgz-a.grs;

    ofstream fout("gz.dat",ios::out);//以输出形式打开gz.dat
    if(!fout)
	    {
		    cout<<"Cannot open the file.\n";
		    exit(1);
	    }
    fout<<a.num<<" "<<a.name<<" "<<a.gwgz<<" "<<a.xjgz<<" "<<a.zwjt<<" "<<a.jxgz<<" "<<a.yfgz<<" "<<a.grs<<" "<<a.sfgz<<endl;
	fout.close();

    ifstream fin("gz.dat",ios::in);//以输入形式打开gz.dat
	if(!fin)
	{
        cout<<"Cannot open the file.\n";
    	exit(1);
	}
	cout<<"职工工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 个人所得税 应发工资:\n";
	char str[80];
	while(fin)
	{
        fin.getline(str,80);
        cout<<str<<endl;
	}
    fin.close();
	return 0;
}

void menu()//菜单
{
	int x=0;
    cout<<"          <----------工资管理系统---------->          "<<endl;
    cout<<"          <            1.查询              >          "<<endl;
    cout<<"          <            2.浏览              >          "<<endl;
    cout<<"          <            3.修改              >          "<<endl;
    cout<<"          <            4.添加              >          "<<endl;
    cout<<"          <            5.删除              >          "<<endl;
    cout<<"          <            6.保存              >          "<<endl;
    cout<<"          <            7.退出              >          "<<endl;
    cout<<"          <-------------------------------->          "<<endl;
	cout<<"请输入数字选择需要使用的功能(回车确定):"
    cin>>x;
}


float grsds(float x)//个人所得税
{
    float grs;
    if(x<=500)
	{
	    grs=x*0.05;
	}
	else if(x>500&&x<=2000)