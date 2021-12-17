#pragma once
#include <map>
#include <string>
#include <iostream>
using namespace std;

class AuthenticUtils
{
public:
	// ���ܣ���ѡ���ܣ�
	// ����password��
	// �������password
	static string encrpty();

	// ��ȡ�ļ�����
	static map<string, string> get_db();
};

class SignUpAndInBase
{
	/**
	  * ע�⣺
	  *		Ҫʵ�ֹ��캯������������
	**/
protected:
	// �˺ţ�Ψһ��
	string account;

	// ����
	string password;

	// �˺��������ݿ�
	map<string, string> acc_pw_db;

public:
	// ���캯��
	// ���ļ��б�����˺��������ݳ�ʼ��acc_pw_db
	// ����ʹ��AuthenticUtils.get_db()��ȡ��ϣ��
	SignUpAndInBase();

	// ��������
	~SignUpAndInBase();

	// �����˺ź����벢���浽account��password��
	// Args: 
	// un: string		�û���
	// pw: string		����
	virtual void input_un_pw(string un, string pw) = 0;
};

class SignInBase: public SignUpAndInBase
{
	/**
	  * ClassName: SignInBase
	  * Purpose:   ��¼
	  * MainFlow:  ���캯����ʼ���˺��������ݿ�->�û�����input_un_pw()��������->�û�����judge()�ж��˻�����
	  * Attention: ʹ����ӿڵ�ʱ��Ҫ��Sign_inAndSign_up_Model�ļ���SignIn�ඨ�������������Ҫ�õ��ĺ�����������Ķ��壬����ؽ�������Ϊprivate
	  *			   ���⣬�ӿں͸����еĹ��캯�������������͸��麯������ʵ��
	**/
public:
	// �ж��˺��������
	// ʹ���������е�account��passwordΪ��������acc_pw_db�в���
	// Return:
	// -1���˻����벻ƥ�估�����ڵ�ǰ�˺�
	// 0:  ��ͨ�û�
	// 1:  ����Ա�û�
	virtual int judge() = 0;
};

class SignUpBase : public SignUpAndInBase
{
	/**
	  * ClassName: SignUpBase
	  * Purpose:   ע��
	  * MainFlow:  ���캯����ʼ���˺��������ݿ�->�û�����input_un_pw()��������->�û�����write_into()�ж��Ƿ�ע��ɹ�
	  * Attention: ʹ����ӿڵ�ʱ��Ҫ��Sign_inAndSign_up_Model�ļ���SignUp�ඨ�������������Ҫ�õ��ĺ�����������Ķ��壬����ؽ�������Ϊprivate
	  *			   ���⣬�ӿں͸����еĹ��캯�������������͸��麯������ʵ��
	**/
public:
	// д������
	// �����ݿ���ڸ�account������false��
	// ����account��passwordд��acc_pw_db�в���acc_pw_db����д��ԭ�ļ���������true
	virtual bool write_into() = 0;
};