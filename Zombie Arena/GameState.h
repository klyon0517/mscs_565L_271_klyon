#pragma once

// The game will always be in one of four states
enum class State
{
    PAUSED,
    LEVELING_UP,
    GAME_OVER,
    PLAYING
};