#include <iostream>
#include "Company.h"
#include "Employee.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   Company::~Company(){
      deleteEmployees();
   }
   void Company::start(){
      cout << "Please enter company name: ";
      m_name.read();
   }
   void Company::start(const char* name){
      m_name.set(name);
      setNoOfEmployees();
   }
   void Company::setNoOfEmployees() {
      displayName();
      cout << "Number of employees to hire: ";
      cin >> m_total_no_of_employee;
      cin.ignore(1000, '\n');
      m_workers = new Employee[m_total_no_of_employee];
      if (m_workers == nullptr) {
         m_total_no_of_employee = 0;
      }
   }
   void Company::displayName(){
      if (!m_name.isEmpty()) {
         cout << "Company: " << m_name.get() << endl;
      }
      else {
         cout << "No name company" << endl;
      }
   }
   void Company::hireMoreEmployees() {
      int to_add;
      Employee* temp;
      cout << "Number of employees to add: " << endl;
      cin >> to_add;
      temp = new Employee[m_total_no_of_employee + to_add];
      for (int i = 0; i < m_total_no_of_employee; i++) {
         temp[i] = m_workers[i];
      }
      deleteEmployees();
      m_total_no_of_employee += to_add;
      m_workers = temp;
   }

   void Company::deleteEmployees() {
      delete[] m_workers;  // if m_workers is nullptr, nothing happens 
      m_workers = nullptr;
   }
   Company::Company(){
      start();
   }
   Company::Company(const char* name){
      start(name);
   }
   void Company::listEmployees() {
      displayName();
      int i;   // function scope
      for (i = 0; i < m_no_ofEmployees; i++) {
         m_workers[i].display();
      }
   }
   void Company::hire() {
      displayName();
      while (m_no_ofEmployees < m_total_no_of_employee) {
         cout << "Employee no " << m_no_ofEmployees + 1 << " out of " << m_total_no_of_employee << endl;
         m_workers[m_no_ofEmployees].hire();
         m_no_ofEmployees++;
      }
   }
   int Company::noOfEmployees() {
      return m_no_ofEmployees;
   }
   void Company::closeDown(){
      deleteEmployees();
   }
}