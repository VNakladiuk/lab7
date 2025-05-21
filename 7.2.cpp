#include <iostream>
#include <string>
using namespace std;

class Printer {
private:
    static Printer* instance;

    Printer() {
        cout << "[Принтер увімкнено]\n";
    }

public:
    Printer(const Printer&) = delete;
    Printer& operator=(const Printer&) = delete;

    static Printer* getInstance() {
        if (!instance)
            instance = new Printer();
        return instance;
    }

    void print(string text) {
        cout << "[Друк]: " << text << endl;
    }
};

Printer* Printer::instance = nullptr;

class OfficeWorker {
private:
    string name;

public:
    OfficeWorker(string name) : name(name) {}

    void sendToPrint(string doc) {
        Printer::getInstance()->print(name + " друкує: " + doc);
    }
};

int main() {
    OfficeWorker alice("Аліса");
    OfficeWorker bob("Боб");

    alice.sendToPrint("Звіт за березень");
    bob.sendToPrint("План на квітень");

    return 0;
}


