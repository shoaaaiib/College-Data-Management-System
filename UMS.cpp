#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>

using namespace std;

class student
{
	public:
		long int reg;
		char name[80],college[80],branch[50],year[20],division[5],contact[20],mail[50],bloodgrp[10];
		void input()
		{
			cout<<"\n\t\t ENTER NAME : ";
			gets(name);
			cout<<"\n\t\t ENTER COLLEGE : ";
			gets(college);
			cout<<"\n\t\t ENTER REG. NO : ";
			cin>>reg;
			fflush(stdin);
			cout<<"\n\t\t ENTER BRANCH : ";
			gets(branch);
			cout<<"\n\t\t ENTER YEAR OF STUDY : ";
			gets(year);
			cout<<"\n\t\t ENTER DIVISION : ";
			gets(division);
			cout<<"\n\t\t ENTER CONTACT NUMBER : ";
			gets(contact);
			cout<<"\n\t\t ENTER CONTACT MAIL ID : ";
			gets(mail);
			cout<<"\n\t\t ENTER BLOOD GROUP : ";
			gets(bloodgrp);
		}

		void display()
		{
			system("CLS");
			cout<<"\t\tDISPLAY RECORDS";
			cout<<"\n";
			cout<<"\n\t\t NAME : "<<name;
			cout<<"\n\t\t COLLEGE : "<<college;
			cout<<"\n\t\t REG NO. : "<<reg;
			cout<<"\n\t\t BRANCH : "<<branch;
			cout<<"\n\t\t YEAR OF STUDY : "<<year;
			cout<<"\n\t\t DIVISION : "<<division;
			cout<<"\n\t\t CONTACT NUMBER : "<<contact;
			cout<<"\n\t\t MAIL ID : "<<mail;
			cout<<"\n\t\t BLOOD GROUP : "<<bloodgrp;
			cout<<"\n";
			system("PAUSE");
			system("CLS");
		}

		bool operator == (student a)
		{
			if(reg==a.reg)
				return true;
			else
				return false;
		}
};

class teacher
{
    public:
        long int reg;
		char name[80],college[80],dept[50],qualification[50],subject[50],pay[10],contact[20],mail[50],bloodgrp[10];

        void input()
		{
			cout<<"\n\t\t ENTER NAME : ";
			gets(name);
			cout<<"\n\t\t ENTER COLLEGE : ";
			gets(college);
			cout<<"\n\t\t ENTER REG. NO : ";
			cin>>reg;
			fflush(stdin);
			cout<<"\n\t\t ENTER DEPARTMENT : ";
			gets(dept);
			cout<<"\n\t\t ENTER QUALIFICATION : ";
			gets(qualification);
			cout<<"\n\t\t ENTER SUBJECT : ";
			gets(subject);
			cout<<"\n\t\t ENTER PAY : ";
			gets(pay);
			cout<<"\n\t\t ENTER CONTACT NUMBER : ";
			gets(contact);
			cout<<"\n\t\t ENTER CONTACT MAIL ID : ";
			gets(mail);
			cout<<"\n\t\t ENTER BLOOD GROUP : ";
			gets(bloodgrp);
		}

		void display()
		{
			system("CLS");
			cout<<"\t\tDISPLAY RECORDS";
			cout<<"\n";
			cout<<"\n\t\t NAME : "<<name;
			cout<<"\n\t\t COLLEGE : "<<college;
			cout<<"\n\t\t REG NO. : "<<reg;
			cout<<"\n\t\t DEPARTMENT : "<<dept;
			cout<<"\n\t\t QUALIFICATION : "<<qualification;
			cout<<"\n\t\t SUBJECT : "<<subject;
			cout<<"\n\t\t PAY : "<<pay;
			cout<<"\n\t\t CONTACT NUMBER : "<<contact;
			cout<<"\n\t\t MAIL ID : "<<mail;
			cout<<"\n\t\t BLOOD GROUP : "<<bloodgrp;
			cout<<"\n";
			system("PAUSE");
			system("CLS");
		}

		bool operator == (teacher a)
		{
			if(reg==a.reg)
				return true;
			else
				return false;
		}
};


vector <student>v;
vector <teacher>vt;
int search_reg(long int reg,int &i,int st);

