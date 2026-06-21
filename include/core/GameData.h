#pragma once

#include "core/ShootZone.h"
#include "entities/Ball.h"
#include "entities/GoalKeeper.h"

struct GameData
{
    int score = 0;

    int round = 1;

    int maxRounds = 5;

    bool lastShotGoal = false;

    ShootZone selectedZone =
        ShootZone::CENTER;

    Ball ball;

    GoalKeeper keeper;
};