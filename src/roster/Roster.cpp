#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Employee {
	char *id;
	char *firstName;
	char *lastName;
	char *phoneNumber;
	char *position;
	double *basicSalary;
	Employee(char *id,
		 char *firstName,
		 char *lastName,
		 char *phoneNumber,
		 char *position,
		 double *basicSalary);
	void *operator new(size_t size);
	void operator delete(void *p);
	void disp() const;
};

void test();

int main ()
{
	test();
	return 0;
}

void test (void)
{
	char *id = strdup("1234-5678-9ABC-DEFG");
	char *firstName = strdup("First");
	char *lastName = strdup("Last");
	char *phoneNumber = strdup("999-999-9999");
	char *position = strdup("position");
	double *basicSalary = (double*) malloc(sizeof(double));
	*basicSalary = 1.0;
	Employee *employee = new Employee(id,
					  firstName,
					  lastName,
					  phoneNumber,
					  position,
					  basicSalary);
	employee->disp();
	delete(employee);
	employee = NULL;
}

Employee::Employee(char *id,
		   char *firstName,
		   char *lastName,
		   char *phoneNumber,
		   char *position,
		   double *basicSalary)
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
	p->id = NULL;
	p->firstName = NULL;
	p->lastName = NULL;
	p->phoneNumber = NULL;
	p->position = NULL;
	p->basicSalary = NULL;
	free(p);
	p = NULL;
	vp = NULL;
}

void Employee::disp() const
{
	printf("id: %s\n", this->id);
	printf("firstName: %s\n", this->firstName);
	printf("lastName: %s\n", this->lastName);
	printf("phoneNumber: %s\n", this->phoneNumber);
	printf("position: %s\n", this->position);
	printf("basicSalary: %lf\n", *this->basicSalary);
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
