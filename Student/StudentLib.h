#pragma once

#include "atlstr.h" //CString 


class Human 
{
protected:
	bool gender;
	int age;
	int weight;
	CString name;

public:

friend CString makelength(CString , int );

bool get_gender()
{
	return gender;
}

int get_age()
{
	return age;
}

int get_weight()
{
	return weight;
}

CString  get_name()
{
	return name;
}

void set(bool value_gender,  int value_age,  int value_weight, CString value_name)
{
	gender= value_gender;
	age= value_age;
	weight= value_weight;
	name= value_name;
}

void set(Human& obj)
{
	gender = obj.gender;
	age = obj.age;
	weight = obj.weight;
	name = obj.name;
}

Human()
{
	set(0, 0, 0, _T(""));
}

Human(Human& obj)
{
	gender = obj.gender;
	age = obj.age;
	weight = obj.weight;
	name = obj.name;

}

Human(bool value_gender, int value_age, int value_weight, CString value_name)
{
	gender = value_gender;
	age = value_age;
	weight = value_weight;
	name = value_name;
}

CString get_string()
{
	CString temp_str, temp_age, temp_weight, temp_name, temp_gender;
	temp_age.Format(_T("%d"), age);
	temp_weight.Format(_T("%d"), weight);
	if (gender) temp_gender = _T(" мужской        ");
	else temp_gender = _T(" женский        ");
	temp_name = makelength(name, 35);
	temp_age = makelength(temp_age, 10);
	temp_weight = makelength(temp_weight, 10);
	temp_str = temp_name + temp_age + temp_gender + temp_weight ;
	return temp_str;
}

~Human()
{
}

};

class Student :public Human
{
protected:
 int study_year;
public:
	
	bool get_gender()
	{
		return gender;
	}

	int get_age()
	{
		return age;
	}

	int get_weight()
	{
		return weight;
	}

	CString  get_name()
	{
		return name;
	}

	unsigned short int get_study_year()
	{
		return study_year;
	}


	void set_study_year( int value_study_year)
	{
		study_year = value_study_year;
	}

	void set(bool value_gender, int value_age, int value_weight, CString value_name,int value_study_year)
	{
		Human::set(value_gender, value_age, value_weight, value_name);
		study_year = value_study_year;
	}

	Student()
	{
		Human::set(0, 0, 0, _T(""));
		study_year = 1;
	}

	Student(bool value_gender,  int value_age,  int value_weight, CString value_name,  int value_study_year)
	{
		Human::set(value_gender, value_age, value_weight, value_name);
		study_year=value_study_year;
	}

	CString get_string()
	{
		CString temp_str, temp_st_year;
		temp_str = Human::get_string();
		temp_st_year.Format(_T("%d"), get_study_year());
		temp_st_year = makelength(temp_st_year, 10);
		temp_str = temp_str + temp_st_year;
		return temp_str;
	}

	~Student()
	{
	}
};


CString makelength(CString str, int length)
{
	CString tempstr = str;
	int l = length- tempstr.GetLength();
	for (int i = tempstr.GetLength(); i < l; ++i)
	{
		tempstr = tempstr + _T(" ");
	}
	return tempstr;
}



