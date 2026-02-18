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
    extern int EglWidth;
    extern int EglHeight;
    extern int DisplayWidth;
    extern int DisplayHeight;
    extern bool LoginValid;
    extern bool Initialized;
    extern bool ClearMouse;
    extern bool ShowImGui;
};

namespace Esp {
    extern bool SkillsId;
}

namespace AutoSkills {
    extern bool SoYou;
    extern bool Lucas;
    extern bool KimmyTrigger;
    extern bool GusionTrigger;
    extern bool JoyTrigger;
    extern bool PaquitoTrigger;
};

struct sAutoRetribution {
    bool RedandBlue;
    bool TurtleandLord;
    bool Crab;
    bool litho;
    float Custom;
};

struct sAim {
    bool SelfPos;
    bool TargetPriority;
    bool AutoTakeSword;
    bool AutoTakeSword2;
    bool ActivePredict;
    float RangeFOV;
    Vector3 Dir;
    Vector3 Pos;
    Vector3 NearestEnemyPos;
    int NearestEnemyGuid;
    float NearestEnemyDist;
    bool RetriDistButton;
};

struct sESP {
    bool FPS;
    bool Line;
    bool Box;
    bool Health;
    bool Name;
    bool Distance;
    bool Hero;
    bool Visible;
    bool Antilag;
    bool ShowMonster;
};

extern sAutoRetribution AutoRetribution;
extern sAim Aim;
extern sESP ESP;
