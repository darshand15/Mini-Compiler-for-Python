#ifndef test1.hpp
#define test1.hpp

#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <iomanip>
using namespace std;

//node of my_stack
struct my_node
{
    int level_of_indentation; 
    struct my_node *next;
    struct my_node *prev;
};
typedef struct my_node node_t;

//my_stack used to maintain information about the level of indentation
struct my_stack
{
    node_t *head;
    node_t *top;
};
typedef struct my_stack my_stack_t;




//class representing a node or record in the symbol table
class node
{
    private:

        string identifier;
        int line_no;
        string value;
        int scope;
        int column_no;

    public:

        //Constructors
        node();
        node(string identifier, int line_no, string value, int scope, int column_no);
        node(const node &copy_node);
        // node& operator=(const node&) = delete;

        //Getters
        string get_identifier() const;
        int get_line_no() const;
        string get_value() const;
        int get_scope() const;
        int get_column_no() const;

        //Setters
        void set_identifier(string identifier);
        void set_line_no(int line_no);
        void set_value(string value);
        void set_scope(int scope);
        void set_column_no(int column_no);

        //Displays all attributes of class node - overloading the put out operator
        friend ostream& operator<<(ostream& o, const node&);

        //Used for ordering in set
        bool operator<(const node &d) const;

};


// class representing the symbol table
// a separate symbol table is implemented per scope

class symbol_table : public node
{
    vector<vector<unordered_map<string, node> > > tree;

    public:

        //Default constructor
        symbol_table();
        void create_map(int scope);

        //Overloaded insert functions, inserts into the hashmap.
        void insert(string identifier, int line_no, string value, int scope, int column_no);
        void insert(node n1);

        //check if the declaration exists in the current scope or in the higher scopes into which this scope is nested
        int declaration_exists(string identifier, int scope);

        //check if the declaration exists in the current given scope
        int declaration_exists_scope(string identifier, int scope);

        //get the value of the identifier if it exists
        char* identifier_value(string identifier,int scope);

        //update the value of the identifier
        bool update_identifier(string identifier, int scope, string value);

        //Displays based on identifier, and the corresponding sorted line numbers.
        friend ostream& operator<<(ostream& o, const symbol_table&);

};

//function that converts a string vector into a char*
char *conversion(vector<string> vec_s);


//data structure to store the intermediate code in quadruple format
struct quadruple_node
{
    char *op;
    char *arg1;
    char *arg2;
    char *res;
    struct quadruple_node *next;
    struct quadruple_node *prev;
};

typedef struct quadruple_node quadruple_node_t; 

struct quadruple
{
    quadruple_node_t *head;
    quadruple_node_t *top;
};

typedef struct quadruple quadruple_t;

//function to initialize the quadruple
void init_quad(quadruple_t *ptr_quad);

//function to insert a record into the quadruple data structure
void push_quad(quadruple_t *ptr_quad, char *op, char *arg1, char *arg2, char *res);

//function to display the contents of the quadruple data structure
void disp_quad(quadruple_t *ptr_quad, int flag);






#endif