#include "ESPManager.h"
#include <algorithm>

ESPManager g_ESPManager;

bool ESPManager::IsEnemyPresent(void* enemyObject) {
    for (const auto& enemy : enemies) {
        if (enemy && enemy->object == enemyObject) return true;
    }
    return false;
}

void ESPManager::TryAddEnemy(void* enemyObject) {
    if (!enemyObject || IsEnemyPresent(enemyObject)) return;
    enemies.push_back(std::make_unique<EnemyInfo>(enemyObject));
}

void ESPManager::UpdateEnemies() {
    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
            [](const std::unique_ptr<EnemyInfo>& enemy) {
                return !enemy;
            }),
        enemies.end()
    );
}

void ESPManager::RemoveEnemyGivenObject(void* enemyObject) {
    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
            [enemyObject](const std::unique_ptr<EnemyInfo>& enemy) {
                return enemy && enemy->object == enemyObject;
            }),
        enemies.end()
    );
}
