#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <stack>	
#include "bp.hpp"
#define YYSTYPE Node*


using namespace std;

class Node{
	public:
		string type;
		
		// HW5 
		
		int reg;
		string label;
		vector<int> next_list;
		vector<int> true_list;
		vector<int> false_list;
		vector<int> break_list;
		vector<int> continue_list;

		
		Node(string type) : type(type), reg(), label(), next_list(), true_list(), false_list(), continue_list(){}
		
		virtual ~Node(){}

};

class Value_node : public Node{
	public:
		string value;
		
		Value_node(string type, string value) : Node(type), value(value) {}
};

class Exp_list : public Node{
	public:
	vector<string>* types;
	vector<int>* places;
	
	Exp_list(string type, int place) : Node("EXP_LIST"){
		types = new vector<string>();
		places = new vector<int>();
		types->push_back(type);
		places->push_back(place);
	}
	
	Exp_list() : Node("EXP_LIST"){
		types = new vector<string>();
		places = new vector<int>();
	}
};

class Mem_list : public Node{
	public:
	vector<string>* types;
	vector<string>* names;
	
	Mem_list(string type, string name) : Node("MEM_LIST"){
		types = new vector<string>();
		names = new vector<string>();
		types->push_back(type);
		names->push_back(name);
	}
	
	Mem_list(vector<string>* _types, vector<string>* _names): Node("MEM_LIST"){
		types = new vector<string>(*_types);
		names = new vector<string>(*_names);		
	}
	
};


class Info {
	public:
		string name;
		string type;
		int offset;
		vector<string>* arg_types; 
		vector< pair <string, string> >* struct_fields; // first - type, second - name;
		int symbol_index;
		
		Info() {};
		Info(string name, string type, int offset,vector<string>* arg_types,vector< pair <string, string> >* struct_fields) :
		name(name), type(type), offset(offset), arg_types(arg_types), struct_fields(struct_fields), symbol_index(0){}
		
		~Info () {
			delete arg_types;
			delete struct_fields;
		}
}
;

typedef vector<Info*> SymbolTable;
