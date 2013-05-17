#include <iostream>
using namespace std;

class MyString{
private:
  char * itsString;
public:
	MyString(int);
	MyString(const char *const);
	//~MyString();
	int SizeOf();
	void Show();
	bool Equals(MyString);
	int BiggerThan(MyString);
	void DeleteAfter(int);
	void DeleteBefore(int);
	void DeleteAfter(char);
	void DeleteBefore(char);
	void Replace(char*,char*);
	void Join(MyString*);
};

MyString::MyString(int a){
	itsString=new char[a];
	for (int i=0; i < a; i++)
		itsString[i]='0';
	itsString[a-1]='\0';
}

MyString::MyString(const char*const s){
	int l=0;
	while(s[l]!=NULL)
	{l++;}
	itsString=new char[l+1];
	for (int i=0; i < l; i++)
		itsString[i]=s[i];
	itsString[l]='\0';
}

/*MyString::~MyString(){
   delete [] itsString;
}*/

int MyString::SizeOf(){
	int n=0;
	while(itsString[n]!='\0')
	{n++;}
	return n;
}

void MyString::Show(){
	for (int i=0;itsString[i]!='\0';i++)
		cout<<itsString[i];
	cout<<endl;
}

bool MyString::Equals(MyString a){
	if (SizeOf()==a.SizeOf())
		{for (int i=0;itsString[i]!='\0';i++)
			if (itsString[i]!=a.itsString[i])
				return 0;
			return 1;}
	else return 0;
}

int MyString::BiggerThan(const MyString a)
{	
	if(this->Equals(a)) return 0;
else{
for (int i=0; itsString[i]!='\0';i++)
{if (itsString[i]==a.itsString[i]) continue;
else if (itsString[i]<a.itsString[i]) return -1;
else return 1;}}
return 0;
}

void MyString::DeleteAfter(int a){
MyString tmp(a+1);
	int i;
for (i=0;i<a;i++)
	tmp.itsString[i]=this->itsString[i];
delete []itsString;
itsString=tmp.itsString;
}

void MyString:: DeleteBefore(int a){
	MyString tmp((this->SizeOf())-a+2);
	int i;
	for (i=(a-1);i<this->SizeOf();i++)
	tmp.itsString[i-a+1]=this->itsString[i];
delete []itsString;
itsString=tmp.itsString;
}

void MyString::DeleteAfter(char a){
	int i;int n;
	for (i=0;itsString[i]!='\0';i++)
		if (this->itsString[i]==a) {n=i+1;break;}
		this->DeleteAfter(n);
}

void MyString:: DeleteBefore(char a){
	int i;int n;
	for (i=0;itsString[i]!='\0';i++)
		if (this->itsString[i]==a) {n=i+1;break;}
		this->DeleteBefore(n);
}

void MyString::Replace(char* a,char*b){
	for (int i=0;itsString[i]!='\0';i++)
	{if (itsString[i]==a[0]) {
		if (itsString[i+1]==a[1]){
			itsString[i]=b[0];
			itsString[i+1]=b[1];
		}
	}
	}
}

void MyString::Join(MyString *a){
	int k=a->SizeOf();
	int f=this->SizeOf();
	MyString temp(k+f+1);
	int i;
	for (i=0;itsString[i]!='\0';i++)
		temp.itsString[i]=itsString[i];
	for (i=f;temp.itsString[i]!='\0';i++)
		temp.itsString[i]=a->itsString[i-f];
	delete []itsString;
	itsString=temp.itsString;
	

}



void main(){
	MyString *S=new MyString("Banana");
	MyString *S2=new MyString("Banana");
	MyString *S3=new MyString("Alphabet");
	MyString *S4=new MyString("Hi,people!Hi!");
	S->Show();
	int d=S->SizeOf();
	cout<<"Dlina stroki:"<<d<<endl;
	S2->Show();
	d=S2->SizeOf();
	cout<<"Dlina stroki:"<<d<<endl;
	S3->Show();
	d=S3->SizeOf();
	cout<<"Dlina stroki:"<<d<<endl;
	S4->Show();
	d=S4->SizeOf();
	cout<<"Dlina stroki:"<<d<<endl;
	bool k=S->Equals(*S2);
	if (k) cout<<"Stroki ravni"<<endl;
	else cout<<"Stroki NE ravni!"<<endl;
	int z=S->BiggerThan(*S2);
	if (z==1) cout<<"S>S2"<<endl;
	else if(z==-1) cout<<"S<S2"<<endl;
	else cout<<"S=S2"<<endl;
	int n;
	cout<<"Vvedite poziciu udal(posle kakogo udal)"<<endl;
	cin>>n;
	S->DeleteAfter(n);
	S->Show();
	cout<<"Vvedite poziciu udal(do kakogo udal)"<<endl;
	cin>>n;
	S2->DeleteBefore(n);
	S2->Show();
	char t;
	cout<<"Vvedite simvol udal(posle kakogo udal)"<<endl;
	cin>>t;
	S3->DeleteAfter(t);
	S3->Show();
	cout<<"Vvedite simvol udal(do kakogo udal)"<<endl;
	cin>>t;
	S4->DeleteBefore(t);
	S4->Show();
	S4->Replace("Hi","Go");
	S4->Show();
	S->Join(S2);
	S->Show();
	cin.get();
	cin.get();
}
