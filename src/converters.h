#include  <ffi.h>
#include  <Rdefines.h>

#ifdef WIN32
typedef unsigned long __uint64_t;
#endif

extern ffi_type ffi_type_string;
extern ffi_type ffi_type_sexp;

extern ffi_type ffi_string_array_element_types[];

SEXP convertFromNative(void *val, ffi_type *type);
void * convertToNative(void **val, SEXP r_val, ffi_type *type);

#define GET_FFI_TYPE_REF(x) \
    TYPEOF((x)) == EXTPTRSXP ? (ffi_type *) R_ExternalPtrAddr((x)) : \
                             (ffi_type *) R_ExternalPtrAddr(GET_SLOT((x), Rf_install("ref")))

#define GET_EXT_PTR_REF(x) \
    (TYPEOF((x)) == EXTPTRSXP ? R_ExternalPtrAddr((x)) :		\
                                R_ExternalPtrAddr(GET_SLOT((x), Rf_install("ref"))))



void *getAddressOfExtPtr(SEXP val);
