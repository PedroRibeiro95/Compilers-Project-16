// $Id: simetric_node.h,v 1.1 2016/03/17 17:41:44 ist179055 Exp $ -*- c++ -*-
#ifndef __ZU_SIMETRIC_NODE_H__
#define __ZU_SIMETRIC_NODE_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing simetric ('-') nodes.
   */
  class simetric_node: public cdk::unary_expression_node {

  public:
    inline simetric_node(int lineno, cdk::expression_node *argument) :
        cdk::unary_expression_node(lineno, argument) {
    }

  public:

    //Getter implemented in unary_expression_node class!!
      
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_simetric_node(this, level);
    }

  };

} // zu

#endif
