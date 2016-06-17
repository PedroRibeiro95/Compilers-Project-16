// $Id: declaration_node.h,v 1.2 2016/04/15 04:43:19 ist179055 Exp $ -*- c++ -*-
#ifndef __ZU_DECLARATION_NODE_H__
#define __ZU_DECLARATION_NODE_H__

#include <cdk/ast/basic_node.h>
#include <iostream>

namespace zu {

  /**
   * Class for describing function declaration nodes.
   */
  class declaration_node: public cdk::basic_node {
    basic_type *_returns;
    std::string *_name;
    bool _extOrNot; //boolean to use when variable is external (true) or not (false)
    cdk::expression_node *_returnvl;
    bool _privOrPub;

  public:
    inline declaration_node(int lineno, basic_type *returns, std::string *name, bool extOrNot, cdk::expression_node *returnvl, bool privOrPub) :
        cdk::basic_node(lineno), _returns(returns), _name(name), _extOrNot(extOrNot), _returnvl(returnvl), _privOrPub(privOrPub) {
    }

  public:
    /*inline basic_type *ftype() {
      return _ftype;
    }*/
    inline basic_type *returns() {
      return _returns;
    }
    inline std::string *name() {
      return _name;
    }
    inline bool extOrNot(){
      return _extOrNot;
    }
    inline cdk::expression_node *returnvl() {
      return _returnvl;
    }
    inline bool privOrPub(){
      return _privOrPub;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_declaration_node(this, level);
    }

  };

} // zu

#endif
