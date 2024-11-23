#include <iostream>
#include <fstream>

using namespace std;

class FileHandler {
public:
    virtual ~FileHandler() {}

    virtual void Display(const char* path) {
        ifstream file(path, ios::in);
        if (!file.is_open()) {
            cerr << "Cannot open file: " << path << endl;
            return;
        }

        char ch;
        while (file.get(ch)) {
            cout << ch;
        }

        file.close();
    }
};

class AsciiFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path, ios::in);
        if (!file.is_open()) {
            cerr << "Cannot open file: " << path << endl;
            return;
        }

        char ch;
        while (file.get(ch)) {
            cout << static_cast<int>(ch) << " ";
        }

        cout << endl;
        file.close();
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path, ios::in);
        if (!file.is_open()) {
            cerr << "Cannot open file: " << path << endl;
            return;
        }

        char ch;
        while (file.get(ch)) {
            for (int i = 7; i >= 0; --i) {
                cout << ((ch >> i) & 1);
            }
            cout << " ";
        }

        cout << endl;
        file.close();
    }
};

int main() {
    FileHandler* handler1 = new FileHandler();
    FileHandler* handler2 = new AsciiFileHandler();
    FileHandler* handler3 = new BinaryFileHandler();

    const char* path = "example.txt";

    cout << "Base Handler:" << endl;
    handler1->Display(path);

    cout << "\nASCII Handler:" << endl;
    handler2->Display(path);

    cout << "\nBinary Handler:" << endl;
    handler3->Display(path);

    delete handler1;
    delete handler2;
    delete handler3;
}
