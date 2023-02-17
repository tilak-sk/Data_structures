// Design a menu driven Program in C++ for the following operations on 
// Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, 
// Dept, Designation and salary. Perform the following operations.
// a. Create a double linked list of employees data.
// b. Insert a new employee to the left of the node whose key value 
// (employee name) is read as an input. 
// c. Delete a node with given data, if it is found. Otherwise display 
// appropriate error message
#include <iostream>
#include <string>
using namespace std;

class DLL;
class Node {
    private:
        int ssn;
        string name, dept, designation;
        double salary;
        Node *prev, *next;
        friend class DLL;
};

class DLL {
    private:
        Node *first, *last, *t;
        int count;
    public:
        DLL() {
            first = NULL;
            count = 0;
        }
        void insert(int ssn, string name, string dept, string designation, double salary) {
            t = new Node;
            t->ssn = ssn;
            t->name = name;
            t->dept = dept;
            t->designation = designation;
            t->salary = salary;
            t->next = NULL;
            t->prev = NULL;
            if(first == NULL) {
                first = t;
                last = t;
            } else {
                last->next = t;
                t->prev = last;
                last = t;
            }
            count++;
        }

        void insertLeft(string keyName, int ssn, string name, string dept, string designation, double salary) {
            Node *p = first;
            while(p != NULL && p->name != keyName) {
                p = p->next;
            }
            if(p == NULL) {
                cout << "Employee with name " << keyName << " not found.\n";
                return;
            }
            t = new Node;
            t->ssn = ssn;
            t->name = name;
            t->dept = dept;
            t->designation = designation;
            t->salary = salary;
            if(p == first) {
                t->prev = NULL;
                t->next = first;
                first->prev = t;
                first = t;
            } else {
                t->prev = p->prev;
                t->next = p;
                p->prev->next = t;
                p->prev = t;
            }
            count++;
            cout << "Employee inserted successfully.\n";
        }

        void deleteNode(string keyName) {
            Node *p = first;
            while(p != NULL && p->name != keyName) {
                p = p->next;
            }
            if(p == NULL) {
                cout << "Employee with name " << keyName << " not found.\n";
                return;
            }
            if(p == first) {
                first = p->next;
                if(first != NULL) {
                    first->prev = NULL;
                } else {
                    last = NULL;
                }
            } else if(p == last) {
                last = p->prev;
                last->next = NULL;
            } else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            delete p;
            count--;
            cout << "Employee deleted successfully.\n";
        }

        void display() {
            Node *p = first;
            while(p != NULL) {
                cout << "SSN: " << p->ssn << ", Name: " << p->name << ", Dept: " << p->dept << ", Designation: " << p->designation << ", Salary: " << p->salary << "\n";
                p = p->next;
            }
        }

        int getCount() {
            return count;
        }
};

int main() {
    DLL empList;
    int choice, ssn, salary;
    string name, dept, designation;
    while (true) {
        cout << "1. Create a double linked list of employees data\n";
        cout << "2. Insert a new employee to the left of the node whose key value is read as an input\n";
        cout << "3. Delete a node with given data\n";
        cout << "4. Display the employee data\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear the input buffer
        switch(choice) {
            case 1:
                cout << "Enter the employee details (SSN, Name, Dept, Designation, Salary):\n";
                cin >> ssn;
                getline(cin, name);
                getline(cin, dept);
                getline(cin, designation);
                cin >> salary;
                empList.insert(ssn, name, dept, designation, salary);
                cout << "Employee added successfully.\n";
                break;
            case 2:
                cout << "Enter the key value (Name) of the employee to the left of which the new employee is to be inserted: ";
                getline(cin, name);
                cout << "Enter the employee details (SSN, Name, Dept, Designation, Salary):\n";
                cin >> ssn;
                cin.ignore(); // clear the input buffer
                getline(cin, name);
                getline(cin, dept);
                getline(cin, designation);
                cin >> salary;
                empList.insertLeft(name, ssn, name, dept, designation, salary);
                break;
            case 3:
                cout << "Enter the name of the employee to be deleted: ";
                getline(cin, name);
                empList.deleteNode(name);
                break;
            case 4:
                cout << "Employee Data:\n";
                empList.display();
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
