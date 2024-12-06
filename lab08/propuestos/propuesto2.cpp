#include <iostream>
using namespace std;

class Button {
public:
    virtual void Draw() = 0;
};

class CheckBox {
public:
    virtual void Draw() = 0;
};

class LinuxButton : public Button {
public:
    void Draw() { cout << "Linux Button" << endl; }
};

class WindowsButton : public Button {
public:
    void Draw() { cout << "Windows Button" << endl; }
};

class LinuxCheckBox : public CheckBox {
public:
    void Draw() { cout << "Linux CheckBox" << endl; }
};

class WindowsCheckBox : public CheckBox {
public:
    void Draw() { cout << "Windows CheckBox" << endl; }
};

class AbstractFactory {
public:
    virtual Button* createButton() = 0;
    virtual CheckBox* createCheckBox() = 0;
};

class LinuxFactory : public AbstractFactory {
public:
    Button* createButton() { return new LinuxButton(); }
    CheckBox* createCheckBox() { return new LinuxCheckBox(); }
};

class WindowsFactory : public AbstractFactory {
public:
    Button* createButton() { return new WindowsButton(); }
    CheckBox* createCheckBox() { return new WindowsCheckBox(); }
};

int main() {
    AbstractFactory *factory = nullptr;
    int os;
    cout << "Select OS (1 for Linux, 2 for Windows): ";
    cin >> os;

    if (os == 1) factory = new LinuxFactory();
    else if (os == 2) factory = new WindowsFactory();

    if (factory) {
        Button *btn = factory->createButton();
        CheckBox *chk = factory->createCheckBox();
        btn->Draw();
        chk->Draw();
        delete btn;
        delete chk;
        delete factory;
    } else {
        cout << "Invalid OS type!" << endl;
    }
    return 0;
}

