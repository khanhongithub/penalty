#pragma once

#include "core/ShootZone.h"
#include "entities/Ball.h"
#include "entities/GoalKeeper.h"

struct GameData
{
    GameData() = default;
    int score = 0;

    int round = 1;

    int maxRounds = 5;

    bool lastShotGoal = false;

    ShootZone selectedZone =
        ShootZone::CENTER;

    Ball ball;

    GoalKeeper keeper;

    GameData(const GameData&) = delete;
    GameData& operator=(const GameData&) = delete;

    GameData(GameData&&) = delete;
    GameData& operator=(GameData&&) = delete;
};