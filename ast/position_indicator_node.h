// $Id: position_indicator_node.h,v 1.1 2016/03/17 23:04:36 ist179055 Exp $ -*- c++ -*-
#ifndef __ZU_POSITION_INDICATOR_NODE_H__
#define __ZU_POSITION_INDICATOR_NODE_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing reference ('?') nodes.
   */
  class position_indicator_node: public cdk::expression_node {
  private:
      cdk::expression_node *_argument;

  public:
    inline position_indicator_node(int lineno, lvalue_node *argument) :
        cdk::expression_node(lineno), _argument(argument) {
    }

  public:

    inline cdk::expression_node *argument(){
    
        return _argument;
    }
      
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_position_indicator_node(this, level);
    }

  };

} // zu

#endif
