/*
 * This file helps with detection of C++ versions.
 * 
 * The macro __cplusplus should be set to 199711L, 201103L, 201402L, 201703L, 202002L for C++97, C++11, C++14, C++17, and C++20 respectively.
 * However in MSVC, the macro is defined to 199711L regardless of C++versions. The corresponding value is defined in _MSVC_LANG.
 * 
 * Plus, some older version of compiler defines things differently, e.g. gcc 6.3.0 when compiling C++17, __cplusplus is defined to 201500L.
 * 
 * Author: Erembourck
 * Date: 08 Oct 12022HE
 */

#pragma once
#ifndef __XY_COMPATIBILITY_CPPVERS_
#define __XY_COMPATIBILITY_CPPVERS_

#if _MSC_VER
#undef __cplusplus
#define __cplusplus _MSVC_LANG
#endif

#ifndef __cplusplus
#error You should use a C++ compiler for this Project!
#endif

#if __cplusplus < 199711L
#error The macro "__cplusplus" is defined under the standard 199711.
#endif

#if __cplusplus > 201100L
#define cpp11 1
#if __cplusplus > 201400L
#define cpp14 1
#if __cplusplus > 201499L
#define cpp17 1
#if __cplusplus > 202000L
#define cpp20 1
#endif//202000
#endif//201499
#endif//201400
#endif//201099

#endif//__XY_COMPATIBILITY_CPPVERS_