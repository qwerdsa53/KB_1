#include "CL_application.h"

CL_application::CL_application(CL_base* p_head_obj)
    : CL_base(p_head_obj) {}

int CL_application::exec_app() {
    cout << this->get_name();
    this->print_names();
    return (0);
}

void CL_application::build_tree_obj() {
    CL_base* p_head = this;
    CL_base* p_sub = nullptr;
    string s_head;
    string s_sub;

    cin >> s_head;
    set_name(s_head);

    while (true) {
        cin >> s_head >> s_sub;
        if (s_head == s_sub)
            break;
        if (p_sub != nullptr && s_head == p_sub->get_name()) {
            p_head = p_sub;
        }
        if (p_head->get_sub_obj(s_sub) == nullptr && s_head == p_head->get_name()) {
            p_sub = new CL_1(p_head, s_sub);
        }
    }
}
