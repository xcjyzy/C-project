#ifndef FORMAT_H
#define FORMAT_H
#include <string>
using namespace std;


class global_setting//�������࣬�����ټ�
{
public:
	int indent;//ȫ���趨�Ķ�����������Ĭ��ֵ��һ��Ϊ0��
	int spacing;//ȫ���趨�Ķ���������Ĭ��ֵ
	int size;
	global_setting();
protected:

};

class format//��Ҫ�ĸ�ʽ�������
{
public:
	int color;//0~255^3������Ĺ���
	int size;//�ֺţ���ȫ���趨

	bool parastart_flag;//��sentence��ͬ����־һ�����俪ʼ������������ȶ�Ҫ����һ��ĸ�ʽ
	//ע�⣬���������־��flagʱ�������formatָ�����������Ϊ������һ�������䶼�����ָ��
	int indent;//����������Ĭ��Ϊȫ���趨�����Ƕ��俪ʼ���ʱ��Ϊ-1
	int spacing;//�����࣬Ĭ��Ϊȫ���趨�����Ƕ��俪ʼ���ʱ��Ϊ-1

	format(bool flag);
	format(bool flag, int color, int size, int indent, int spacing);
protected:

};


class sentence//ʵ��ʵ�ִ���һЩ�ѵ�
{
	//һ��һ������ÿ����ʽһ���䣬�������1�ͺ���223��������sentence��
	//����������Σ�����ᵼ�·־䣬1\n2�������䣬��Ϊ1��2������2��parastart_flagΪtrue������ǵ��ȷֶ�
public:
	sentence* nextse;
	bool parastart_flag;//�����ǣ�true������仰��һ�ο�ʼ
	bool paraend_flag;//�����־��true���������һ�εĽ�����Ҫ\n

	bool cross_flag;//��Խ��־��true������仰��Խ������ҳ��

	format* format;//��ʽ��ǣ�ע�⣬���parastart_flagΪtrue�������ʽ�����������ʽ
	//����ÿ�����������parastart_flagΪtrue�ʹ洢���ĸ�ʽ��ֱ����һ��parastart_flagΪtrue������format����

	string statement;//�޸�ʽ��䣬string�õ��˾��ã��ò��˾ͻ���ʽ��������ʱ����
	//���˹��캯��
	sentence();
	~sentence()
	{
		delete nextse;
	}
protected:

};

class passage
{
public:
	sentence* firstse;//�׶��䣬֮��Ķ������׶��������ȥ
	sentence* lastse;//���һ��
	global_setting* set;//�����µ�ȫ���趨
	int total_word;//���ܲ��ã�������
	passage();
protected:

};


#endif 