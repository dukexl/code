#include <boost/version.hpp>
#include <boost/config.hpp>
#include <boost/timer.hpp>
#include <iostream>
using namespace boost;
using std::cout;
using std::endl;

int version(int argc, char *argv[])
{
	std::cout << BOOST_VERSION << std::endl;
	std::cout << BOOST_LIB_VERSION << std::endl;
	std::cout << BOOST_PLATFORM << std::endl;
	std::cout << BOOST_COMPILER << std::endl;
	std::cout << BOOST_STDLIB << std::endl;

	timer t;
	std::cout << "Max timespan:" << t.elapsed_max() / 3600 << "h" << endl;
	cout << "min timespan:" << t.elapsed_min() << "s" << endl;
	cout << "now timespan:" << t.elapsed() << "s" << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <boost/program_options.hpp>
#include <chrono>

#include <time.h>

namespace bpo = boost::program_options;
using namespace std;

int test01(int argc, char const *argv[])
{

	//外部变量，用于保存获取的参数值
	int apple_num = 0, orange_num = 0;

	std::vector<std::string> addr;
	bpo::options_description opt("all options"); // opt 名称

	opt.add_options()

		//指定该参数的默认值

		// "apple,a" : 指定选项的全写形式为 --apple, 简写形式为 -a
		// value<type>(ptr) : ptr为该选项对应的外部变量的地址, 当该选项被解析后,

		//可通过下面的notify()函数将选项的值赋给该外部变量,该变量的值会自动更新
		//defaut_value(num) : num为该选项的默认值, 若命令行中未输入该选项, 则该选项的值取为num

		("apple,a", bpo::value<int>(&apple_num)->default_value(10), "苹果的数量")

			("orange,o", bpo::value<int>(&orange_num)->default_value(20), "橘子的数量")

		//该参数的实际类型为vector,所以命令行中输入的值可以是多个,

		//multitoken()的作用就是告诉编译器,该选项可接受多个值

		("address", bpo::value<std::vector<std::string>>()->multitoken(), "生产地")

			("help", "计算苹果和橘子的总数量");

	bpo::variables_map vm;

	try
	{

		bpo::store(parse_command_line(argc, argv, opt), vm);
	}

	catch (...)
	{

		std::cout << "输入的参数中存在未定义的选项！\n";

		return 0;
	}

	//参数解析完成后，通知variables_map去更新所有的外部变量

	//这句话执行后, 会使得apple_num和orange_num的值自动更新为选项指定的值

	bpo::notify(vm);

	if (vm.count("help"))
	{
		std::cout << opt << std::endl;
		return 0;
	}

	if (vm.count("address"))
	{

		std::cout << "生产地为：";
		//遍历选项值

		for (auto &str : vm["address"].as<std::vector<std::string>>())
			std::cout << str << " ";

		std::cout << std::endl;
	}

	std::cout << "苹果的数量:" << apple_num << std::endl;
	std::cout << "橘子的数量:" << orange_num << std::endl;
	std::cout << "总数量数量:" << orange_num + apple_num << std::endl;

	return 0;
}

int test02(int argc, char const *argv[])
{

	//步骤一: 构造选项描述器和选项存储器

	//选项描述器,其参数为该描述器的名字
	bpo::options_description opts("all options");

	//选项存储器,继承自map容器
	bpo::variables_map vm;

	//步骤二: 为选项描述器增加选项

	//其参数依次为: key, value的类型，该选项的描述
	opts.add_options()("filename", bpo::value<std::string>(), "the file name which want to be found")("help", "this is a program to find a specified file");

	//步骤三: 先对命令行输入的参数做解析,而后将其存入选项存储器
	//如果输入了未定义的选项，程序会抛出异常，所以对解析代码要用try-catch块包围

	try
	{
		//parse_command_line()对输入的选项做解析
		//store()将解析后的结果存入选项存储器
		bpo::store(bpo::parse_command_line(argc, argv, opts), vm);
	}
	catch (...)
	{

		std::cout << "输入的参数中存在未定义的选项！\n";
		return 0;
	}

	//步骤四: 参数解析完毕，处理实际信息

	//count()检测该选项是否被输入
	if (vm.count("help"))
	{ //若参数中有help选项
		//options_description对象支持流输出， 会自动打印所有的选项信息
		std::cout << opts << std::endl;
	}

	if (vm.count("filename"))
	{

		//variables_map(选项存储器)是std::map的派生类,可以像关联容器一样使用,
		//通过operator[]来取出其中的元素.但其内部的元素类型value_type是boost::any,
		//用来存储不确定类型的参数值,必须通过模板成员函数as<type>()做类型转换后,
		//才能获取其具体值.
		std::cout << "find " << vm["filename"].as<std::string>() << std::endl;
	}

	if (vm.empty())
	{
		std::cout << "no options found \n";
	}

	return 0;
}

void testTime()
{
	uint64_t n_day = 20200921;
	uint64_t n_time = 91502;
	char szStr[64] = {0};
	sprintf(szStr, "%d %02d:%02d:%02d", n_day, n_time / 10000, n_time / 100 % 100, n_time % 100);
	std::cout << szStr << std::endl;
}

int testtime2()
{
	struct tm t1, t2; //结构体

	/*输入年月日时分*/
	scanf("%d/%d/%d/%d:%d", &t1.tm_year, &t1.tm_mon, &t1.tm_mday, &t1.tm_hour, &t1.tm_min);
	scanf("%d/%d/%d/%d:%d", &t2.tm_year, &t2.tm_mon, &t2.tm_mday, &t2.tm_hour, &t2.tm_min);

	/*将年份和月份转为tm结构体的正常值，秒钟默认为0，可自行修改*/
	t1.tm_year -= 1900;
	t1.tm_mon -= 1;
	t1.tm_sec = 0;

	t2.tm_year -= 1900;
	t2.tm_mon -= 1;
	t2.tm_sec = 0;

	/*定义两个时间戳（1970年到现在的秒数，到2038年会溢出）*/
	time_t time1, time2;

	/*将tm结构体的时间转换成时间戳*/
	time1 = mktime(&t1);
	time2 = mktime(&t2);

	/*利用difftime函数计算两个时间戳的差，注意是double类型*/
	double dif;
	dif = difftime(time1, time2);
	printf("相差:%.2f秒\n", dif);
	printf("相差:%.2f分钟\n", dif / 60.0);

	return 1;
}

#include <sys/time.h>	 //添加头文件
int64_t getCurrentTime() //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
	struct timeval tv;
	gettimeofday(&tv, NULL); //该函数在sys/time.h头文件中
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int testmain()
{
	std::cout << "nowTime: " << getCurrentTime() << "\n"; //如果想要到秒级别的，只要除以1000就行了
	return 0;
}

int test01()
{
	time_t mytt, myrtt;
	time(&mytt);
	myrtt = mytt + 8 * 3600; // transform the time zone
	tm *my_t = gmtime(&myrtt);
	long long cur_usecond = getCurrentTime();
	char str_time[128];
	snprintf(str_time, 128, "%04d-%02d-%02d %02d:%02d:%02d %03d", my_t->tm_year + 1900, my_t->tm_mon + 1, my_t->tm_mday, my_t->tm_hour, my_t->tm_min, my_t->tm_sec, (int)(cur_usecond % 1000));
	printf("%s\n", str_time);
	return 0;
}

void teststring()
{
	string key = "ORDER_TOPIC_SH";
	key += "|";
	key += "ORDER_TOPIC_SH_key";
	key += "|";
	key += "ORDER_TOPIC_SH_msg";
	std::cout << key << ":" << key.substr(0, key.find("|")) << ":" << (key.substr(key.find("|") + 1)).substr(0, (key.substr(key.find("|") + 1)).rfind("|")) << ":" << key.substr(key.rfind("|") + 1) << std::endl;
}

void testint(int i)
{
	//int i = 98000;
	char str_time[128];
	snprintf(str_time, 128, "%d.%02d", i / 10000, i % 10000 / 100);
	printf("%s\n", str_time);
}

void teststring1()
{
	string str = "";
	str += '\"';
	str += "1";
	str += '\"';
	std::cout << str << endl;
}

void teststring2()
{
	char tmp[128];
	tmp[0] = '\0';
	snprintf(tmp + strlen(tmp), 128, "1\",\"2");
	snprintf(tmp + strlen(tmp), 128, "3\",\"24");
	std::cout << tmp << endl;
}

int main(int argc, char const *argv[])
{
	teststring2();
	return 0;
}
