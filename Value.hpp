#include<iostream>

using namespace std;

#ifndef Value_H
#define Value_H

class JSON;

class Value {
    private:
        string svalue;
        long double fvalue;
        JSON* jvalue;
        char type;
    public:
        Value(string svalue) {
            type = 's';
            this->svalue = svalue;
        }
        Value(long double fvalue) {
            type = 'f';
            this->fvalue = fvalue;
        }
        Value(JSON* jvalue) {
            type = 'j';
            this->jvalue = jvalue;
        }
        char getType() {
            return type;
        }
        string getString() {
            return svalue;
        }
        long double getNumber() {
            return fvalue;
        }
        JSON* getJSON() {
            return jvalue;
        }

};

#endif
