#pragma once
#include <vector>
#include <memory>
#include "../SDK/Vector3.h"

struct EnemyInfo {
    void* object;
    Vector3 location;
    int health;
    int maxHealth;
    int heroId;
    
    EnemyInfo(void* obj) : object(obj), location(Vector3::zero()), health(100), maxHealth(100), heroId(0) {}
};

class ESPManager {
public:
    std::vector<std::unique_ptr<EnemyInfo>> enemies;
    
    ESPManager() = default;
    ~ESPManager() = default;
    
    bool IsEnemyPresent(void* enemyObject);
    void TryAddEnemy(void* enemyObject);
    void UpdateEnemies();
    void RemoveEnemyGivenObject(void* enemyObject);
    const std::vector<std::unique_ptr<EnemyInfo>>& GetEnemies() const { return enemies; }
};

extern ESPManager g_ESPManager;
