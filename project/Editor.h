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
	void ShowMainMune();//���˵�
	void ShowEditorMune();//�༭�˵�
	void Run();//���к���
	void Exit();//�˳�
	void Open();//���ļ�
	void Save(char * path);//����ļ�
	void FileSave();//����
	void Clear();//����
	void Review();//���������ǰ���ַ���
	void OutputCharCount();//ͳ���ַ�
	void Search();//�ı�����
	void Replace();//�ı��滻
	void Delete();//�ı�ɾ��
	void Insert();//�ı�����
	void Copy(char * &temp);//�ı�����
};
#endif // EDITOR_H
