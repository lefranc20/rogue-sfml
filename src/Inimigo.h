#ifndef INIMIGO_H
#define INIMIGO_H

#include <SFML/Graphics.hpp>

class Inimigo {
public:
    Inimigo(float x, float y);
    void seguir(sf::Vector2f posJogador, float deltaTime);
    sf::Sprite& getSprite();
    sf::Vector2f getPosicao();

private:
    sf::Sprite sprite;
    sf::Texture textura;
    float velocidade;
};

#endif