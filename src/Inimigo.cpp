#include "Inimigo.h"
#include <cmath>
#include <iostream>

// Construtor
Inimigo::Inimigo(float x, float y) {
    if (!textura.loadFromFile("assets/inimigo.png")) {
        std::cerr << "Erro ao carregar textura do inimigo!" << std::endl;
    }
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    sprite.setScale(2.f, 2.f); // Aumenta o tamanho do sprite
    sprite.setPosition(x, y); // A posição é declarada no Jogo.cpp

    velocidade = 100.0f; // Talvez mudar isso para outro local?
}

// Método para ele seguir o jogador
void Inimigo::seguir(sf::Vector2f posJogador, float deltaTime) {
    sf::Vector2f posInimigo = sprite.getPosition();
    sf::Vector2f direcao = posJogador - posInimigo;

    // Normalização do vetor direção
    float comprimento = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
    if (comprimento != 0) {
        direcao /= comprimento;
    }

    // Move o inimigo na direção do jogador
    sprite.move(direcao * velocidade * deltaTime);
}

// Método para obter o sprite do inimigo
sf::Sprite& Inimigo::getSprite() {
    return sprite;
}

// Método para pegar a posição do inimigo.
sf::Vector2f Inimigo::getPosicao() {
    return sprite.getPosition();
}
