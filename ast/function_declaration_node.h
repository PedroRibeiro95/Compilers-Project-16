// $Id: function_declaration_node.h,v 1.8 2016/04/13 20:22:58 ist179055 Exp $ -*- c++ -*-
#ifndef __ZU_FUNCTION_DECLARATION_NODE_H__
#define __ZU_FUNCTION_DECLARATION_NODE_H__

#include <cdk/ast/basic_node.h>
#include <iostream>

namespace zu {

  /**
   * Class for describing function declaration nodes.
   */
  class function_declaration_node: public cdk::basic_node {
    cdk::sequence_node *_arguments;
    basic_type *_returns;
    std::string *_name;
    bool _impOrExp; //boolean to use when function uses import (true) or export (false)
    cdk::expression_node *_returnvl;

  public:
    inline function_declaration_node(int lineno, cdk::sequence_node *arguments, basic_type *returns, std::string *name, bool impOrExp, cdk::expression_node *returnvl) :
        cdk::basic_node(lineno), _arguments(arguments), _returns(returns), _name(name), _impOrExp(impOrExp), _returnvl(returnvl) {
    }

  public:
    /*inline basic_type *ftype() {
      return _ftype;
    }*/
    inline cdk::sequence_node *arguments() {
      return _arguments;
    }
    inline basic_type *returns() {
      return _returns;
    }
    inline std::string *name() {
      return _name;
    }
    inline bool impOrExp(){
      return _impOrExp;
    }
    inline cdk::expression_node *returnvl() {
      return _returnvl;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_declaration_node(this, level);
    }

  };

} // zu

#endif
