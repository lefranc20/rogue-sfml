#include "Jogador.h"

// Construtor: Inicializa posição, textura e sprite
Jogador::Jogador() {
    if (!textura.loadFromFile("assets/BODY_skeleton.png")) {
        std::cerr << "Erro ao carregar textura do jogador!" << std::endl;
    }
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    sprite.setScale(2.f, 2.f); // Aumenta o tamanho do sprite
    sprite.setPosition(400.f, 300.f); // Define a posição inicial
}

// Atualiza a posição do jogador e a animação
void Jogador::atualizar(float deltaTime) {
    sf::Vector2f novaPosicao = sprite.getPosition();
    bool isMoving = false;

    float velocidade = 200.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        velocidade = 400.0f; // Aumenta a velocidade ao segurar Shift
    }

    // Verifica teclas pressionadas e ajusta a posição
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        novaPosicao.x -= velocidade * deltaTime;
        isMoving = true;
        direcao = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        novaPosicao.y -= velocidade * deltaTime;
        isMoving = true;
        direcao = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        novaPosicao.y += velocidade * deltaTime;
        isMoving = true;
        direcao = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        novaPosicao.x += velocidade * deltaTime;
        isMoving = true;
        direcao = 3;
    }

    // Colisões com a borda da tela
    if (novaPosicao.x < 0.f) novaPosicao.x = 0.f;
    if (novaPosicao.y < 0.f) novaPosicao.y = 0.f;
    if (novaPosicao.x + sprite.getGlobalBounds().width > JANELA_LARGURA)
        novaPosicao.x = JANELA_LARGURA - sprite.getGlobalBounds().width;
    if (novaPosicao.y + sprite.getGlobalBounds().height > JANELA_ALTURA)
        novaPosicao.y = JANELA_ALTURA - sprite.getGlobalBounds().height;

    // Aplica a nova posição ao sprite
    sprite.setPosition(novaPosicao);

    // Animação
    if (isMoving) {
        frameClock += deltaTime;
        if (frameClock >= frameTime) {
            frameClock = 0.0f;
            frameIndex = (frameIndex + 1) % frameMax;
        }
        sprite.setTextureRect(sf::IntRect(frameIndex * 64, direcao * 64, 64, 64));
    } else {
        sprite.setTextureRect(sf::IntRect(0, direcao * 64, 64, 64));
    }
}

// Retorna o sprite para ser desenhado no jogo
sf::Sprite& Jogador::getSprite() {
    return sprite;
}