void get_file_student()
{
	student x;
	int i=0;
	fstream f;
	f.open("University_student.txt",ios::in);
	if(f)
	{
		f.read((char *) &x,sizeof(class student));
		while(!f.eof())
		{
			v.push_back(x);
			f.read((char *) &x,sizeof(class student));
		}
	}
	else
		;
	f.close();
}

void get_file_teacher()
{
	teacher x;
	int i=0;
	fstream f;
	f.open("University_teacher.txt",ios::in);
	if(f)
	{
		f.read((char *) &x,sizeof(class teacher));
		while(!f.eof())
		{
			vt.push_back(x);
			f.read((char *) &x,sizeof(class teacher));
		}
	}
	else
		;
	f.close();
}


void bubblesort_student()
{
	int i,j;
	student x;
	for(i=0;i<v.size();i++)
		for(j=0;j<v.size()-i-1;j++)
			if(v[j].reg>v[j+1].reg)
			{
				x=v[j];
				v[j]=v[j+1];
				v[j+1]=x;
			}
}


void bubblesort_teacher()
{
	int i,j;
	teacher x;
	for(i=0;i<vt.size();i++)
		for(j=0;j<vt.size()-i-1;j++)
			if(vt[j].reg>vt[j+1].reg)
			{
				x=vt[j];
				vt[j]=vt[j+1];
				vt[j+1]=x;
			}
}


void insert_new(int st)
{
    char ch='y';
    int ta;

        if(st==0)
        {
            while(ch=='y')
            {
                fflush(stdin);
                student x;
                x.input();
                if(search_reg(x.reg,ta,0)==0)
                    v.push_back(x);
                else
                    cout<<"\n\t\tTHE REGISTRATION NO. ALREADY EXIST! CANNOT ADD!";
                cout<<"\n\t\t PRESS 'Y' TO ENTER MORE OR 'N' TO STOP ENTRY : ";
                cin>>ch;
                fflush(stdin);
            }
        }
        else
        {
            while(ch=='y')
            {
                fflush(stdin);
                teacher x;
                x.input();
                if(search_reg(x.reg,ta,1)==0)
                    vt.push_back(x);
                else
                    cout<<"\n\t\tTHE REGISTRATION NO. ALREADY EXIST! CANNOT ADD!";
                cout<<"\n\t\t PRESS 'Y' TO ENTER MORE OR 'N' TO STOP ENTRY : ";
                cin>>ch;
                fflush(stdin);
            }
        }
}


void write_file_student()
{
	bubblesort_student();
	fstream f;
	f.open("University_student.txt",ios::out);
	for(int i=0;i<v.size();i++)
	{
		student x=v[i];
		f.write((char *) &x,sizeof(class student));
	}
	f.close();
}


void write_file_teacher()
{
	bubblesort_teacher();
	fstream f;
	f.open("University_teacher.txt",ios::out);
	for(int i=0;i<vt.size();i++)
	{
		teacher x=vt[i];
		f.write((char *) &x,sizeof(class teacher));
	}
	f.close();
}


int search_reg(long int reg,int &i,int st)
{
    if(st == 0)
    {
        int ta=0;
        for(i=0;i<v.size();i++)
            if(v[i].reg==reg)
            {
                ta=1;
                break;
            }
        return ta;
    }

    else
    {
        int ta=0;
        for(i=0;i<vt.size();i++)
            if(vt[i].reg==reg)
            {
                ta=1;
                break;
            }
        return ta;
    }
}


int search_name(char name[],vector<int> &vi,int st)
{
    if(st == 0)
    {
        int i,ta=0;
        for(i=0;i<v.size();i++)
            if(strcmp(v[i].name,name)==0)
            {
                ta=1;
                vi.push_back(i);
            }
        return ta;
    }

    else
    {
        int i,ta=0;
        for(i=0;i<vt.size();i++)
            if(strcmp(vt[i].name,name)==0)
            {
                ta=1;
                vi.push_back(i);
            }
        return ta;
    }
}

