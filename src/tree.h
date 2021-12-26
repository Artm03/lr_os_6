#ifndef _TREE_H
#define _TREE_H

#include <vector>
using namespace std;

class tree_el{
public:
	tree_el* left;
	tree_el* right;
	int value;
	tree_el(int new_val);
	int& get_value();
	tree_el*& get_left();
	tree_el*& get_right();
	friend bool operator<(tree_el& lhs, tree_el& rhs);
	friend bool operator==(tree_el& lhs, tree_el& rhs);
};

class tree {
public:
	tree_el* root;
	void delete_tree(tree_el*& cur);
	bool find_el(tree_el* cur, int val);
	void insert_el(tree_el*& cur, int new_val);
	void delete_el_tree(tree_el*& cur, int val);
	int get_parent(tree_el*& cur, int val);
	void get_all(tree_el* cur, vector<int>& tmp);
	tree();
	tree(int new_val);
	void insert(int new_val);
	bool find(int val);
	void delete_el(int val);
	int get_place(int val);
	vector<int> get_all_elems();
	~tree();
};

#endif