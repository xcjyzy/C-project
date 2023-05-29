#ifndef EDITOR_H
#define EDITOR_H
#include<iostream>
#include <iosfwd>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <commdlg.h>
#include <atlstr.h>
#include <ShlObj.h>
#include<bits/stdc++.h>
#include"Format.h"
#include"Graphical.h"
using namespace std;


class TextEditor
{
public:
	void ShowMainMune();//主菜单
	void ShowEditorMune();//编辑菜单
	void Run();//运行函数
	void Exit();//退出
	void Open();//打开文件
	void Save(char* path);//输出文件
	void FileSave();//保存
	void Clear();//控制台清屏
	void Review();//重新输出当前的字符串
	void OutputCharCount();//统计字符
	void Search();//文本查找
	void Replace();//文本替换
	void Delete();//文本删除
	void Insert();//文本插入
	void Copy(char*& temp);//文本复制
	string getDataPath();
protected:
	string DataPath;
	string fileContent;
	passage Text;//全局文本
	global_setting global;//这里是全局设定，多文件则引用之
};
//下面是新加的，我不确定要不要留你原来的，所以先放着
void read_temp(passage* p, fstream& data, fstream& d_format);
void save(fstream& t_format, fstream& t_data, passage* p);

#endif EDITOR_H