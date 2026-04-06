#pragma once

#include "inc.h"


#define DECLARE_A_TSPARSE_ARRAY(__type)  \
  _DECL_FALIGNED_ELEMENTS(__type); \
  _DECL_TTYPE_COMPATIBILITY_BYTES(__type); \
  _DECL_TARRAY(_TTYPE_COMPATIBILITY_BYTES_NAME(__type)); \
  _DECL_TSPARSE_ARRAY(__type)


_DECL_AS_PTR(void);

DECLARE_A_TSPARSE_ARRAY(_PTR_NAME(void));
