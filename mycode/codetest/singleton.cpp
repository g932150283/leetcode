#include<bits/stdc++.h>

using namespace std;

class Singleton
{
private:
    /* data */
    Singleton(/* args */) = default;
    // ~Singleton();
    Singleton(const Singleton& s)=delete;
    Singleton& operator=(const Singleton& s) = delete;
    
public:
    

    static Singleton& getInstance(){
        static Singleton value;
        return value;
    }

    void printAddress() const {
        std::cout << "The address of this object is: " << this << std::endl;
    }
};

int main(){

    Singleton& s1 = Singleton::getInstance();
    cout << &s1 << endl;
    s1.printAddress();
    Singleton& s3 = Singleton::getInstance();
    s3.printAddress();
    cout << &s3 << endl;

    return 0;
}
