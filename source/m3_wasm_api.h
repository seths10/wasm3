//
//  WASM C API implementation for wasm3
//

#ifndef __wasm3_api_h
#define __wasm3_api_h

#include "m3_core.h"
#include <stdint.h>

typedef uint8_t byte_t;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct wasm_engine_t     wasm_engine_t;
typedef struct wasm_store_t      wasm_store_t;
typedef struct wasm_module_t     wasm_module_t;
typedef struct wasm_instance_t   wasm_instance_t;
typedef struct wasm_trap_t       wasm_trap_t;
typedef struct wasm_extern_t     wasm_extern_t;

typedef struct wasm_byte_vec_t {
    size_t size;
    byte_t* data;
} wasm_byte_vec_t;

typedef struct wasm_extern_vec_t {
    size_t size;
    wasm_extern_t* const* data;
} wasm_extern_vec_t;


wasm_engine_t* wasm_engine_new(void);
void wasm_engine_delete(wasm_engine_t*);
  
wasm_store_t* wasm_store_new(wasm_engine_t*);
void wasm_store_delete(wasm_store_t*);

wasm_module_t* wasm_module_new(wasm_store_t*, const wasm_byte_vec_t* binary);
void wasm_module_delete(wasm_module_t*);

wasm_instance_t* wasm_instance_new(wasm_store_t*, 
                                  const wasm_module_t*,
                                  const wasm_extern_vec_t* imports,
                                  wasm_trap_t**);
void wasm_instance_delete(wasm_instance_t*);

void wasm_byte_vec_new(wasm_byte_vec_t*, size_t, const byte_t*);
void wasm_byte_vec_delete(wasm_byte_vec_t*);

void wasm_extern_vec_new(wasm_extern_vec_t*, size_t, wasm_extern_t* const[]);
void wasm_extern_vec_delete(wasm_extern_vec_t*);

#ifdef __cplusplus
}
#endif

#endif