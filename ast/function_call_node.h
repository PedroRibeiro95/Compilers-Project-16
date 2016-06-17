// $Id: function_call_node.h,v 1.1 2016/03/16 21:57:24 ist179055 Exp $ -*- c++ -*-
#ifndef __ZU_FUNCTION_CALL_NODE_H__
#define __ZU_FUNCTION_CALLNODE_H__

#include <cdk/ast/basic_node.h>
#include <iostream>

namespace zu {

  /**
   * Class for describing program nodes.
   */
  class function_call_node: public cdk::expression_node {
    cdk::sequence_node *_arguments;
    std::string *_name;

  public:
    inline function_call_node(int lineno, cdk::sequence_node *arguments, std::string *name) :
        cdk::expression_node(lineno), _arguments(arguments), _name(name) {
    }

  public:
    inline cdk::sequence_node *arguments() {
      return _arguments;
    }
    inline std::string *name() {
      return _name;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // zu

#endif
