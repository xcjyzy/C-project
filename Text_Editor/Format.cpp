#include "Format.h"

global_setting::global_setting()
{
	indent = 2;
	spacing = 12;//�ο�word����λΪ��
	size = 15;//�ο�wordѡ�˸�����
}

global_setting global;

format::format(bool flag)//flag�Ƕ�����ʼ��
{
	color = 0;//����Ҳ����
	size = global.size;
	parastart_flag = flag;
	if (flag == false)
	{
		indent = -1;
		spacing = -1;
	}
	else
	{
		indent = global.indent;
		spacing = global.spacing;
	}
}

format::format(bool flag, int color, int size, int indent, int spacing) :parastart_flag(flag)
{
	this->color = color;
	this->size = size;
	this->indent = indent;
	this->spacing = spacing;
}

sentence::sentence()
{
	nextse = NULL;
	parastart_flag = false;
	paraend_flag = false;
	cross_flag = true;
	format = NULL;
}

passage::passage()
{
	firstse = NULL;
	lastse = NULL;
	set = NULL;
	total_word = 0;
}