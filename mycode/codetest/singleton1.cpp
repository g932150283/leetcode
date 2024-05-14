#include<bits/stdc++.h>

using namespace std;

mutex mt;

class Singleton
{
private:
    /* data */
    Singleton(/* args */){}
    static Singleton* _instance;
public:
    static Singleton* instance(){
        mt.lock();
        if(_instance == 0){
            _instance = new Singleton();
        }
        mt.unlock();
        return _instance;
    }
    
};

Singleton::Singleton(/* args */)
{
}

Singleton::~Singleton()
{
}
