#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
class Bank{
	private:
		int total;
		string Id;
		struct person{
			string name;
			string address;
			string id;
			string contact;
			long long int cash;
		}person[100];
	public:
	Bank(){
	   total=0;
		      }
	void choice();
	void createnewaccount();   //choice 1
	void display();            //choice 2
	void search();             //choice 3
	void update();             //choice 4
	void transactions();       //choice 5
	void remove();             //choice 6
};
void Bank::choice(){
	char ch;
	while(1){
	cout<<"\n\nENTER THE DIGIT FOR YOUR REQUIRED OPERATION"<<endl;
	cout<<" 1. Create new account "<<endl;
	cout<<" 2. Display all the customer details "<<endl;
	cout<<" 3. Check the details of the existing account "<<endl;
	cout<<" 4. Update the information of the existing account "<<endl;
	cout<<" 5. For transactions "<<endl;
	cout<<" 6. Remove existing account "<<endl;
	cout<<" 7. Exit "<<endl;
	ch=getch();
	system("CLS");
	switch(ch){
		case '1':
			Bank::createnewaccount();
			break;
		case '2':
		    if(total==0)cout<<" No account is present "<<endl;
		    else  Bank::display();
			break;
		case '3':
			if(total==0)cout<<" No account is present "<<endl;
		    else Bank::search();
			break;
		case '4':
			if(total==0)cout<<" No account is present "<<endl;
		    else Bank::update();
			break;
		case '5':
			if(total==0)cout<<" No account is present "<<endl;
		    else Bank::transactions();
			break;
		case '6':
			if(total==0)cout<<" No account is present "<<endl;
		    else Bank::remove();
			break;
		case '7':
			exit(0);
			break;
	}
}}

void Bank::createnewaccount(){//choice 1
	cout<<"Enter data of the person "<<total+1<<endl;
	cout<<"Enter name : ";
	getline(cin,person[total].name);
	cout<<"Enter address : ";
	getline(cin,person[total].address);
	cout<<"Enter ID : ";
	cin>>person[total].id;
	cout<<"Enter contact : ";
	cin>>person[total].contact;
	cout<<"Enter the cash you want to deposit : ";
	cin>>person[total].cash;
	total++;
}
void Bank::display(){//choice 2

if(total==0)cout<<" THERE IS NO ANY ACCOUNT TO DISPLAY "<<endl;

	for(int i=0;i<total;i++){
		cout<<" Data of person "<<i+1<<endl;
		cout<<" Name : "    <<person[i].name<<endl;
		cout<<" Address : " <<person[i].address<<endl;
		cout<<" ID : "      <<person[i].id<<endl;
		cout<<" contact : " <<person[i].contact<<endl;
		cout<<" cash : "    <<person[i].cash<<endl;
	}
}

void Bank::search(){//choice 3
	cout<<"Enter the id of the person to search : ";
	cin>>Id;
	for(int i=0;i<total;i++){
		if(person[i].id==Id){
		cout<<" Name : "    <<person[i].name<<endl;
		cout<<" Address : " <<person[i].address<<endl;
		cout<<" ID : "      <<person[i].id<<endl;
		cout<<" contact : " <<person[i].contact<<endl;
		cout<<" cash : "    <<person[i].cash<<endl;
		break;}
		if(i==total-1)cout<<"NO SUCH RECORD FOUND "<<endl;
}}

void Bank::update(){//choice 4
	cout<<"Enter the id of the person to update contact or address : ";
	cin>>Id;
	for(int i=0;i<total;i++){
		if(person[i].id==Id){
		cout<<" Previous data of the person "<<endl;
		cout<<" Name : "    <<person[i].name<<endl;
		cout<<" Address : " <<person[i].address<<endl;
		cout<<" ID : "      <<person[i].id<<endl;
		cout<<" contact : " <<person[i].contact<<endl;
		cout<<" cash : "    <<person[i].cash<<endl;
	cout<<"Enter updated data of the person "<<endl;

	cout<<"Enter new address : ";
	cin>>person[i].address;
	cout<<"Enter new contact : ";
	cin>>person[i].contact;

	break;}
	if(i==total-1)cout<<"NO SUCH RECORD FOUND "<<endl;

}}

void Bank::transactions(){//choice 5
	char ch;
	int cash;
	cout<<" Enter the id of the person you want to make transactions : ";
	cin>>Id;
	for(int i=0;i<total;i++){
		if(person[i].id==Id){
		cout<<" Name : "    <<person[i].name<<endl;
		cout<<" Address : " <<person[i].address<<endl;
		cout<<" ID : "      <<person[i].id<<endl;
		cout<<" contact : " <<person[i].contact<<endl;
		cout<<" \n Existing cash : "    <<person[i].cash<<endl;
		cout<<" Press 1 to depost "<<endl;
		cout<<" Press 2 to withdraw "<<endl;
		ch=getch();
		switch(ch){
		  case '1':
			 cout<<" Enter the amount of cash to deposit :";
			 cin>>cash;
			 person[i].cash+=cash;
			 cout<<" Your new cash is "<<person[i].cash<<endl;
			 break;
		 case '2':
		 	back:
			 cout<<" Enter the amount of cash to withdraw :";
			 cin>>cash;
			 if(cash>person[i].cash){
			 	cout<<" INSUFFICIENT BALANCE "<<endl;
			 	cout<<" Your existing cash is just "<<person[i].cash<<endl;
			 	Sleep(5000);
			 	goto back;
			 }
			 person[i].cash-=cash;
			 cout<<" Your new cash is "<<person[i].cash<<endl;
			 break;
		default:
			 	cout<<" INVALID INPUT "<<endl;
				break;}
		break;}
			 	if(i==total-1)cout<<"NO SUCH RECORD FOUND "<<endl;

}}

void Bank::remove(){
    char ch;
	cout<<" Press 1 to remove a specific account "<<endl;
	cout<<" Press 2 to remove whole record "<<endl;
	ch=getch();
	switch(ch){
 	 case '1':
		  	cout<<" Enter the ID of the account to be removed: "<<endl;
		  	cin>>Id;
	        for(int i=0;i<total;i++){
		    if(person[i].id==Id){
		    	for(int j=i;i<total;j++){
		    		person[i].name=person[i+1].name;
		    		person[i].id=person[i+1].id;
		    		person[i].address=person[i+1].address;
		    		person[i].contact=person[i+1].contact;
		    		person[i].cash=person[i+1].cash;
		    		total--;
		    		cout<<" The required account is deleted "<<endl;
		    		break;
				}}}

	 break;
	 case '2':
	 	total=0;
	 	cout<<" The Entire record is deleted "<<endl;
	 	break;
	 default:
	 	cout<<" INVALID INPUT "<<endl;
	 	break;}}

int main(){
	Bank a;
	a.choice();
	return 0;}

