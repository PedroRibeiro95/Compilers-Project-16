// $Id: xml_writer.cpp,v 1.20 2016/05/20 01:24:41 ist179055 Exp $ -*- c++ -*-
#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

//---------------------------------------------------------------------------

void zu::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  openTag("int", lvl);
  os() << node->value() <<  std::endl;
  closeTag("int", lvl);
}

void zu::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  openTag("string", lvl);
  os() << node->value() << std::endl;
  closeTag("string", lvl);
}

void zu::xml_writer::do_double_node(cdk::double_node * const node, int lvl) {
  openTag("double", lvl);
  os() << node->value() <<  std::endl;
  closeTag("double", lvl);
}

//---------------------------------------------------------------------------

inline void zu::xml_writer::processUnaryExpression(cdk::unary_expression_node * const node, int lvl) {
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

inline void zu::xml_writer::processBinaryExpression(cdk::binary_expression_node * const node, int lvl) {
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_break_node(zu::break_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_continue_node(zu::continue_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_and_node(zu::and_node * const node, int lvl) {
  processBinaryExpression(node, lvl); //FIXME
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_position_indicator_node(zu::position_indicator_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("argument", lvl + 2);
  node->argument()->accept(this, lvl + 4);
  closeTag("argument", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_memory_reservation_node(zu::memory_reservation_node * const node, int lvl) {
  openTag(node, lvl);openTag("argument", lvl + 2);
  node->argument()->accept(this, lvl + 4);
  closeTag("argument", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_or_node(zu::or_node * const node, int lvl) {
  processBinaryExpression(node, lvl); //FIXME
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_rvalue_node(zu::rvalue_node * const node, int lvl) {
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_identifier_node(zu::identifier_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("name", lvl + 2);
  std::string *identifier = node->identifier();
  os() << *identifier << std::endl;
  closeTag("name", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_index_node(zu::index_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("index", lvl + 2);
  node->index()->accept(this, lvl + 4);
  closeTag("index", lvl + 2);
  openTag("value", lvl + 2);
  node->value()->accept(this, lvl + 4);
  closeTag("value", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_assignment_node(zu::assignment_node * const node, int lvl) {
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 2);
  openTag("rvalue", lvl + 2);
  node->rvalue()->accept(this, lvl + 4);
  closeTag("rvalue", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_function_call_node(zu::function_call_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("name", lvl + 2);
  std::string *name = node->name();
  os() << *name << std::endl;
  closeTag("name", lvl + 2);
  if(node->arguments() != nullptr){
    openTag("arguments", lvl + 2);
    node->arguments()->accept(this, lvl + 4);
    closeTag("arguments", lvl + 2);
  }
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_declaration_node(zu::declaration_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("returns", lvl + 2);
  if(node->returns()->name() == basic_type::TYPE_INT) { os() << "int" << std::endl; }
  if(node->returns()->name() == basic_type::TYPE_DOUBLE) { os() << "double" << std::endl; }
  if(node->returns()->name() == basic_type::TYPE_STRING) { os() << "string" << std::endl; }
  if(node->returns()->name() == basic_type::TYPE_VOID) { os() << "void" << std::endl; }
  closeTag("returns", lvl + 2);
  
  openTag("name", lvl + 2);
  std::string *name = node->name();
  os() << *name << std::endl;
  closeTag("name", lvl + 2);
  
  openTag("returnvl", lvl + 2);
  if(node->returnvl() != nullptr){
    node->returnvl()->accept(this, lvl + 4);
  }
  closeTag("returnvl", lvl + 2);
  
  openTag("extOrNot", lvl + 2);
  if(node->extOrNot()){
     os() << "external" << std::endl;
  }
  else{
     os() << "not external" << std::endl;
  }
  closeTag("extOrNot", lvl + 2);
  
  openTag("privOrPub", lvl + 2);
  if(node->privOrPub()){
     os() << "public" << std::endl;
  }
  else{
     os() << "private" << std::endl;
  }
  closeTag("privOrPub", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_function_declaration_node(zu::function_declaration_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("returns", lvl + 2);
  if(node->returns()->name() == basic_type::TYPE_INT) { os() << "int" << std::endl; }
  if(node->returns()->name() == basic_type::TYPE_DOUBLE) { os() << "double" << std::endl; }
  if(node->returns()->name() == basic_type::TYPE_STRING) { os() << "string" << std::endl; }
  if(node->returns()->name() == basic_type::TYPE_VOID) { os() << "void" << std::endl; }
  closeTag("returns", lvl + 2);
  
  openTag("name", lvl + 2);
  std::string *name = node->name();
  os() << *name << std::endl;
  closeTag("name", lvl + 2);
  
  openTag("returnvl", lvl + 2);
  if(node->returnvl() != nullptr){
    node->returnvl()->accept(this, lvl + 4);
  }
  closeTag("returnvl", lvl + 2);
  
  openTag("impOrExp", lvl + 2);
  if(node->impOrExp()){
     os() << "export" << std::endl;
  }
  else{
     os() << "import" << std::endl;
  }
  closeTag("impOrExp", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_function_definition_node(zu::function_definition_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("returns", lvl + 2);
  if(node->returns()->name() == basic_type::TYPE_INT) { os() << "int" << std::endl; }
  if(node->returns()->name() == basic_type::TYPE_DOUBLE) { os() << "double" << std::endl; }
  if(node->returns()->name() == basic_type::TYPE_STRING) { os() << "string" << std::endl; }
  if(node->returns()->name() == basic_type::TYPE_VOID) { os() << "void" << std::endl; }
  closeTag("returns", lvl + 2);
  
  openTag("name", lvl + 2);
  std::string *name = node->name();
  os() << *name << std::endl;
  closeTag("name", lvl + 2);
  
  openTag("arguments", lvl + 2);
  if(node->arguments() != nullptr){
    node->arguments()->accept(this, lvl + 4);
  }
  closeTag("arguments", lvl + 2);
  
  openTag("impOrExp", lvl + 2);
  if(node->impOrExp()){
     os() << "export" << std::endl;
  }
  else{
     os() << "import" << std::endl;
  }
  closeTag("impOrExp", lvl + 2);
  
  openTag("body", lvl + 2);
  node->body()->accept(this, lvl + 4);
  closeTag("body", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_evaluation_node(zu::evaluation_node * const node, int lvl) {
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_print_node(zu::print_node * const node, int lvl) {
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_return_node(zu::return_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_identity_node(zu::identity_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_simetric_node(zu::simetric_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_block_node(zu::block_node * const node, int lvl) {
  openTag(node, lvl);
  
  openTag("declarations", lvl + 2);
  if(node->declarations() != nullptr){
    node->declarations()->accept(this, lvl + 4);
  }
  closeTag("declarations", lvl + 2);
  
  openTag("instructions", lvl + 2);
  if(node->instructions() != nullptr){
    node->instructions()->accept(this, lvl + 4);
  }
  closeTag("instructions", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_read_node(zu::read_node * const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_for_node(zu::for_node * const node, int lvl) {
  openTag(node, lvl);
  
  openTag("init", lvl + 2);
  if(node->init() != nullptr){
    node->init()->accept(this, lvl + 4);
  }
  closeTag("init", lvl + 2);
  
  openTag("condition", lvl + 2);
  if(node->condition() != nullptr){
    node->condition()->accept(this, lvl + 4);
  }
  closeTag("condition", lvl + 2);
  
  openTag("incr", lvl + 2);
  if(node->incr() != nullptr){
    node->incr()->accept(this, lvl + 4);
  }
  closeTag("incr", lvl + 2);
  
  openTag("instruction", lvl + 2);
  node->instruction()->accept(this, lvl + 4);
  closeTag("instruction", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_if_node(zu::if_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_if_else_node(zu::if_else_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  
  openTag("else", lvl + 2);
  if(node->elseblock() != nullptr){
    node->elseblock()->accept(this, lvl + 4);
  }
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}
