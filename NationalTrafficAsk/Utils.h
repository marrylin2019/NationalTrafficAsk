#pragma once
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& prime, const std::string& sign);

class AuthenticUtils
{
public:
	// 加密（可选功能）
	// 加密password，
	// 结果放入password
	static std::string encrpty();

	// 读取文件数据
	static std::map<std::string, std::string> get_db();
};
