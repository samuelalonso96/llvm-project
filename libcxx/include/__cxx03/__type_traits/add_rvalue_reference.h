//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___CXX03___TYPE_TRAITS_ADD_RVALUE_REFERENCE_H
#define _LIBCPP___CXX03___TYPE_TRAITS_ADD_RVALUE_REFERENCE_H

#include <__cxx03/__config>
#include <__cxx03/__type_traits/is_referenceable.h>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

#if __has_builtin(__add_rvalue_reference)

template <class _Tp>
using __add_rvalue_reference_t = __add_rvalue_reference(_Tp);

#else

template <class _Tp, bool = __libcpp_is_referenceable<_Tp>::value>
struct __add_rvalue_reference_impl {
  typedef _LIBCPP_NODEBUG _Tp type;
};
template <class _Tp >
struct __add_rvalue_reference_impl<_Tp, true> {
  typedef _LIBCPP_NODEBUG _Tp&& type;
};

template <class _Tp>
using __add_rvalue_reference_t = typename __add_rvalue_reference_impl<_Tp>::type;

#endif // __has_builtin(__add_rvalue_reference)

template <class _Tp>
struct add_rvalue_reference {
  using type = __add_rvalue_reference_t<_Tp>;
};

_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___CXX03___TYPE_TRAITS_ADD_RVALUE_REFERENCE_H
