#pragma once
#include <vector>
#include <string>
#include "Structure.h"

class InitInterface {
protected:
	// ������Ҫ�ڹ��캯���г�ʼ��
	const bool is_admin;

	// ��ͨ��Ϣ��ÿ�и�ʽ����
	// ע�⣬ȫ��Ϊstring����
	const std::vector<BaseData> traffict_info;


	// ���ڳ�ʼ����Ȩ�����Ĺ��캯��
	// ������get_data()����
	InitInterface(bool is_admin) : is_admin(is_admin) { init_traffic_info(); };

	// ���ļ��ж�ȡ��Ϣ����ʼ��traffic_info
	virtual void init_traffic_info() = 0;

public:
	// ��ó�ʼ����Ľ�ͨ��Ϣ
	std::vector<BaseData> get_traffic_info() { return traffict_info; }
};

class CommandProcessInterface {
protected:
	// ������Ҫ�ڹ��캯���г�ʼ��
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

	// ���ڳ�ʼ����Ȩ�����Ĺ��캯��
	CommandProcessInterface(bool is_admin) : is_admin(is_admin) {};

public:
	/** �������
		* ����������ڴ������������Ӧ����
		**** �������ɲο�https://blog.csdn.net/sesiria/article/details/52204448
		**** �ر�ע�⣬�ж�����Ϊedit��show��ִ����Ӧ����ǰҪ�ж�is_admin
	**/
	virtual void proc_command(std::string command) = 0;
};
