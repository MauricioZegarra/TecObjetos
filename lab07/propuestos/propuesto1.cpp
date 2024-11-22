#include <iostream>
#include <string>
#include <vector>

using namespace std;

class item {
public:
    virtual string GetName() { return ""; };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class Processor : public item {
public:
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class IntelI5 : public Processor {
public:
    string GetName() {
        return "Intel i5";
    }
    float GetPrice() {
        return 3000.00;
    }
    void GetConfiguration() {
        cout << "1.50 Ghz, up to 2.0 Ghz with turbo, 2 cores, 4 threads, 8 MB cache, RAM 4 GB - 8 GB" << endl;
    }
};

class IntelI7 : public Processor {
public:
    string GetName() {
        return "Intel i7";
    }
    float GetPrice() {
        return 4700.00;
    }
    void GetConfiguration() {
        cout << "1.6 Ghz, up to 1.99 Ghz, 9na Gen, 4 cores, 8 threads, 16 MB cache, RAM 16 GB" << endl;
    }
};

class Drive : public item {
public:
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class HDD : public Drive {
public:
    string GetName() {
        return "Hard disk drive";
    }
    float GetPrice() {
        return 150.00;
    }
    void GetConfiguration() {
        cout << "capacity: 1 TB, data transfer 1050 mbits/s" << endl;
    }
};

class SDD : public Drive {
public:
    string GetName() {
        return "Solid state drive";
    }
    float GetPrice() {
        return 270.00;
    }
    void GetConfiguration() {
        cout << "capacity: 250 GB, data transfer 1800 mbits/s" << endl;
    }
};

class DisplayType : public item {
public:
    virtual string GetName() { return string(""); }
    virtual float GetPrice() { return 0.0; }
    virtual void GetConfiguration() {}
};

class Normal : public DisplayType {
public:
    string GetName() {
        return "Non-touch screen";
    }
    float GetPrice() {
        return 195.00;
    }
    void GetConfiguration() {
        cout << "15.6 inch FHD(1920 x 1080), plane, ....etc" << endl;
    }
};

class Plasma : public DisplayType {
public:
    string GetName() {
        return "Plasma screen";
    }
    float GetPrice() {
        return 300.00;
    }
    void GetConfiguration() {
        cout << "17 inch QHD(2560 x 1440), HDR support" << endl;
    }
};

class Printer : public item {
public:
    string GetName() {
        return "Printer";
    }
    float GetPrice() {
        return 600.00;
    }
    void GetConfiguration() {
        cout << "Multifunctional printer with scanning, copying, and printing" << endl;
    }
};

class Color : public item {
public:
    string GetName() {
        return "Color";
    }
    float GetPrice() {
        return 50.00;
    }
    void GetConfiguration() {
        cout << "Available colors: Black, Silver, and Red" << endl;
    }
};

class Brand : public item {
public:
    string GetName() {
        return "Brand";
    }
    float GetPrice() {
        return 0.00;
    }
    void GetConfiguration() {
        cout << "Brand: Lenovo" << endl;
    }
};

class laptop {
public:
    void AddParts(item *item) {
        mLaptopParts.push_back(item);
    }

    float GetCost() {
        float cost = 0.0;
        for (auto item : mLaptopParts) {
            cost += item->GetPrice();
        }
        return cost;
    }

    void GetConfiguration() {
        for (auto i = 0; i < mLaptopParts.size(); i++) {
            cout << mLaptopParts[i]->GetName() << ": ";
            mLaptopParts[i]->GetConfiguration();
        }
    }

private:
    vector<item*> mLaptopParts;
};

class laptopBuilder {
public:
    laptop *opcion1() {
        laptop *lap = new laptop();
        lap->AddParts(new Brand());
        lap->AddParts(new IntelI5());
        lap->AddParts(new Normal());
        lap->AddParts(new HDD());
        lap->AddParts(new Color());
        return lap;
    }

    laptop *opcion2() {
        laptop *lap = new laptop();
        lap->AddParts(new Brand());
        lap->AddParts(new IntelI7());
        lap->AddParts(new Plasma());
        lap->AddParts(new SDD());
        lap->AddParts(new Printer());
        lap->AddParts(new Color());
        return lap;
    }
};

int main() {
    laptopBuilder cotizar;
    cout << "Laptop Lenovo XY\n";

    laptop *lenovo1 = cotizar.opcion1();
    cout << "\nConfiguration for Option 1:\n";
    lenovo1->GetConfiguration();
    cout << "Price: " << lenovo1->GetCost() << endl;

    laptop *lenovo2 = cotizar.opcion2();
    cout << "\nConfiguration for Option 2:\n";
    lenovo2->GetConfiguration();
    cout << "Price: " << lenovo2->GetCost() << endl;

    return 0;
}

