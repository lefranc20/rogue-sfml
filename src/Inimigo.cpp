#include "Inimigo.h"
#include <cmath>
#include <iostream>
#include <ctime>    // Para seed do rand()

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
void Inimigo::seguir(sf::Vector2f posJogador, float deltaTime, Jogador& jogador) {
    sf::Vector2f posInimigo = sprite.getPosition();
    sf::Vector2f direcaoVetor = posJogador - posInimigo;

    // Normalização do vetor direção = Serve para que ele tenha o seu comprimento igual a 1, ideal para conseguir a direção do mesmo 
    float comprimento = std::sqrt(direcaoVetor.x * direcaoVetor.x + direcaoVetor.y * direcaoVetor.y);
    if (comprimento != 0) {
        direcaoVetor /= comprimento;
    }

    // Checagem de Vida do Jogador
    float distancia = std::sqrt(std::pow(posJogador.x - sprite.getPosition().x, 2) +
    std::pow(posJogador.y - sprite.getPosition().y, 2));
    if (distancia < 50.0f) { // Se estiver muito perto do jogador
        jogador.perderVida();
        respawn(); // faz o inimigo reaparecer em outro local aleatorio
    }

    // Atualizar a direção do sprite com base no movimento
    if (std::abs(direcaoVetor.x) > std::abs(direcaoVetor.y)) {
        inimigoDirecao = (direcaoVetor.x > 0) ? 3 : 1; // Direita ou Esquerda
    } else {
        inimigoDirecao = (direcaoVetor.y > 0) ? 2 : 0; // Baixo ou Cima
    }

    // Move o inimigo na direção do jogador
    sprite.move(direcaoVetor * velocidade * deltaTime);

    // Atualizar a animação
    inimigoFrameClock += deltaTime;
    if (inimigoFrameClock >= inimigoFrameTime) {
        inimigoFrameClock = 0.0f;
        inimigoFrameIndex = (inimigoFrameIndex + 1) % inimigoFrameMax;
    }

    // Aplicar o frame correto à textura
    sprite.setTextureRect(sf::IntRect(inimigoFrameIndex * 64, inimigoDirecao * 64, 64, 64));

    std::cout << "Posição do Inimigo: " << sprite.getPosition().x << ", " << sprite.getPosition().y << std::endl;
}

// Método para obter o sprite do inimigo
sf::Sprite& Inimigo::getSprite() {
    return sprite;
}

// Método para pegar a posição do inimigo.
sf::Vector2f Inimigo::getPosicao() {
    return sprite.getPosition();
}

// Método para reposicionar o inimigo em uma posição aleatória
void Inimigo::respawn() {
    float novoX = static_cast<float>(rand() % JANELA_LARGURA);
    float novoY = static_cast<float>(rand() % JANELA_ALTURA);
    
    sprite.setPosition(novoX, novoY);
}