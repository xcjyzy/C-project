#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include"Editor.h"//���������������������⣬�����ظ�����

extern global_setting global;

int main()
{
	TextEditor E;
	passage* p = new passage();
	int a = 1280, b = 640;//�ɵ�
	initgraph(a, b, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	print_border(a, b);
	E.Open();
	string datafile, formatfile;
	datafile = E.getDataPath();
	formatfile = "C://Users//asus//Desktop//3_spring//C++//Text//Text//format.txt";

	fstream data(datafile, ios::in);
	fstream d_format(formatfile, ios::in);
	read_temp(p, data, d_format);//�����ǲ��еģ����������Լ����һ�º�������ļ������ԣ�Ȼ��ͺ���
	print_g(*p, a);

	fstream t_format(formatfile, ios::out);
	fstream t_data(datafile, ios::out);
	save(t_format, t_data, p);

	system("pause");
}



