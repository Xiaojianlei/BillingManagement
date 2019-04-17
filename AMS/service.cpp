//ϵͳ�˵�������
#include"stdafx.h"
#include<string>
#include "menu.h"
#include<vector>
#include<iostream>
#include<iomanip>
#include"model.h"
#include"global.h"
#include"cardlist.h"
#include"billList.h"
#include"reportlist.h"
#include"tool.h"
using namespace std;
//��ӿ�
void addCard(CardNode** ppCardNodeHead, ReportNode** ppReportNodeHead)
{
	string strNo;
	string strPwd;   
	float fBalance;
	if (inputNoPwdBalance(strNo, strPwd, fBalance))
	{
		int nResult = addNewCard(strNo, strPwd, fBalance, ppCardNodeHead, ppReportNodeHead);
		switch (nResult)
		{
		case FINDCARD:
		{
			cout << endl << endl << "����" << strNo << "���Ѿ����ڣ������ ��ʧ�ܣ�" << endl << endl;
			break;
		}
		case SUCCESS:
		{
			cout << endl << endl << "����¿��ɹ�!" << endl << endl;
			cout << "�¿����ţ�" << strNo << endl;
			cout << "�¿���" << setiosflags(ios::fixed) << setprecision(2) <<fBalance << endl;
			break;
		}
		default:
		{
			cout << endl << endl << "ϵͳ����!" << endl << endl;
			break;
		}
		}
	}
	else 
	{
		cout << endl << endl << "����ġ����ţ����룬������Ϣ��ʽ������Ҫ�� ��ӿ�ʧ��!" << endl << endl;
	}
}
//��ѯ��
void queryCard(CardNode* const pCardNodeHead)
{
	string strNo;
	cout << "�����뿨�ţ�������0������ʾȫ��������Ϣ\n";
	cin >> strNo;
	if (strNo == "!"|| strNo == "0") displayCard(pCardNodeHead);
	else displayCardone(pCardNodeHead, strNo);
	}
//�ϻ�
void loginCard(CardNode* pCardNodeHead, BillingNode **ppBillingNodeHead, ReportNode** ppReportNodeHead) {
	string strNo;
	string strPwd;
	LogonInfo* pInfo = new LogonInfo;
	char aTime[TIMELENGTH] = { 0 };
	if (inputNoPwd(strNo, strPwd)) {
		cout << endl << "----------�ϻ���Ϣ----------" << endl;
		int nResult = logon(strNo, strPwd, pInfo, pCardNodeHead, ppBillingNodeHead, ppReportNodeHead);
		switch (nResult)
		{
		case NOFINDCARD:
		case NOMATCH: {
			cout << endl << endl << "�������ڣ�����Ϣ���ԣ������ϻ���" << endl << endl;
			break;
		}
		case SUCCESS:
		{
			timeToString(pInfo->tLogon, aTime);
			cout << endl;
			cout << "����: \t" << strNo << endl;
			cout << "���: \t" << pInfo->fBalance << endl;
			cout << "�ϻ�ʱ�䣺\t" << aTime << endl;
			break;
		}
		case USING:
		{
			cout << endl << "�ÿ�����ʹ�ã������ظ��ϻ���" << endl;
			break;
		}
		case INVALID:
		{
			cout << endl << "�ÿ���ע���������ϻ���" << endl;
			break;
		}
		case ENOUGHMONEY:
		{
			cout << endl << "�����Ϊ0�������ϻ���" << endl;
			break;
		}
		default:break;
		}
	}
	else
	{
		cout << endl << endl << "���Ż��������ʽ����ȷ���ϻ�ʧ��!" << endl << endl;
	}
	delete pInfo;
}
//�»�
void logoutCard(CardNode* pCardNodeHead, BillingNode* pBillingNodeHead, ReportNode** ppReportNodeHead) {
	string strNo;
	string strPwd;
	SettleInfo* pInfo = new SettleInfo;
	char aStartTime[TIMELENGTH] = { 0 };
	char aEndTime[TIMELENGTH] = { 0 };
	if (inputNoPwd(strNo, strPwd)) {
		cout << "----------�»���Ϣ����----------\n";
		int nResult = settle(strNo, strPwd, pInfo, pCardNodeHead, pBillingNodeHead, ppReportNodeHead);
		switch (nResult)
		{
		case NOFINDCARD:
		case NOMATCH:
		{
			cout << endl << endl << "�������ڣ�����Ϣ���ԣ��»�ʧ�ܣ�" << endl << endl;
			break;
		}
		case SUCCESS:
		{
			timeToString(pInfo->tStart, aStartTime);
			timeToString(pInfo->tEnd, aEndTime);
			cout << endl;
			cout << "����: \t" << strNo << endl;
			cout << "����: \t" << pInfo->fAmount << endl;
			cout << "���: \t" << setiosflags(ios::fixed) << setprecision(2)<<pInfo->fBalance << endl;
			cout << "�ϻ�ʱ�䣺\t" << aStartTime << endl;
			cout << "�»�ʱ�䣺\t" << aEndTime << endl;
			break;
		}
		case INVALID:
		{
			cout << endl << "�ÿ���ע��������ִ�иò�����" << endl;
			break;
		}
		case UNUSE:
		{
			cout << endl << endl << "�ÿ�û���ϻ���" << endl << endl;
			break;
		}
		case ENOUGHMONEY:
		{
			cout << endl << endl << "�����㣬���ȳ�ֵ���»���" << endl << endl;
		}
		default:break;
		}
	}
	else
	{
		cout << endl << endl << "���Ż��������ʽ����ȷ���»�ʧ��!" << endl << endl;
	}

	delete pInfo;
}

