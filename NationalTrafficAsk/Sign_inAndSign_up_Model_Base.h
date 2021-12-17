#pragma once
#include <map>
#include <string>
#include <iostream>
using namespace std;

class AuthenticUtils
{
public:
	// 加密（可选功能）
	// 加密password，
	// 结果放入password
	static string encrpty();

	// 读取文件数据
	static map<string, string> get_db();
};

class SignUpAndInBase
{
	/**
	  * 注意：
	  *		要实现构造函数和析构函数
	**/
protected:
	// 账号（唯一）
	string account;

	// 密码
	string password;

	// 账号密码数据库
	map<string, string> acc_pw_db;

public:
	// 构造函数
	// 用文件中保存的账号密码数据初始化acc_pw_db
	// 可以使用AuthenticUtils.get_db()获取哈希表
	SignUpAndInBase();

	// 析构函数
	~SignUpAndInBase();

	// 输入账号和密码并保存到account和password中
	// Args: 
	// un: string		用户名
	// pw: string		密码
	virtual void input_un_pw(string un, string pw) = 0;
};

class SignInBase: public SignUpAndInBase
{
	/**
	  * ClassName: SignInBase
	  * Purpose:   登录
	  * MainFlow:  构造函数初始化账号密码数据库->用户调用input_un_pw()输入数据->用户调用judge()判断账户类型
	  * Attention: 使用这接口的时候要在Sign_inAndSign_up_Model文件的SignIn类定义内自行添加需要用到的函数和数据域的定义，但务必将其设置为private
	  *			   另外，接口和父类中的构造函数、析构函数和各虚函数必须实现
	**/
public:
	// 判断账号密码情况
	// 使用数据域中的account和password为参数，在acc_pw_db中查找
	// Return:
	// -1：账户密码不匹配及不存在当前账号
	// 0:  普通用户
	// 1:  管理员用户
	virtual int judge() = 0;
};

class SignUpBase : public SignUpAndInBase
{
	/**
	  * ClassName: SignUpBase
	  * Purpose:   注册
	  * MainFlow:  构造函数初始化账号密码数据库->用户调用input_un_pw()输入数据->用户调用write_into()判断是否注册成功
	  * Attention: 使用这接口的时候要在Sign_inAndSign_up_Model文件的SignUp类定义内自行添加需要用到的函数和数据域的定义，但务必将其设置为private
	  *			   另外，接口和父类中的构造函数、析构函数和各虚函数必须实现
	**/
public:
	// 写入数据
	// 若数据库存在该account，返回false；
	// 否则将account和password写入acc_pw_db中并将acc_pw_db覆盖写入原文件，并返回true
	virtual bool write_into() = 0;
};