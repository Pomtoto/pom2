#include "Config.h"

namespace Configs {
    int EglWidth = 0;
    int EglHeight = 0;
    int DisplayWidth = 0;
    int DisplayHeight = 0;
    bool LoginValid = false;
    bool Initialized = false;
    bool ClearMouse = true;
    bool ShowImGui = true;
};

namespace Esp {
    bool SkillsId = false;
}

namespace AutoSkills {
    bool SoYou = false;
    bool Lucas = false;
    bool KimmyTrigger = false;
    bool GusionTrigger = false;
    bool JoyTrigger = false;
    bool PaquitoTrigger = false;
};

sAutoRetribution AutoRetribution{false, false, false, false, 7.0f};
sAim Aim{false, false, false, false, false, 10.0f, Vector3::zero(), Vector3::One(), Vector3::zero(), 0, 9999, false};
sESP ESP{false, false, false, false, false, false, false, false, false, false};
