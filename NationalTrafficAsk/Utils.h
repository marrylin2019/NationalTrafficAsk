#pragma once
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& prime, const std::string& sign);

class AuthenticUtils
{
public:
	// ���ܣ���ѡ���ܣ�
	// ����password��
	// �������password
	static std::string encrpty();

	// ��ȡ�ļ�����
	static std::map<std::string, std::string> get_db();
};
