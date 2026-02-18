#pragma once
#include "../SDK/Vector3.h"

#define targetLib "liblogic.so"

enum EThemeTarget {
    None = 0,
    Transparent = 1,
    Blacki = 2,
    Blue = 3,
    Pink = 4
};

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

struct sAutoRetribution {
    bool RedandBlue = false;
    bool TurtleandLord = false;
    bool Crab = false;
    bool litho = false;
    float Custom = 7.0f;
};

struct sAim {
    bool SelfPos = false;
    bool TargetPriority = false;
    bool AutoTakeSword = false;
    bool AutoTakeSword2 = false;
    bool ActivePredict = false;
    float RangeFOV = 10.0f;
    Vector3 Dir;
    Vector3 Pos;
    Vector3 NearestEnemyPos;
    int NearestEnemyGuid;
    float NearestEnemyDist;
    bool RetriDistButton;
};

struct sESP {
    bool FPS = false;
    bool Line = false;
    bool Box = false;
    bool Health = false;
    bool Name = false;
    bool Distance = false;
    bool Hero = false;
    bool Visible = false;
    bool Antilag = false;
    bool ShowMonster = false;
};

extern sAutoRetribution AutoRetribution;
extern sAim Aim;
extern sESP ESP;
