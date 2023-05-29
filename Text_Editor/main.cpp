#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include"Editor.h"//里面又声明了其他两个库，不用重复声明

extern global_setting global;

int main()
{
	TextEditor E;
	passage* p = new passage();
	int a = 1280, b = 640;//可调
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
	read_temp(p, data, d_format);//本来是不行的，但是让他自己输出一下好像改了文件的属性，然后就好了
	print_g(*p, a);

	fstream t_format(formatfile, ios::out);
	fstream t_data(datafile, ios::out);
	save(t_format, t_data, p);

	system("pause");
}



