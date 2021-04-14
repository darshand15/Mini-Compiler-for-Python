#include "test1.hpp"
#include <cstdlib>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdio>
using namespace std;

//node of the symbol table
node::node() {}

node::node(string identifier, int line_no, string value, int scope, int column_no)
: identifier(identifier), line_no(line_no), value(value), scope(scope), column_no(column_no) {}

node::node(const node &copy_node)
: identifier(copy_node.identifier), line_no(copy_node.line_no), value(copy_node.value), scope(copy_node.scope), column_no(copy_node.column_no) {} 

//getter functions

string node::get_identifier() const
{
    return identifier;
}

int node::get_line_no() const
{
    return line_no;
}

string node::get_value() const
{
    return value;
}

int node::get_scope() const
{
    return scope;
}

int node::get_column_no() const
{
    return column_no;
}

//setter functions

void node::set_identifier(string identifier)
{
    this->identifier = identifier;
}

void node::set_line_no(int line_no)
{
    this->line_no = line_no;
}

void node::set_value(string value)
{
    this->value = value;
}

void node::set_scope(int scope)
{
    this->scope = scope;
}

void node::set_column_no(int column_no)
{
    this->column_no = column_no;
}

ostream& operator<<(ostream& o, const node& n)
{
    
    o << left << setw(20) << n.identifier;
    o << left << setw(34) << n.value;
    o << left << setw(21) << n.line_no;
    o << left << setw(14) << n.column_no;
    o << left << setw(13) << n.scope;
    
    
    return o << "\n";
}

bool node::operator<(const node& rhs) const
{

    if (this->get_scope() == rhs.get_scope())
        return this->get_line_no() < rhs.get_line_no();

    return this->get_scope() < rhs.get_scope();
}


symbol_table::symbol_table()
{
    vector<unordered_map<string, node>> temp;
    tree.push_back(temp);
    unordered_map<string, node> temp1;
    tree[0].push_back(temp1);
}

void symbol_table::create_map(int scope)
{
    if (scope >= tree.size())
    {
        vector<unordered_map<string, node>> temp;
        tree.push_back(temp);
    }
    unordered_map<string, node> temp1;
    tree[scope].push_back(temp1);
    return;
}


void symbol_table::insert(string identifier, int line_no, string value, int scope, int column_no)
{
    unordered_map<string, node> &temp = tree[scope].back();
    temp[identifier] = node(identifier, line_no, value, scope, column_no);
}

void symbol_table::insert(node n1)
{
    string identifier = n1.get_identifier();
    int scope = n1.get_scope();

    unordered_map<string, node> &temp = tree[scope].back();
    temp[identifier] = n1;
}

ostream& operator<<(ostream& o, const symbol_table& tree_h)
{

    // o << tree_h.tree.size() << "\n\n";
    // tree_h.tree.size(): Max Scope Depth
    for (int i = 0; i < tree_h.tree.size(); ++i)
    {
        // o << "Symbol Table Number: " << i << "\n";

        // o << tree_h.tree[i].size() << "\n\n";
        for (int j = 0; j < tree_h.tree[i].size(); ++j)
        {
            // o << tree_h.tree[i][j].size() << "\n\n";
            o<< "\n\n";
            o << "Symbol Table Number: " << i << "." << j << "\n";
            o << "----------------------------------------------------------------------------------------------------------------" << "\n";
            o << "SNo \t|   Token\t|\t\tValue\t\t|    Line No  \t|\tColumn No\t|\tScope\t\n";
            o << "----------------------------------------------------------------------------------------------------------------" << "\n";
            int k = 0;
            for (auto &it1 : tree_h.tree[i][j])
            {	
                ++k;
                o << left << setw(14) << k;
                o << it1.second;
            }
        }
        o << "\n";
    }
    return o << "\n";
}


