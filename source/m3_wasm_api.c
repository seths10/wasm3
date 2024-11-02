#include "m3_wasm_api.h"
#include "m3_env.h"
#include "m3_exception.h"

struct wasm_engine_t {
    M3Environment* env;
};

struct wasm_store_t {
    M3Runtime* runtime;
};

struct wasm_module_t {
    IM3Module module;
};

struct wasm_instance_t {
    IM3Module module;
    M3Runtime* runtime;
};

wasm_engine_t* wasm_engine_new() {
    wasm_engine_t* engine = m3_AllocStruct(wasm_engine_t);
    if (engine) {
        engine->env = m3_NewEnvironment();
    }
    return engine;
}

void wasm_engine_delete(wasm_engine_t* engine) {
    if (engine) {
        m3_FreeEnvironment(engine->env);
        m3_Free(engine);
    }
}

wasm_store_t* wasm_store_new(wasm_engine_t* engine) {
    wasm_store_t* store = m3_AllocStruct(wasm_store_t);
    if (store) {
        store->runtime = m3_NewRuntime(engine->env, 64*1024, NULL);
    }
    return store;
}

void wasm_store_delete(wasm_store_t* store) {
    if (store) {
        m3_FreeRuntime(store->runtime);
        m3_Free(store);
    }
}