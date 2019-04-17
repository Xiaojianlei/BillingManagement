#include"stdafx.h"
#include<string>
#include<iostream>
#include"model.h"
#include"global.h"
#include"menu.h"
#include <fstream>
#include<iomanip>
#include"tool.h"
using namespace std;
ReportNode* ReportListInit(const string reportFilename)
{
	ifstream reportfile(reportFilename);
	ReportNode *pReportNode, *pReportNodeHead, *pReportNodeTail;
	Report report;
	if (!reportfile.is_open()) { return NULL; }
	pReportNodeHead = NULL;
	pReportNodeTail = NULL;
	while (1) {
		reportfile.read((char*)&report, sizeof(Report));
		if (reportfile.eof()) { break; }
		pReportNode = new ReportNode;
		pReportNode->data = report;
		if (pReportNodeHead == NULL)
		{
			pReportNodeHead = pReportNode;
			pReportNodeTail = pReportNode;
		}
		else
		{
			pReportNodeTail->next = pReportNode;
			pReportNodeTail = pReportNode;
		}
	}

	pReportNodeTail->next = NULL;
	reportfile.close();
	return pReportNodeHead;
}
Report* reportIsExist(string strNo, int &nReportIndex, ReportNode*  pReportNodeHead)
{
	ReportNode *pReportNode = pReportNodeHead;
	nReportIndex = 0;
	while (pReportNode != NULL)
	{
		if (strcmp(pReportNode->data.aName, strNo.c_str()) == 0)
		{
			return &(pReportNode->data);
		}
		pReportNode = pReportNode->next;
		nReportIndex++;
	}
	return NULL;
}
bool saveReport(const Report* pReport, const string filename)
{
	ofstream ofile(filename, ios::binary | ios::app);
	ofile.write((char*)pReport, sizeof(Report));
	ofile.close();
	return true;
}
void  addNewReport(string strNo, int operate, float operateuse, float fBalance, ReportNode** ppReportNodeHead)
{
	int nCardIndex = 0;
	Report report;
	strcpy(report.aName, strNo.c_str());
	report.fBalance = fBalance;
	report.OperateUse = operateuse;
	report.Operate = operate;
	report.operatetime = time(NULL);
	ReportNode* pReportNode = new ReportNode;
	pReportNode->data = report;
	ReportNode *pReportNodeHead = *ppReportNodeHead;  ReportNode *pReportNodeTail = *ppReportNodeHead;
	if (pReportNodeHead == NULL)
	{
		pReportNodeHead = pReportNode;
		pReportNodeTail = pReportNode;
		*ppReportNodeHead = pReportNode;
	}
	else
	{
		pReportNodeTail = pReportNodeHead;
		while (pReportNodeTail->next != NULL)
			pReportNodeTail = pReportNodeTail->next;
		pReportNodeTail->next = pReportNode;
		pReportNodeTail = pReportNode;
	}
	pReportNodeTail->next = NULL;
	saveReport(&report, REPORTPATH);
}
void find(ReportNode* pReportNodeHead)
{
	string strNo;
	int n = 0;
	cout << "�����뿨��\n";
	cin >> strNo;
	Report* pReport = reportIsExist(strNo, n, pReportNodeHead);
		ReportNode *pReportNode = pReportNodeHead;
		if (pReport == NULL) cout << "�޸ÿ���¼\n"; 
		else cout << "����\t\tִ�в���\t����ʱ��\t\t�漰���\t\t���\n";
		while (pReportNode != NULL)
		{
			if (strcmp(pReportNode->data.aName, strNo.c_str()) == 0)
			{
				Report *it =& pReportNode->data;
				char aLastTime[TIMELENGTH] = { 0 };
				timeToString(it->operatetime, aLastTime);
				cout << setiosflags(ios::left) << setw(8) << it->aName << "\t";
				if (it->Operate == ADD) cout << setiosflags(ios::left) << setw(8) << "ע��\t";
				else if (it->Operate == LOGIN) cout << setiosflags(ios::left) << setw(8) << "�ϻ�\t";
				else if (it->Operate == LOGOUT) cout << setiosflags(ios::left) << setw(8) << "�»�\t";
				else if (it->Operate == TOPUP) cout << setiosflags(ios::left) << setw(8) << "��ֵ\t";
				else if (it->Operate == RETURNFEE) cout << setiosflags(ios::left) << setw(8) << "�˷�\t";
				else if (it->Operate == CANCEL) cout << setiosflags(ios::left) << setw(8) << "ע��\t";
				else cout << setw(8) << "����\t";
				cout << setiosflags(ios::left) << setw(8) << aLastTime <<"\t\t";
				cout << setiosflags(ios::left) << setw(8) << setiosflags(ios::fixed) << setprecision(2) << it->OperateUse << "\t\t";
				cout << setiosflags(ios::left) << setw(8) << setiosflags(ios::fixed) << setprecision(2) << it->fBalance << "\n";
				n++;
			}
			pReportNode = pReportNode->next;
		}
}