int search_college(char college[],vector<int> &vj,int st)
{
    if(st == 0)
    {
        int i,ta=0;
        for(i=0;i<v.size();i++)
            if(strcmp(v[i].college,college)==0)
            {
                ta=1;
                vj.push_back(i);
            }
        return ta;
    }
    else
    {
        int i,ta=0;
        for(i=0;i<vt.size();i++)
            if(strcmp(vt[i].college,college)==0)
            {
                ta=1;
                vj.push_back(i);
            }
        return ta;
        }
}


int search_branch(char branch[],vector<int> &vk)
{
	int i,ta=0;
	for(i=0;i<v.size();i++)
		if(strcmp(v[i].branch,branch)==0)
		{
			ta=1;
			vk.push_back(i);
		}
	return ta;
}


int search_dept(char dept[],vector<int> &vk)
{
	int i,ta=0;
	for(i=0;i<vt.size();i++)
		if(strcmp(vt[i].dept,dept)==0)
		{
			ta=1;
			vk.push_back(i);
		}
	return ta;
}

void search_and_show(int st)
{
        int ch,i,ta=0;
        char name[80],branch[50],dept[50],college[80];
        long int reg;

        if(st==0)
        {
            vector <int>vi;
            vector <int>vj;
            vector <int>vk;
            poi:
            cout<<"\n\t\tPRESS [1] TO SEARCH REG NO."
            <<"\n\t\tPRESS [2] TO SEARCH NAME"
            <<"\n\t\tPRESS [3] TO SEARCH COLLEGE"
            <<"\n\t\tPRESS [4] TO SEARCH BRANCH"
            <<"\n\n\t\t";
            cin>>ch;
            switch(ch)
            {
                case 1:
                    cout<<"\n\t\tENTER REG NO. : ";
                    cin>>reg;
                    if(search_reg(reg,i,0)==1)
                        v[i].display();
                    else
                        cout<<"\n\t\tRECORD NOT FOUND!";
                    break;
                case 2:
                    cout<<"\n\t\tENTER NAME : ";
                    fflush(stdin);
                    gets(name);
                    if(search_name(name,vi,0)==1)
                    {
                        for(int j=0;j<vi.size();j++)
                            v[vi[j]].display();
                    }
                    else
                        cout<<"\n\t\tRECORD NOT FOUND!";
                    break;
                case 3:
                    cout<<"\n\t\tENTER COLLEGE : ";
                    fflush(stdin);
                    gets(college);
                    if(search_college(college,vj,0)==1)
                    {
                        for(int j=0;j<vj.size();j++)
                            v[vj[j]].display();
                    }
                    else
                        cout<<"\n\t\tRECORD NOT FOUND!";
                    break;
                case 4:
                    cout<<"\n\t\tENTER BRANCH : ";
                    fflush(stdin);
                    gets(branch);
                    if(search_branch(branch,vk)==1)
                    {
                        for(int j=0;j<vk.size();j++)
                            v[vk[j]].display();
                    }
                    else
                        cout<<"\n\t\tRECORD NOT FOUND!";
                    break;
                default:
                    cout<<"\n\t\tWRONG CHOICE!";
                    goto poi;
            }
        }
        else
        {
            vector <int>vit;
            vector <int>vjt;
            vector <int>vkt;
            poit:
            cout<<"\n\t\tPRESS [1] TO SEARCH REG NO."
            <<"\n\t\tPRESS [2] TO SEARCH NAME"
            <<"\n\t\tPRESS [3] TO SEARCH COLLEGE"
            <<"\n\t\tPRESS [4] TO SEARCH DEPARTMENT"
            <<"\n\n\t\t";
            cin>>ch;
            switch(ch)
            {
                case 1:
                    cout<<"\n\t\tENTER REG NO. : ";
                    cin>>reg;
                    if(search_reg(reg,i,1)==1)
                        vt[i].display();
                    else
                        cout<<"\n\t\tRECORD NOT FOUND!";
                    break;
                case 2:
                    cout<<"\n\t\tENTER NAME : ";
                    fflush(stdin);
                    gets(name);
                    if(search_name(name,vit,1)==1)
                    {
                        for(int j=0;j<vit.size();j++)
                            vt[vit[j]].display();
                    }
                    else
                        cout<<"\n\t\tRECORD NOT FOUND!";
                    break;
                case 3:
                    cout<<"\n\t\tENTER COLLEGE : ";
                    fflush(stdin);
                    gets(college);
                    if(search_college(college,vjt,1)==1)
                    {
                        for(int j=0;j<vjt.size();j++)
                            vt[vjt[j]].display();
                    }
                    else
                        cout<<"\n\t\tRECORD NOT FOUND!";
                    break;
                case 4:
                    cout<<"\n\t\tENTER DEPARTMENT : ";
                    fflush(stdin);
                    gets(dept);
                    if(search_dept(dept,vkt)==1)
                    {
                        for(int j=0;j<vkt.size();j++)
                            vt[vkt[j]].display();
                    }
                    else
                        cout<<"\n\t\tRECORD NOT FOUND!";
                    break;
                default:
                    cout<<"\n\t\tWRONG CHOICE!";
                    goto poit;
            }
        }
}


