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
};

int main(){

    Singleton& s1 = Singleton::getInstance();
    cout << &s1 << endl;
    Singleton& s3 = Singleton::getInstance();
    cout << &s3 << endl;

    return 0;
}
