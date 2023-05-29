#include"Graphical.h"
#include<iostream>
#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

void print_border(int a, int b)//Ĭ�ϱ߿��ӡ������Ҫ�İ�ťҲ������
{
	setlinecolor(RED);
	setlinestyle(0, 3);
	line(0, 0, a - 2, 0);
	line(a - 2, 0, a - 2, b - 1);
	line(1, 0, 1, b - 1);
	line(2, b - 1, a - 2, b - 1);//���ܱ߿�
	setlinestyle(1, 1);
	setlinecolor(BLACK);
	line(20, 40, 20, b - 20);
	line(a - 120, 40, a - 120, b - 20);//��ʾ����
}

wstring string_wstring(string str)
{
	wstring result;
	//��ȡ��������С��������ռ䣬��������С���ַ�����  
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	TCHAR* buffer = new TCHAR[len + 1];
	//���ֽڱ���ת���ɿ��ֽڱ���  
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';             //����ַ�����β  
	//ɾ��������������ֵ  
	result.append(buffer);
	delete[] buffer;
	return result;
}

bool com_chinese(string s, int p)//�����������������ľ�true
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



void print_g(passage p, int a)//���
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
		f = t->format;//�����ʽ��¼
		setfont(f->size, 0, BLACK);//BLACK�Ǻ��壬��ʱ��̫�������
		settextcolor(f->color);
		if (f->parastart_flag)
		{
			para_f = f;//�����ʽ��¼
			x = 21 + para_f->indent * 12;
		}
		cout << temp << endl;
		next = x + strlen(temp.c_str()) * (f->size + 1) / 2;
		while (next > a - 120)//���Ԥ�ڳ��ȳ���
		{
			if (com_chinese(temp, (a - 120 - x) * 2 / (f->size + 1) - 1))
			{
				k = temp.substr(0, (a - 120 - x) * 2 / (f->size + 1));//�����Ѿ�����
				//�����Ǹ�����1����ʵ����������һ���ֽ�
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
			x = 21; y = y + para_f->spacing + f->size;//��һ��
		}
		else
		{
			x += strlen(temp.c_str()) * (f->size + 1) / 2;//size+1����������λ
			//��ʱ��x������һ��Ŀ�ʼλ�ã����Լ�¼�����߳���һ��Ľ���λ�ã�������������
		}
		t = t->nextse;
	}
}


