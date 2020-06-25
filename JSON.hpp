#include<iostream>
#include<unordered_map>
#include<string>
#include "Value.hpp"
#include<utility>

using namespace std;

#ifndef JSON_H
#define JSON_H

//class Value;
class JSON {
    private:
        unordered_map <string, Value> table;
        void rprint(JSON* j) {
            cout<<'{'<<endl;
            for (auto i : j->table) {
                cout<<"\t"<<i.first<<" : ";
                if (i.second.getType() == 's') {
                    cout<<i.second.getString()<<","<<endl;
                } else if (i.second.getType() == 'f') {
                    cout<<i.second.getNumber()<<","<<endl;
                } else {
                    rprint(i.second.getJSON());
                }
            }
            cout<<'}';
        }
    public:
        void insert(string key, string value) {
            table.insert(make_pair(key, Value(value)));
        }
        void insert(string key, long double value) {
            table.insert(make_pair(key, Value(value)));
        }
        void insert(string key, JSON* value) {
            table.insert(make_pair(key, Value(value)));
        }
        /* Value operator[] (string key) {
            return table.at(key);
        } */
        string getString(string key) {
            return table.at(key).getString();
        }
        long long getNumber(string key) {
            return table.at(key).getNumber();
        }
        JSON* getJSON(string key) {
            return table.at(key).getJSON();
        } 
        void print() {
            rprint(this);
        }
        
};

#endif

