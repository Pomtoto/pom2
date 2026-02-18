#include "And64InlineHook.h"
#include <sys/mman.h>
#include <cstring>
#include <unistd.h>
#include <android/log.h>
#include <cstdint>

#if defined(__aarch64__)

#define A64_NOP 0xd503201fu

static void __flush_cache(void *c, size_t n) {
    __builtin___clear_cache(reinterpret_cast<char *>(c), reinterpret_cast<char *>(c) + n);
}

extern "C" {

void A64HookFunction(void* const symbol, void* const replace, void** result) {
    if (!symbol || !replace) return;
    
    size_t page_size = sysconf(_SC_PAGESIZE);
    uintptr_t page_start = reinterpret_cast<uintptr_t>(symbol) & ~(page_size - 1);
    
    if (mprotect((void*)page_start, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, "A64_HOOK", "mprotect failed");
        return;
    }
    
    if (result) *result = symbol;
}

void* A64HookFunctionV(void* const symbol, void* const replace, void* const rwx, const uintptr_t rwx_size) {
    A64HookFunction(symbol, replace, nullptr);
    return rwx;
}

}

#endif
