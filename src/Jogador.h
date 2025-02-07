#ifndef JOGADOR_H
#define JOGADOR_H

#include <SFML/Graphics.hpp>
#include <iostream>

const unsigned JANELA_LARGURA = 800;
const unsigned JANELA_ALTURA = 600;

class Jogador {
private:
    sf::Texture textura;
    sf::Sprite sprite;
    
    // Variáveis de animação
    int frameIndex = 0;
    const int frameMax = 9;
    float frameTime = 0.15f;
    float frameClock = 0.0f;
    int direcao = 2; // 0 = Cima, 1 = Esquerda, 2 = Baixo, 3 = Direita

public:
    Jogador();
    void atualizar(float deltaTime);
    sf::Sprite& getSprite();
    sf::Vector2f getPosicao();
};

#endif
