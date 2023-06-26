#include <bits/stdc++.h>
#include<conio.h>
#include<string>
using namespace std;

void line(int times, char c) {
	for (int i = 0; i < times; i++)
		cout << c << " ";
	cout << endl;
}

struct doctor {
	string name;
	string address;
	string contact;
	int age;
	string sex;
	string doctorID;
};
struct patient {
	string name;
	string address;
	string contact;
	int age;
	string sex;
	string blood_group;
	string had_diseases;
	string patientID;
	string date;
	doctor doctorofPatient;
	double billcost;

};


patient patients[50];
doctor doctors[10];
int patientcounter;
int doctorcounter;

void doctorinfo(doctor &doc);
doctor getdoctorByID(string ID, int count, doctor docs[]);
void Patientinfo(patient &patieent);
	void doctorinfo(doctor &doc);

	void addDoctor();
	void addpatient();
	int getpatientByID(string Id);
	void editpatientbill();
	void editpatientdoctor();

	void printpatientbill() {
		string id;
		cout << "please input the id of the patient : ";
		cin >> id;
		cin.ignore();
		patient temp;
		temp=patients[getpatientByID(id)];
		line(50, '-');
		cout << "the cost of the bill is : " << temp.billcost << endl;
		line(50, '-');
	}
	void printpatientinfo() {
		string id;
		cout << "please input the id of the patient : ";
		cin >> id;
		cin.ignore();
		patient temp = patients[getpatientByID(id)];
		line(70, '=');
		cout << "Name : " << temp.name << endl;
		cout << "address : " << temp.address << endl;
		cout << "contact number : " << temp.contact << endl;
		cout << "Age : " << temp.age << endl;
		cout << "sex : " << temp.sex << endl;
		cout << "blood group : " << temp.blood_group << endl;
		cout << "earlier symptoms : " << temp.had_diseases << endl;
		cout << "patient ID : " << temp.patientID << endl;
		cout << " date : " << temp.date << endl;
		cout << "the doctor of the patient is : " << temp.doctorofPatient.name << endl;
		cout << "the bill : " << temp.billcost << endl;
		line(70, '=');
	}
	void printalldoctors() {
		if (doctorcounter == 0)
			cout << "there is no data to show \n";
		else {
			line(60, '_');
			for (int i = 0; i <= doctorcounter; i++) {
				cout << "doctor name : " << doctors[i].name << endl;
				cout << "doctor address : " << doctors[i].address << endl;
				cout << "doctor age : " << doctors[i].age << endl;
				cout << "doctor contact number : " << doctors[i].contact << endl;
				cout << "doctor sex : " << doctors[i].sex << endl;
				cout << "doctor ID is : " << doctors[i].doctorID << endl;
			}
			line(60, '_');
		}
	}

	int main() {
		patientcounter = 0;
		doctorcounter = 0;
		int choice=0;
		while (choice != 8) {
                	cout << "\n\n\t    PLEASE SELECT FROM THE MENUE  ";
		cout << "\n\n\t Please choose one of the below options:  \n \n";
		cout << "--------------------------------------------------------\n\n";
		cout << "(1).Add a new doctor \n\n";
		cout << "(2).add a new patient  \n\n";
		cout << "(3).edit the patient bill \n\n";
		cout << "(4).edit the patien doctor \n\n";
		cout << "(5).print patient info \n\n";
		cout << "(6).print patient bill \n \n";
		cout << "(7).print docors record  \n\n";
        cout << "8 - exit program \n";
		cout<< "--------------------------------------------------------\n\n";
        cout << "please input the number of the choice you want to excute : ";

			cin >> choice;
			cin.ignore();
			if (choice == 1)
				addDoctor();
			else if (choice == 2)
				addpatient();
			else if (choice == 3)
				editpatientbill();
			else if (choice == 4)
				editpatientdoctor();
			else if (choice == 5)
				printpatientinfo();
			else if (choice == 6)
				printpatientbill();
			else if (choice == 7)
				printalldoctors();
			else if (choice == 8)
				break;
		}
		_getche();
	}
	void doctorinfo(doctor &doc) {
		string nme;
		string adres;
		string contactnum;
		int Age;
		string sex;
		string Id;
		cout << "\nplease input the doctor name : ";
		getline(cin, nme);
		cin.ignore();
		cout << "please input the doctor address : ";
		getline(cin, adres);
		cin.ignore();
		cout << "please input the doctor contact number without any spaces: ";
		cin >> contactnum;
		cin.ignore();
		cout << "please input the doctor age with numbers : ";
		cin >> Age;
		cin.ignore();
		cout << "please input the doctor sex female or male : ";
		cin >> sex;
		cin.ignore();
		cout << "please input the doctor ID : ";
		cin >> Id;
		cin.ignore();

		doc.name = nme;
		doc.address = adres;
		doc.contact = contactnum;
		doc.age = Age;
		doc.sex = sex;
		doc.doctorID = Id;

	}
	doctor getdoctorByID(string ID, int count, doctor docs[]) {
		string Idagain;		//this we will use it if the id is wrong
		int index = -1;
		int counterError = 0;
	reEnter:
		for (int i = 0; i < count; i++) {
			if (ID == docs[i].doctorID)
				index = i;
		}
		if (index <= 0)
			return docs[index];
		if (index == -1)
		{
			cout << "sorry couldn't find this Id try to write it again \n";
		}
		if (counterError == 3) {
			cout << "sorry this is a wrong id chick it and edit the patient info\n ";
			return doctor();
		}
		while (index == -1) {
			cin >> Idagain;
			cin.ignore();
			counterError++;
			goto reEnter;

		}
	}

	void Patientinfo(patient &patieent) {
		string nme;
		string adres;
		string contactnum;
		int Age;
		string sex;
		string blood;
		string diseases;
		string Id;
		string docid;
		string whatsdate;
		cout << "\n please input the patient name : ";
		getline(cin, nme);
		cin.ignore();
		cout << "please input the patient address : ";
		getline(cin, adres);
		cin.ignore();
		cout << "please input the patient contact number without any spaces: ";
		cin >> contactnum;
		cin.ignore();
		cout << "please input the patient age with numbers : ";
		cin >> Age;
		cin.ignore();
		cout << "please input the patient sex female or male : ";
		cin >> sex;
		cin.ignore();
		cout << "please input the patient blood group example o+: ";
		cin >> blood;
		cin.ignore();
		cout << "does the patient had diseases earlier input none if not ";
		getline(cin, diseases);
		cin.ignore();
		cout << "please input the patient ID : ";
		cin >> Id;
		cin.ignore();
		cout << "please input the doctor ID that treat the patient : ";
		cin >> docid;
		cin.ignore();
		cout << "please input the date of today in the format yy/mm/dd : ";
		getline(cin, whatsdate);
		cin.ignore();

		patieent.name = nme;
		patieent.address = adres;
		patieent.contact = contactnum;
		patieent.age = Age;
		patieent.sex = sex;
		patieent.blood_group = blood;
		patieent.had_diseases = diseases;
		patieent.patientID = Id;
		patieent.doctorofPatient = getdoctorByID(docid, doctorcounter, doctors);
		patieent.date = whatsdate;
	}

	void addDoctor() {
		if (doctorcounter < 10) {
			doctorinfo(doctors[doctorcounter]);
			doctorcounter++;


		}
		else
			cout << "sorry the doctor's record is full \n";

	}

	void editpatientdoctor() {
		string pid;		//the patient id ;
		string id;		// the doctor id ;
		cout << "please input the patient id : ";
		cin >> pid;
		cin.ignore();
		cout << "please input the doctors id : ";
		cin >> id;
		cin.ignore();
		int patientindex = getpatientByID(pid);
		if (patientindex >= 0)
			patients[patientindex].doctorofPatient = getdoctorByID(id, doctorcounter, doctors);
		else
			cout << "invalid patient id ";
	}

	void addpatient() {
		if (patientcounter < 50) {
			Patientinfo(patients[patientcounter]);
			patientcounter++;
		}
		else
			cout << "sorry the patients record is full\n";
	}
	int getpatientByID(string Id) {
		for (int i = 0; i < patientcounter; i++) {
			if (patients[i].patientID == Id)
				return i;
		}
		return -2;
	}
	void editpatientbill() {
		string id;
		double price;
		int choice;
		cout << "please input the id of the patient : ";
		cin >> id;
		cin.ignore();
		int index = getpatientByID(id);
		if (index >= 0) {
			cout << "1 - add amount to the cost of the bill \n";
			cout << "2 - pay the bill \n ";
			cout << "please input your choice number from above : ";
			cin >> choice;
			cin.ignore();
			if (choice == 1)
			{
				cout << "please input the amount to add it to the bill : ";
				cin >> price;
				cin.ignore();
				patients[index].billcost += price;
			}
			else if (choice == 2) {
				cout << "please input the amount that the patient paid : ";
				cin >> price;
				cin.ignore();
				patients[index].billcost -= price;
			}
			else
				cout << "invalid choice !!!!!!\n ";
		}
		else
			cout << "sorry the patient id is invalid try again later \n";


	}





















