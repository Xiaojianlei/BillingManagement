//�����ຯ��
#include"stdafx.h"
#include<string>
#include<iostream>
#include<vector>
#include"model.h"
#include"global.h"
#include"tool.h"
#include<iomanip>
#include <fstream> 
using namespace std;

//����˵�
void outputMenu()
{
	cout << "------�Ʒ�ϵͳ�˵�------" << endl << endl;
	cout << "1.��ӿ�" << endl;
	cout << "2.��ѯ��" << endl;
	cout << "3.�ϻ�" << endl;
	cout << "4.�»�" << endl;
	cout << "5.��ֵ" << endl;
	cout << "6.�˷�" << endl;
	cout << "7.��ѯͳ��" << endl;
	cout << "8.ע����" << endl;
	cout << "0.�˳�" << endl;
	cout << "��ѡ��˵����ţ�0~8):";
}
//���뿨��
bool inputcard(string& strNo) {
	while(true) 
	{
		cout << "�����뿨�ţ�5��8λ����";
		cin >> strNo;
		cin.clear();
		cin.sync();
		if(strNo.length() > 8|| strNo.length()<5) {
			cout << "���ų��Ȳ���ȷ��" << endl;
			char ch = 'M';
			while (ch != 'N'&&ch != 'Y') {
				cout << "�Ƿ��������룿�ǣ�Y��/��N)";
				cin >> ch;
				ch = toupper(ch);
				cin.clear();
				cin.sync();
			}
			if(ch == 'N') { return false; }
		}
		else { break; }
	}
}
//��������
bool inputCardPwd(string& strPwd) {
	while (true)
	{
		cout << "���������루5��8λ����";
		cin >> strPwd;
		cin.clear();
		cin.sync();
		if (strPwd.length() < 5|| strPwd.length()>8) {
			cout << "���볤�Ȳ���ȷ��" << endl;
			char ch = 'M';
			while (ch != 'N'&&ch != 'Y') {
				cout << "�Ƿ��������ã��ǣ�Y�� / ��N)";
				cin >> ch;
				ch = toupper(ch);
				cin.clear();
				cin.sync();
			}
			if (ch == 'N') { return false; }
		}
		else { break; }
	}
}
//������
bool inputCardBalance(float& fBalance) {
	while (true)
	{
		cout << "�������ֵ����λ��Ԫ��";
		cin >> fBalance;
		cin.clear();
		cin.sync();
		if ((fBalance*100!=int(fBalance * 100))&&fBalance>=0) {
			cout << "�������ʽ����" << endl;
			char ch = 'M';
			while (ch != 'N'&&ch != 'Y') {
				cout << "�Ƿ��������룿�ǣ�Y�� / ��N)";
				cin >> ch;
				ch = toupper(ch);
				cin.clear();
				cin.sync();
			}
			if (ch == 'N') { return false; }
		}
		else { break; }
	}
}
//�Ƿ������˺ż�����
bool inputNoPwd(string& strNo, string& strPwd) 
{
	if (inputcard(strNo) && inputCardPwd(strPwd)) return true;
	else return false;
}
//�Ƿ�����ȫ����Ϣ
bool inputNoPwdBalance(string& strNo, string& strPwd, float& fBalance) {
	if (inputcard(strNo)&& inputCardPwd(strPwd)&& inputCardBalance(fBalance)) return true; 
	else return false;
}
