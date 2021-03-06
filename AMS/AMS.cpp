// AMS.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "menu.h"
#include"service.h"
#include"model.h"
#include"global.h"
#include<vector>
#include<iostream>
#include<fstream>
#include"cardlist.h"
#include"reportlist.h"
#include"billList.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	char selection;
	CardNode*pCardNodeHead = NULL;
	pCardNodeHead = CardListInit(CARDPATH);
	BillingNode *pBillingNodeHead = NULL;
	pBillingNodeHead=BillListInit(BILLINGPATH);
	ReportNode*pReportNodeHead = NULL;
	pReportNodeHead = ReportListInit(REPORTPATH);
	cout << endl;
	cout << "---------------欢迎进入小剑网咖计费管理系统---------------" << endl; 
	cout << endl;

	do {
		outputMenu();
		selection ='a';
		cin >> selection;
		cin.clear();
		cin.sync();
		switch (selection) {
		case '1':
		{ cout << endl << "-------添加卡--------" << endl << endl;
		addCard(&pCardNodeHead, &pReportNodeHead);
		break; }
		case '2':
		{ cout << endl << "-------查询卡--------" << endl << endl;
		queryCard(pCardNodeHead);
		break; }
		case '3':
		{ cout << endl << "-------上机--------" << endl << endl;
		loginCard(pCardNodeHead,&pBillingNodeHead, &pReportNodeHead);
		break; }
		case '4':
		{ cout << endl << "-------下机--------" << endl << endl;  
		logoutCard(pCardNodeHead, pBillingNodeHead, &pReportNodeHead);
		break; }
		case '5':
		{ cout << endl << "-------充值--------" << endl << endl;
		top_up(pCardNodeHead, &pReportNodeHead);
		break; }
		case '6':
		{ cout << endl << "-------退费--------" << endl << endl; 
		return_fee(pCardNodeHead, &pReportNodeHead);
		break; }
		case '7':
		{ cout << endl << "-------查询统计--------" << endl << endl;  
		statis(&pReportNodeHead);
		break; }
		case '8':
		{ cout << endl << "-------注销卡--------" << endl << endl; 
		DeleteOff(pCardNodeHead, &pReportNodeHead);
		break; }
		case '0':
		{
			clearData(pCardNodeHead);
			cout << endl << "感谢你使用本系统！" << endl << endl; break;
		}
		default:
		{cout << "输入的菜单编号错误！\n"; break; }
		}
		cout << endl;
	} while (selection != '0');

    return 0;
}

