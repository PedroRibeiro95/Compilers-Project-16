// $Id: symbol.h,v 1.6 2016/05/19 00:51:49 ist179055 Exp $ -*- c++ -*-
#ifndef __ZU_SEMANTICS_SYMBOL_H__
#define __ZU_SEMANTICS_SYMBOL_H__

#include <string>
#include <cdk/basic_type.h>

namespace zu {

    class symbol {
      basic_type *_type;
      std::string _name;
      long _value; // hack!
      bool _variableOrFunction; //true if variable, false if function
      bool _privOrPub;
      int _offset;
      bool _defined;

    public:
      inline symbol(basic_type *type, std::string name, long value, bool variableOrFunction, bool privOrPub, int offset, bool defined) :
          _type(type), _name(name), _value(value), _variableOrFunction(variableOrFunction), _privOrPub(privOrPub), _offset(offset), _defined(defined) {
      }

      virtual ~symbol() {
        delete _type;
      }

      inline basic_type *type() {
        return _type;
      }
      inline std::string name() {
        return _name;
      }
      inline long value() {
        return _value;
      }
      inline long value(long v) {
        return _value = v;
      }
      inline bool variableOrFunction() {
        return _variableOrFunction;
      }
      inline bool privOrPub() {
        return _privOrPub;
      }
      inline int offset() {
        return _offset;
      }
      inline bool defined() {
        return _defined;
      }
      inline void defined(bool def) {
        _defined = def;
      }
      inline void offset(int off) {
        _offset = off;
      }
      inline void privOrPub(bool privOrPub) {
        _privOrPub = privOrPub;
      }
    };

} // zu

#endif
