// $Id: calculate_size.cpp,v 1.2 2016/05/16 12:44:05 ist179055 Exp $ -*- c++ -*-
#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/calculate_size.h"
#include "ast/all.h"  // all.h is automatically generated

//---------------------------------------------------------------------------
//     THIS IS THE VISITOR'S DEFINITION
//---------------------------------------------------------------------------

int zu::calculate_size::getSize() {
    return _size;
}

void zu::calculate_size::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_integer_node(cdk::integer_node * const node, int lvl) {
    _size+=4;
}

void zu::calculate_size::do_string_node(cdk::string_node * const node, int lvl) {
    _size+=8;
}

void zu::calculate_size::do_double_node(cdk::double_node * const node, int lvl) {
    _size+=8;
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_neg_node(cdk::neg_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_add_node(cdk::add_node * const node, int lvl) {
}
void zu::calculate_size::do_sub_node(cdk::sub_node * const node, int lvl) {
}
void zu::calculate_size::do_mul_node(cdk::mul_node * const node, int lvl) {
}
void zu::calculate_size::do_div_node(cdk::div_node * const node, int lvl) {
}
void zu::calculate_size::do_mod_node(cdk::mod_node * const node, int lvl) {
}
void zu::calculate_size::do_lt_node(cdk::lt_node * const node, int lvl) {
}
void zu::calculate_size::do_le_node(cdk::le_node * const node, int lvl) {
}
void zu::calculate_size::do_ge_node(cdk::ge_node * const node, int lvl) {
}
void zu::calculate_size::do_gt_node(cdk::gt_node * const node, int lvl) {
}
void zu::calculate_size::do_ne_node(cdk::ne_node * const node, int lvl) {
}
void zu::calculate_size::do_eq_node(cdk::eq_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_and_node(zu::and_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_position_indicator_node(zu::position_indicator_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_memory_reservation_node(zu::memory_reservation_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_or_node(zu::or_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_rvalue_node(zu::rvalue_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_lvalue_node(zu::lvalue_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_identifier_node(zu::identifier_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_index_node(zu::index_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_assignment_node(zu::assignment_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_function_call_node(zu::function_call_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_declaration_node(zu::declaration_node * const node, int lvl) {
    node->returnvl()->accept(this, lvl+2);
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_function_declaration_node(zu::function_declaration_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_function_definition_node(zu::function_definition_node * const node, int lvl) {
    if(node->body()) node->body()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_evaluation_node(zu::evaluation_node * const node, int lvl) {
}

void zu::calculate_size::do_print_node(zu::print_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_return_node(zu::return_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_identity_node(zu::identity_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_simetric_node(zu::simetric_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_block_node(zu::block_node * const node, int lvl) {
    if(node->declarations()) node->declarations()->accept(this, lvl + 2);
    if(node->instructions()) node->instructions()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_read_node(zu::read_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_for_node(zu::for_node * const node, int lvl) {
    if(node->init()) node->init()->accept(this, lvl + 2);
    node->instruction()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_break_node(zu::break_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_continue_node(zu::continue_node * const node, int lvl) {
}
  
//---------------------------------------------------------------------------

void zu::calculate_size::do_if_node(zu::if_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::calculate_size::do_if_else_node(zu::if_else_node * const node, int lvl) {
}