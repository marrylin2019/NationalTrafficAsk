#pragma once
#include <map>
#include <string>

class SignInferfaceBase
{
protected:
	// �˺ţ�Ψһ��
	std::string account;

	// ����
	std::string password;

	// �˺��������ݿ�
	std::map<std::string, std::string> acc_pw_db;


	// ���ڳ�ʼ���˺��������ݿ⣬��Ҫ�ڹ��캯���е���
	virtual void init_acc_pw_db() = 0;
public:
	// �����˺ź����벢���浽account��password��
	// Args: 
	// un: string		�û���
	// pw: string		����
	virtual void input_un_pw(std::string un, std::string pw) = 0;
};

class SignInInterface: public SignInferfaceBase
{
	/**
	  * ClassName: SignInBase
	  * Purpose:   ��¼
	  * MainFlow:  ���캯����ʼ���˺��������ݿ�->�û�����input_un_pw()��������->�û�����judge()�ж��˻�����
	  * Attention: ʹ����ӿڵ�ʱ��Ҫ��Sign_inAndSign_up_Model�ļ���SignIn�ඨ�������������Ҫ�õ��ĺ�����������Ķ��壬����ؽ�������Ϊprivate
	  *			   ���⣬�ӿں͸����еĹ��캯�������������͸��麯������ʵ��
	**/
protected:
	// ��¼��״̬
	// ȡֵ��������
	// 0���˻����벻ƥ�估�����ڵ�ǰ�˺�
	// 1:  ��ͨ�û�
	// 2:  ����Ա�û�
	int status;

	// ���캯��
	SignInInterface() { init_acc_pw_db(); judge(); }

	// �ж��˺��������
	// ʹ���������е�account��passwordΪ��������acc_pw_db�в���
	// ��ʼ��status
	// ȡֵ��status����
	virtual void judge() = 0;
public:
	// ���ص�¼״̬
	int get_status() { return status; }
};

class SignUpInterface : public SignInferfaceBase
{
	/**
	  * ClassName: SignUpBase
	  * Purpose:   ע��
	  * MainFlow:  ���캯����ʼ���˺��������ݿ�->�û�����input_un_pw()��������->�û�����write_into()�ж��Ƿ�ע��ɹ�
	  * Attention: ʹ����ӿڵ�ʱ��Ҫ��Sign_inAndSign_up_Model�ļ���SignUp�ඨ�������������Ҫ�õ��ĺ�����������Ķ��壬����ؽ�������Ϊprivate
	  *			   ���⣬�ӿں͸����еĹ��캯�������������͸��麯������ʵ��
	**/
protected:
	// ���캯��
	SignUpInterface() { init_acc_pw_db(); }
public:
	// д������
	// �����ݿ���ڸ�account������false��
	// ����account��passwordд��acc_pw_db�в���acc_pw_db����д��ԭ�ļ���������true
	virtual bool write_into() = 0;
};