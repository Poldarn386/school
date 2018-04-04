#include <iostream>
#include <iomanip>
#include "marcum_header.h"
#include "marcum_header.cpp"
#include <sstream>
using namespace std;

class Employee {
protected:
    string employee_name;
    int employee_number;
    string hire_date;
    static int empNumCount;
public:
    Employee(string name, int number, int year = 1900, int month = 1, int day = 1) {
        employee_name = name;
        employee_number = number;
        setHireDate(year,month,day);
        empNumCount++;
    }
    ~Employee() { empNumCount--; }
    string getName() { return employee_name; }
    int getNumber() { return employee_number; }
    string getHireDate() { return hire_date; }
    void setName(string name){ employee_name = name; }
    void setNumber(int num) { employee_number = num; }
    void setHireDate(int year, int month, int day){
        stringstream temp;
        temp << day << "/" << month << "/" << year;
        hire_date = temp.str();
    }
    static const int getEmployeeTotal();
};

int Employee::empNumCount = 0;
const int Employee::getEmployeeTotal() { return empNumCount; }

class ProductionWorker : public Employee {
private:
    //day == 1, night == 2
    int shift;
    double pay_rate;
public:
    ProductionWorker(int shift_time, double rate, string name, int number, \
        int year = 1900, int month = 1, int day = 1) : Employee(name, number, year, month, day) {
            shift = shift_time;
            pay_rate = rate;
    }
    void setRate(double rate) { pay_rate = rate; }
    void setShift(int shift_time) { shift = shift_time; }
    int getShift() { return shift; }
    double getRate() { return pay_rate; }
};
int MainLoop();

int main() {
    int selection = -1;
    while(selection = MainLoop()){


    }
    cout << Employee::getEmployeeTotal();
    return 0;
}

//==============================================================================
int MainLoop() {
char option; //options[] = {'a','b','c'};
string options[] = {"Create Production Worker","View Workers","Exit"};
system("CLS");
display("Worker Automation Station","v1.01",9);
option = Menu(options,3);
if (option == 'a')
    return 1;
if (option == 'b')
    return 2;
if (option == 'c')
    return 0;
}
//MainLoop
//==============================================================================
