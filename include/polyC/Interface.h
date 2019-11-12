#ifndef POLYC_INTERFACE_H
#define POLYC_INTERFACE_H

#define _CONCAT_TOKENS(x, y) x##y
#define CONCAT_TOKENS(x, y) _CONCAT_TOKENS(x,y)

#define POLYC_INTERFACE_METHOD_SUFFIX _polyc_method

#define DECLARE_ACTION(name) typedef void(*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))();
#define DECLARE_ACTION_ARG(name, argument) \
typedef void(*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))(argument arg);

#define DECLARE_FUNC(name, returnType) \
typedef returnType (*CONCAT_TOKENS(name, POLYC_INTERFACE_METHOD_SUFFIX))();

#define DECLARE_INTERFACE(name, method) \
        typedef struct name \
        { \
            CONCAT_TOKENS(method, POLYC_INTERFACE_METHOD_SUFFIX) (method); \
        } I##name;

#define DECLARE_MULTI_INTERFACE(name, method1, method2) \
        typedef struct name \
        { \
            CONCAT_TOKENS(method1, POLYC_INTERFACE_METHOD_SUFFIX) (method1); \
            CONCAT_TOKENS(method2, POLYC_INTERFACE_METHOD_SUFFIX) (method2); \
        } I##name;

#endif