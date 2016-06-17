// $Id: continue_node.h,v 1.2 2016/03/17 16:49:58 ist179055 Exp $ -*- c++ -*-
#ifndef ______CONTINUENODE_H__
#define ______CONTINUENODE_H__

#include <cdk/ast/basic_node.h>

namespace zu {

  /**
   * Class for describing continue ('<>') nodes.
   */
  class continue_node: public cdk::basic_node {

  public:
    inline continue_node(int lineno) :
        basic_node(lineno) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_continue_node(this, level);
    }

  };

} // zu

#endif
