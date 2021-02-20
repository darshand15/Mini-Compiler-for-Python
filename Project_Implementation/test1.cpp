#include "test1.hpp"
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
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
    o << left << setw(13) << n.identifier;
    o << left << setw(12) << n.value;
    o << left << setw(13) << n.line_no;
    o << left << setw(15) << n.column_no;
    o << left << setw(12) << n.scope;
    
    
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
            o << "Symbol Table Number: " << i << "." << j << "\n";
            o << "---------------------------------------------------------------------------------------------------" << "\n";
            o << "SNo \t|\tToken \t|\tValue\t|\tLine No\t|\tColumn No\t|\tScope\t\n";
            o << "---------------------------------------------------------------------------------------------------" << "\n";
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
        temp += i;
    }

    char *writable = new char[temp.size() + 1];
    std::copy(temp.begin(), temp.end(), writable);
    writable[temp.size()] = '\0'; 
    return writable;
}