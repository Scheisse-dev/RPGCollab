#include "RPG_Mob.h"
#include "../../../../Animation/Animation.h"

#pragma region constructor/destructor
RPG_Mob::RPG_Mob(const int _life, const int _damage, const char* _name, const char* _path, const float _scale, sf::Sprite* _sprite, sf::Vector2f _position) : RPG_Entity( _life, _damage, _name)
{
    patern = new sf::Clock();
    speed = new sf::Clock();
    sprite = _sprite;
    scale = _scale;
    path = _path;
    position = _position; 

    SetScale();
    SetTexture();
    SetPosition();

}

RPG_Mob::RPG_Mob(const RPG_Mob& _copy) : RPG_Entity(_copy) 
{
    patern = _copy.patern;
    sprite = _copy.sprite;
    scale = _copy.scale;
    path = _copy.path;
    position = _copy.position;
}

RPG_Mob::~RPG_Mob() 
{
    texture = nullptr; 
    delete texture;
    sprite = nullptr;
    delete sprite; 
}



#pragma endregion constructor/destructor
#pragma region methods
void RPG_Mob::SetPosition()
{
    sprite->setPosition(position);

}

void RPG_Mob::SetScale()
{
    sprite->setScale(sf::Vector2f(scale, scale));

}

void RPG_Mob::SetTexture()
{
    texture = new sf::Texture();
    if (!texture->loadFromFile(path)) return;
    sprite->setTexture(*texture); 

}

void RPG_Mob::Move()
{
    float _boucle = speed->getElapsedTime().asSeconds();
    float _elapsed = patern->getElapsedTime().asSeconds();

    if (_boucle <= 3.0f)
    {
        if (_elapsed >= 0.1f)
        {
            sprite->setPosition(sprite->getPosition() + sf::Vector2f(-MOB_SPEED, 0));
            patern->restart();
        }
    }
    if (_boucle >= 3.0f && _boucle <= 6.f)
    {
        if (_elapsed >= 0.1f)
        {
            sprite->setPosition(sprite->getPosition() + sf::Vector2f(MOB_SPEED, 0));
            patern->restart();
        }
    }
    if(_boucle >= 6.f)
        speed->restart();

}
#pragma endregion methods
#pragma region override
int RPG_Mob::Life() const
{
    return MOB_MAX_LIFE;
}

int RPG_Mob::Damage() const
{
    return MOB_DAMAGE;
}

std::string RPG_Mob::Name() const
{
    return name;
}
#pragma endregion override