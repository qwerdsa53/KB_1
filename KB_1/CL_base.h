#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class CL_base
{
	string s_name;
	CL_base* p_head_obj;
	vector<CL_base*> p_sub_obj;
public:
	CL_base(CL_base* p_head_obj, string s_name = "Base object");
	bool set_name(string s_new_name);
	string get_name();
	CL_base* get_head();
	void print_names();
	CL_base* get_sub_obj(string s_name);
	~CL_base();
};