void show(int st)
{
    if(st == 0)
    {
        int i;
        for(i=0;i<v.size();i++)
            v[i].display();
    }
    else
    {
        int i;
        for(i=0;i<vt.size();i++)
            vt[i].display();
    }
}


void delete_data(int st)
{
    int i;
    long int reg;

        if(st==0)
        {
            vector <student>::iterator p=v.begin();
            cout<<"\n\t\tENTER REG NO. : ";
            cin>>reg;
            if(search_reg(reg,i,0)==1)
            {
                student x=v[i];
                cout<<"\n\t\tTHE FOLLOWING DATA IS BEING DELETED";
                x.display();
                p+=i;
                v.erase(p,p+1);
            }
        }
        else
        {
            vector <teacher>::iterator pt=vt.begin();
            cout<<"\n\t\tENTER REG NO. : ";
            cin>>reg;
            if(search_reg(reg,i,1)==1)
            {
                teacher x=vt[i];
                cout<<"\n\t\tTHE FOLLOWING DATA IS BEING DELETED";
                x.display();
                pt+=i;
                vt.erase(pt,pt+1);
            }
        }
}

void edit_data(int st)
{
    int i;
    long int reg;

        if(st==0)
        {
            vector <student>vi;
            cout<<"\n\t\tENTER REG NO. : ";
            cin>>reg;
            if(search_reg(reg,i,0)==1)
            {
                cout<<"\n\t\tENTER NEW DATA : \n";
                fflush(stdin);
                v[i].input();
            }
        }
        else
        {
            vector <teacher>vit;
            cout<<"\n\t\tENTER REG NO. : ";
            cin>>reg;
            if(search_reg(reg,i,1)==1)
            {
                cout<<"\n\t\tENTER NEW DATA : \n";
                fflush(stdin);
                vt[i].input();
            }
        }
}


int main()
{
	int i=1;
	int st;
	get_file_student();
	get_file_teacher();
	while(i)
	{
		system("CLS");
		cout<<"\t\t\t-----------------------------------------\n";
		cout<<"\t\t\t     UNIVERSITY MANAGEMENT SYSTEM\n";
		cout<<"\t\t\t-----------------------------------------\n";
		cout<<"\n\t\t\tEnter <1> to ENTRY"
			<<"\n\t\t\tEnter <2> to DISPLAY"
			<<"\n\t\t\tEnter <3> to DELETE"
			<<"\n\t\t\tEnter <4> to MODIFICATION"
			<<"\n\t\t\tEnter <5> to SEARCH"
			<<"\n\t\t\tEnter <6> to SAVE CHANGES"
			<<"\n\t\t\tEnter <0> to EXIT\n";
		cout<<"\n\n\t\t\tENTER YOUR CHOICE : ";
		cin>>i;
		if(i!=0 && i!=6)
        {
            cout<<"\n\n\t\t\tPRESS 0 FOR STUDENT AND 1 FOR TEACHER : ";
            cin>>st;
        }

		switch(i)
		{
			case 1 :
				insert_new(st);
				break;
			case 2 :
				show(st);
				break;
			case 3 :
				delete_data(st);
				break;
			case 4 :
				edit_data(st);
				break;
			case 5 :
				search_and_show(st);
				break;
			case 6 :
			    write_file_student();
			    write_file_teacher();
				break;
            case 0:
                break;
			default :
				cout<<"\nWRONG CHOICE! TRY AGAIN!";
		}
	}
	return 0;
}
