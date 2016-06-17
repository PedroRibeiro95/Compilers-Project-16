// $Id: function_definition_node.h,v 1.4 2016/05/15 22:52:04 ist179055 Exp $ -*- c++ -*-
#ifndef __ZU_FUNCTION_DEFINITION_NODE_H__
#define __ZU_FUNCTION_DEFINITION_NODE_H__

#include <cdk/ast/basic_node.h>
#include <iostream>

namespace zu {

  /**
   * Class for describing function definition nodes.
   */
  class function_definition_node: public cdk::basic_node {
    cdk::sequence_node *_arguments;
    basic_type *_returns;
    std::string *_name;
    block_node *_body;
    bool _impOrExp;
    cdk::expression_node *_returnvl;

  public:
    inline function_definition_node(int lineno, cdk::sequence_node *arguments, basic_type *returns, std::string *name, block_node *body, bool impOrExp, cdk::expression_node *returnvl) :
        cdk::basic_node(lineno), _arguments(arguments), _returns(returns), _name(name), _body(body), _impOrExp(impOrExp), _returnvl(returnvl) {
    }

  public:
    inline cdk::sequence_node *arguments() {
      return _arguments;
    }
    inline basic_type *returns() {
      return _returns;
    }
    inline std::string *name() {
      return _name;
    }
    inline block_node *body() {
      return _body;
    }
    inline bool impOrExp() {
      return _impOrExp;
    }
    inline cdk::expression_node *returnvl() {
      return _returnvl;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // zu

#endif

