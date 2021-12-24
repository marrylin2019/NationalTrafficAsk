#pragma once
#include "Utils.h"
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
class TIME {
public:
	int date[6];
	struct tm struct_time;
	TIME(const std::string& time)
	{
		sscanf_s(time.c_str(), "%d-%d-%d %d:%d:%d", &date[0], &date[1], &date[2], &date[3], &date[4], &date[5]);
		sscanf_s(time.c_str(), "%d-%d-%d %d:%d:%d", &struct_time.tm_year, &struct_time.tm_mon, &struct_time.tm_mday, &struct_time.tm_hour, &struct_time.tm_min, &struct_time.tm_sec);
		struct_time.tm_year -= 1900;
		struct_time.tm_mon -= 1;
	}
	long operator-(TIME& t)
	{
		return (long)difftime(mktime(&this->struct_time), mktime(&t.struct_time));
	}
	long operator-(TIME* t)
	{
		return (long)difftime(mktime(&this->struct_time), mktime(&t->struct_time));
	}
};

class BaseData {
// 0. 索引号 1. 出发城市 2. 目的城市 3. 出发时间 4. 到达时间 5. 班次 6. 交通方式 7. 费用
public:
	int index;
	std::string begin_city;
	std::string end_city;
	TIME* begin_time;
	TIME* end_time;
	std::string classes;
	std::string traffic_type;
	double price;

	BaseData(const int& id, const std::string& bc, const std::string& ec, TIME* bt, TIME* et,
		const std::string& cla, const std::string& tt, const double& price) :
			index(id), begin_city(bc), end_city(ec), begin_time(bt), end_time(et), classes(cla), 
			traffic_type(tt), price(price) {};
};
