#include <iostream>
using namespace std;

class Object {
    public: 
        int sum; 
    void sumValues (int a, int b){
        sum = a + b;
    }
    int returnSum (){
        return sum; 
    }
};

Object * sum(int a, int b){
    Object *obj1 = new Object();
    obj1->sumValues(a, b);
    return obj1;
}

void func() {
    Object *obj1 = sum(10, 5);
    std::cout << obj1->returnSum() << std::endl;
    Object *obj2 = sum(2, 8);
    std::cout << obj2->returnSum() << std::endl;
}

int main(){
    func();
    Object *obj1 = new Object();
    obj1->sumValues(10, 20);
    std::cout << obj1->returnSum() << std::endl;
    return 0;
}
