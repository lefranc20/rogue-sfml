#include "Jogador.h"

// CONSTRUTOR: Inicializa posição, textura e sprite
Jogador::Jogador() {
    if (!textura.loadFromFile("assets/jogador.png")) {
        std::cerr << "Erro ao carregar textura do jogador!" << std::endl;
    }

    /* ALTERAR A TEXTURA 
    * A textura do jogador e inimigo ainda tem que ser alterada/modificada, ela possui cantos transparentes demasiadamente grandes, 
    * que atrapalham, pois dá a impressão que se está colidindo com uma parede invisível, e não os cantos de colisão delimitados pela janela.
    */

    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    sprite.setScale(2.f, 2.f); // Aumenta o tamanho do sprite
    sprite.setPosition(400.f, 300.f); // Define a posição inicial

    // Carregamento daa fonte e configuração do texto de vidas
    if (!fonte.loadFromFile("assets/VT323-Regular.ttf")) {
        std::cerr << "Erro ao carregar fonte!" << std::endl;
    }
    textoVidas.setFont(fonte);
    textoVidas.setCharacterSize(24);
    textoVidas.setFillColor(sf::Color::Red);
    textoVidas.setPosition(10.f, 10.f);
    atualizarTextoVidas();

    // Configuração do texto de pontos (praticamente a mesma coisa de cima)
    textoPontos.setFont(fonte);
    textoPontos.setCharacterSize(24);
    textoPontos.setFillColor(sf::Color::Green);
    textoPontos.setPosition(10.f, 40.f); // Colocando abaixo do texto de vidas
    atualizarTextoPontos();

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
        direcao = 1; // Esquerda
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        novaPosicao.y -= velocidade * deltaTime;
        isMoving = true;
        direcao = 0; // Cima
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        novaPosicao.y += velocidade * deltaTime;
        isMoving = true;
        direcao = 2; // Baixo
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        novaPosicao.x += velocidade * deltaTime;
        isMoving = true;
        direcao = 3; // Direita
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

    // atualiza a animação APENAS caso o jogador esteja se movendo
    if (isMoving) {
        frameClock += deltaTime;
        if (frameClock >= frameTime) {
            frameClock = 0.0f;
            frameIndex = (frameIndex + 1) % frameMax;
        }
        sprite.setTextureRect(sf::IntRect(frameIndex * 64, direcao * 64, 64, 64));
    } else {
        // Reseta para o primeiro quadro da animação de idle
        frameIndex = 0;
        sprite.setTextureRect(sf::IntRect(0, direcao * 64, 64, 64));
    }

    // Atualiza posição e animação dos equipamentos, como o frameIndex fica em 0 com o jogqdor parado, ele não troca o frame do equipamento
    for (auto& equipamento : spritesEquipamentos) {
        equipamento.setPosition(novaPosicao);
        equipamento.setTextureRect(sf::IntRect(frameIndex * 64, direcao * 64, 64, 64));
    }
}



// Retorna o sprite para ser desenhado no jogo
sf::Sprite& Jogador::getSprite() {
    return sprite;
}

// Método para pegar a posição do jogador. Utilizado para o cálculo de movimento do Inimigo até ele.
sf::Vector2f Jogador::getPosicao() {
    return sprite.getPosition();
}

// retorna os sprites dos equipamentos
const std::vector<sf::Sprite>& Jogador::getEquipamentos() const {
    return spritesEquipamentos;
}

// Adiciona um equipamento ao jogador
void Jogador::adicionarEquipamento(const std::string& caminhoTextura) {
    std::shared_ptr<sf::Texture> texturaEquipamento = std::make_shared<sf::Texture>();
    if (!texturaEquipamento->loadFromFile(caminhoTextura)) {
        std::cerr << "Erro ao carregar textura do equipamento: " << caminhoTextura << std::endl;
        return;
    }

    texturasEquipamentos.push_back(texturaEquipamento); // Armazena a textura

    sf::Sprite spriteEquipamento;
    spriteEquipamento.setTexture(*texturasEquipamentos.back()); // Usa ponteiro para manter a textura válida
    spriteEquipamento.setTextureRect(sf::IntRect(0, 0, 64, 64));
    spriteEquipamento.setScale(2.f, 2.f); // Mesmo tamanho do jogador
    spritesEquipamentos.push_back(spriteEquipamento);
}

// Atualiza o texto das vidas
void Jogador::atualizarTextoVidas() {
    std::stringstream ss;
    ss << "Vidas: " << vidas;
    textoVidas.setString(ss.str());
}

// Método para atualizar o texto de pontuação
void Jogador::atualizarTextoPontos() {
    std::stringstream ss;
    ss << "Pontos: " << pontos;
    textoPontos.setString(ss.str());
}

// Incrementa a pontuação
void Jogador::adicionarPontos() {
    pontos++;
    atualizarTextoPontos();  // Atualiza o texto de pontos
}

// Método para perder uma vida
void Jogador::perderVida() {
    if (vidas > 0) {
        vidas--;
        std::cout << "Jogador perdeu uma vida! Vidas restantes: " << vidas << std::endl;
        atualizarTextoVidas();

    }
    if (vidas == 0) {
        std::cout << "GAME OVER!" << std::endl;
        gameOver = true; // Define o estado de Game Over, isso é checado no Jogo.cpp
    }
}

int Jogador::getVidas() const {
    return vidas;
}

int Jogador::getPontos() const {
    return pontos;
}