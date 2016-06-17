// $Id: return_node.h,v 1.4 2016/04/06 22:29:31 ist179055 Exp $ -*- c++ -*-
#ifndef __ZU_RETURN_NODE_H__
#define __ZU_RETURN_NODE_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing return ('!!!') nodes.
   */
  class return_node: public cdk::basic_node {

  public:
    inline return_node(int lineno) :
        cdk::basic_node(lineno) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // zu

#endif
