#pragma once
#include <vector>
#include <string>
#include "Structure.h"

class InitInterface {
protected:
	// 常量，要在构造函数中初始化
	const bool is_admin;

	// 交通信息，每行格式如下
	// 注意，全部为string类型
	const std::vector<BaseData> traffict_info;


	// 用于初始化鉴权变量的构造函数
	// 并调用get_data()函数
	InitInterface(bool is_admin) : is_admin(is_admin) { init_traffic_info(); };

	// 从文件中读取信息并初始化traffic_info
	virtual void init_traffic_info() = 0;

public:
	// 获得初始化后的交通信息
	std::vector<BaseData> get_traffic_info() { return traffict_info; }
};

class CommandProcessInterface {
protected:
	// 常量，要在构造函数中初始化
	const bool is_admin;

	const std::string help_msg[4] = {
		// {0} help command's info of part 1(for guest)
		"help\nquit\nquery\n",
		// {1} help command's info of part 2(for administrator and should also include part 1)
		"edit\nshow\n",
		// {2} query -h output info
		"query (-b|--begin) city1 (-e | --end) city2 (-f factor| -n (0 | 1))\n\t-b city1 | --begin city1\t\tset begin city\n\t-e city2 | --end city2\t\tset end city\n\t(-f factor | -n (0 | 1))\t\tset  priority policyn\n\t\t-f has two values in (money, time)\n\t\t-n 0: money\t1: time\n",
		// {3} edit -h output info
		"edit (-o OPERATE | -s)\n\t-s\t\twill save temporary alter\n\t-o OPERATE\t\tOPERATE has two values in (insert, delete, update) with case sensitive and will into specified sub-system\n"
	};

	const std::string err_msg[2] = {
		// {0} Error message for error command.
			// Error arguments message should be build by yourself with document
		"Error Command. Input 'help' to get all commands.",
		// {1} Error message for guest use administrator command
		"Sorry, you have no authority to use this command."
	};

	// 用于初始化鉴权变量的构造函数
	CommandProcessInterface(bool is_admin) : is_admin(is_admin) {};

public:
	/** 命令处理函数
		* 这个函数用于处理命令并调用相应函数
		**** 处理方法可参考https://blog.csdn.net/sesiria/article/details/52204448
		**** 特别注意，判断命令为edit或show后，执行相应功能前要判断is_admin
	**/
	virtual void proc_command(std::string command) = 0;
};
