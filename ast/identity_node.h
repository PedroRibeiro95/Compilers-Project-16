// $Id: identity_node.h,v 1.1 2016/03/17 17:41:44 ist179055 Exp $ -*- c++ -*-
#ifndef __ZU_IDENTITY_NODE_H__
#define __ZU_IDENTITY_NODE_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing return ('+') nodes.
   */
  class identity_node: public cdk::unary_expression_node {

  public:
    inline identity_node(int lineno, cdk::expression_node *argument) :
        cdk::unary_expression_node(lineno, argument) {
    }

  public:

    //Getter implemented in unary_expression_node class!!
      
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_identity_node(this, level);
    }

  };

} // zu

#endif
