#pragma once
#include <SFML/Graphics.hpp>

#define WIDTH 900
#define HEIGHT 500

#define MAIN_MENU "main menu"

//Player
#define PLAYER_MAX_LIFE 100
#define PLAYER_DAMAGE 10
#define JUMP_FORCE 100
#define SAMUS_POSITION sf::Vector2f(50, HEIGHT - 125)
#define SAMUS_SPEED 40
#define SAMUS_SCALE 1.5f
#define GRAVITY 0.5f

#define MANA_PER_ATTACK 5
#define MANA_REGEN 1

//Mob
#define MOB_MAX_LIFE 50
#define MOB_DAMAGE 15
#define PALPATINE_POSITION sf::Vector2f(WIDTH-125, HEIGHT - 125)
#define PALPATINE_SCALE 0.8f

//Potion
#define HEAL_POTION 5
#define MANA_POTION 5

//Starter Pack
#define START_HEALPOTION_COUNT 0
#define START_MANAPOTION_COUNT 0
#define START_GOLD_COUNT 0

//Animation
#define SAMUS_ANIMATION_INITIAL_SPEED 1.0f
#define SAMUS_ANIMATION_SPEED 1.0f
#define MOB_ANIMATION_INITIAL_SPEED 1.0f
#define MOB_ANIMATION_SPEED 1.0f
#define CHEST_ANIMATION_INITIAL_SPEED 1.0f
#define CHEST_ANIMATION_SPEED 1.0f

//Chest
#define CHEST_SIZE 0.1f

#define LABEL_FONT ""