void sum(ReportNode* pReportNodeHead) {
	int year,month,day,hour,min;
	int year1, month1, day1, hour1, min1;
	float  consume = 0, topupfee = 0, returnFee = 0;
	int n = 0;
	cout << "��������ʼʱ�䡰--��--��--��--ʱ--��--��\n";
	cin>> year>> month>> day>> hour>>min;
	cout << "��������ֹʱ�䡰--��--��--��--ʱ--��--��\n";
	cin >> year1 >> month1 >> day1 >> hour1 >> min1;
	cout << "����\t\tִ�в���\t����ʱ��\t\t�漰���\t\t���\n";
	ReportNode *pReportNode = pReportNodeHead;
	while (pReportNode != NULL)
	{
		Report *it = &pReportNode->data;
		if( (stringToTime(year, month, day, hour, min)<= it->operatetime) && (it->operatetime <=stringToTime(year1, month1, day1, hour1, min1) ))
		{
			char aLastTime[TIMELENGTH] = { 0 };
			timeToString(it->operatetime, aLastTime);
			cout << setiosflags(ios::left) << setw(8) << it->aName << "\t";
			if (it->Operate == ADD) cout << setiosflags(ios::left) << setw(8) << "ע��\t";
			else if (it->Operate == LOGIN) cout << setiosflags(ios::left) << setw(8) << "�ϻ�\t";
			else if (it->Operate == LOGOUT) {
				cout << setiosflags(ios::left) << setw(8) << "�»�\t";
				consume = consume + it->OperateUse;
			}
			else if (it->Operate == TOPUP) {
				cout << setiosflags(ios::left) << setw(8) << "��ֵ\t";
				topupfee = topupfee + it->OperateUse;
			}
			else if (it->Operate == RETURNFEE) {
				cout << setiosflags(ios::left) << setw(8) << "�˷�\t";
				returnFee = returnFee + it->OperateUse;
			}
			else if (it->Operate == CANCEL) {
				cout << setiosflags(ios::left) << setw(8) << "ע��\t";
			}
			else cout << setw(8) << "����\t";
			cout << setiosflags(ios::left) << setw(8) << aLastTime << "\t\t";
			cout << setiosflags(ios::left) << setw(8) << setiosflags(ios::fixed) << setprecision(2) << it->OperateUse << "\t\t";
			cout << setiosflags(ios::left) << setw(8) << setiosflags(ios::fixed) << setprecision(2) << it->fBalance << "\n";
			n++;
		}
		pReportNode = pReportNode->next;
	}
	if (n == 0) cout << "�ö�ʱ������ʹ�ü�¼" << endl;
	else {
		cout << "�ö�ʱ���ܼƶ��\n";
		cout << "��ʹ��\t\t" << "�ܳ�ֵ\t\t" << "���˷�\n";
		cout << consume << "\t\t" << topupfee << "\t\t" << returnFee << endl;
	}
}
