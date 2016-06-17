// $Id: postfix_writer.cpp,v 1.38 2016/05/20 01:24:41 ist179055 Exp $ -*- c++ -*-
#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "targets/calculate_size.h"
#include "ast/all.h"  // all.h is automatically generated

//---------------------------------------------------------------------------
//     THIS IS THE VISITOR'S DEFINITION
//---------------------------------------------------------------------------

void zu::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  _pf.INT(node->value()); // push an integer
}

void zu::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.STR(node->value()); // output string characters

  /* leave the address on the stack */
  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
}

void zu::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
  _pf.DOUBLE(node->value());
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value
  _pf.NEG(); // 2-complement
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->left()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE && 
      node->left()->type()->name() == basic_type::TYPE_INT)
      _pf.I2D();
  
  node->right()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE && 
      node->right()->type()->name() == basic_type::TYPE_INT)
      _pf.I2D();
  
  //FIXME POINTERS
  if(node->type()->name() == basic_type::TYPE_DOUBLE) {
      _pf.DADD();
  }
  else { _pf.ADD(); }
}
void zu::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->left()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE && 
      node->left()->type()->name() == basic_type::TYPE_INT)
      _pf.I2D();
  
  node->right()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE && 
      node->left()->type()->name() == basic_type::TYPE_INT)
      _pf.I2D();
  
  if(node->type()->name() == basic_type::TYPE_DOUBLE) {
      _pf.DSUB();
  }
  else { _pf.SUB(); }
}
void zu::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->left()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE && 
      node->left()->type()->name() == basic_type::TYPE_INT)
      _pf.I2D();
  
  node->right()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE && 
      node->left()->type()->name() == basic_type::TYPE_INT)
      _pf.I2D();
  
  if(node->type()->name() == basic_type::TYPE_DOUBLE) {
      _pf.DMUL();
  }
  else { _pf.MUL(); }
}
void zu::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->left()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE && 
      node->left()->type()->name() == basic_type::TYPE_INT)
      _pf.I2D();
  
  node->right()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE && 
      node->left()->type()->name() == basic_type::TYPE_INT)
      _pf.I2D();
  
  if(node->type()->name() == basic_type::TYPE_DOUBLE) {
      _pf.DDIV();
  }
  else { _pf.DIV(); }
}
void zu::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->left()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE && 
      node->left()->type()->name() == basic_type::TYPE_INT)
      _pf.I2D();
  
  node->right()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE && 
      node->left()->type()->name() == basic_type::TYPE_INT)
      _pf.I2D();
  
  _pf.MOD();
}
void zu::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LT();
}
void zu::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LE();
}
void zu::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GE();
}
void zu::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GT();
}
void zu::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.NE();
}
void zu::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.EQ();
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_and_node(zu::and_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  _pf.JZ("end1");
  node->right()->accept(this, lvl);
  _pf.AND();
  _pf.LABEL("end1");
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_position_indicator_node(zu::position_indicator_node * const node, int lvl) {
  /*FIXME CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.ADD();*/
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_memory_reservation_node(zu::memory_reservation_node * const node, int lvl) {
  /*FIXME CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.ADD();*/
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_or_node(zu::or_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  _pf.JNZ("end1");
  node->right()->accept(this, lvl);
  _pf.OR();
  _pf.LABEL("end1");
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_rvalue_node(zu::rvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->lvalue()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.DLOAD();
  }
  else { _pf.LOAD(); } //FIXME: depends on type size
}


//---------------------------------------------------------------------------

void zu::postfix_writer::do_identifier_node(zu::identifier_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  std::shared_ptr<zu::symbol> symbol = _symtab.find(*node->identifier());
  
  if(symbol->privOrPub()){
    if(symbol->variableOrFunction()) _pf.ADDR(symbol->name());
    else {
        _pf.LOCAL(symbol->offset());
    }
  }
  else {
    _pf.LOCAL(symbol->offset());
  }
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_index_node(zu::index_node * const node, int lvl) {
  /*CHECK_TYPES(_compiler, _symtab, node);
  
  std::shared_ptr<zu::symbol> symbol = _symtab.find(*node->identifier());
  
  node->value()->accept(this, lvl + 2);
  _PF.INT(node->value()->type()->size());
  _PF.MUL;
  if(symbol->privOrPub()){
      _pf.ADDR(symbol.get()->name());
  }
  else { _pf.LOCAL(symbol.get()->offset()); }
  _pf.ADD();
  _pf.LOAD();*/
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_assignment_node(zu::assignment_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
    
  if(node->type()->name() == basic_type::TYPE_INT ||
      node->type()->name() == basic_type::TYPE_STRING) {
    node->rvalue()->accept(this, lvl); // determine the new value
    _pf.DUP();
    node->lvalue()->accept(this, lvl); // where to store the value
    _pf.STORE(); // store the value at address
  }
  else if(node->type()->name() == basic_type::TYPE_DOUBLE){
    node->rvalue()->accept(this, lvl); // determine the new value
    _pf.DDUP(); //because rvalue HAS to be a double (conversion)
    node->lvalue()->accept(this, lvl); // where to store the value
    _pf.DSTORE(); // store the value at address
  }
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_function_call_node(zu::function_call_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  int toTrash = 0;
    
  if(node->arguments()) {
      for(int i = node->arguments()->size()-1; i >= 0; i--){
         node->arguments()->node(i)->accept(this, lvl + 2);
         toTrash += ((cdk::expression_node*) node->arguments()->node(i))->type()->size();
      }
  }
  std::shared_ptr<zu::symbol> symbol = _symtab.find(*node->name());
  _pf.CALL(*node->name());
  _pf.TRASH(toTrash);
  if(symbol->type()->name() == basic_type::TYPE_INT || symbol->type()->name() == basic_type::TYPE_STRING) {
      _pf.PUSH();
  }
  else if (symbol->type()->name() == basic_type::TYPE_DOUBLE) { _pf.DPUSH(); }
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_declaration_node(zu::declaration_node * const node, int lvl) {
  // Note that Zu doesn't have functions. Thus, it doesn't need
  // a function node. However, it must start in the main function.
  // The ProgramNode (representing the whole program) doubles as a
  // main function node.
    
  CHECK_TYPES(_compiler, _symtab, node);
    
  if(node->extOrNot()) {
    _pf.EXTERN(*node->name());
  }
  else {
      if(!_arguments){
        if(node->privOrPub()){
            
            if (!_symtab.insert(*node->name(), std::make_shared<zu::symbol>(node->returns(), *node->name(), 0, true, true, 0, false)))
                        throw *node->name() + " redeclared";
            
            if(node->returnvl()){
                
                _pf.DATA();
                _pf.ALIGN();
                _pf.GLOBAL(*node->name(), _pf.OBJ());
                _pf.LABEL(*node->name());
                
                if(node->returns()->name() == basic_type::TYPE_INT){
        
                    _pf.CONST(((cdk::simple_value_node<int>*) node->returnvl())->value());
                }
                else if(node->returns()->name() == basic_type::TYPE_DOUBLE){
                     
                    _pf.DOUBLE(((cdk::simple_value_node<double>*) node->returnvl())->value());
                }
                else {
                    
                    _pf.RODATA(); // strings are DATA readonly
                    _pf.ALIGN(); // make sure we are aligned
                    _pf.LABEL(mklbl(++_lbl)); // give the string a name
                    _pf.STR((dynamic_cast<cdk::string_node*>(node->returnvl()))->value()); // output string characters

                    _pf.DATA(); // return to the TEXT segment
                    _pf.ALIGN();
                    _pf.ID(mklbl(_lbl)); // the string to be printed
                    _pf.TEXT();
                    
                }
            }
            else {
                _pf.BSS();
                _pf.ALIGN();
                _pf.GLOBAL(*node->name(), _pf.OBJ());
                _pf.LABEL(*node->name());
                _pf.BYTE(node->returns()->size());
            }
        }
        else {
            if(node->returnvl()){
                if(node->returns()->name() == basic_type::TYPE_INT){
                    
                    _offset -= 4;
                    if (!_symtab.insert(*node->name(), std::make_shared<zu::symbol>(node->returns(), *node->name(), 0, true, false, _offset, false)))
                        throw *node->name() + " redeclared";
                    
                    cdk::simple_value_node<int> *i = (cdk::simple_value_node<int>*) node->returnvl();
                    
                    _pf.INT(i->value());
                    //_pf.DUP();                
                    _pf.LOCA(_offset); //FIXME
                    //_pf.TRASH(4);
                }
                else if(node->returns()->name() == basic_type::TYPE_DOUBLE){
                    _offset -= 8;
                    if (!_symtab.insert(*node->name(), std::make_shared<zu::symbol>(node->returns(), *node->name(), 0, true, false, _offset, false)))
                        throw *node->name() + " redeclared";
                    
                    cdk::simple_value_node<int> *i = (cdk::simple_value_node<int>*) node->returnvl();
                    
                    _pf.DOUBLE(i->value());
                    //_pf.DDUP();                
                    _pf.LOCAL(_offset); //FIXME
                    _pf.DSTORE();
                    //_pf.TRASH(8);
                }
                else {
                    
                }
            }
            else {
            }
        }
      }
      else {
        if(node->returns()->name() == basic_type::TYPE_INT || node->returns()->name() == basic_type::TYPE_STRING){
            if (!_symtab.insert(*node->name(), std::make_shared<zu::symbol>(node->returns(), *node->name(), 0, true, false, _posoffset, false)))
                throw *node->name() + " redeclared";
            _posoffset -= 4;
        }
        else if(node->returns()->name() == basic_type::TYPE_DOUBLE){
            if (!_symtab.insert(*node->name(), std::make_shared<zu::symbol>(node->returns(), *node->name(), 0, true, false, _posoffset, false)))
                throw *node->name() + " redeclared";
            _posoffset -= 8;
        }
        
        /*std::cout << *node->name() << std::endl;
        std::cout << _posoffset << std::endl;*/
      }
    }
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_function_declaration_node(zu::function_declaration_node * const node, int lvl) {
  
  if (!_symtab.insert(*node->name(), std::make_shared<zu::symbol>(node->returns(), *node->name(), 0, false, node->impOrExp(), 0, false)))
        throw *node->name() + " redeclared";
  _extern.insert(*node->name());
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_function_definition_node(zu::function_definition_node * const node, int lvl) {
  // Note that Zu doesn't have functions. Thus, it doesn't need
  // a function node. However, it must start in the main function.
  // The ProgramNode (representing the whole program) doubles as a
  // main function node.
  
  CHECK_TYPES(_compiler, _symtab, node);
  
  std::string name;

  // generate the main function (RTS mandates that its name be "_main")
  _pf.TEXT();
  _pf.ALIGN();
  
  if(!node->name()->compare("zu")) name = "_main";
  else if(!node->name()->compare("_main")) name = "zu";
  else name = *node->name();
  
  _pf.GLOBAL(name, _pf.FUNC());
  _pf.LABEL(name);
  
  std::shared_ptr<zu::symbol> symbol = _symtab.find(name);
  if(symbol.get() != NULL && symbol.get()->defined()) { //function already defined
      throw name + " redefinition";
  }
  else if(symbol.get() == NULL) { //function not declared or defined
    if(node->returns()->name() == basic_type::TYPE_INT || node->returns()->name() == basic_type::TYPE_STRING){
        _offset -= 4;
        if (!_symtab.insert(name, std::make_shared<zu::symbol>(node->returns(), name, 0, false, true, _offset, true)))
            throw name + " redeclared";
    }
    else if (node->returns()->name() == basic_type::TYPE_DOUBLE){
        _offset -= 8;
        if (!_symtab.insert(name, std::make_shared<zu::symbol>(node->returns(), name, 0, false, true, _offset, true)))
            throw name + " redeclared";
    }
    else {
        if (!_symtab.insert(name, std::make_shared<zu::symbol>(node->returns(), name, 0, false, true, 0, true)))
            throw name + " redeclared";
    }
  }
  else { //function declared
    symbol.get()->defined(true);
    symbol.get()->privOrPub(false);
    if(symbol.get()->type()->name() == basic_type::TYPE_INT || symbol.get()->type()->name() == basic_type::TYPE_STRING) {
        _offset -= -4;
        symbol.get()->offset(-4);
    }
    else if(symbol.get()->type()->name() == basic_type::TYPE_DOUBLE) {
        _offset -= 8;
        symbol.get()->offset(-8);
    }
  }
  
  if(_extern.count(name) == 1) _extern.erase(name);
  
  //FIXME
  calculate_size *visit = new calculate_size(_compiler); //creates visitor to calculate size of local variables
  visit->do_function_definition_node(node, lvl + 2); //visits this function to find how much size the local variables need
  _pf.ENTER(visit->getSize() + node->returns()->size()); //allocates said space
  
  //FIXME
  
  _symtab.push();
  
  _arguments = true;
  _posoffset = 0;
  if(node->arguments()) {
      for(int i = node->arguments()->size()-1; i >= 0; i--){
         _posoffset += ((declaration_node*)node->arguments()->node(i))->returns()->size();
      }
      _posoffset += ((declaration_node*)node->arguments()->node(node->arguments()->size()-1))->returns()->size();
      for(int i = node->arguments()->size()-1; i >= 0; i--){
          node->arguments()->node(i)->accept(this, lvl + 2);
      }
  }
  _arguments = false;
  
  _lblret = mklbl(++_lbl);
  
  
  if(node->returnvl() != NULL) { //normal return
      node->returnvl()->accept(this, lvl+2);
      _pf.LOCAL(0-node->returns()->size());
      if(node->returns()->name() == basic_type::TYPE_DOUBLE) {
          _pf.DSTORE();
      }
      else {
          _pf.STORE();
      }
  }
  else {
      if(node->returns()->name() == basic_type::TYPE_INT){
        _pf.INT(0);
        _pf.LOCA(-4);
      }
      else if(node->returns()->name() == basic_type::TYPE_DOUBLE) {
        _pf.RODATA();
        _pf.RODATA();
        _pf.ALIGN();
        _pf.LABEL(mklbl(++_lbl));
        _pf.DOUBLE(0);
        _pf.TEXT();
        _pf.ALIGN();
        _pf.ADDR(mklbl(_lbl));
        _pf.DLOAD();
        _pf.LOCAL(-8);
        _pf.DSTORE();
      }
  }
  
  node->body()->accept(this, lvl + 2);
  
  _pf.LABEL(_lblret);
  
  // end the main function
   
  if(node->returns()->name() == basic_type::TYPE_DOUBLE){
      _pf.LOCAL(-8);
      _pf.DLOAD();
      _pf.DPOP();
  }
  else if(node->returns()->name() == basic_type::TYPE_VOID) {
  }
  else{
      _pf.LOCV(-4);
      _pf.POP();
  }
  
  _symtab.pop();
  _pf.LEAVE();
  _pf.RET();
  
  _offset = 0;
  
  // these are just a few library function imports
  _pf.EXTERN("readi");
  _pf.EXTERN("printi");
  _pf.EXTERN("prints");
  _pf.EXTERN("printd");
  _pf.EXTERN("println");
  
  if(!name.compare("_main")){
    for(std::string extrn : _extern) {
        _pf.EXTERN(extrn);
    }
  }
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_evaluation_node(zu::evaluation_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->argument()->accept(this, lvl); // determine the value
  
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.TRASH(4); // delete the evaluated value
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.TRASH(4); // delete the evaluated value's address
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.TRASH(8); // delete the evaluated value's address
  }
  else if (dynamic_cast<function_call_node*>(node->argument())){ } //FIXME 
  else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}

void zu::postfix_writer::do_print_node(zu::print_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value to print
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.CALL("printi");
    _pf.TRASH(4); // delete the printed value
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.CALL("prints");
    _pf.TRASH(4); // delete the printed value's address
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.CALL("printd");
    _pf.TRASH(8); // delete the printed value's address
  }
  else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
  _pf.CALL("println"); // print a newline
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_return_node(zu::return_node * const node, int lvl) {
  _pf.JMP(_lblret);
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_identity_node(zu::identity_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->argument()->accept(this, lvl); // determine the value
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_simetric_node(zu::simetric_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value
  _pf.NEG();
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_block_node(zu::block_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  if(node->declarations()) node->declarations()->accept(this, lvl + 2);
  if(node->instructions()) node->instructions()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_read_node(zu::read_node * const node, int lvl) {
  /*CHECK_TYPES(_compiler, _symtab, node);
  _pf.CALL("readi");
  _pf.PUSH();
  node->argument()->accept(this, lvl);
  _pf.STORE();*/
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_for_node(zu::for_node * const node, int lvl) {
    CHECK_TYPES(_compiler, _symtab, node);
    
    int lblcond, lblendfor, lblinc;
    
    
    if(node->init()) node->init()->accept(this, lvl + 2);
    _pf.LABEL(mklbl(lblcond = ++_lbl));
    if(node->condition()) node->condition()->accept(this, lvl + 2);
    _lblend = mklbl(lblendfor = ++_lbl);
    _pf.JZ(_lblend);
    _lblinc = mklbl(lblinc = ++_lbl);
    node->instruction()->accept(this, lvl + 2);
    _pf.LABEL(_lblinc);
    _lblinc = mklbl(lblinc = ++_lbl);
    if(node->incr()) node->incr()->accept(this, lvl + 2);
    _lblend = mklbl(lblendfor);
    _pf.JMP(mklbl(lblcond));
    _pf.LABEL(_lblend);
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_break_node(zu::break_node * const node, int lvl) {
  _pf.JMP(_lblend);
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_continue_node(zu::continue_node * const node, int lvl) {
  _pf.JMP(_lblinc);
}
  
//---------------------------------------------------------------------------

void zu::postfix_writer::do_if_node(zu::if_node * const node, int lvl) {
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_if_else_node(zu::if_else_node * const node, int lvl) {
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1 = lbl2));
}
