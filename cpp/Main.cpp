#include <jni.h>
#include <android/log.h>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdint>
#include <dlfcn.h>
#include <sys/mman.h>
#include <cstring>
#include <inttypes.h>

#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "Config/Config.h"
#include "SDK/Vector3.h"
#include "ESP/ESPManager.h"
#include "Hooks/And64InlineHook.h"

uintptr_t g_Il2CppBase = 0;
JavaVM* g_vm = nullptr;

void MainThread() {
    LOGI("🚀 Main Thread Started");
    
    while (g_Il2CppBase == 0) {
        g_Il2CppBase = Tools::GetBaseAddress(targetLib);
        if (g_Il2CppBase == 0) {
            sleep(1);
            continue;
        }
        break;
    }
    
    LOGI("✅ Target Library Found: 0x%" PRIxPTR, g_Il2CppBase);
    LOGI("✅ Initialization Complete");
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    g_vm = vm;
    
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    
    LOGI("=================================");
    LOGI("🎯 Native Library Loaded");
    LOGI("📦 Project: NativeProject");
    LOGI("=================================");
    
    std::thread(MainThread).detach();
    
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
    LOGI("👋 Library Unloading...");
}
