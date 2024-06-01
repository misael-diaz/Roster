#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Employee {
	char *id;
	char *firstName;
	char *lastName;
	char *phoneNumber;
	char *position;
	char *basicSalary;
	char *overtime;
	char *extraWorkedHours;
	char *loanDiscount;
	char *voluntarySavings;
	char *socialSecurityDiscount;
	double wage;
	Employee(char *id,
		 char *firstName,
		 char *lastName,
		 char *phoneNumber,
		 char *position,
		 char *basicSalary);
	void *operator new(size_t size);
	void operator delete(void *p);
	void logBasicInfo() const;
	void logWageInfo() const;
	void promptWage();
	void calcWage();
};

struct Roster {
	int num_employees;
	Employee **employees;
	Roster(int num_employees, Employee **employees);
	void *operator new(size_t size);
	void operator delete(void *p);
	void logBasicInfo() const;
	void logWageInfo() const;
	void promptWage();
	void calcWage();
};

int form(Employee ***employees);

int main ()
{
	Employee **employees = NULL;
	int num_employees = form(&employees);
	Roster *roster = new Roster(num_employees, employees);
	roster->logBasicInfo();
	roster->promptWage();
	roster->calcWage();
	roster->logWageInfo();
	delete(roster);
	roster = NULL;
	return 0;
}

static char *readline (char const *prompt_message)
{
	char *str = NULL;
	printf("%s", prompt_message);
	scanf("%ms", &str);
	return str;
}

static Employee *prompt(void)
{
	char *id = readline("input employee id:");
	char *firstName = readline("input first name:");
	char *lastName = readline("input last name:");
	char *phoneNumber = readline("input phone number:");
	char *position = readline("input position:");
	char *basicSalary = readline("input basic salary:");
	Employee *employee = new Employee(id,
					  firstName,
					  lastName,
					  phoneNumber,
					  position,
					  basicSalary);
	return employee;
}

int form(Employee ***employees)
{
	int num_employees = 0;
	printf("input the number of employees:");
	scanf("%d", &num_employees);
	size_t const sz = num_employees * sizeof(Employee*);
	*employees = (Employee**) malloc(sz);
	Employee **iter = *employees;
	for (int i = 0; i != num_employees; ++i) {
		printf("input the basic info of employee No %d\n", i);
		iter[i] = prompt();
	}
	return num_employees;
}

void test (void)
{
	char *id = strdup("1234-5678-9ABC-DEFG");
	char *firstName = strdup("First");
	char *lastName = strdup("Last");
	char *phoneNumber = strdup("999-999-9999");
	char *position = strdup("position");
	char *basicSalary = strdup("1.0");
	Employee *employee = new Employee(id,
					  firstName,
					  lastName,
					  phoneNumber,
					  position,
					  basicSalary);
	employee->logBasicInfo();
	delete(employee);
	employee = NULL;
}

Employee::Employee(char *id,
		   char *firstName,
		   char *lastName,
		   char *phoneNumber,
		   char *position,
		   char *basicSalary)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
	this->position = position;
	this->basicSalary = basicSalary;
}

void *Employee::operator new(size_t size)
{
	return malloc(size);
}

void Employee::operator delete(void *vp)
{
	Employee *p = (Employee*) vp;
	free(p->id);
	free(p->firstName);
	free(p->lastName);
	free(p->phoneNumber);
	free(p->position);
	free(p->basicSalary);
	free(p->overtime);
	free(p->extraWorkedHours);
	free(p->loanDiscount);
	free(p->voluntarySavings);
	free(p->socialSecurityDiscount);
	p->id = NULL;
	p->firstName = NULL;
	p->lastName = NULL;
	p->phoneNumber = NULL;
	p->position = NULL;
	p->basicSalary = NULL;
	p->overtime = NULL;
	p->extraWorkedHours = NULL;
	p->loanDiscount = NULL;
	p->voluntarySavings = NULL;
	p->socialSecurityDiscount = NULL;
	free(p);
	p = NULL;
	vp = NULL;
}

void Employee::logBasicInfo() const
{
	printf("id: %s\n", this->id);
	printf("firstName: %s\n", this->firstName);
	printf("lastName: %s\n", this->lastName);
	printf("phoneNumber: %s\n", this->phoneNumber);
	printf("position: %s\n", this->position);
	printf("basicSalary: %s\n", this->basicSalary);
}

void Employee::logWageInfo() const
{
	printf("overtime: %s\n", this->overtime);
	printf("extraWorkedHours: %s\n", this->extraWorkedHours);
	printf("loanDiscount: %s\n", this->loanDiscount);
	printf("voluntarySavings: %s\n", this->voluntarySavings);
	printf("socialSecurityDiscount: %s\n", this->socialSecurityDiscount);
	printf("wage: %lf\n", this->wage);
}

void Employee::promptWage()
{
	this->overtime = readline("input overtime paytment rate:");
	this->extraWorkedHours = readline("input extra worked hours:");
	this->loanDiscount = readline("input loan discount:");
	this->voluntarySavings = readline("input voluntary savings:");
	this->socialSecurityDiscount = readline("input social security discount:");
}

void Employee::calcWage()
{
	double const basicSalary = atof(this->basicSalary);
	double const overtime = atof(this->overtime);
	double const extraWorkedHours = atof(this->extraWorkedHours);
	double const loanDiscount = atof(this->loanDiscount);
	double const voluntarySavings = atof(this->voluntarySavings);
	double const socialSecurityDiscount = atof(this->socialSecurityDiscount);
	double const wage = (basicSalary +
			     overtime * extraWorkedHours -
			     loanDiscount -
			     voluntarySavings -
			     socialSecurityDiscount);
	this->wage = wage;
}


Roster::Roster(int num_employees, Employee **employees)
{
	this->num_employees = num_employees;
	this->employees = employees;
}

void *Roster::operator new(size_t size)
{
	return malloc(size);
}

void Roster::operator delete(void *vp)
{
	Roster *p = (Roster*) vp;

	for (int i = 0; i != p->num_employees; ++i) {
		Employee *employee = p->employees[i];
		delete(employee);
		employee = NULL;
	}

	free(p->employees);
	p->employees = NULL;
	free(p);
	p = NULL;
	vp = NULL;
}

void Roster::promptWage()
{
	for (int i = 0; i != this->num_employees; ++i) {
		printf("input the wage info of employee No %d\n", i);
		Employee *employee = this->employees[i];
		employee->promptWage();
	}
}

void Roster::calcWage()
{
	for (int i = 0; i != this->num_employees; ++i) {
		Employee *employee = this->employees[i];
		employee->calcWage();
	}
}

void Roster::logBasicInfo() const
{
	for (int i = 0; i != num_employees; ++i) {
		printf("basic info of employee No %d\n", i);
		Employee *employee = this->employees[i];
		employee->logBasicInfo();
	}
}

void Roster::logWageInfo() const
{
	for (int i = 0; i != this->num_employees; ++i) {
		printf("wage info of employee No %d\n", i);
		Employee *employee = this->employees[i];
		employee->logWageInfo();
	}
}

/*

Rosters						May 30, 2024

source: Roster.cpp
author: @misael-diaz

Copyright (C) 2024 Misael Díaz-Maldonado

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

References:

[0] https://en.cppreference.com/w/cpp

*/
