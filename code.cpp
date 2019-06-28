#include<iostream>
#include<fstream>
#include<unistd.h>
#include<string.h>
using namespace std;
struct cus
{
int plan_type;
int validity;
float rate;
int code;
int speed;
char userid[10];
char password[20];
char name[20];
char address[50];
char Mno[10];
};
class customer
{
public:
struct cus c;
virtual void view_details();
void update_details();
void make_payment();
friend ostream& operator<<(ostream&,struct cus);
};

class provider: public customer
{
public:
friend void get_details(provider);
friend void get_details(provider,int);
void add_customer();
void remove_customer();
void view_plans();
void view_details();
};
void plans_view()
{
cout<<"\n\t\t\t\t~~~PLANS AVAILABLE~~~\n\n";
cout<<"\t\t\t\tFor 1 Month\n\n";

cout<<"\tCODE: 11\t\t";
cout<<"1 Mbps\t\t";
cout<<"@Rs.499.0";
cout<<" Per month.\n\n";

cout<<"\tCODE: 12\t\t";
cout<<"10 Mbps\t\t";
cout<<"@Rs.899.0";
cout<<" Per month.\n\n";

cout<<"\tCODE: 13\t\t";
cout<<"50 Mbps\t\t";
cout<<"@Rs.1199.0";
cout<<" Per month.\n\n";

cout<<"\t\t\t\tFor 6 Months\n\n";

cout<<"\tCODE: 21\t\t";
cout<<"1 Mbps\t\t";
cout<<"@Rs.2099.0";
cout<<" Per 6 months.\n\n";

cout<<"\tCODE: 22\t\t";
cout<<"10 Mbps\t\t";
cout<<"@Rs.4099.0";
cout<<" Per 6 months.\n\n";

cout<<"\tCODE: 23\t\t";
cout<<"50 Mbps\t\t";
cout<<"@Rs.6099.0";
cout<<" Per 6 months.\n\n";

cout<<"\t\t\t\tFor 12 Months\n\n";

cout<<"\tCODE: 31\t\t";
cout<<"1 Mbps\t\t";
cout<<"@Rs.3599.0";
cout<<" Per year.\n\n";

cout<<"\tCODE: 32\t\t";
cout<<"10 Mbps\t\t";
cout<<"@Rs.8099.0";
cout<<" Per year.\n\n";

cout<<"\tCODE: 33\t\t";
cout<<"50 Mbps\t\t";
cout<<"@Rs.10999.0";
cout<<" Per year.\n\n";

}
ostream& operator<<(ostream& ps,struct cus c)
{
cout<<"\tDetails:\n";
cout<<"\tName:";
ps<<c.name<<endl;
cout<<"\tAddress:";
ps<<c.address<<endl;
cout<<"\tMobile no.:";
ps<<c.Mno<<endl;
cout<<"\tPlan details:"<<endl;
cout<<"\tPlan type:";
c.plan_type?cout<<"Prepaid":cout<<"Postpaid";
cout<<"\tValidity:";
ps<<c.validity;
cout<<" Months"<<endl;
cout<<"\tSpeed:";
ps<<c.speed;
cout<<" Mbps"<<endl;
c.plan_type?cout<<"\tRecharge Amount: Rs.":cout<<"\tYour Bill is: Rs.";
ps<<c.rate<<endl;
return ps;

}
void customer::view_details()
{
cout<<"\n\n\tDetails:\n";
cout<<"\tName:"<<c.name<<endl;
cout<<"\tAddress:"<<c.address<<endl;
cout<<"\tMobile no.:"<<c.Mno<<endl;
cout<<"\tPlan details:"<<endl;
cout<<"\tPlan type:";
c.plan_type?cout<<"Prepaid":cout<<"Postpaid";
cout<<"\tValidity:"<<c.validity<<" Months"<<endl;
cout<<"\tSpeed:"<<c.speed<<" Mbps"<<endl;
c.plan_type?cout<<"\tRecharge Amount: Rs.":cout<<"\tYour Bill is: Rs.";
cout<<c.rate<<endl;
}

