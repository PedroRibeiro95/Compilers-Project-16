// $Id: type_checker.cpp,v 1.30 2016/05/20 01:24:41 ist179055 Exp $ -*- c++ -*-
#include <string>
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

#define ASSERT_UNSPEC \
    { if (node->type() != nullptr && \
          node->type()->name() != basic_type::TYPE_UNSPEC) return; }

//---------------------------------------------------------------------------

void zu::type_checker::do_integer_node(cdk::integer_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void zu::type_checker::do_string_node(cdk::string_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_STRING));
}

void zu::type_checker::do_double_node(cdk::double_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_DOUBLE));
}

void zu::type_checker::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

inline void zu::type_checker::processUnaryExpression(cdk::unary_expression_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in argument of unary expression");

  // in Zu, expressions are always int
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void zu::type_checker::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->argument()->accept(this, lvl + 2);
  
  if(node->argument()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(4, basic_type::TYPE_INT));
  }
  else if(node->argument()->type()->name() == basic_type::TYPE_DOUBLE ) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
}

//---------------------------------------------------------------------------

inline void zu::type_checker::processBinaryExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  //if(node->left()->type() != nullptr){ //FIXME terrible hack!
    node->left()->accept(this, lvl + 2);
    if (node->left()->type()->name() != basic_type::TYPE_INT)
        throw std::string("wrong type in left argument of binary expression");
  //}
  
  //if(node->right()->type() != nullptr){ //FIXME terrible hack!
    node->right()->accept(this, lvl + 2);
    if (node->right()->type()->name() != basic_type::TYPE_INT)
        throw std::string("wrong type in right argument of binary expression");
  //}

  // in Zu, expressions are always int
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void zu::type_checker::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  
  if(node->left()->type()->name() == basic_type::TYPE_INT &&
      node->right()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(4, basic_type::TYPE_INT));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_DOUBLE &&
      node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_INT &&
      node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_DOUBLE &&
      node->right()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_POINTER &&
      node->right()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(4, basic_type::TYPE_POINTER));
  }
  else { std::cerr << "unsupported types for add" << std::endl; }
}
void zu::type_checker::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  
  if(node->left()->type()->name() == basic_type::TYPE_INT &&
      node->right()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(4, basic_type::TYPE_INT));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_DOUBLE &&
      node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_INT &&
      node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_DOUBLE &&
      node->right()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else { std::cerr << "unsupported types for sub" << std::endl; }
}
void zu::type_checker::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  
  if(node->left()->type()->name() == basic_type::TYPE_INT &&
      node->right()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(4, basic_type::TYPE_INT));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_DOUBLE &&
      node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_INT &&
      node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_DOUBLE &&
      node->right()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else { std::cerr << "unsupported types for mul" << std::endl; }
}
void zu::type_checker::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  
  if(node->left()->type()->name() == basic_type::TYPE_INT &&
      node->right()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(4, basic_type::TYPE_INT));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_DOUBLE &&
      node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_INT &&
      node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else if(node->left()->type()->name() == basic_type::TYPE_DOUBLE &&
      node->right()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
  else { std::cerr << "unsupported types for div" << std::endl; }
}
void zu::type_checker::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  
  if(node->left()->type()->name() == basic_type::TYPE_INT &&
      node->right()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(4, basic_type::TYPE_INT));
  }
}
void zu::type_checker::do_lt_node(cdk::lt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::type_checker::do_le_node(cdk::le_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::type_checker::do_ge_node(cdk::ge_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::type_checker::do_gt_node(cdk::gt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::type_checker::do_ne_node(cdk::ne_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::type_checker::do_eq_node(cdk::eq_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void zu::type_checker::do_and_node(zu::and_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void zu::type_checker::do_position_indicator_node(zu::position_indicator_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void zu::type_checker::do_memory_reservation_node(zu::memory_reservation_node * const node, int lvl) {
  if(node->argument()->type()->name() != basic_type::TYPE_INT){
      throw std::string("wrong type for memory reservation expression");  
  }
}

//---------------------------------------------------------------------------

void zu::type_checker::do_or_node(zu::or_node * const node, int lvl) {
  processBinaryExpression(node, lvl); //FIXME
}

//---------------------------------------------------------------------------

void zu::type_checker::do_rvalue_node(zu::rvalue_node * const node, int lvl) {
  
  node->lvalue()->accept(this, lvl + 2);
  node->type(node->lvalue()->type());
  
}



//---------------------------------------------------------------------------

void zu::type_checker::do_identifier_node(zu::identifier_node * const node, int lvl) {
  
  std::shared_ptr<zu::symbol> symbol = _symtab.find(*node->identifier());
  node->type(symbol.get()->type());
}

//---------------------------------------------------------------------------

void zu::type_checker::do_index_node(zu::index_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->index()->accept(this, lvl + 2);
  
  node->value()->accept(this, lvl + 2);
  if(node->value()->type()->name() != basic_type::TYPE_INT){
      std::cerr << "wrong type for index" << std::endl;  
  }
  node->type(new basic_type(4, basic_type::TYPE_POINTER));
}

//---------------------------------------------------------------------------

void zu::type_checker::do_assignment_node(zu::assignment_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->rvalue()->accept(this, lvl + 2);
  node->lvalue()->accept(this, lvl + 2);

  if((node->lvalue()->type()->name() == node->rvalue()->type()->name()) ||
     (node->lvalue()->type()->name() == basic_type::TYPE_DOUBLE &&
      node->rvalue()->type()->name() == basic_type::TYPE_INT))
    node->type(new basic_type(node->lvalue()->type()->size(), node->lvalue()->type()->name()));
  else
    throw std::string("unsupported types for assignment");
}

//---------------------------------------------------------------------------

void zu::type_checker::do_evaluation_node(zu::evaluation_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void zu::type_checker::do_print_node(zu::print_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void zu::type_checker::do_return_node(zu::return_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::type_checker::do_identity_node(zu::identity_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->argument()->accept(this, lvl + 2);
  
  if(node->argument()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(4, basic_type::TYPE_INT));
  }
  else if(node->argument()->type()->name() == basic_type::TYPE_DOUBLE ) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
}

//---------------------------------------------------------------------------

void zu::type_checker::do_simetric_node(zu::simetric_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->argument()->accept(this, lvl + 2);
  
  if(node->argument()->type()->name() == basic_type::TYPE_INT) {
      node->type(new basic_type(4, basic_type::TYPE_INT));
  }
  else if(node->argument()->type()->name() == basic_type::TYPE_DOUBLE ) {
      node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  }
}


//---------------------------------------------------------------------------

void zu::type_checker::do_block_node(zu::block_node * const node, int lvl) { 
}

//---------------------------------------------------------------------------

void zu::type_checker::do_read_node(zu::read_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  if(node->type()->name() == basic_type::TYPE_INT)
     node->type(new basic_type(4, basic_type::TYPE_INT));
  else if(node->type()->name() == basic_type::TYPE_DOUBLE)
     node->type(new basic_type(8, basic_type::TYPE_DOUBLE)); 
  else
     std::cerr << "wrong type for read expression" << std::endl;
}

//---------------------------------------------------------------------------

void zu::type_checker::do_for_node(zu::for_node * const node, int lvl) {
}


//---------------------------------------------------------------------------

void zu::type_checker::do_break_node(zu::break_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::type_checker::do_continue_node(zu::continue_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::type_checker::do_if_node(zu::if_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::type_checker::do_if_else_node(zu::if_else_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::type_checker::do_function_call_node(zu::function_call_node * const node, int lvl) {
  //FIXME CONFIRM THIS WITH TEACHER ASAP!!!!
    
  std::shared_ptr<zu::symbol> symbol = _symtab.find(*node->name());
  if (!symbol) throw *node->name() + " undeclared";
 
  node->type(new basic_type(symbol.get()->type()->size(), symbol.get()->type()->name()));
  
  if(node->arguments())
    node->arguments()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void zu::type_checker::do_function_declaration_node(zu::function_declaration_node * const node, int lvl) {
  
}

//---------------------------------------------------------------------------

void zu::type_checker::do_function_definition_node(zu::function_definition_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void zu::type_checker::do_declaration_node(zu::declaration_node * const node, int lvl) {
}