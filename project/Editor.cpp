#include"Editor.h"
using namespace std;
void TextEditor::ShowMainMune() //��ʾͼ�ν���
{
		cout << "*------------------------��������-----------------------*" << endl;
		cout << "*------------------------1.���ļ�-------------------------*" << endl;
		cout << "*------------------------2.�½��ļ�-------------------------*" << endl;
		cout << "*------------------------3.�����ļ�-------------------------*" << endl;
		cout << "*------------------------4.�༭-----------------------------*" << endl;
		cout << "*------------------------5.�˳�-----------------------------*" << endl;
		cout << "*------------------------������������---------------------*" << endl;

}
void TextEditor::ShowEditorMune() {
	cout << "6.����" << endl;
	cout << "7.�滻" << endl;
	cout << "8.ɾ��" << endl;
	cout << "9.����" << endl;
	cout << "10.����" << endl;
	cout << "11.����" << endl;
	cout << "12.�ַ�ͳ��" << endl;
	cout << "13.����" << endl;
	cout << "14.����" << endl;
	cout << "15.ճ��" << endl;
}
void TextEditor::Open() //���ļ�
{
	ifstream inputFile("../test.txt"); // ��Ҫ��ȡ��txt�ļ�
	if (inputFile.is_open())
	{
		// �ļ��򿪳ɹ�
		cout << "���ļ��ɹ���" << endl;
		// ���Խ��ж�ȡ��д�����
		string fileContent;
		// ��ȡ�ļ�����
		getline(inputFile, fileContent);
		cout << "�ļ����ݣ�" << endl;
		cout << fileContent << endl;
		inputFile.close(); // �ر��ļ�
	}
	else cout << "���ļ�ʧ�ܣ�" << endl;
}
void TextEditor::Search()
{
	ifstream inputFile("../test.txt"); // ��Ҫ��ȡ��txt�ļ�
	if (inputFile.is_open())
	{
		// �ļ��򿪳ɹ�
		cout << "���ļ��ɹ���" << endl;
		// ���Խ��ж�ȡ��д�����
		int posnow=0;
		
		string fileContent;
		// ��ȡ�ļ�����
		getline(inputFile, fileContent);
		cout << "�ļ����ݣ�" << endl;
		cout << fileContent << endl;
		inputFile.close(); // �ر��ļ�
	}
	else cout << "���ļ�ʧ�ܣ�" << endl;
}
void TextEditor::Run()
{
	ShowMainMune();
	int command;
	while (1)
	{
		cin >> command;
		cin.ignore(2, '\n');	
		cout << "��ѡ�������"<<command<<endl;
		switch (toupper(command))
		{
		case  1:
			cout << "����ִ�����" << command << endl;
			Open();
			break;
		case 4:
			ShowEditorMune();
			break;
		case 6:
			cout << "����ִ�����" << command << endl;
			Search();//�ı�����
		default:
			cout << "���·���" << endl;
			break;
		}
	}
}