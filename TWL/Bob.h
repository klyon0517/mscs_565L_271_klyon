#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
    // A constructor specific to Thomas
    Bob();

    // The overriden input handler for Thomas
    virtual bool handleInput() override;
};