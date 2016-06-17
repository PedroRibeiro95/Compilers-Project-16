// $Id: index_node.h,v 1.1 2016/03/17 22:25:14 ist179055 Exp $
#ifndef __ZU_INDEX_NODE_H__
#define __ZU_INDEX_NODE_H__

#include "lvalue_node.h"

namespace zu {

  /**
   * Class for describing syntactic tree leaves for holding lvalues without identifiers.
   */
  class index_node: public lvalue_node {
  private:
      cdk::expression_node *_index;
      cdk::expression_node *_value;
  
  public:
    inline index_node(int lineno, cdk::expression_node *index, cdk::expression_node *value) :
        lvalue_node(lineno), _index(index), _value(value) {
    }
    
    inline cdk::expression_node *index(){
        return _index;
    }
    inline cdk::expression_node *value(){
        return _value;
    }
    
    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    virtual void accept(basic_ast_visitor *sp, int level){
        sp->do_index_node(this, level);
    }
  };

} // zu

#endif
