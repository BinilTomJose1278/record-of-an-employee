#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class emp
{
int eno;
char ename[30];
float salary;
public:
void input(int n);
void Delete();
void Modify();
void Display();
}e1;
void emp::input(int n)
{clrscr();
ofstream fout;
fout.open("emp.dat",ios::binary);
for(int i=1;i<=n;i++)
{cout<<"enter the employee number";
cin>>eno;
cout<<"\n enter employee name:";
gets(ename);
cout<<"\n enter the salary:";
cin>>salary;
fout.write((char*)&e1,sizeof(e1));
}
fout.close();
getch();
}
void emp::Delete()
{
int no;
ifstream fin;
ofstream fout;
clrscr();
cout<<"\n enter the employee no to be deleted:";
cin>>no;
fin.open("emp.dat",ios::binary);
fout.open("temp.dat",ios::binary);
while(fin.read((char*)&e1,sizeof(e1)))
{
if(eno!=no)
{
fout.write((char*)&e1,sizeof(e1));
}
}
fin.close();
fout.close();
remove("emp.dat");
rename("temp.dat","emp.dat");
}
void emp::Modify()
{
int no,flag=0;
ifstream fin;
ofstream fout;
clrscr();
cout<<"\n enter the employee no to be modified:";
cin>>no;
fin.open("emp.dat",ios::binary);
fout.open("temp.dat",ios::binary);
while(fin.read((char*)&e1,sizeof(e1)))
{
if(eno==no)
{
flag=1;
cout<<"\n enter the new employee no:";
cin>>eno;
cout<<"\n enter the new employee name:";
gets(ename);
cout<<"\n enter the new salary";
cin>>salary;
}
fout.write((char*)&e1,sizeof(e1));
}
if(flag==0)
cout<<"record doesn't exists";
fin.close();
fout.close();
remove("emp.dat");
rename("temp.dat","emp.dat");
}
void emp::Display()
{
ifstream fin;
clrscr();
fin.open("emp.dat",ios::binary);
while(fin.read((char*)&e1,sizeof(e1)))
{
cout<<"\n emp no:"<<eno;
cout<<"\n emp name:"<<ename;
cout<<"\n salary:"<<salary;
getch();
}
fin.close();
}
void main()
{
int ch,n;
do
{
clrscr();
cout<<"\n MAIN MENU";
cout<<"\n 1. Input records to file:";
cout<<"\n 2. Delete the records:";
cout<<"\n 3. Modify the records:";
cout<<"\n 4. Display the records:";
cout<<"\n 5. Exit:";
cout<<"\n enter your choice:";
cin>>ch;
switch(ch)
{
case 1:cout<<"enter total  no. of records:";
cin>>n;
e1.input(n);
break;
case 2:e1.Delete();
break;
case 3:e1.Modify();
break;
case 4:e1.Display();
break;
getch();
}
}
while(ch<5);
}