void top_up(CardNode* pCardNodeHead, ReportNode** ppReportNodeHead)
{
	string strNo;
	string strPwd;
	TopupInfo* pInfo = new TopupInfo;
	if (inputNoPwd(strNo, strPwd)) {
		cout << "----------��ֵ��Ϣ����----------\n";
		int nResult = topup(strNo, strPwd, pInfo, pCardNodeHead, ppReportNodeHead);
		switch (nResult)
		{
		case NOFINDCARD:
		case NOMATCH:
		{
			cout << endl << endl << "�������ڣ�����Ϣ���ԣ���ֵʧ�ܣ�" << endl << endl;
			break;
		}
		case INVALID:
		{
			cout << endl << "�ÿ���ע��������ִ�иò�����" << endl;
			break;
		}
		case SUCCESS:
		{
			cout << endl;
			cout << "����: \t" << strNo << endl;
			cout << "���: \t" << setiosflags(ios::fixed) << setprecision(2) << pInfo->fBalance << endl;
			break;
		}
		default:break;
		}
	}
	else
	{
		cout << endl << endl << "���Ż��������ʽ����ȷ����ֵʧ��!" << endl << endl;
	}

	delete pInfo;
}
//�˷�
void return_fee(CardNode* pCardNodeHead, ReportNode** ppReportNodeHead) {
	string strNo;
	string strPwd;
	ReturnfeeInfo* pInfo = new ReturnfeeInfo;
	if (inputNoPwd(strNo, strPwd)) {
		cout << "----------�˷���Ϣ����----------\n";
		int nResult = returnfee(strNo, strPwd, pInfo, pCardNodeHead, ppReportNodeHead);
		switch (nResult)
		{
		case NOFINDCARD:
		case NOMATCH:
		{
			cout << endl << endl << "�������ڣ�����Ϣ���ԣ��˷�ʧ�ܣ�" << endl << endl;
			break;
		}
		case INVALID:
		{
			cout << endl << "�ÿ���ע��������ִ�иò�����" << endl;
			break;
		}
		case USING:
		{
			cout << endl << "�ÿ�����ʹ�ã������˷ѣ�" << endl;
			break;
		}
		case ENOUGHMONEY:
		{
			cout << endl << endl << "�����㣬���������룡" << endl << endl;
			break;
		}
		case SUCCESS:
		{
			cout << endl;
			cout << "����: \t" << strNo << endl;
			cout << "���: \t" << setiosflags(ios::fixed) << setprecision(2) << pInfo->fBalance << endl;
			break;
		}
		default:break;
		}
	}
	else
	{
		cout << endl << endl << "���Ż��������ʽ����ȷ���˷�ʧ��!" << endl << endl;
	}
		}
//��ѯͳ��
void statis(ReportNode** ppReportNodeHead) {
	char selection;
	cout << "1.��ѯ 2.ͳ��" << endl;
	do {
		selection = 'a';
		cin >> selection;
		cin.clear();
		cin.sync();
		switch (selection) {
		case '1':
		{ cout << endl << "-------��ѯ --------" << endl << endl;
		find(*ppReportNodeHead);
		break; }
		case '2':
		{ cout << endl << "-------ͳ��--------" << endl << endl;
		sum(*ppReportNodeHead);
		break; }
		default:
		{cout << "����Ĳ˵���Ŵ���\n"; break; }
		}
		cout << endl;
	} while (selection != '0');
}
void DeleteOff(CardNode* pCardNodeHead, ReportNode** ppReportNodeHead) {
	char selection;
	cout << "1.ע�� 2.ɾ���� 3.ɾ��ʹ�ü�¼" << endl;
	do {
		selection = 'a';
		cin >> selection;
		cin.clear();
		cin.sync();
		switch (selection) {
		case '1':
		{ cout << endl << "-------ע�� --------" << endl << endl;
		invalid(pCardNodeHead, ppReportNodeHead);
		break; }
		case '2':
		{ cout << endl << "-------ɾ����--------" << endl << endl;
		DeleteCard(pCardNodeHead);
		break; }
		case '3':
		{ cout << endl << "-------ɾ��ʹ�ü�¼--------" << endl << endl;
		DeleteReport(*ppReportNodeHead);
		break; }
		default:
		{cout << "����Ĳ˵���Ŵ���\n"; break; }
		}
		cout << endl;
	} while (selection != '0');
}
//ɾ���ڵ�
void clearData(CardNode* pCardNodeHead) 
{
	CardNode *pCardNode;
	while (pCardNodeHead != NULL)
	{
		pCardNode = pCardNodeHead; 
		pCardNodeHead = pCardNodeHead->next;
		delete pCardNode;
	}
}