void customer::update_details()
{
int ch;
cout<<"\tYour Details:"<<endl;
view_details();
h:
cout<<"\t1.Name\t\t2.Address\t\t3.Mobile No.\n";
cout<<"\tSelect the option you want to update\n\t";
cin>>ch;
switch(ch)
{
case 1:cout<<"\tEnter new Name:";
      cin>>c.name;
      break;
case 2:cout<<"\tEnter new Address:";
      cin>>c.address;
      break;
case 3:cout<<"\tEnter new Mobile No.:";
      cin>>c.Mno;
      break;
default:cout<<"\tInvalid choice!!!\n";
       goto h;
}
}
void customer::make_payment()
{
int ch;
cout<<"\tYour current plan is:\n";
cout<<"\tPlan Type:"<<c.plan_type?cout<<"Prepaid":cout<<"Postpaid";
cout<<"\n\tCode:"<<c.code;
cout<<"\n\tValidity:"<<c.validity<<" Months";
cout<<"\n\tSpeed:"<<c.speed<<" Mbps";
c.plan_type?cout<<"\tRecharge Amount: Rs.":cout<<"\tYour Bill is: Rs.";
cout<<c.rate<<endl;
b:cout<<"\tPayment Modes:\n";
cout<<"\t1.Pay by Cash\n";
cout<<"\t2.Pay by Cheque\n\t";
cin>>ch;
switch(ch)
{
case 1:cout<<"\tIn order to make DATATRUCK Broadband Service Bill payment\n";
       cout<<"\tsubscriber opting for cash payment can use Home pickup or Flexi Recharge facility.\n";
       cout<<"\n\tHome Pick-up Facility:\n";
       cout<<"\tThe subscriber can hand over cash payment against SMS payment receipt to authorised DATATRUCK representative.\n";
       cout<<"\tTo avail this facility, call on 1860 3000 3535\n";
       cout<<"\n\tFlexi Recharge Facility:\n";
       cout<<"\tThe subscriber can visit any of the Bill payment/recharge outlets and pay cash.\n";
       cout<<"\tThe retailer will process the payment and provide the subscriber with authorised payment receipt.\n";
       break;
case 2:cout<<"\tThe subscriber can make payment of DATATRUCK Broadband Service Bill through Drop Box or Home Pick-up option.";
       cout<<"\tDrop Boxes:\n";
       cout<<"\tCheque/Demand Draft can be dropped at any of the 5000 drop boxes\n";
       cout<<"\tfacility available with our partners ICICI Bank Ltd.(Selected ATM's)\n";
       cout<<"\n\tHome Pick-up Facility:\n";
       cout<<"\tThe subscriber can hand over cash payment against SMS payment receipt to authorised DATATRUCK representative.\n";
       cout<<"\tTo avail this facility, call on 1860 3000 3535\n";
	break;
default:cout<<"\tInvalid choice!!!\n";
       goto b;
}
}
void provider::remove_customer()
{
char nm[20],ch,n1[10],n2[10];
int i=0,n=0,x,x1,x2;
customer cu[100];
fstream f,g;
f.open("cust.dat",ios::in|ios::out|ios::binary);
g.open("ncust.dat",ios::out|ios::binary);
if(!f)
{
cout<<"\tCan't open file!!\n";
return;
}
while(!f.eof())
{
f.read((char*)&cu[n].c,sizeof(struct cus));
n++;
}
n--;
view_details();
cout<<"\tEnter the name of the customer to be removed:";
cin>>nm;
while(i<n)
{
if(strcmp(nm,cu[i].c.name)==0)
x=1;
else
g.write((char*)&cu[i].c,sizeof(struct cus));
i++;
}
if(x==1)
cout<<"\tCustomer deleted\n";
else
{
cout<<"\tCustomer not found\n";
}
strcpy(n1,"cust.dat");
strcpy(n2,"ncust.dat");
x2=remove(n1);
x1=rename(n2,n1);
f.close();
g.close();
}
void get_details(customer co,int k)
{
provider pro;
char mo[4],nm[4];
fstream f;
int ch,pt,i;
f.open("cust.dat",ios::in|ios::out|ios::app|ios::binary);
if(!f)
{
cout<<"\tCan't open file!!\n";
return;
}
cout<<"\tLET US HELP YOU FIND A PLAN!!!"<<endl;
j:pro.view_plans();
cout<<"\tSelect Your Postpaid Plan:";
cin>>co.c.code;
ch=co.c.code;
switch(ch)
{
case 11 : co.c.validity=1;
	co.c.rate=499.0;
	co.c.speed=1;
	break;
case 12 : co.c.validity=1;
	co.c.rate=899.0;
	co.c.speed=10;
	break;
case 13 : co.c.validity=1;
	co.c.rate=1199.0;
	co.c.speed=50;
	break;
case 21 : co.c.validity=6;
	co.c.rate=2099.0;
	co.c.speed=1;
	break;
case 22 : co.c.validity=6;
	co.c.rate=4099.0;
	co.c.speed=10;
	break;
case 23 : co.c.validity=6;
	co.c.rate=6099.0;
	co.c.speed=50;
	break;
case 31 : co.c.validity=12;
	co.c.rate=3599.0;
	co.c.speed=1;
	break;
case 32 : co.c.validity=12;
	co.c.rate=8099.0;
	co.c.speed=10;
	break;
case 33 : co.c.validity=12;
	co.c.rate=10999.0;
	co.c.speed=50;
	break;
default: cout<<"\tInvalid choice\n";
	goto j;
}
cout<<"\tEnter Your Details:\n";
cout<<"\tName:";
cin>>co.c.name;
cout<<"\tAddress:";
cin>>co.c.address;
cout<<"\tMobile no.:";
cin>>co.c.Mno;
strcpy(co.c.userid,co.c.name);
strcpy(co.c.password,co.c.Mno);
f.write((char*)&co.c,sizeof(struct cus));
f.close();
}
void get_details(customer co)
{
provider pro;
fstream f;
int ch;
f.open("cust.dat",ios::out|ios::binary);
if(!f)
{
cout<<"\tCan't open file!!\n";
return;
}
cout<<"\tLET US HELP YOU FIND A PLAN!!!"<<endl;
k:pro.view_plans();
cout<<"\tSelect Your Prepaid Plan:";
cin>>co.c.code;
ch=co.c.code;
switch(ch)
{
case 11 : co.c.validity=1;
	co.c.rate=499.0;
	co.c.speed=1;
	break;
case 12 : co.c.validity=1;
	co.c.rate=899.0;
	co.c.speed=10;
	break;
case 13 : co.c.validity=1;
	co.c.rate=1199.0;
	co.c.speed=50;
	break;
case 21 : co.c.validity=6;
	co.c.rate=2099.0;
	co.c.speed=1;
	break;
case 22 : co.c.validity=6;
	co.c.rate=4099.0;
	co.c.speed=10;
	break;
case 23 : co.c.validity=6;
	co.c.rate=6099.0;
	co.c.speed=50;
	break;
case 31 : co.c.validity=12;
	co.c.rate=3599.0;
	co.c.speed=1;
	break;
case 32 : co.c.validity=12;
	co.c.rate=8099.0;
	co.c.speed=10;
	break;
case 33 : co.c.validity=12;
	co.c.rate=10999.0;
	co.c.speed=50;
	break;
default: cout<<"\tInvalid choice\n";
	goto k;
}
d:
try
{
cout<<"\tEnter Your Details:\n";
cout<<"\tName:";
cin>>co.c.name;
cout<<"\tAddress:";
cin>>co.c.address;
cout<<"\tMobile no.:";
cin>>co.c.Mno;
if(strlen(co.c.Mno)!=10)
throw(10);
}
catch(int i)
{
cout<<"\tInvalid Mobile No.\n";
goto d;
}
strcpy(co.c.userid,co.c.name);
strcpy(co.c.password,co.c.Mno);
f.write((char*)&co.c,sizeof(struct cus));
f.close();
}
void provider::add_customer()
{
customer co;
int pt;
cout<<"\tSelect Customer's Plantype:";
cout<<"\n\t1. Postpaid\t2.Prepaid\n\t";
cin>>pt;
(pt==1)?co.c.plan_type=0:co.c.plan_type=1;
if(co.c.plan_type)
{
get_details(co);
}
else
get_details(co,10);
cout<<"\n\tNew Customer added successfully\n";
}
void provider::view_details()
{
fstream f;
customer cu[100];
int i,n=0;
f.open("cust.dat",ios::in|ios::binary);
if(!f)
{
cout<<"\tCan't open file!!\n";
return;
}
while(!f.eof())
{
f.read((char*)&cu[n].c,sizeof(struct cus));
n++;
}
n--;
cout<<"\n\t\tDATATruck-Broadband Service Provider\n\n";
cout<<"\tCUSTOMERS\t\t\tPLAN AVAILING\n\n";
for(i=0;i<n;i++)
{
cout<<"\t"<<i+1<<". "<<cu[i].c.name<<endl;
cout<<"\t\t\t\t\tPLAN TYPE:";
cu[i].c.plan_type?cout<<"Prepaid":cout<<"Postpaid"<<endl;
cout<<"\t\t\t\t\tVALIDITY:"<<cu[i].c.validity<<" Months"<<endl;
cout<<"\t\t\t\t\tSPEED:"<<cu[i].c.speed<<" Mbps"<<endl;
cout<<"\n\n";
}
f.close();
}

