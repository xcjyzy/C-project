#include"Editor.h"
using namespace std;

string TextEditor::getDataPath()
{
	return DataPath;
}
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
void TextEditor::Clear()
{
	system("cls");
}
void TextEditor::Open() //���ļ�
{
	OPENFILENAME open;// �����Ի���ṹ��
	char file[MAX_PATH];// ���������ȡ�ļ����ƵĻ������� 
	ZeroMemory(&open, sizeof(OPENFILENAME)); // ��ʼ��ѡ���ļ��Ի���
	open.lStructSize = sizeof(OPENFILENAME);//ָ������ṹ�Ĵ�С�����ֽ�Ϊ��λ��
	open.lpstrFile = file;//�򿪵��ļ���ȫ·��
	open.lpstrFile[0] = '\0'; //��һ���ַ����ǹ�������������ʾ�ַ���
	open.nMaxFile = MAX_PATH;  //ָ��lpstrFile����Ĵ�С����TCHARsΪ��λ
	open.lpstrFilter = "�ı��ļ�(*.txt)\0*.txt\0�����ļ�(*.*)\0*.*\0\0";  //���ļ�����
	open.nFilterIndex = 1;  //ָ�����ļ����Ϳؼ��е�ǰѡ��Ĺ�����������
	open.lpstrFileTitle = NULL; // ָ�����ѡ����ļ����ļ�������չ���Ļ��壨����·����Ϣ���������Ա������NULL��
	open.nMaxFileTitle = 0;  //ָ��lpstrFileTitle����Ĵ�С����TCHARsΪ��λ
	open.lpstrInitialDir = NULL;  //ָ���Կ��ַ��������ַ���������������ַ�����ָ����ʼĿ¼��
	open.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	//GetOpenFileName (&open) ;//���ļ��Ի���
	//GetSaveFileName(&open);//�����ļ��Ի���
	if (GetOpenFileName(&open))  // ��ʾ��ѡ���ļ��Ի���  
	{
		string cafile = file;
		string cfile;
		for (char c : cafile) {
			if (c == '\\') {
				cfile += "//";
			}
			else {
				cfile += c;
			}
		}
		DataPath = cfile;
	}
	//ifstream inputFile("../test.txt", ios::in | ios::binary); // ��Ҫ��ȡ��txt�ļ�
	//if (inputFile.is_open())
	//{
	//	// �ļ��򿪳ɹ�
	//	cout << "���ļ��ɹ���" << endl;
	//	// ���Խ��ж�ȡ��д�����
	//	// ��ȡ�ļ�����
	//	int length;
	//	inputFile.seekg(0, ios::end);
	//	length = inputFile.tellg();
	//	inputFile.seekg(0, ios::beg);
	//	//buffer�ݴ�ȫ��
	//	char* buffer = new char[length + 1];
	//	inputFile.read(buffer, length);
	//	buffer[length] = '\0';
	//	this->fileContent = buffer;
	//	//����sentence
	//	Text.total_word = length;
	//	int i = 0;
	//	while (buffer[i] != '\n' && buffer[i] != '\0' && buffer[i] != '\r')
	//	{
	//		Text.firstse->statement.push_back(buffer[i]);
	//		i++;
	//	}
	//	Text.firstse->statement[i] = '\0';
	//	cout << "Frist sentence:" << Text.firstse->statement << endl;
	//	Text.lastse = Text.firstse;
	//	Text.firstse->parastart_flag = true;
	//	i = i + 2;
	//	int flag = 1;
	//	while (buffer[i] != '\n' && buffer[i] != '\0' && buffer[i] != '\r' && i <= length)
	//	{
	//		sentence a = sentence();
	//		if (flag)
	//		{
	//			Text.firstse->nextse = &a;
	//			flag = 0;
	//		}
	//		while (buffer[i] != '\n' && buffer[i] != '\0' && buffer[i] != '\r')
	//		{
	//			a.statement.push_back(buffer[i]);
	//			i++;
	//		}
	//		i++;
	//		Text.lastse->nextse = &a;
	//		Text.lastse = &a;
	//		cout << "next sentence:" << Text.lastse->statement << endl;
	//	}



	//	delete(buffer);
	//	cout << "�ļ����ݣ�" << endl;
	//	cout << fileContent << endl;
	//	cout << "��������" << endl;
	//	cout << Text.total_word << endl;
	//	inputFile.close(); // �ر��ļ�
	//}
	//else cout << "���ļ�ʧ�ܣ�" << endl;
}
void TextEditor::Search()
{
	ifstream inputFile("../test.txt"); // ��Ҫ��ȡ��txt�ļ�
	if (inputFile.is_open())
	{
		// �ļ��򿪳ɹ�
		cout << "���ļ��ɹ���" << endl;
		// ���Խ��ж�ȡ��д�����
		int posnow = 0;
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
		cout << "��ѡ�������" << command << endl;
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



void read_temp(passage* p, fstream& data, fstream& d_format)
{
	p->firstse = NULL;
	p->set = NULL;
	p->total_word = 0;//�Է���һ�������ʼ����

	int flag[5];
	sentence* se = new sentence();
	sentence* past = NULL;
	p->firstse = se;
	string s;
	while (!data.eof())
	{
		getline(data, s);
		d_format >> flag[0] >> flag[1] >> flag[2] >> flag[3] >> flag[4];
		//0��5�ֱ��Ƕ�����ʼ�꣬color,size,indent,spacing
		se->statement = s;
		if (flag[0])
		{
			if (past != NULL)
			{
				past->paraend_flag = true;
			}
			se->parastart_flag = true;
			se->format = new format(true, flag[1], flag[2], flag[3], flag[4]);
		}
		else
		{
			se->format = new format(false, flag[1], flag[2], flag[3], flag[4]);
		}
		if (!data.eof())
		{
			se->nextse = new sentence();
			past = se;
			se = se->nextse;
		}
	}
}

void save(fstream& t_format, fstream& t_data, passage* p)
{
	sentence* se = p->firstse;
	format* f;
	while (se != NULL)
	{
		f = se->format;
		t_data << se->statement;
		if (se->nextse != NULL) t_data << endl;
		if (se->parastart_flag) t_format << 1;
		else t_format << 0;
		t_format << " " << f->color << " " << f->size << " " << f->indent << " " << f->spacing << endl;
		se = se->nextse;
	}
}