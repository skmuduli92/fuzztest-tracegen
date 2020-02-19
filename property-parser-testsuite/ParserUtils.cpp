
#include "property_parser.h"

void substring(char* dest, char* src, int start, int finish) {

    int j=0,i;
    for ( i = start; i <= finish; i++) {
        dest[j]=src[i];
        // std::cout << src[i] << endl;
        j++;
    }

    dest[j] = '\0';
    return;
}

void cleanup(void) {
    num_lit = 0;
    tr_lit.clear();
}

Formula* parse(char* f) {

    char* left=NULL;// left side of the operator
    char* right=NULL;// right side of the operator

    char *temp=NULL;// just to store some temperory strings
    char* op=NULL;// operator &, | forall, etc

    Formula* node=NULL;// tree node to be returned

    int count = -1;// counting "(" if property in brackets
    int i,j; // just variable to keep track of indexes
    char *c = f; // c pointer to identify whether  f is literal/ variable(leaf node)
    bool lit = true;// assuming f is literal/variable
    int tr_num; // initial and final index of $ in $op$ respectively
    // std::cout << "parsing " << f << endl;

    assert(tr_lit.size());

    while(*c){
        if(*c == ' '){
            lit = false; // f is not a leaf node
            break;
        }
        c++;
    }

    if(lit) { // if leaf node
        temp = (char*)malloc(strlen(f)-1);
        if(f[2]!='.'){
            substring(temp,f,1,strlen(f)-2);
            if (strcmp(temp,"TRUE")==0){
                TRUE* v = new TRUE();
                node = v;
                return node;
            }
            CONSTANT* const_var = new CONSTANT(stoi(temp));
            node = const_var;
            cout << "constant created "<< f <<endl;
            return node;
        }

        if(f[1]=='1'){
            tr_num=1;
        }else if (f[1]=='2'){
            tr_num=2;
        }else {
            assert(0);
        }

        substring(temp,f,3,strlen(f)-2);

        for ( i = 0; i < num_lit; i++) {
            if (strcmp(temp,tr_lit[i].c_str())==0 && strcmp(tr_lit[i].c_str(),temp)==0){
                VARIABLE* variable = new VARIABLE(i, tr_num);
                node = variable;
                cout << "var created "<< f <<endl;
                return node; // returns leaf node
            }
        }

        assert(0); // unexpected string

    } else if(f[0]=='('){// formula starting with (
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
