#pragma once
#include<time.h>

struct Card
{
	char aName[8];
	char aPwd[8];
	int nStatus;                    // ��״̬(UNUSE-δ�ϻ���USING-�����ϻ���INVALID-��ע����
	time_t tStart;
	float fTotalUse;                 //�ۼƽ��
	time_t tLast;                    // ���ʹ��ʱ�䣬long 
	int nUseCount;                   //ʹ�ô���
	float fBalance;                  //���
};
struct CardNode
{
	Card data;
	struct CardNode *next;
};
struct Billing
{
	char aCardName[8];
	time_t tStart;
	time_t tEnd;
	float fAmount;
	float fTotalUse;
	int nStatus;
	int nDel;
};
struct BillingNode
{
	Billing data;
	struct BillingNode *next;
};
struct LogonInfo
{
	char aCardName[8];
	time_t tLogon;
	float fBalance;
};

struct SettleInfo
{
	char aCardName[8];
	int tStart;
	int tEnd;
	float fAmount;
	float fBalance;
	float fTotalUse;
};
struct TopupInfo
{
	char aCardName[8];
	float fBalance;
};
struct ReturnfeeInfo
{
	char aCardName[8];
	float fBalance;
};
struct CancelInfo
{
	char aCardName[8];
	float fBalance;
};
struct Report
{
	char aName[18]; // ����
	int Operate; // ������(ADD-ע�Ῠ LOGIN-�ϻ� LOGOUT-�»� TOPUP-��ֵ RETURNFEE-�˷�)
	time_t operatetime; // ����ʱ��
	float OperateUse; // �������
	float fBalance; // ���
};
struct ReportNode {
	Report data;
	struct ReportNode *next;
};
