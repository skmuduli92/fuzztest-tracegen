
#ifndef _PROPERTY_PARSER_H_
#define _PROPERTY_PARSER_H_

#include<iostream>
#include<string.h>
#include<assert.h>
#include<vector>

#include "global_defs.h"

class VARIABLE;

using namespace std;

// to copy substring from index start to finish

// Class to store tree nodes for the property

void substring(char* dest, char* src, int start, int finish);
void cleanup(void);

class Formula {
private:
//    Formula() : num_lit(0), tr_lit(NULL) {}
protected:

public:
    bool val;
    char* op;
    int lit_i;

//    Formula(int nlit, char** lits) : num_lit(nlit), tr_lit(lits) {}

    vector<Formula*> child;

    virtual char* formula(){
        return op;
    }

    virtual bool eval(const long* temp1, const long* temp2) const {
        return true;
    }

    virtual int value(const long* temp1, const long* temp2){
        return 0;
    }

    virtual void display(){};


    // parses the property or formula and generates Tree
};

class TRUE : public Formula {

public:
    virtual bool eval(const long* trace1, const long* trace2){
        return true;
    }

    void display(){
        cout << "(TRUE)";
    }
};

// literal or variable e.g. a, b, cxrom_dot_ioadr, etc.
class CONSTANT : public Formula{ // its child is in right

public:
    long int const_val;

    CONSTANT(int i) : const_val(i) {}

    int value(const long* trace1, const long* trace2){
        return const_val;
    }

    void display(){
        cout << "("<< const_val <<")";
    }
};

class VARIABLE : public Formula { // its child is in right

public:
    int tr_num;

    VARIABLE(int i, int j) {
        lit_i = i;
        tr_num = j;
    }

    int value(const long* trace1, const long* trace2){
        if(tr_num==1){
            return trace1[lit_i];
        }else if (tr_num==2){
            return trace2[lit_i];
        }else{
            assert(0);
        }
    }

    void display(){
        cout << "("<< tr_num<< "."<< tr_lit[lit_i]<<")";
    }

};

// yesterday
class Y : public Formula{
public:
    bool old;
    bool res;
    Y(){ // constructor
        old = false;
        res = false;
    }

    virtual bool eval(const long* trace1, const long* trace2){
        res = old;
        old = child[0]->eval(trace1, trace2);
        return res;
    }

    void display(){
        cout << "(Y ";
        child[0]->display();
        cout<<")";
    }
};

//yesterday with true for time instance 0
class Z : public Formula{

public:
    bool old;
    bool res;

    Z() { // constructor
        old = true;
        res = true;
    }

    virtual bool eval(const long* trace1, const long* trace2) {
        res = old;
        old = child[0]->eval(trace1, trace2);
        return res;
    }

    void display() {
        cout << "(Z ";
        child[0]->display();
        cout<<")";
    }
};

// Once: if the property was ever true
class O : public Formula{
public:
    bool past;

    O(){ // constructor
        past = false;
    }

    virtual bool eval(const long* trace1, const long* trace2) {
        past = past?true:child[0]->eval(trace1, trace2);
        return past;
    }

    void display() {
        cout << "(O ";
        child[0]->display();
        cout<<")";
    }
};

class G : public Formula {

public:
    bool past;
    G(){ // constructor
        past = true;
    }

    virtual bool eval(const long* trace1, const long* trace2) {
        past = past?child[0]->eval(trace1, trace2):false;
        return past;
    }

    void display() {
        cout << "(G ";
        child[0]->display();
        cout<<")";
    }
};

//Since: aSb is equavalant to baaaaaa
class S : public Formula{

public:
    bool res;
    S() { // constructor
        res = false;
    }

    virtual bool eval(const long* trace1, const long* trace2){
        if (child[1]->eval(trace1, trace2)) {
            res = true;
        }else if(res) {
            res = child[0]->eval(trace1, trace2);
        } else {
            res = false;
        }
        return res;
    }

    void display(){
        cout << "(S ";
        child[0]->display();
        cout << " ";
        child[1]->display();
        cout<<")";
    }
};

// Simple not operator
class NOT : public Formula{
public:
    NOT(){ // constructor
    }

