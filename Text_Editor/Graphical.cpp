#include"Graphical.h"
#include<iostream>
#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

void print_border(int a, int b)//默认边框打印，有需要的按钮也在这里
{
	setlinecolor(RED);
	setlinestyle(0, 3);
	line(0, 0, a - 2, 0);
	line(a - 2, 0, a - 2, b - 1);
	line(1, 0, 1, b - 1);
	line(2, b - 1, a - 2, b - 1);//四周边框
	setlinestyle(1, 1);
	setlinecolor(BLACK);
	line(20, 40, 20, b - 20);
	line(a - 120, 40, a - 120, b - 20);//显示区域
}

wstring string_wstring(string str)
{
	wstring result;
	//获取缓冲区大小，并申请空间，缓冲区大小按字符计算  
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	TCHAR* buffer = new TCHAR[len + 1];
	//多字节编码转换成宽字节编码  
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';             //添加字符串结尾  
	//删除缓冲区并返回值  
	result.append(buffer);
	delete[] buffer;
	return result;
}

bool com_chinese(string s, int p)//如果输出了完整的中文就true
{
	int count = 0;
	for (int i = p; i >= 0; i--)
	{
		if ((int)s[i] < 0)
			count++;
		else break;
	}
	if (count % 2 == 0) return true;
	return false;
}



void print_g(passage p, int a)//输出
{
	setfont(12, 0, BLACK);
	if (p.firstse == NULL) return;
	sentence* t;
	t = p.firstse;
	string temp;
	string k;
	settextcolor(BLACK);
	format* f;
	format* para_f = p.firstse->format;
	int x = 21, y = 40, next;

	while (t != NULL)
	{
		temp = t->statement;
		f = t->format;//本句格式记录
		setfont(f->size, 0, BLACK);//BLACK是黑体，暂时不太会改字体
		settextcolor(f->color);
		if (f->parastart_flag)
		{
			para_f = f;//段落格式记录
			x = 21 + para_f->indent * 12;
		}
		cout << temp << endl;
		next = x + strlen(temp.c_str()) * (f->size + 1) / 2;
		while (next > a - 120)//这句预期长度超标
		{
			if (com_chinese(temp, (a - 120 - x) * 2 / (f->size + 1) - 1))
			{
				k = temp.substr(0, (a - 120 - x) * 2 / (f->size + 1));//这里已经可以
				//上面那个减完1就是实际输出的最后一个字节
				temp = temp.substr((a - 120 - x) * 2 / (f->size + 1));
			}
			else
			{
				k = temp.substr(0, (a - 120 - x) * 2 / (f->size + 1) - 1);
				temp = temp.substr((a - 120 - x) * 2 / (f->size + 1) - 1);
			}
			outtextxy(x, y, string_wstring(k).c_str());
			x = 21; y = y + para_f->spacing + f->size;
			next = x + strlen(temp.c_str()) * (f->size + 1) / 2;
		}
		outtextxy(x, y, string_wstring(temp).c_str());

		if (t->paraend_flag)
		{
			x = 21; y = y + para_f->spacing + f->size;//下一行
		}
		else
		{
			x += strlen(temp.c_str()) * (f->size + 1) / 2;//size+1可以留出空位
			//此时的x就是下一句的开始位置，可以记录，或者称这一句的结束位置，光标可以在这里
		}
		t = t->nextse;
	}
}


