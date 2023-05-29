#include"Editor.h"
using namespace std;

string TextEditor::getDataPath()
{
	return DataPath;
}
void TextEditor::ShowMainMune() //显示图形界面
{
	cout << "*------------------------测试用例-----------------------*" << endl;
	cout << "*------------------------1.打开文件-------------------------*" << endl;
	cout << "*------------------------2.新建文件-------------------------*" << endl;
	cout << "*------------------------3.保存文件-------------------------*" << endl;
	cout << "*------------------------4.编辑-----------------------------*" << endl;
	cout << "*------------------------5.退出-----------------------------*" << endl;
	cout << "*------------------------请输出操作编号---------------------*" << endl;

}
void TextEditor::ShowEditorMune() {
	cout << "6.查找" << endl;
	cout << "7.替换" << endl;
	cout << "8.删除" << endl;
	cout << "9.插入" << endl;
	cout << "10.撤销" << endl;
	cout << "11.重做" << endl;
	cout << "12.字符统计" << endl;
	cout << "13.复制" << endl;
	cout << "14.剪切" << endl;
	cout << "15.粘贴" << endl;
}
void TextEditor::Clear()
{
	system("cls");
}
void TextEditor::Open() //打开文件
{
	OPENFILENAME open;// 公共对话框结构。
	char file[MAX_PATH];// 用来保存获取文件名称的缓冲区。 
	ZeroMemory(&open, sizeof(OPENFILENAME)); // 初始化选择文件对话框
	open.lStructSize = sizeof(OPENFILENAME);//指定这个结构的大小，以字节为单位。
	open.lpstrFile = file;//打开的文件的全路径
	open.lpstrFile[0] = '\0'; //第一个字符串是过滤器描述的显示字符串
	open.nMaxFile = MAX_PATH;  //指定lpstrFile缓冲的大小，以TCHARs为单位
	open.lpstrFilter = "文本文件(*.txt)\0*.txt\0所有文件(*.*)\0*.*\0\0";  //打开文件类型
	open.nFilterIndex = 1;  //指定在文件类型控件中当前选择的过滤器的索引
	open.lpstrFileTitle = NULL; // 指向接收选择的文件的文件名和扩展名的缓冲（不带路径信息）。这个成员可以是NULL。
	open.nMaxFileTitle = 0;  //指定lpstrFileTitle缓冲的大小，以TCHARs为单位
	open.lpstrInitialDir = NULL;  //指向以空字符结束的字符串，可以在这个字符串中指定初始目录。
	open.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	//GetOpenFileName (&open) ;//打开文件对话框
	//GetSaveFileName(&open);//保存文件对话框
	if (GetOpenFileName(&open))  // 显示打开选择文件对话框。  
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
	//ifstream inputFile("../test.txt", ios::in | ios::binary); // 打开要读取的txt文件
	//if (inputFile.is_open())
	//{
	//	// 文件打开成功
	//	cout << "打开文件成功！" << endl;
	//	// 可以进行读取和写入操作
	//	// 读取文件内容
	//	int length;
	//	inputFile.seekg(0, ios::end);
	//	length = inputFile.tellg();
	//	inputFile.seekg(0, ios::beg);
	//	//buffer暂存全文
	//	char* buffer = new char[length + 1];
	//	inputFile.read(buffer, length);
	//	buffer[length] = '\0';
	//	this->fileContent = buffer;
	//	//创建sentence
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
	//	cout << "文件内容：" << endl;
	//	cout << fileContent << endl;
	//	cout << "总字数：" << endl;
	//	cout << Text.total_word << endl;
	//	inputFile.close(); // 关闭文件
	//}
	//else cout << "打开文件失败！" << endl;
}
void TextEditor::Search()
{
	ifstream inputFile("../test.txt"); // 打开要读取的txt文件
	if (inputFile.is_open())
	{
		// 文件打开成功
		cout << "打开文件成功！" << endl;
		// 可以进行读取和写入操作
		int posnow = 0;
		string fileContent;
		// 读取文件内容
		getline(inputFile, fileContent);
		cout << "文件内容：" << endl;
		cout << fileContent << endl;
		inputFile.close(); // 关闭文件
	}
	else cout << "打开文件失败！" << endl;
}
void TextEditor::Run()
{
	ShowMainMune();
	int command;
	while (1)
	{
		cin >> command;
		cin.ignore(2, '\n');
		cout << "您选择了命令：" << command << endl;
		switch (toupper(command))
		{
		case  1:
			cout << "正在执行命令：" << command << endl;
			Open();
			break;
		case 4:
			ShowEditorMune();
			break;
		case 6:
			cout << "正在执行命令：" << command << endl;
			Search();//文本查找
		default:
			cout << "无事发生" << endl;
			break;
		}
	}
}



void read_temp(passage* p, fstream& data, fstream& d_format)
{
	p->firstse = NULL;
	p->set = NULL;
	p->total_word = 0;//以防万一，这里初始化了

	int flag[5];
	sentence* se = new sentence();
	sentence* past = NULL;
	p->firstse = se;
	string s;
	while (!data.eof())
	{
		getline(data, s);
		d_format >> flag[0] >> flag[1] >> flag[2] >> flag[3] >> flag[4];
		//0到5分别是段落起始标，color,size,indent,spacing
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