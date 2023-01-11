#include "RPG_Image.h"
#include "../../Window/Window.h"
#pragma region constructor/destructor
RPG_Image::RPG_Image(Window* _owner, const char* _path) : RPG_UIElement(_owner)
{
    sprite = new sf::Sprite();
    texture = new sf::Texture();
    if (!texture->loadFromFile(_path))
    {
        Free();
        return;
    }
    sprite->setTexture(*texture);
}

RPG_Image::RPG_Image(const RPG_Image& _copy) : RPG_UIElement(_copy)
{
    sprite = _copy.sprite;
    texture = _copy.texture;
}

RPG_Image::~RPG_Image()
{
    Free();
}
#pragma endregion constructor/destructor
#pragma region methods
void RPG_Image::Free()
{
    delete sprite;
    sprite = nullptr;
    delete texture;
    texture = nullptr;
}
sf::FloatRect RPG_Image::GlobalBounds() const
{
    return sprite->getGlobalBounds();
}
#pragma endregion methods
#pragma region override
void RPG_Image::SetPosition(const sf::Vector2f& _position)
{
    sprite->setPosition(_position);
}

void RPG_Image::SetScale(const sf::Vector2f& _scale)
{
    sprite->setScale(_scale);
}

void RPG_Image::Draw(Window* _window)
{
    if (sprite != nullptr)
        _window->Draw(sprite);
}

void RPG_Image::SetOrigin(const sf::Vector2f& _origin)
{
    sprite->setOrigin(_origin);
}
sf::FloatRect RPG_Image::GetGlobalBounds() const
{
    return sprite->getGlobalBounds();
}
#pragma endregion override