int symbol_table::declaration_exists(string identifier, int scope)
{
    int n = scope;
    while (n >= 0)
    {
        unordered_map<string, node> &temp = tree[n].back();
        if (temp.find(identifier) != temp.end())
        {
            return 1;
        }
        n--;
    }
    return 0;
}


bool symbol_table::update_identifier(string identifier, int scope, string value)
{
    int n = scope;
    while (n >= 0)
    {
        unordered_map<string, node> &temp = tree[n].back();
        if (temp.find(identifier) != temp.end())
        {
            temp[identifier].set_value(value);
            return 1;
        }
        n--;
    }
    return 0;
}



int symbol_table::declaration_exists_scope(string identifier, int scope)
{
    
    unordered_map<string, node> &temp = tree[scope].back();
    if (temp.find(identifier) != temp.end())
    {
        return 1;
    }
    return 0;
}

char* symbol_table::identifier_value(string identifier, int scope)
{
    int n = scope;
    while (n >= 0)
    {
        unordered_map<string, node> &temp = tree[n].back();
        if (temp.find(identifier) != temp.end())
        {
            vector <string> temp1{temp[identifier].get_value()};
            return conversion(temp1);
        }
        n--;
    }
    char* temp1= new char[2];
    temp1[0]='0';
    temp1[1]='\0';
    return temp1;
}

char *conversion(vector<string> vec_s)
{
    string temp;
    for (auto &i : vec_s)
    {
        // cout << i << "\n";
        temp = temp + i;
    }

    char *writable = new char[temp.size() + 1];
    std::copy(temp.begin(), temp.end(), writable);
    writable[temp.size()] = '\0'; 
    return writable;
}


//function to initialize the quadruple
void init_quad(quadruple_t *ptr_quad)
{
    ptr_quad->head = NULL;
    ptr_quad->top = NULL;
}

//function to insert a record into the quadruple data structure
void push_quad(quadruple_t *ptr_quad, char *op, char *arg1, char *arg2, char *res)
{
    quadruple_node_t *temp = (quadruple_node_t*)malloc(sizeof(quadruple_node_t));
    temp->op = op;
    temp->arg1 = arg1;
    temp->arg2 = arg2;
    temp->res = res;
    temp->next = NULL;
    temp->prev = NULL;

    //quad data structure is empty
    if(ptr_quad->head == NULL)
    {
        ptr_quad->head = temp;
        ptr_quad->top = temp;
    }

    //quad data structure is not empty
    else
    {
        ptr_quad->top->next = temp;
        temp->prev = ptr_quad->top;
        ptr_quad->top = temp;
    }

}

template<typename T>
void print_elem_quad(T t, const int& width)
{
    const char separator = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

//function to display the contents of the quadruple data structure
void disp_quad(quadruple_t *ptr_quad, int flag)
{
    quadruple_node_t *trav = ptr_quad->head;

    // cout<<"Quadruple form of Intermediate Code:\n\n";
    // cout<<"Operator     Arg 1     Arg 2     Result\n";
    // while(trav!=NULL)
    // {
    //     cout<<trav->op<<"\t     "<<trav->arg1<<"\t       "<<trav->arg2<<"\t         "<<trav->res<<"\n";
    //     trav = trav->next;
    // }
    // cout<<"\n\n";

    if(flag==0)
    {
        freopen("quad_intermediate_code.txt","w",stdout);
    }
    else
    {
        cout<<"Quadruple form of Intermediate Code:\n\n";
        print_elem_quad("Operator",15);
        print_elem_quad("Arg 1",15);
        print_elem_quad("Arg 2",15);
        print_elem_quad("Result",15);
        cout<<"\n\n";
    }
    
    while(trav!=NULL)
    {
        print_elem_quad(trav->op,15);
        print_elem_quad(trav->arg1,15);
        print_elem_quad(trav->arg2,15);
        print_elem_quad(trav->res,15);
        cout<<"\n";
        trav = trav->next;
    }

    if(flag==1)
    {
        cout<<"\n\n";
    }
    


}