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
	void ShowMainMune();//���˵�
	void ShowEditorMune();//�༭�˵�
	void Run();//���к���
	void Exit();//�˳�
	void Open();//���ļ�
	void Save(char* path);//����ļ�
	void FileSave();//����
	void Clear();//����̨����
	void Review();//���������ǰ���ַ���
	void OutputCharCount();//ͳ���ַ�
	void Search();//�ı�����
	void Replace();//�ı��滻
	void Delete();//�ı�ɾ��
	void Insert();//�ı�����
	void Copy(char*& temp);//�ı�����
	string getDataPath();
protected:
	string DataPath;
	string fileContent;
	passage Text;//ȫ���ı�
	global_setting global;//������ȫ���趨�����ļ�������֮
};
//�������¼ӵģ��Ҳ�ȷ��Ҫ��Ҫ����ԭ���ģ������ȷ���
void read_temp(passage* p, fstream& data, fstream& d_format);
void save(fstream& t_format, fstream& t_data, passage* p);

#endif EDITOR_H