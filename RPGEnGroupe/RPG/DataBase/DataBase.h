#pragma once
#include <SFML/Graphics.hpp>

#define WIDTH 1500
#define HEIGHT 800
#define BACKGROUND_SCALE sf::Vector2f(3.0f, 2.4f)

#define MAIN_MENU "main menu"

#pragma region Platforme
#define PLATFORME1_SCALE 0.3f
#define PLATFORME2_SCALE 0.3f
#define PLATFORME3_SCALE 0.3f
#define PLATFORME4_SCALE 0.3f

#define PLATFORME1_POSITION sf::Vector2f(50, 550)
#define PLATFORME2_POSITION sf::Vector2f(700, 275)
#define PLATFORME3_POSITION sf::Vector2f(400, 400)
#define PLATFORME4_POSITION sf::Vector2f(1000, 100)  
#pragma endregion

#pragma region Player
#define PLAYER_MAX_LIFE 100
#define PLAYER_DAMAGE 10
#define JUMP_FORCE 250
#define SAMUS_POSITION sf::Vector2f(50, HEIGHT - 140)
#define SAMUS_SPEED 10
#define SAMUS_SCALE 1.5f
#define GRAVITY 1.0f

#define MANA_PER_ATTACK 5
#define MANA_REGEN 1  
#pragma endregion

#pragma region Mob
#define MOB_MAX_LIFE 50
#define MOB_DAMAGE 15
#define PALPATINE_POSITION sf::Vector2f(WIDTH-125, HEIGHT - 125)
#define PALPATINE_SCALE 0.8f
#define MOB_SPEED 10  
#pragma endregion

#pragma region Potions and Coins
#define HEAL_POTION 5
#define MANA_POTION 5

#define POTION_HEAL_POSITION sf::Vector2f(WIDTH-100, 40)
#define POTION_MANA_POSITION sf::Vector2f(WIDTH-50, 40)

#define POTION_HEAL_ROD_POSITION sf::Vector2f(5, HEIGHT - 30)
#define POTION_MANA_ROD_POSITION sf::Vector2f(50, HEIGHT - 37)

#define COIN_POSITION sf::Vector2f(WIDTH-30, 8)

#define TEXT_MANA_POSITION sf::Vector2f(WIDTH-30, 65)
#define TEXT_HEAL_POSITION sf::Vector2f(WIDTH-80, 65)

#define TEXT_HEAL_ROD_POSITION sf::Vector2f(35, HEIGHT - 22.5f)
#define TEXT_MANA_ROD_POSITION sf::Vector2f(85, HEIGHT - 22.5f)

#define TEXT_COIN_POSITION sf::Vector2f(WIDTH-55, 10)
#define COLOR_TEXT sf::Color::White
#define SIZE_TEXT 15

#define POTION_MANA_SCALE 0.5f
#define POTION_HEAL_SCALE 0.5f

#define POTION_MANA_ROD_SCALE 0.07f
#define POTION_HEAL_ROD_SCALE 0.02f

#define COIN_SCALE 0.2f  
#pragma endregion

#pragma region Item
#define QUANTITY_OF_ITEMS_TYPE 3  
#pragma endregion

#pragma region Starter Pack
#define START_HEALPOTION_COUNT 0
#define START_MANAPOTION_COUNT 0
#define START_GOLD_COUNT 0  
#pragma endregion

#pragma region Animation
#define SAMUS_ANIMATION_INITIAL_SPEED 0.1f
#define SAMUS_ANIMATION_SPEED 0.1f
#define MOB_ANIMATION_INITIAL_SPEED 0.1f
#define MOB_ANIMATION_SPEED 0.1f
#define CHEST_ANIMATION_INITIAL_SPEED 0.1f
#define CHEST_ANIMATION_SPEED 0.1f  
#pragma endregion

#pragma region Chest
#define CHEST_SCALE 0.4f

#define CHEST_POSITION sf::Vector2f(1200, 45)

#define CHEST_SIZE 0.1f  
#pragma endregion


