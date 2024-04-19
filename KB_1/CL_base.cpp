#include "CL_base.h"
#include "string"
#include "iostream"
#include "vector"

CL_base::CL_base(CL_base* p_head_obj, string s_name)
    : p_head_obj(p_head_obj), s_name(s_name) {
    if (p_head_obj != nullptr)
        p_head_obj->p_sub_obj.push_back(this);
}

CL_base::~CL_base() {
    for (int i = 0; i < p_sub_obj.size(); i++)
        delete p_sub_obj[i];
}

string CL_base::get_name() {
    return s_name;
}

CL_base* CL_base::get_head() {
    return p_head_obj;
}

bool CL_base::set_name(string name) {
    if (p_head_obj != nullptr) {
        for (auto obj : p_head_obj->p_sub_obj)
            if (obj->get_name() == name) {
                return false;
            }
    }
    this->s_name = name;
    return true;
}

CL_base* CL_base::get_sub_obj(string name) {
    for (auto p_sub : p_sub_obj) {
        if (name == p_sub->get_name())
            return p_sub;
    }
    return nullptr;
}

void CL_base::print_names() {
    if (p_sub_obj.size() != 0) {
        cout << endl << s_name;
        for (auto obj : p_sub_obj) {
            cout << "  " << obj->get_name();
            obj->print_names();
        }
    }
}
