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
struct zggz//ְ������
{
    char num[10];
    char name[10];
    float gwgz,xjgz,zwjt,jxgz,yfgz,grs,sfgz;
};

int main()
{
    void read();//��ȡְ����������
    void write();//����ְ����������
    void find();//��ѯְ����������
    void list();//���ְ����������
    void modify();//�޸�ְ����������
    void del();//ɾ��ְ����������
    void add();//���ְ����������
    float grsds(float x);//�����������˰
	void menu();
	menu();
    char num1[10];
    char name1[10];
    struct zggz a;
    cout<<"������ְ�����š���������λ���ʡ�н�����ʡ�ְ���������Ч����:\n";
    cin>>num1>>name1>>a.gwgz>>a.xjgz>>a.zwjt>>a.jxgz;
	cout<<endl;
	a.yfgz=a.gwgz+a.xjgz+a.zwjt+a.jxgz;
    strcpy(a.num,num1);
    strcpy(a.name,name1);
	a.grs=grsds(a.gwgz+a.xjgz+a.zwjt+a.jxgz);
	a.sfgz=a.yfgz-a.grs;

    ofstream fout("gz.dat",ios::out);//�������ʽ��gz.dat
    if(!fout)
	    {
		    cout<<"Cannot open the file.\n";
		    exit(1);
	    }
    fout<<a.num<<" "<<a.name<<" "<<a.gwgz<<" "<<a.xjgz<<" "<<a.zwjt<<" "<<a.jxgz<<" "<<a.yfgz<<" "<<a.grs<<" "<<a.sfgz<<endl;
	fout.close();

    ifstream fin("gz.dat",ios::in);//��������ʽ��gz.dat
	if(!fin)
	{
        cout<<"Cannot open the file.\n";
    	exit(1);
	}
	cout<<"ְ������ ���� ��λ���� н������ ְ����� ��Ч���� ��������˰ Ӧ������:\n";
	char str[80];
	while(fin)
	{
        fin.getline(str,80);
        cout<<str<<endl;
	}
    fin.close();
	return 0;
}

void menu()//�˵�
{
	int x=0;
    cout<<"          <----------���ʹ���ϵͳ---------->          "<<endl;
    cout<<"          <            1.��ѯ              >          "<<endl;
    cout<<"          <            2.���              >          "<<endl;
    cout<<"          <            3.�޸�              >          "<<endl;
    cout<<"          <            4.���              >          "<<endl;
    cout<<"          <            5.ɾ��              >          "<<endl;
    cout<<"          <            6.����              >          "<<endl;
    cout<<"          <            7.�˳�              >          "<<endl;
    cout<<"          <-------------------------------->          "<<endl;
	cout<<"����������ѡ����Ҫʹ�õĹ���(�س�ȷ��):"
    cin>>x;
}


float grsds(float x)//��������˰
{
    float grs;
    if(x<=500)
	{
	    grs=x*0.05;
	}
	else if(x>500&&x<=2000)