/*
/////////////  Codeforces 427A     //////////
#include<bits/stdc++.h>
using namespace std;
int main(){
int n,v,con=0,conn=0;
cin>>n;
for(int i=0;i<n;i++){
    cin>>v;
    if(v>0){
        con+=v;
        continue;
    }
    else if(v<0&&con>0){
        con-=1;
        continue;
    }
    else if(v<0){
        conn++;
}}
cout<<conn;
}
///////   Codeforces 289A       //////////
#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,con=0;
cin>>n>>m;
for(int i=0;i<n;i++){
    int s,e;
    cin>>s>>e;
    con+=e-s+1;
     con%=m;
}
if(con!=0)
 con=m-con;
    cout<<con;
}
////////////Codeforces 467A/////////

#include<bits/stdc++.h>
using namespace std;
int main(){
int n,con=0;
cin>>n;
for(int i=0;i<n;i++){
    int p,q;
    cin>>p>>q;
   if(q-p>=2){
    con++;
}}
cout<<con;
}
///////////////  A. Shaass and Oskols  /////////

#include<bits/stdc++.h>
using namespace std;
int main(){
int n,mx=100;
cin>>n;
int a[mx];
for(int i=0;i<n;i++)
    cin>>a[i];
int b;
cin>>b;
for(int i=0;i<b;i++){
int x,y;
cin>>x>>y;
x--;
if(x!=0)
    a[x-1]+=y-1;

  if(x!=n-1)
    a[x+1]+=a[x]-y;

  a[x]=0;
}

for(int i=0;i<n;i++){
    cout<<a[i]<<"\n";
    #include<bits/stdc++.h>

using namespace std;
#define cin(vec) for(auto& i : (vec)) cin >> i;
#define cout(vec) for(auto& i : (vec)) cout << i << " "; cout << "\n";
#define int long long
#define ull unsigned long long
#define dd double
#define endl "\n"
#define all(v) ((v).begin()), ((v).end())
#define gcd(a, b)  __gcd(arr, b)
#define lcm(a, b) (arr * b) / (gcd(arr, b))
#define mod(a, b) (arr - arr / b * b)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

}}



*/
