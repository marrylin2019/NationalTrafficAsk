#pragma once
#include <map>
#include <string>

class SignInferfaceBase
{
protected:
	// 账号（唯一）
	std::string account;

	// 密码
	std::string password;

	// 账号密码数据库
	std::map<std::string, std::string> acc_pw_db;


	// 用于初始化账号密码数据库，需要在构造函数中调用
	virtual void init_acc_pw_db() = 0;
public:
	// 输入账号和密码并保存到account和password中
	// Args: 
	// un: string		用户名
	// pw: string		密码
	virtual void input_un_pw(std::string un, std::string pw) = 0;
};

class SignInInterface: public SignInferfaceBase
{
	/**
	  * ClassName: SignInBase
	  * Purpose:   登录
	  * MainFlow:  构造函数初始化账号密码数据库->用户调用input_un_pw()输入数据->用户调用judge()判断账户类型
	  * Attention: 使用这接口的时候要在Sign_inAndSign_up_Model文件的SignIn类定义内自行添加需要用到的函数和数据域的定义，但务必将其设置为private
	  *			   另外，接口和父类中的构造函数、析构函数和各虚函数必须实现
	**/
protected:
	// 登录的状态
	// 取值含义如下
	// 0：账户密码不匹配及不存在当前账号
	// 1:  普通用户
	// 2:  管理员用户
	int status;

	// 构造函数
	SignInInterface() { init_acc_pw_db(); judge(); }

	// 判断账号密码情况
	// 使用数据域中的account和password为参数，在acc_pw_db中查找
	// 初始化status
	// 取值见status词条
	virtual void judge() = 0;
public:
	// 返回登录状态
	int get_status() { return status; }
};

class SignUpInterface : public SignInferfaceBase
{
	/**
	  * ClassName: SignUpBase
	  * Purpose:   注册
	  * MainFlow:  构造函数初始化账号密码数据库->用户调用input_un_pw()输入数据->用户调用write_into()判断是否注册成功
	  * Attention: 使用这接口的时候要在Sign_inAndSign_up_Model文件的SignUp类定义内自行添加需要用到的函数和数据域的定义，但务必将其设置为private
	  *			   另外，接口和父类中的构造函数、析构函数和各虚函数必须实现
	**/
protected:
	// 构造函数
	SignUpInterface() { init_acc_pw_db(); }
public:
	// 写入数据
	// 若数据库存在该account，返回false；
	// 否则将account和password写入acc_pw_db中并将acc_pw_db覆盖写入原文件，并返回true
	virtual bool write_into() = 0;
};