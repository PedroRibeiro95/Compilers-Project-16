// $Id: identifier_node.h,v 1.5 2016/04/14 13:17:16 ist179055 Exp $
#ifndef __ZU_IDENTIFIER_NODE_H__
#define __ZU_IDENTIFIER_NODE_H__

#include <string>
#include "lvalue_node.h"

namespace zu {

  /**
   * Class for describing syntactic tree leaves for holding lvalues with identifiers.
   */
  class identifier_node: public lvalue_node {
  private:
      std::string *_identifier;
  
  public:
    inline identifier_node(int lineno, std::string *identifier) :
        lvalue_node(lineno), _identifier(identifier) {
            type(new basic_type(4, basic_type::TYPE_INT));
    }
    
    inline std::string *identifier(){
        return _identifier;
    }
    
    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level){
        sp->do_identifier_node(this, level);
    }
  };

} // zu

#endif
