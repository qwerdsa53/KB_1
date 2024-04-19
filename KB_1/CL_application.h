#pragma once
#include "CL_base.h"
#include "CL_1.h"
class CL_application: public CL_base {
	public:
		CL_application(CL_base* p_head_obj);
		void build_tree_obj();
		int exec_app();
};

