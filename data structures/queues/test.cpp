
#include <iostream>
using namespace std;

#define MAXSIZE 3

class CircularQueue {
private:
    int queue[MAXSIZE], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue() {
        if ((front == 0 && rear == MAXSIZE - 1) || (front == rear + 1)) {
            cout << "Queue is full!" << endl;
        } else {
            int data;
            cout<<"Enter data:";
              cin >>data;
            if (front == -1) {
                front = rear = 0;
            } else {
                if (rear == MAXSIZE - 1) {
                    rear = 0;
                } else {
                    rear++;
                }
            }
            queue[rear] = data;
        }
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Dequeued data: " << queue[front] << endl;
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                if (front == MAXSIZE - 1) {
                    front = 0;
                } else {
                    front++;
                }
            }
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
        } else {
            if (rear >= front) {
                for (int i = front; i <= rear; i++) {
                    cout << queue[i] << " ";
                }
            } else {
                for (int i = front; i < MAXSIZE; i++) {
                    cout << queue[i] << " ";
                }
                for (int i = 0; i <= rear; i++) {
                    cout << queue[i] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    int choice;
    while (true) {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout<< "Enter your choice:";    
          cin >>choice;
        switch (choice) {
            case 1:
                cq.enqueue();
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}