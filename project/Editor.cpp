#include"Editor.h"
using namespace std;
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
void TextEditor::Open() //打开文件
{
	ifstream inputFile("../test.txt"); // 打开要读取的txt文件
	if (inputFile.is_open())
	{
		// 文件打开成功
		cout << "打开文件成功！" << endl;
		// 可以进行读取和写入操作
		string fileContent;
		// 读取文件内容
		getline(inputFile, fileContent);
		cout << "文件内容：" << endl;
		cout << fileContent << endl;
		inputFile.close(); // 关闭文件
	}
	else cout << "打开文件失败！" << endl;
}
void TextEditor::Search()
{
	ifstream inputFile("../test.txt"); // 打开要读取的txt文件
	if (inputFile.is_open())
	{
		// 文件打开成功
		cout << "打开文件成功！" << endl;
		// 可以进行读取和写入操作
		int posnow=0;
		
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
		cout << "您选择了命令："<<command<<endl;
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