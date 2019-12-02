//
// Created by Timor Gruber on 11/12/19.
// Copyright (c) 2019 Takpit. All rights reserved.
//

#ifndef POLYC_MACROUTILS_H
#define POLYC_MACROUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#define _CONCAT_TOKENS(x, y) x##y
#define CONCAT_TOKENS(x, y) _CONCAT_TOKENS(x,y)

#define __NARG_I_(...) __ARG_N(__VA_ARGS__)
#define __NARG__(...)  __NARG_I_(__VA_ARGS__,__RSEQ_N())

#define __RSEQ_N() \
     63,62,61,60,                   \
     59,58,57,56,55,54,53,52,51,50, \
     49,48,47,46,45,44,43,42,41,40, \
     39,38,37,36,35,34,33,32,31,30, \
     29,28,27,26,25,24,23,22,21,20, \
     19,18,17,16,15,14,13,12,11,10, \
     9,8,7,6,5,4,3,2,1,0
#define __ARG_N(\
      _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
     _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
     _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
     _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
     _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
     _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
     _61, _62, _63, N, ...) N

#define VFUNC(func, ...) CONCAT_TOKENS(func, __NARG__(__VA_ARGS__)) (__VA_ARGS__)
#define VFUNC1(func, param1, ...) CONCAT_TOKENS(func, __NARG__(__VA_ARGS__)) (param1, __VA_ARGS__)
#define VFUNC2(func, param1, param2, ...) CONCAT_TOKENS(func, __NARG__(__VA_ARGS__)) (param1, param2, __VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif //POLYC_MACROUTILS_H
