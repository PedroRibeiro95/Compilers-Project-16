// $Id: break_node.h,v 1.2 2016/03/17 16:49:58 ist179055 Exp $ -*- c++ -*-
#ifndef ______BREAKNODE_H__
#define ______BREAKNODE_H__

#include <cdk/ast/basic_node.h>

namespace zu {

  /**
   * Class for describing break ('><') nodes.
   */
  class break_node: public cdk::basic_node {

  public:
    inline break_node(int lineno) :
        basic_node(lineno) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_break_node(this, level);
    }

  };

} // zu

#endif
