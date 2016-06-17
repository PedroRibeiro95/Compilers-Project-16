// $Id: memory_reservation_node.h,v 1.3 2016/04/15 02:54:59 ist179055 Exp $ -*- c++ -*-
#ifndef __ZU_MEMORY_RESERVATION_NODE_H__
#define __ZU_MEMORY_RESERVATION_NODE_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing memory reservation ('[]') nodes.
   */
  class memory_reservation_node: public cdk::expression_node {
  private:
      cdk::expression_node *_argument;

  public:
    inline memory_reservation_node(int lineno, cdk::expression_node *argument) :
        cdk::expression_node(lineno), _argument(argument) {
    }

  public:

    inline cdk::expression_node *argument(){
    
        return _argument;
    }
      
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_memory_reservation_node(this, level);
    }

  };

} // zu

#endif
