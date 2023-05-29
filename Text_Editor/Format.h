#ifndef FORMAT_H
#define FORMAT_H
#include <string>
using namespace std;


class global_setting//东西不多，可以再加
{
public:
	int indent;//全局设定的段落缩进，是默认值，一般为0？
	int spacing;//全局设定的段落间隔，是默认值
	int size;
	global_setting();
protected:

};

class format//需要的格式差不多齐了
{
public:
	int color;//0~255^3，这里改过了
	int size;//字号，看全局设定

	bool parastart_flag;//和sentence处同理，标志一个段落开始，段落的缩进等都要看这一句的格式
	//注意，看到这个标志是flag时，把这个format指针存下来，因为接下来一整个段落都按这个指针
	int indent;//段落缩进，默认为全局设定，不是段落开始句的时候，为-1
	int spacing;//段落间距，默认为全局设定，不是段落开始句的时候，为-1

	format(bool flag);
	format(bool flag, int color, int size, int indent, int spacing);
protected:

};


class sentence//实际实现存在一些难点
{
	//一句一句来，每个格式一个句，比如红字1和黑字223，是两个sentence。
	//另外无论如何，段落会导致分句，1\n2，是两句，分为1和2，其中2的parastart_flag为true，输出记得先分段
public:
	sentence* nextse;
	bool parastart_flag;//段落标记，true代表这句话是一段开始
	bool paraend_flag;//段落标志，true代表这句是一段的结束，要\n

	bool cross_flag;//跨越标志，true代表这句话跨越了两个页面

	format* format;//格式标记，注意，如果parastart_flag为true则这个格式还包括段落格式
	//建议每次输出，看到parastart_flag为true就存储这句的格式，直到下一次parastart_flag为true，更新format即可

	string statement;//无格式语句，string用的了就用，用不了就换格式，不过及时申请
	//加了构造函数
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
	sentence* firstse;//首段落，之后的段落用首段落延伸出去
	sentence* lastse;//最后一句
	global_setting* set;//本文章的全局设定
	int total_word;//可能不用，总字数
	passage();
protected:

};


#endif 