#ifndef EDITOR_H
#define EDITOR_H
#include<iostream>
#include <iosfwd>
#include <afxdlgs.h>
#include <commdlg.h>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
class TextEditor
{
public:
	void ShowMainMune();//主菜单
	void ShowEditorMune();//编辑菜单
	void Run();//运行函数
	void Exit();//退出
	void Open();//打开文件
	void Save(char * path);//输出文件
	void FileSave();//保存
	void Clear();//清屏
	void Review();//重新输出当前的字符串
	void OutputCharCount();//统计字符
	void Search();//文本查找
	void Replace();//文本替换
	void Delete();//文本删除
	void Insert();//文本插入
	void Copy(char * &temp);//文本复制
};
#endif // EDITOR_H
