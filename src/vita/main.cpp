#include <cstdint>

#include <psp2/ctrl.h>
#include <vitaGL.h>

#include "vita_abi.h"

namespace {

constexpr int kWidth = 960;
constexpr int kHeight = 544;
constexpr int kRamThreshold = 8 * 1024 * 1024;
constexpr std::uint32_t kCircularPool = 8 * 1024 * 1024;

} // namespace

int main()
{
    vglSetCircularPoolSize(kCircularPool);

    if (!vglInitExtended(0, kWidth, kHeight, kRamThreshold, SCE_GXM_MULTISAMPLE_NONE)) {
        return 1;
    }

    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG_WIDE);

    for (;;) {
        SceCtrlData pad{};
        sceCtrlPeekBufferPositive(0, &pad, 1);
        if (pad.buttons & SCE_CTRL_START) {
            break;
        }

        glViewport(0, 0, kWidth, kHeight);
        glClearColor(0.04f, 0.05f, 0.08f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        vglSwapBuffers(GL_FALSE);
    }

    return 0;
}
