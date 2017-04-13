#include <ruby.h>
#include <ruby/intern.h>
#include <stdbool.h>

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_DLL
    #define HELIX_EXTERN __declspec(dllexport)
  #else
    #define HELIX_EXTERN __declspec(dllimport)
  #endif
#else
  #define HELIX_EXTERN extern
#endif

#ifndef HELIXRUNTIME_H
#define HELIXRUNTIME_H

#define RUST_U64 uint64_t
#define RUST_I64 int64_t

#define RUST_U32 uint32_t
#define RUST_I32 int32_t

#define RUST_F64 double

HELIX_EXTERN const char* HELIX_RUNTIME_VERSION;

HELIX_EXTERN const char* HELIX_PRIsVALUE;
HELIX_EXTERN const char* HELIX_SPRINTF_TO_S;
HELIX_EXTERN const char* HELIX_SPRINTF_INSPECT;

HELIX_EXTERN RUST_U64 HELIX_NUM2U64(VALUE);
HELIX_EXTERN VALUE HELIX_U642NUM(RUST_U64);

HELIX_EXTERN RUST_I64 HELIX_NUM2I64(VALUE);
HELIX_EXTERN VALUE HELIX_I642NUM(RUST_I64);

HELIX_EXTERN RUST_U32 HELIX_NUM2U32(VALUE);
HELIX_EXTERN VALUE HELIX_U322NUM(RUST_U32);

HELIX_EXTERN RUST_I32 HELIX_NUM2I32(VALUE);
HELIX_EXTERN VALUE HELIX_I322NUM(RUST_I32);

HELIX_EXTERN RUST_F64 HELIX_NUM2F64(VALUE);
HELIX_EXTERN VALUE HELIX_F642NUM(RUST_F64);

HELIX_EXTERN VALUE HELIX_Qtrue;
HELIX_EXTERN VALUE HELIX_Qfalse;
HELIX_EXTERN VALUE HELIX_Qnil;

HELIX_EXTERN long HELIX_RSTRING_LEN(VALUE string);
HELIX_EXTERN const char* HELIX_RSTRING_PTR(VALUE string);

HELIX_EXTERN long HELIX_RARRAY_LEN(VALUE array);
HELIX_EXTERN void* HELIX_RARRAY_PTR(VALUE array);
HELIX_EXTERN const void* HELIX_RARRAY_CONST_PTR(VALUE array);

HELIX_EXTERN bool HELIX_RB_TYPE_P(VALUE v, int type);
HELIX_EXTERN int HELIX_TYPE(VALUE v);

HELIX_EXTERN VALUE HELIX_INT2FIX(int c_int);
HELIX_EXTERN VALUE HELIX_FIX2INT(VALUE fix);

HELIX_EXTERN VALUE HELIX_rb_utf8_str_new(const char* str, long len);

// typedef VALUE (*HELIX_rb_alloc_func_t)(VALUE);
// void HELIX_rb_define_alloc_func(VALUE klass, HELIX_rb_alloc_func_t func);

typedef void (*HELIX_RUBY_DATA_FUNC)(void*);

HELIX_EXTERN VALUE HELIX_Data_Wrap_Struct(VALUE klass, HELIX_RUBY_DATA_FUNC mark, HELIX_RUBY_DATA_FUNC free, void* data);
HELIX_EXTERN void* HELIX_Data_Get_Struct_Value(VALUE obj);
HELIX_EXTERN void HELIX_Data_Set_Struct_Value(VALUE obj, void* data);

HELIX_EXTERN int HELIX_T_NONE;
HELIX_EXTERN int HELIX_T_NIL;
HELIX_EXTERN int HELIX_T_OBJECT;
HELIX_EXTERN int HELIX_T_CLASS;
HELIX_EXTERN int HELIX_T_ICLASS;
HELIX_EXTERN int HELIX_T_MODULE;
HELIX_EXTERN int HELIX_T_FLOAT;
HELIX_EXTERN int HELIX_T_STRING;
HELIX_EXTERN int HELIX_T_REGEXP;
HELIX_EXTERN int HELIX_T_ARRAY;
HELIX_EXTERN int HELIX_T_HASH;
HELIX_EXTERN int HELIX_T_STRUCT;
HELIX_EXTERN int HELIX_T_BIGNUM;
HELIX_EXTERN int HELIX_T_FILE;
HELIX_EXTERN int HELIX_T_FIXNUM;
HELIX_EXTERN int HELIX_T_TRUE;
HELIX_EXTERN int HELIX_T_FALSE;
HELIX_EXTERN int HELIX_T_DATA;
HELIX_EXTERN int HELIX_T_MATCH;
HELIX_EXTERN int HELIX_T_SYMBOL;
HELIX_EXTERN int HELIX_T_RATIONAL;
HELIX_EXTERN int HELIX_T_COMPLEX;
HELIX_EXTERN int HELIX_T_UNDEF;
HELIX_EXTERN int HELIX_T_NODE;
HELIX_EXTERN int HELIX_T_ZOMBIE;
HELIX_EXTERN int HELIX_T_MASK;
// HELIX_EXTERN int HELIX_T_IMEMO = T_IMEMO;

#endif /* HELIXRUNTIME_H */