    virtual bool eval(const long* trace1, const long* trace2){
        val = !child[0]->eval(trace1, trace2);
        return val;
    }

    void display(){
        cout << "(NOT ";
        child[0]->display();
        cout<<")";
    }
};

// Simple and operator
class AND : public Formula {
public:

    virtual bool eval(const long* trace1, const long* trace2){
        val = child[1]->eval(trace1, trace2) & child[0]->eval(trace1, trace2);
        return val;
    }

    void display() {
        cout << "(AND ";
        child[0]->display();
        cout << " ";
        child[1]->display();
        cout<<")";
    }
};

// simple or operator
class OR : public Formula{
public:

    virtual bool eval(const long* trace1, const long* trace2) {
        val = child[1]->eval(trace1, trace2) | child[0]->eval(trace1, trace2);
        return val;
    }

    void display(){
        cout << "(OR ";
        child[0]->display();
        cout << " ";
        child[1]->display();
        cout<<")";
    }
};

class IMPLIES : public Formula{
public:

    virtual bool eval(const long* trace1, const long* trace2) {
        if (child[0]->eval(trace1,trace2) && !child[1]->eval(trace1,trace2))
            return false;
        return true;
    }

    void display(){
        cout << "(IMPLIES ";
        child[0]->display();
        cout << " ";
        child[1]->display();
        cout<<")";
    }
};

class EQL : public Formula{
public:

    virtual bool eval(const long* trace1, const long* trace2){
        val = (child[0]->value(trace1, trace2) == child[1]->value(trace1, trace2));
        // cout << child[0]->value(trace1, trace2) << " " << child[1]->value(trace1, trace2) <<endl;
        return val;
    }

    void display(){
        cout << "(EQL ";
        child[0]->display();
        cout << " ";
        child[1]->display();
        cout<<")";
    }
};

class LEQ : public Formula{
public:

    virtual bool eval(const long* trace1, const long* trace2){
        val = (child[0]->value(trace1, trace2) <= child[1]->value(trace1, trace2));
        // cout << child[0]->value(trace1, trace2) << " " << child[1]->value(trace1, trace2) <<endl;
        return val;
    }

    void display(){
        cout << "(LEQ ";
        child[0]->display();
        cout << " ";
        child[1]->display();
        cout<<")";
    }
};


class GEQ : public Formula{
public:

    virtual bool eval(const long* trace1, const long* trace2){
        val = (child[0]->value(trace1, trace2) >= child[1]->value(trace1, trace2));
        // cout << child[0]->value(trace1, trace2) << " " << child[1]->value(trace1, trace2) <<endl;
        return val;
    }

    void display(){
        cout << "(GEQ ";
        child[0]->display();
        cout << " ";
        child[1]->display();
        cout<<")";
    }
};

class GREATER : public Formula{
public:
    virtual bool eval(const long* trace1, const long* trace2){
        val = (child[0]->value(trace1, trace2) > child[1]->value(trace1, trace2));
        // cout << child[0]->value(trace1, trace2) << " " << child[1]->value(trace1, trace2) <<endl;
        return val;
    }

    void display(){
        cout << "(GEQ ";
        child[0]->display();
        cout << " ";
        child[1]->display();
        cout<<")";
    }
};

class LESS : public Formula{
public:
    virtual bool eval(const long* trace1, const long* trace2){
        val = (child[0]->value(trace1, trace2) < child[1]->value(trace1, trace2));
        return val;
    }

    void display(){
        cout << "(GEQ ";
        child[0]->display();
        cout << " ";
        child[1]->display();
        cout<<")";
    }
};

class EQLARRAY : public Formula{
public:
    int startIndex;
    int endIndex;

    virtual bool eval(const long* trace1, const long* trace2){
        for (size_t i = startIndex; i <= endIndex; i++) {
            if (trace1[i]!=trace2[i]){
                return false;
            }
        }
        return true;
    }
    void display(){
        cout << "(EQLARRAY (";
        cout << startIndex;
        cout << ") (";
        cout << endIndex;
        cout<<"))";
    }
};
// forall: Do we need to implement it ?

Formula* parse(char* f);

#endif
