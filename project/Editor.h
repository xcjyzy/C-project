#ifndef EDITOR_H
#define EDITOR_H
#include<iostream>
#include <iosfwd>
#include <afxdlgs.h>
#include <commdlg.h>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
#include"Format.h"
using namespace std;
class TextEditor
{
public:
	void ShowMainMune();//���˵�
	void ShowEditorMune();//�༭�˵�
	void Run();//���к���
	void Exit();//�˳�
	void Open();//���ļ�
	void Save(char * path);//����ļ�
	void FileSave();//����
	void Clear();//����̨����
	void Review();//���������ǰ���ַ���
	void OutputCharCount();//ͳ���ַ�
	void Search();//�ı�����
	void Replace();//�ı��滻
	void Delete();//�ı�ɾ��
	void Insert();//�ı�����
	void Copy(char * &temp);//�ı�����
protected:
	string fileContent;
	passage Text;//ȫ���ı�
	global_setting global;//������ȫ���趨�����ļ�������֮
};

#endif // EDITOR_H
