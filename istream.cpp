#include <iostream>
#include <string>
using namespace std;


string readData(std::istream& input) {
    std::string data;
    char ch;
    while (input.get(ch) && ch != '\n') {
        data = data + ch;
    }
    return data;
}

int countWords(string data) { return 0; }

int main() {
    std::cout << "Digite aqui: ";
    string data = readData(std::cin);
    int count = countWords(data);
    std::cout << data << " count : " << count << "\n";
    return 0;
}
