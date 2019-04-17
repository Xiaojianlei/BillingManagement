#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED   
#include <string> 
using namespace std; 
const string CARDPATH = "card.dat";     
const string BILLINGPATH = "billing.dat";   
const string REPORTPATH = "report.dat";    
const int TIMELENGTH=20; 
const int ADD = 11;// -ע�Ῠ
const int LOGIN = 12;//- �ϻ�
const int LOGOUT = 13;// -�»� 
const int TOPUP = 14;// -��ֵ 
const int RETURNFEE = 15;// -�˷�
const int CANCEL = 16;// -ע����
const int SUCCESS =0;       
const int FINDCARD    = 1;       
const int NOFINDCARD  = 2;      
const int NOMATCH     = 3;       
const int ENOUGHMONEY = 4;      
const int NOFARE = 5;      
const int USING = 6;      
const int UNUSE       = 7;      
const int INVALID     = 8;       
const int NOSETTLEMENT = 0;     
const int YESSETTLEMENT = 1;   
const int UNIT = 15;           
const float CHARGE = 0.5f;        

#endif 
