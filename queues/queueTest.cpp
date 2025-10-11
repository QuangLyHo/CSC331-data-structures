#include <iostream>
#include "queueType.hpp"
#include <cassert>
#include <fstream>

using namespace std;

void processQueue(queueType<string>&);

int main() {
    ifstream inputFilePriority("priority.txt");
    ifstream inputFileRegular("regular.txt");
    queueType<string> priorityQ(100);
    queueType<string> regularQ(79);
    queueType<string> tomorrowQ(200);

    if (!inputFilePriority.is_open()) {
        cerr << "Error: Unable to open priority.txt file" << endl;
        return 1;
    }
    if (!inputFileRegular.is_open()) {
        cerr << "Error: Unable to open regular.txt file" << endl;
        return 1;
    }

    string name;

    while (inputFilePriority) {
        inputFilePriority >> name;
        priorityQ.addQueue(name);
    }

    while (inputFileRegular) {
        inputFileRegular >> name;
        regularQ.addQueue(name);
    }

    int count = 1;
    while (count < 30) {
        if (count % 4 == 0) {
            cout << "Processed regular queue: ";
            processQueue(regularQ);
        }
        else {
            cout << "Processed priority queue: "; 
            processQueue(priorityQ);
        }
        count++;
    }
    while (!regularQ.isEmptyQueue() && !priorityQ.isEmptyQueue()) {
        if (count % 4 == 0) {
            tomorrowQ.addQueue(regularQ.front());
            regularQ.deleteQueue();
        }
        else {
            tomorrowQ.addQueue(priorityQ.front());
            priorityQ.deleteQueue();
        }
            count++;
    }

    cout << endl;
    cout << "From tommorow's queue:" << endl;

    while (!tomorrowQ.isEmptyQueue()) {
        if (count % 4 == 0) {
            cout << "Saved for tomorrow's queue, regular: ";
            cout << tomorrowQ.front() << endl;
        }
        else {
            cout << "Saved for tomorrow's queue, Prioirty: ";
            cout << tomorrowQ.front() << endl;
        }
        tomorrowQ.deleteQueue();
        count++;
    }

    inputFilePriority.close();
    inputFileRegular.close();

    return 0;
}

void processQueue(queueType<string>& queue) {
    cout    << queue.front() << endl;
    queue.deleteQueue();
}





