#ifndef INIMIGO_H
#define INIMIGO_H

#include <SFML/Graphics.hpp>
#include "Jogador.h" // necessário para a verificação de vidas
#include "Caminho.h"
#include <cmath>
#include <iostream>
#include <ctime>    // Para seed do rand()

class Inimigo {
public:
    Inimigo(float x, float y);
    void seguir(sf::Vector2f posJogador, float deltaTime, Jogador& jogador);
    sf::Sprite& getSprite();
    sf::Vector2f getPosicao();
    void respawn();
    
private:
    sf::Sprite sprite;
    sf::Texture textura;
    float velocidade;

    float inimigoFrameClock = 0.0f;
    float inimigoFrameTime = 0.12f;  // Tempo entre os frames da animação
    int inimigoFrameIndex = 0;       // Índice do frame atual
    int inimigoFrameMax = 8;         // Número total de frames na spritesheet
    int inimigoDirecao = 2;          // Direção do inimigo (0 = cima, 1 = esquerda, 2 = baixo, 3 = direita)

};

#endif