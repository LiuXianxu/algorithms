#include <iostream>
#include <cstdio>
using namespace std;
class Date{
public:
	int year;
	int month;
	int day;
	bool compare(Date& date)
	{
		if(this->year<date.year)
		{
			return true;
		}
		else if(this->month<date.month)
		{
			return true;
		}
		else if(this->day<date.day)
		{
			return true;
		}
		else return false;	
	}
	void print()
	{
		if(this->month!=0&&this->day!=0)
		{
			cout<<this->year<<"-";
			if(this->month<10)
			cout<<"0"<<this->month<<"-";
			else
			cout<<this->month<<"-";
			if(this->day<10)
			cout<<"0"<<this->day<<endl;
			else
			cout<<this->day<<endl;
		}
	}
};

int getYear(const int n)
{
	if(n>=60)
	{
		return 1900+n;
	}
	else
	{
		return 2000+n;
	}
}
int getMonth(int n)
{
	if(n<1||n>12)
	return 0;
	else return n;
}
int getDay(int n)
{
	if(n<1||n>31)
	return 0;
	else return n;
}
bool isExisting(int year,int month,int day)
{
	if(year%4==0&&year%400!=0||year%400==0)
	{
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:return true;
			case 2:
			if(day<=29)
			{
				return true;
			}
			else return false;
			case 4:
			case 6:
			case 9:
			case 11:if(day<=30)return true;else return false;
		}
	}
	else
	{
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:return true;
			case 2:
			if(day<=28)
			{
				return true;
			}
			else return false;
			case 4:
			case 6:
			case 9:
			case 11:if(day<=30)return true;else return false;
		}
	}
}
int main()
{
	int a,b,c;
	scanf("%d/%d/%d",&a,&b,&c);
	Date date[5];
	date[0].year=getYear(a);
	date[0].month=getMonth(b);
	date[0].day = getDay(c);
	date[1].year=getYear(c);
	date[1].month=getMonth(a);
	date[1].day = getDay(b);
	date[2].year=getYear(c);
	date[2].month=getMonth(b);
	date[2].day = getDay(a);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(date[j].compare(date[j+1])==false)
			{
				if(date[j].year==date[j+1].year
				&&date[j].month==date[j+1].month
				&&date[j].day==date[j+1].day)
				{
					date[j+1].month=0;
					date[j+1].day=0;
				}
				else
				{
				Date temp = date[j+1];
				date[j+1]=date[j];
				date[j]=temp;
				}
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		if(isExisting(date[i].year,date[i].month,date[i].day))
		date[i].print();
	}
	return 0;
}
