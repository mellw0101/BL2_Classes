#pragma once


#if defined(__linux__)
# include <endian.h>
# define SYS_BYTE_ORDER     __BYTE_ORDER
# define SYS_BIG_ENDIAN     __BIG_ENDIAN
# define SYS_LITTLE_ENDIAN  __LITTLE_ENDIAN
#elif (defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__))
# include <sys/endian.h>
# define SYS_BYTE_ORDER     _BYTE_ORDER
# define SYS_BIG_ENDIAN     _BIG_ENDIAN
# define SYS_LITTLE_ENDIAN  _LITTLE_ENDIAN
#elif defined(_WIN32) || defined(_WIN64)
# define SYS_BIG_ENDIAN     4321
# define SYS_LITTLE_ENDIAN  1234
# define SYS_BYTE_ORDER     SYS_LITTLE_ENDIAN
#endif

#define __ALIGN(x)  __declspec(align(x))

#define STRUCT(x)       \
  typedef struct x  x;  \
  struct x

#define TARRAY(__type)  \
  STRUCT(TArray_##__type) { \
    __type *Data; \
    int     ArrayNum; \
    int     ArrayMax; \
  }

#define TARRAY_PTR(__type)  \
  STRUCT(TArray_##__type##Ptr) { \
    __type **Data; \
    int      ArrayNum; \
    int      ArrayMax; \
  }

#define TTRANSARRAY(__type)  \
  STRUCT(TTransArray_##__type) { \
    TArray_##__type Data; \
    UObject *Owner; \
  }

#define TTRANSARRAY_PTR(__type)  \
  STRUCT(TTransArray_##__type##Ptr) { \
    TArray_##__type##Ptr Data; \
    UObject *Owner; \
  }


#define TINDIRECTARRAY(__type)  \
  STRUCT(TIndirectArray_##__type) { \
    __type **Data; \
    int      ArrayNum; \
    int      ArrayMax; \
  }


#define _(x)     \
  STRUCT(x);     \
  TARRAY(x);     \
  TARRAY_PTR(x); \
  TTRANSARRAY(x); \
  TTRANSARRAY_PTR(x); \
  TINDIRECTARRAY(x); \
  _DECL_AS_PTR(x)


#define ENUM(x, ...) \
  typedef enum x { \
    __VA_ARGS__ \
  } x;

#define __ASIZE(x, size)  static_assert(sizeof(x) == size)

#define assert_size(x, size)  static_assert(sizeof(x) == (size))

#define CONST  static const

#define atomicwhencooked
#define immutablewhencooked
#define native
#define transient
#define export
#define atomic
#define immutable


#define STRU_(x, size, ...) \
  struct x {  \
    __VA_ARGS__ \
  }; \
  __ASIZE(x,size)

#define STRU_VFTB_(x, ...) \
  typedef struct VfTable__##x { \
    __VA_ARGS__ \
  } VfTable__##x


#define _PP_CAT(a, b)  a ## b
#define PP_CAT(a, b)  _PP_CAT(a, b)

/* This replicates the template aids in UE3 perfectly, and is actualy fucking readable in one go directly at use site. */

#define _FALIGNED_ELEMENTS(__type) \
  struct {  \
    BYTE MisalignmentPadding; \
    __type Element; \
  }


