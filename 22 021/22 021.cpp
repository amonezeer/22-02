#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& newData) : data(newData), next(nullptr), prev(nullptr) {}
};

template<typename T>
class Queue {
private:
    Node<T>* frontPtr;
    Node<T>* rearPtr;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return frontPtr == nullptr;
    }

    void enqueue(const T& newData) {
        Node<T>* newNode = new Node<T>(newData);
        if (isEmpty()) {
            frontPtr = rearPtr = newNode;
        }
        else {
            rearPtr->next = newNode;
            newNode->prev = rearPtr;
            rearPtr = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node<T>* temp = frontPtr;
            if (frontPtr == rearPtr) {
                frontPtr = rearPtr = nullptr;
            }
            else {
                frontPtr = frontPtr->next;
                frontPtr->prev = nullptr;
            }
            delete temp;
        }
        else {
            cout << "Очередь пуста, невозможно выполнить извлечение" << endl;
        }
    }

    T front() const {
        if (!isEmpty()) {
            return frontPtr->data;
        }
        else {
            cerr << "Очередь пуста , невозможно получить первый элемент" << endl;
            exit(EXIT_FAILURE);
        }
    }

    T rear() const {
        if (!isEmpty()) {
            return rearPtr->data;
        }
        else {
            cerr << "Очередь пуста,невозможно получить последний элемент" << endl;
            exit(EXIT_FAILURE);
        }
    }
};

int main() {

    system("chcp 1251");
    Queue<int> intQueue;

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    cout << "Первый элемент: " << intQueue.front() << endl;
    cout << "Последний элемент: " << intQueue.rear() << endl;

    intQueue.dequeue();

    cout << "Первый элемент после извлечения: " << intQueue.front() << endl;

    return 0;
}
