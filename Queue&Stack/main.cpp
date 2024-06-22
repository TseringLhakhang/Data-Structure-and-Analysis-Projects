#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Language.h"
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main() {

    //Declare empty Language vector
    vector<Language> languages;
    string fIn = "../language_file.csv";
    getDataFromFile(fIn, languages);

    /**
     * Code from Project 1
    cout << "Total # of rows: " << languages.size() << endl;
    int first = languages.front().getRow_number();
    cout << "First row_number: " << first << endl;
    int last = languages.back().getRow_number();
    cout << "Last row_number: " << last << endl;

    //Styling
    cout << string(112, ':') << endl;
    //Header
    cout << left << setw(8) << "Row";
    cout << setw(13) << "Wals_code";
    cout << setw(20) << "Name";
    cout << left << setw(16) << "Genus";
    cout << setw(16) << "Family";
    cout << setw(17) << "Macroarea";
    cout << setw(13) << "Latitude";
    cout << "Longitude" << endl;
    cout << string(112, '.') << endl;

    //First 3 lines
    for(int i = 0; i < 3; i++) {
        cout << languages.at(i) << endl;
    }
    //Last 3 lines
    for (int i = last-3; i < languages.size(); i++) {
        cout << languages.at(i) << endl;
    }
    cout << string(112, ':') << endl;

    //Call the displayMacroareaStat to show the calculations
    displayMacroareaStat(languages);
    */

    //Create int Queue object
    Queue<int> integerQueue;
    //Demonstrate the Queue methods by calling them
    integerQueue.enQueue(1);
    integerQueue.enQueue(2);
    integerQueue.enQueue(3);
    integerQueue.enQueue(4);
    integerQueue.deQueue();
    integerQueue.printQueue();

    cout << boolalpha;// Makes bool values as true and false instead of 1 and 0
    cout << "Is 1 in the Queue: "<<integerQueue.search(1) << endl;
    cout << "Is 4 in the Queue: "<<integerQueue.search(4) << endl;
    //Styling
    cout << string(30, '.') << endl;

    //Create string Queue object
    Queue<string> stringQueue;
    stringQueue.enQueue("First");
    stringQueue.enQueue("Second");
    stringQueue.enQueue("Third");
    stringQueue.enQueue("Fourth");
    stringQueue.deQueue();
    stringQueue.printQueue();

    cout << boolalpha;// Makes bool values as true and false instead of 1 and 0
    cout << "Is First in the Queue: "<<stringQueue.search("First") << endl;
    cout << "Is Fourth in the Queue: "<<stringQueue.search("Fourth") << endl;
    cout << string(145, '.') << endl;

    //Create Queue object of type you created in Project 1.
    Queue<Language> langQueue;
    langQueue.enQueue(languages.at(1));
    langQueue.enQueue(languages.at(2));
    langQueue.enQueue(languages.at(3));
    langQueue.enQueue(languages.at(4));
    langQueue.deQueue();
    langQueue.printQueue();
    cout << boolalpha;// Makes bool values as true and false instead of 1 and 0
    cout << "Is 1st row of the Language file in the Queue: "<<langQueue.search(languages.at(1)) << endl;
    cout << "Is 2nd row of the Language file in the Queue: "<<langQueue.search(languages.at(4)) << endl;

    cout << string(145, '.') << endl;

    //Create a Queue object and a Stack object
    Queue<Language> myQueue;
    Stack<Language> myStack;

    //Print and push the first 10 objects from your vector onto the Queue
    for(int i = 0; i < 10; i++) {
        myQueue.enQueue(languages.at(i));
    }
    myQueue.printQueue();

    cout << string(145, '.') << endl;

    //Dequeue objects off the Queue and push onto Stack
    for(int i = 0; i < 10; i++) {
        myStack.push(myQueue.deQueue());
    }
    myStack.printStack();

    cout << string(145, '.') << endl;

    //Pop objects off Stack
    for(int i = 0; i < 10; i++) {
        myStack.pop();
    }
}