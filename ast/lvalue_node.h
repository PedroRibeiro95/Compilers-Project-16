// $Id: lvalue_node.h,v 1.2 2016/03/17 22:25:14 ist179055 Exp $
#ifndef __ZU_NODE_EXPRESSION_LEFTVALUE_H__
#define __ZU_NODE_EXPRESSION_LEFTVALUE_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing syntactic tree leaves for holding lvalues.
   */
  class lvalue_node: public cdk::expression_node {
  public:
    inline lvalue_node(int lineno) :
        cdk::expression_node(lineno) {
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    virtual void accept(basic_ast_visitor *sp, int level) = 0;

  };

} // zu

#endif
