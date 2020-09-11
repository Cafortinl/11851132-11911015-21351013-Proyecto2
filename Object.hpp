#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <string>

using namespace std;

class Object{
    public:
        virtual ~Object(){};
        virtual bool equals(Object*) = 0;
        virtual string toString() = 0;
};
#endif