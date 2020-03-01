#ifndef _PROPERTY_PARSER_H_DEFINED_
#define _PROPERTY_PARSER_H_DEFINED_

#include<iostream>
#include<string.h>
#include<assert.h>
#include<vector>

#include "trace.h"

using namespace std;
class VARIABLE;
extern char *tr_lit[];
extern int num_lit;
// to copy substring from index start to finish
void substring(char* dest, char* src, int start, int finish){
  int j=0,i;
  for ( i = start; i <= finish; i++) {
    dest[j]=src[i];
    // std::cout << src[i] << endl;
    j++;
  }
  dest[j] = '\0';
  return;
}


// Class to store tree nodes for the property
class Formula;
class Formula{
public:
  bool val;
  char* op;
  int lit_i;
  vector<Formula*> child;
  // Formula* left;
  // Formula* right;
  virtual char* formula(){
    return op;
  }
  virtual bool eval(long int* temp1, long int* temp2){
    return true;
  }
  virtual int value(long int* temp1, long int* temp2){
    return 0;
  }
  virtual void display(){};

};
// true
class TRUE : public Formula{
public:
  TRUE(){ // constructor
  }
  bool eval(long int* trace1, long int* trace2){
    return true;
  }
  void display(){
    cout << "(TRUE)";
  }
};
// literal or variable e.g. a, b, cxrom_dot_ioadr etc
class CONSTANT : public Formula{ // its child is in right
public:
  long int const_val;
  CONSTANT(int i, int j){
    const_val = i;
  }
  int value(long int* trace1, long int* trace2){
    return const_val;
  }
  void display(){
    cout << "("<<const_val<<")";
  }
};
class VARIABLE : public Formula{ // its child is in right
public:
  int tr_num;
  VARIABLE(int i, int j){
    lit_i = i;
    tr_num = j;
  }
  int value(long int* trace1, long int* trace2){
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
  bool eval(long int* trace1, long int* trace2){
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
  Z(){ // constructor
    old = true;
    res = true;
  }
  bool eval(long int* trace1, long int* trace2){
    res = old;
    old = child[0]->eval(trace1, trace2);
    return res;
  }
  void display(){
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
  bool eval(long int* trace1, long int* trace2){
    past = past?true:child[0]->eval(trace1, trace2);
    return past;
  }
  void display(){
    cout << "(O ";
    child[0]->display();
    cout<<")";
  }
};

class G : public Formula{
public:
  bool past;
  G(){ // constructor
    past = true;
  }
  bool eval(long int* trace1, long int* trace2){
    past = past?child[0]->eval(trace1, trace2):false;
    return past;
  }
  void display(){
    cout << "(G ";
    child[0]->display();
    cout<<")";
  }
};

//Since: aSb is equavalant to baaaaaa
class S : public Formula{
public:
  bool res;
  S(){ // constructor
    res = false;
  }
  bool eval(long int* trace1, long int* trace2){
    if (child[1]->eval(trace1, trace2)){
      res = true;
    }else if(res){
      res = child[0]->eval(trace1, trace2);
    }else{
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
  bool eval(long int* trace1, long int* trace2){
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
class AND : public Formula{
public:
  AND(){ // constructor
  }
  bool eval(long int* trace1, long int* trace2){
    val = child[1]->eval(trace1, trace2) & child[0]->eval(trace1, trace2);
    return val;
  }
  void display(){
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
  OR(){ // constructor
  }
  bool eval(long int* trace1, long int* trace2){
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
  IMPLIES(){ // constructor
  }
  bool eval(long int* trace1, long int* trace2){
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
  EQL(){ // constructor
  }
  bool eval(long int* trace1, long int* trace2){
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
  LEQ(){ // constructor
  }
  bool eval(long int* trace1, long int* trace2){
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
  GEQ(){ // constructor
  }
  bool eval(long int* trace1, long int* trace2){
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
  GREATER(){ // constructor
  }
  bool eval(long int* trace1, long int* trace2){
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
  LESS(){ // constructor
  }
  bool eval(long int* trace1, long int* trace2){
    val = (child[0]->value(trace1, trace2) < child[1]->value(trace1, trace2));
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

class EQLARRAY : public Formula{
public:
  int startIndex;
  int endIndex;
  EQLARRAY(){ // constructor
  }
  bool eval(long int* trace1, long int* trace2){
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


// parses the property or formula and generates Tree
Formula* parse(char* f){
  char* left=NULL;// left side of the operator
  char *temp=NULL;// just to store some temperory strings
  char* op=NULL;// operator &, | forall, etc
  char* right=NULL;// right side of the operator
  Formula* node=NULL;// tree node to be returned
  int count = -1;// counting "(" if property in brackets
  int i = 1,j; // just variable to keep track of indexes
  char *c = f; // c pointer to identify whether  f is literal/ variable(leaf node)
  bool lit = true;// assuming f is literal/variable
  int tr_num; // initial and final index of $ in $op$ respectively
  // std::cout << "parsing " << f << endl;
  while(*c){
    if(*c == ' '){
      lit = false; // f is not a leaf node
      break;
    }
    c++;
  }

  if(lit){ // if leaf node
    temp = (char*)malloc(strlen(f)-1);
    if(f[2]!='.'){
      substring(temp,f,1,strlen(f)-2);
      if (strcmp(temp,"TRUE")==0){
        TRUE* v = new TRUE();
        node = v;
        return node;
      }
      CONSTANT* const_var = new CONSTANT(stoi(temp),0);
      node = const_var;
      cout << "constant created "<< f <<endl;
      return node;
    }
    if(f[1]=='1'){
      tr_num=1;
    }else if (f[1]=='2'){
      tr_num=2;
    }else{
      assert(0);
    }
    substring(temp,f,3,strlen(f)-2);
    for ( i = 0; i < num_lit; i++) {
      if (strcmp(temp,tr_lit[i])==0 && strcmp(tr_lit[i],temp)==0){
        VARIABLE* variable = new VARIABLE(i, tr_num);
        node = variable;
        cout << "var created "<< f <<endl;
        return node; // returns leaf node
      }
    }
    assert(0); // unexpected string
  }else if(f[0]=='('){// formula starting with (
    count = 0;
    for ( i = 1; i < strlen(f); i++) {
      if (f[i]==' '){
        break;
      }else {
        continue;
      }
    }
    op= (char*)malloc(i);
    substring(op,f,1,i-1);
    i++;

    for ( j = i; i < strlen(f); j++) {
      if (f[j]=='('){
        count++;
      }else if(f[j]==')'){
        count--;
      }
      if (count==0){
        break;
      }
      // std::cout << f[i] << " " <<count << endl;
    }
    left = (char*)malloc(j-i+2);  // left node formula for f
    substring(left,f,i,j);
  }
  //if not unary operators
  if((strcmp(op,"G")!=0 & strcmp(op,"NOT")!=0 & strcmp(op,"Y")!=0 & strcmp(op,"Z")!=0 ) ){
    count = 0;
    i = j+2;
    for ( j = i; i < strlen(f); j++) {
      if (f[j]=='('){
        count++;
      }else if(f[j]==')'){
        count--;
      }
      if (count==0){
        break;
      }
      // std::cout << f[i] << " " <<count << endl;
    }
    right = (char*)malloc(j-i+2);  // left node formula for f
    substring(right,f,i,j);
    i++;
  }
// (EQLARRAY (startIndex) (endIndex)) for trace1 and trace2
  if (strcmp(op,"EQLARRAY")==0){
    EQLARRAY* v = new EQLARRAY();
    char *si,*ei;
    si = (char*)malloc(strlen(left)-1);
    ei = (char*)malloc(strlen(right)-1);
    substring(si,left,1,strlen(left)-2);
    substring(ei,right,1,strlen(right)-2);
    v->startIndex = stoi(si);
    v->endIndex = stoi(ei);
    node = v;
    return node;
  }
  if(strcmp(op,"AND")==0){
    AND* v = new AND();
    node = v;
    // cout << left<< " "<< right <<endl;
    node->child.push_back(parse(left));
    node->child.push_back(parse(right));

  }
  if(strcmp(op,"NOT")==0){
    NOT* v = new NOT();
    node = v;
    // cout << left<< " "<< right <<endl;
    node->child.push_back(parse(left));

  }
  if(strcmp(op,"OR")==0){
    OR* v = new OR();
    node = v;
    node->child.push_back(parse(left));
    node->child.push_back(parse(right));
  }
  if(strcmp(op,"IMPLIES")==0){
    IMPLIES* v = new IMPLIES();
    node = v;
    node->child.push_back(parse(left));
    node->child.push_back(parse(right));
  }

  if(strcmp(op,"Y")==0){
    Y* v = new Y();
    node = v;
    node->child.push_back(parse(left));
    // node->child.push_back(parse(right));
  }
  if(strcmp(op,"G")==0){
    G* v = new G();
    node = v;
    node->child.push_back(parse(left));
    // node->child.push_back(parse(right));
  }

  if(strcmp(op,"Z")==0){
    Z* v = new Z();
    node = v;
    node->child.push_back(parse(left));
    // node->child.push_back(parse(right));
  }
  if(strcmp(op,"O")==0){
    O* v = new O();
    node = v;
    node->child.push_back(parse(left));
    // node->child.push_back(parse(right));
  }
  if(strcmp(op,"S")==0){
    S* v = new S();
    node = v;
    node->child.push_back(parse(left));
    node->child.push_back(parse(right));

  }
  if(strcmp(op,"EQL")==0){
    EQL* eql1 = new EQL();
    node = eql1;
    node->child.push_back(parse(left));
    node->child.push_back(parse(right));

  }
  if(strcmp(op,"LEQ")==0){
    LEQ* v = new LEQ();
    node = v;
    node->child.push_back(parse(left));
    node->child.push_back(parse(right));

  }
  if(strcmp(op,"GEQ")==0){
    GEQ* v = new GEQ();
    node = v;
    node->child.push_back(parse(left));
    node->child.push_back(parse(right));

  }
  if(strcmp(op,"GREATER")==0){
    GREATER* v = new GREATER();
    node = v;
    node->child.push_back(parse(left));
    node->child.push_back(parse(right));

  }
  if(strcmp(op,"LESS")==0){
    LESS* v = new LESS();
    node = v;
    node->child.push_back(parse(left));
    node->child.push_back(parse(right));

  }
return node;

}
#endif