void provider::view_plans()
{
int d;
k:cout<<"\tSelect Your Plan Duration:\n";
cout<<"\t1. 1 MONTH\n";
cout<<"\t2. 6 MONTHS\n";
cout<<"\t3. 1 YEAR\n\t";
cin>>d;
switch(d)
{
case 1:goto r;
       break;
case 2:goto s;
       break;
case 3:goto t;
       break;
default:cout<<"\tInvalid choice!!!";
        goto k;
}
r:
cout<<"\tCODE: 11\t\t";
cout<<"1 Mbps\t\t";
cout<<"@Rs.499.0";
cout<<" Per month.\n\n";

cout<<"\tCODE: 12\t\t";
cout<<"10 Mbps\t\t";
cout<<"@Rs.899.0";
cout<<" Per month.\n\n";

cout<<"\tCODE: 13\t\t";
cout<<"50 Mbps\t\t";
cout<<"@Rs.1199.0";
cout<<" Per month.\n\n";
return;

s:cout<<"\tCODE: 21\t\t";
cout<<"1 Mbps\t\t";
cout<<"@Rs.2099.0";
cout<<" Per 6 months.\n\n";

cout<<"\tCODE: 22\t\t";
cout<<"10 Mbps\t\t";
cout<<"@Rs.4099.0";
cout<<" Per 6 months.\n\n";

cout<<"\tCODE: 23\t\t";
cout<<"50 Mbps\t\t";
cout<<"@Rs.6099.0";
cout<<" Per 6 months.\n\n";
return;

t:cout<<"\tCODE: 31\t\t";
cout<<"1 Mbps\t\t";
cout<<"@Rs.3599.0";
cout<<" Per year.\n\n";

cout<<"\tCODE: 32\t\t";
cout<<"10 Mbps\t\t";
cout<<"@Rs.8099.0";
cout<<" Per year.\n\n";

cout<<"\tCODE: 33\t\t";
cout<<"50 Mbps\t\t";
cout<<"@Rs.10999.0";
cout<<" Per year.\n\n";
}
void Op_login()
{
provider p;
int ch;
{
for(;;)
{
cout<<"\n\t1.Add Customer\t\t2.Remove Customer\t\t3.View Plans\t\t4.View Customer List\t\t5.Logout\n";
cout<<"\tEnter Your Choice:\t";
cin>>ch;
switch(ch)
{
case 1 : p.add_customer();
	break;
case 2 :p.remove_customer();
	break;
case 3 :plans_view();
	break;
case 4 :p.view_details();
	break;
case 5 :cout<<"\n\tThanks for Visiting\n";
	return;
default: cout<<"\tInvalid Choice\n";
}
}
}
}
void Cus_login()
{
char user[20],pass[20];
customer cu[100];
int a,b,i,n,len;
fstream f;
f.open("cust.dat",ios::in|ios::out|ios::binary);
if(!f)
{
cout<<"\tCan't open file!!!\n";
return;
}
while(!f.eof())
{
f.read((char*)&cu[n].c,sizeof(struct cus));
n++;
}
n--;
x:
cout<<"\n\t\t1.New Customer\t\t2.Already Registered\t\t3.Exit\n\t";
cout<<"\tEnter your choice:";
cin>>a;
switch(a)
{
case 1 :cout<<"\n\tWant A New Broadband connection?\n";
		cout<<"\tWith DATATruck its possible in 3 simple steps:-\n";
		cout<<"\t1.Visit our closest service center\n ";
		cout<<"\tTo know our location in YOUR CITY,you can call on this number:1860 3000 3535\n";
		cout<<"\t2.Apply for new connection by filling necessary forms.\n";
		cout<<"\t3.You have to wait for 3 working days and then\n ";
		cout<<"\tCONGRATULATIONS!! Now you can enjoy all our services\n";
		break;
case 2 : cout<<"\tUsername:\n\t";
		cin>>user;
		
		strcpy(pass,getpass("\tPassword:  "));
		cout<<"\t";
		len=strlen(pass);
		while(len--!=0)
		cout<<"*";
		for(i=0;i<n;i++)
		{
		if(strcmp(user,cu[i].c.userid)==0)
		{
		if(strcmp(pass,cu[i].c.password)==0)
		{
		cout<<"\n\n\t\t\t\t\t\t\tWelcome "<<cu[i].c.name<<endl;
		for(;;)
		{
		cout<<"\n\t1.View Details\t\t2.View Plans\t\t3.Update Details\t\t4.Make Payment\t\t5.Logout\n";
		cout<<"\tEnter Your Choice:\t";
		cin>>b;
		cout<<endl;
		switch(b)
		{
		case 1 :cout<<cu[i].c;
			break;
		case 2 :plans_view();
			break;
		case 3 :cu[i].update_details();
			break;
		case 4 :cu[i].make_payment();
			break;
		case 5 :cout<<"\tThanks for Visiting\n";
			return;
		}
		}
		}
		}
		}
		if(i==n)
		cout<<"\tCustomer not found.\n";
		break;
case 3: return;
default : cout<<"\tInvalid option.\n";
	 goto x;
}
for(i=0;i<n;i++)
{
f.write((char*)&cu[i].c,sizeof(struct cus));
}
f.close();
}
void about()
{
cout<<"\n\tDATAtruck is an offline portal that offers wireless broadband services\n";
cout<<"\tto home and enterprise customers in India's top 10 cities.\n";
cout<<"\tThis company envisions a powerful Broadband enabled India and strive to make all\n ";
cout<<"\tpossible contributions to make this happen.\n";
cout<<"\tPowered with leading innovations,DATATruck is now amongst the top broadband service providers in India.\n";
cout<<"\tAnd it is providing the most basic tool for building a large outdoor wi-fi network,taking steps to make\n";
cout<<"\tIndia a digital nation.\n";
}
void contact()
{
cout<<"\n\tDATATruck CARE\n\n";
cout<<"\tCustomer Care\n";
cout<<"\t1860 3000 3535\n";
cout<<"\tWe will be pleased to help you out 24/7.\n";
cout<<"\tCustomers can also visit our service centers available in their respective cities.\n";
cout<<"\tTo know our location in YOUR CITY,you can call on this number:1860 3000 3535\n";
}
int main()
{
int ch;
	cout<<"\n";
	cout<<"\t\t\t****************************************************************************************\n";
	cout<<"\t\t\t*                                     ~~~DATATruck~~~                                  *\n";
	cout<<"\t\t\t****************************************************************************************\n";
	cout<<"\t\t\t========================================================================================\n";
	for(;;)
	{
		cout<<"\n\t1.Customer Login\t\t2.Operator Portal\t\t3.About Us\t\t4.Contact Us\t\t5.Exit\n";
		cout<<"\n\tSelect Login Option: ";
		cin>>ch;
		switch(ch)
		{
			case 1 : Cus_login();
					break;
			case 2 : Op_login();
					break;
			case 3 : about();
					break;
			case 4 : contact();
					break;			
			case 5 : return 0;
			default : cout<<"\tInvalid option.\n";
		}
	}
}
