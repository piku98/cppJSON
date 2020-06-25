#include<iostream>
#include "JSON.hpp"
#include "Value.hpp"
using namespace std;

int main() {
    JSON *j = new JSON();
    j->insert("sourav", 51);
    JSON *j2 = new JSON();
    j2->insert("student", j);
    j2->print();
}