#define _TTYPE_COMPATIBILITY_BYTES(__type)  \
  struct __declspec(align(sizeof(FAlignedElements_##__type) - sizeof(__type))) { \
    BYTE Pad[sizeof(__type)]; \
  }

#define _FPAIR(__t0, __t1)  \
  struct {       \
    __t0 Key;    \
    __t1 Value;  \
  }


#define _TARRAY(__type)  \
  struct {               \
    __type *Data;        \
    int ArrayNum;        \
    int ArrayMax;        \
  }

#define _TRESOURCE_ARRAY(__type) \
  struct {                       \
    _TARRAY_NAME(__type) Super;  \
    UBOOL bNeedsCPUAccess;       \
  }

#define _TARRAY_TINLINEALLOCATOR(__type, __num)   \
  struct {                                        \
    _TINLINE_ALLOCATOR_NAME(__num, __type) Data;  \
    int ArrayNum;                                 \
    int ArrayMax;                                 \
  }

/* We do this, so we can use this with either a predeclared TArray_'__type', or _TARRAY(__type) */
#define _TSPARSE_ARRAY(__type)   \
  struct {                        \
    PP_CAT(TArray_TTypeCompatibleBytes_, __type) Data;                  \
    TBitArray AllocationFlags;    \
    INT FirstFreeIndex;           \
    INT NumFreeIndices;           \
  }

#define _TLINKED_LIST(__type) \
  struct _TLINKED_LIST_NAME(__type) {  \
    __type Element; \
	  _TLINKED_LIST_NAME(__type)* NextLink; \
	  _TLINKED_LIST_NAME(__type)** PrevLink; \
  }

#define _TREF_COUNT_PTR(__type) \
  struct {                      \
    __type *Reference;          \
  }

#define _TSCOPED_POINTER(__type) \
  struct {                       \
    __type *Reference;           \
  }

#define _TINLINE_ALLOCATOR(num_inline, __type)                     \
  struct {                                                         \
    PP_CAT(TTypeCompatibleBytes_, __type) InlineData[num_inline];  \
    FHeapAllocator_ForAnyElement SecondaryData;                    \
  }

#define _TSET__FELEMENT(__type)  \
  struct { \
    __type Value; \
    FSetElementId HashNextId; \
    INT HashIndex;  \
  }

#define _TSET(__type)  \
  struct { \
    PP_CAT(TSparseArray_TSet__FElement_, __type) Elements;  \
    TInlineAllocator_1_FSetElementId Hash;  \
    INT HashSize;  \
  }
// #define _TSET(__type)         __TSET(PP_CAT(TSparseArray_, __type))
// #define _TSET_INLINE(__type)  __TSET(_TSPARSE_ARRAY_INLINE(_TARRAY(__type)))

#define _TMAP(__t0, __t1) \
  struct {\
    PP_CAT(TSet_, _FPAIR_NAME(__t0, __t1)) Pairs;  \
  }

#define _TMULTI_MAP(__t0, __t1) \
  struct {\
    PP_CAT(TSet_, _FPAIR_NAME(__t0, __t1)) Pairs;  \
  }
// #define _TMAP(__t0, __t1)         __TMAP(PP_CAT(TSet_, _TSET__FELEMENT_NAME(_FPAIR_NAME(__t0, __t1))))

#define _PTR_NAME(__type)                        PP_CAT(__type, Ptr)
#define _FALIGNED_ELEMENTS_NAME(__type)          PP_CAT(FAlignedElements_, __type)
#define _FPAIR_NAME(__t0, __t1)                  PP_CAT(FPair_, PP_CAT(__t0, PP_CAT(_, __t1)))
#define _TARRAY_NAME(__type)                     PP_CAT(TArray_, __type)
#define _TRESOURCE_ARRAY_NAME(__type)            PP_CAT(TResourceArray_, __type)

#define _TARRAY_TINLINEALLOCATOR_NAME(__type, __num)  \
  PP_CAT(TArray_TInlineAllocator_, PP_CAT(__num , PP_CAT(_, __type)))

#define _TSPARSE_ARRAY_NAME(__type)              PP_CAT(TSparseArray_, __type)
#define _TLINKED_LIST_NAME(__type)               PP_CAT(TLinkedList_, __type)
#define _TTYPE_COMPATIBILITY_BYTES_NAME(__type)  PP_CAT(TTypeCompatibleBytes_, __type)
#define _TINLINE_ALLOCATOR_NAME(x, __type)       PP_CAT(TInlineAllocator_, PP_CAT(x, PP_CAT(_, __type)))
#define _TREF_COUNT_PTR_NAME(__type)             PP_CAT(TRefCountPtr_, __type)
#define _TSCOPED_POINTER_NAME(__type)            PP_CAT(TScopedPointer_, __type)
#define _TSET__FELEMENT_NAME(__type)             PP_CAT(TSet__FElement_, __type)
#define _TSET_NAME(__type)                       PP_CAT(TSet_, __type)
#define _TMAP_NAME(__t0, __t1)                   PP_CAT(TMap_, PP_CAT(__t0, PP_CAT(_, __t1)))
#define _TMULTI_MAP_NAME(__t0, __t1)             PP_CAT(TMultiMap_, PP_CAT(__t0, PP_CAT(_, __t1)))

#define _DECL_A_TYPE(name, __type)  typedef PP_CAT(name, (__type))  PP_CAT(name, _NAME(__type))

#define _DECL_AS_PTR(__type)                    typedef __type *                           _PTR_NAME(__type)
#define _DECL_FALIGNED_ELEMENTS(__type)         typedef _FALIGNED_ELEMENTS(__type)         _FALIGNED_ELEMENTS_NAME(__type)
#define _DECL_FPAIR(__t0, __t1)                 typedef _FPAIR(__t0, __t1)                 _FPAIR_NAME(__t0, __t1)
#define _DECL_TARRAY(__type)                    typedef _TARRAY(__type)                    _TARRAY_NAME(__type)
#define _DECL_TRESOURCE_ARRAY(__type)           typedef _TRESOURCE_ARRAY(__type)           _TRESOURCE_ARRAY_NAME(__type)

#define _DECL_TARRAY_TINLINEALLOCATOR(__type, __num)  typedef _TARRAY_TINLINEALLOCATOR(__type, __num) _TARRAY_TINLINEALLOCATOR_NAME(__type, __num)

#define _DECL_TSPARSE_ARRAY(__type)             typedef _TSPARSE_ARRAY(__type)             _TSPARSE_ARRAY_NAME(__type)

#define _DECL_TLINKED_LIST(__type) \
  typedef struct _TLINKED_LIST_NAME(__type) _TLINKED_LIST_NAME(__type); \
  typedef _TLINKED_LIST(__type) _TLINKED_LIST_NAME(__type)

#define _DECL_TTYPE_COMPATIBILITY_BYTES(__type) typedef _TTYPE_COMPATIBILITY_BYTES(__type) _TTYPE_COMPATIBILITY_BYTES_NAME(__type)
#define _DECL_TINLINE_ALLOCATOR(x, __type)      typedef _TINLINE_ALLOCATOR(x, __type)      _TINLINE_ALLOCATOR_NAME(x, __type)
#define _DECL_TREF_COUNT_PTR(__type)            typedef _TREF_COUNT_PTR(__type)            _TREF_COUNT_PTR_NAME(__type)

#define _DECL_TSCOPED_POINTER(__type)           typedef _TSCOPED_POINTER(__type)           _TSCOPED_POINTER_NAME(__type)

#define _DECL_TSET__FELEMENT(__type)            typedef _TSET__FELEMENT(__type)            _TSET__FELEMENT_NAME(__type)
#define _DECL_TSET(__type)                      typedef _TSET(__type)                      _TSET_NAME(__type)
#define _DECL_TMAP(__t0, __t1)                  typedef _TMAP(__t0, __t1)                  _TMAP_NAME(__t0, __t1)
#define _DECL_TMULTI_MAP(__t0, __t1)            typedef _TMULTI_MAP(__t0, __t1)            _TMULTI_MAP_NAME(__t0, __t1)

#define DECLARE_A_TARRAY_TINLINEALLOCATOR_BASE(__type)  \
  _DECL_FALIGNED_ELEMENTS(__type);                      \
  _DECL_TTYPE_COMPATIBILITY_BYTES(__type)

#define DECLARE_A_TARRAY_TINLINEALLOCATOR(__type, __num)  \
  _DECL_TINLINE_ALLOCATOR(__num, __type);                 \
  _DECL_TARRAY_TINLINEALLOCATOR(__type, __num)

#define DECLARE_A_TSET(__type) \
  _DECL_TSET__FELEMENT(__type); \
  DECLARE_A_TSPARSE_ARRAY(_TSET__FELEMENT_NAME(__type)); \
  _DECL_TSET(__type)

#define DECLARE_A_TMAP(__t0, __t1)  \
  _DECL_FPAIR(__t0, __t1); \
  DECLARE_A_TSET(_FPAIR_NAME(__t0, __t1)); \
  _DECL_TMAP(__t0, __t1)

#define DECLARE_A_TMULTI_MAP(__t0, __t1)  \
  _DECL_FPAIR(__t0, __t1); \
  DECLARE_A_TSET(_FPAIR_NAME(__t0, __t1)); \
  _DECL_TMULTI_MAP(__t0, __t1)

