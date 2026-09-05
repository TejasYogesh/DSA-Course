#include <iostream>
using namespace std;

class Employee {
public:
    int id;
    string name;
    float salary;
    Employee* next;

    Employee(int i, string n, float s) {
        id = i;
        name = n;
        salary = s;
        next = NULL;
    }
};

class EmployeeManagement {
    Employee* head = NULL;

public:

    // CREATE
    void create(int id, string name, float salary) {
        Employee* newNode =
            new Employee(id, name, salary);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Employee* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }


    // READ
    void read() {
        Employee* temp = head;

        while (temp != NULL) {
            cout << temp->id << " "
                 << temp->name << " "
                 << temp->salary << endl;

            temp = temp->next;
        }
    }


    // UPDATE
    void update(int id, float newSalary) {
        Employee* temp = head;

        while (temp != NULL) {
            if (temp->id == id) {
                temp->salary = newSalary;
                return;
            }

            temp = temp->next;
        }
    }


    // DELETE
    void remove(int id) {

        if (head == NULL)
            return;

        // Delete first node
        if (head->id == id) {
            Employee* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Employee* temp = head;

        while (temp->next != NULL &&
               temp->next->id != id) {
            temp = temp->next;
        }

        if (temp->next != NULL) {
            Employee* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }
};


int main() {

    EmployeeManagement emp;

    // CREATE
    emp.create(101, "Rahul", 50000);
    emp.create(102, "Priya", 60000);
    emp.create(103, "Amit", 55000);

    // READ
    cout << "Employees:\n";
    emp.read();

    // UPDATE
    emp.update(102, 70000);

    cout << "\nAfter Update:\n";
    emp.read();

    // DELETE
    emp.remove(101);

    cout << "\nAfter Delete:\n";
    emp.read();

    emp.create(104, "D", 100000);
    emp.read();

    return 0;
}