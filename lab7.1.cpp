#include <iostream>
#include <string>
using namespace std;
class MicroUSBPhone {
public:
    string useMicroUSB() {
        return "Connected with MicroUSB\n";
    }
};

class ITypeCPhone {
public:
    virtual string useTypeC() = 0;
};

class TypeCPhone : public ITypeCPhone {
public:
    string useTypeC() override {
        return "Connected with Type-C\n";
    }
};

class MicroUSBToTypeCAdapter : public ITypeCPhone {
private:
    MicroUSBPhone* microUSBPhone;
public:
    MicroUSBToTypeCAdapter(MicroUSBPhone* phone) {
        microUSBPhone = phone;
    }

    string useTypeC() override {
        return microUSBPhone->useMicroUSB();
    }
};

class Charger {
public:
    static void chargePhone(ITypeCPhone* phone) {
        cout << phone->useTypeC();
    }
};

int main() {
    TypeCPhone* modernPhone = new TypeCPhone();
    Charger::chargePhone(modernPhone); 

    MicroUSBPhone* oldPhone = new MicroUSBPhone();
    MicroUSBToTypeCAdapter* adapter = new MicroUSBToTypeCAdapter(oldPhone);
    Charger::chargePhone(adapter);    

    delete modernPhone;
    delete oldPhone;
    delete adapter;

    return 0;
}
