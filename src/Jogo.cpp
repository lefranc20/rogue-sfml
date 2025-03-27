#include "Jogo.h"

Jogo::Jogo() : janela(sf::VideoMode(JANELA_LARGURA, JANELA_ALTURA), "Jogo em SFML!"), inimigo(100.f, 100.f) 
{
    if (!texturaChao.loadFromFile(obterCaminhoAsset("Ground_01.png"))) {
        std::cerr << "Erro ao carregar textura do chão!" << std::endl;
    }
    chao.setSize(sf::Vector2f(JANELA_LARGURA, JANELA_ALTURA));
    chao.setTexture(&texturaChao);

    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/HEAD_hair_blonde.png")); // cabelo
    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/LEGS_plate_armor_pants.png")); // pernas
    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/TORSO_chain_armor_jacket_purple.png")); // torso
    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/TORSO_leather_armor_shoulders.png")); // ombro
    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/FEET_shoes_brown.png")); // pés
    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/BELT_leather.png")); // cinto

    inicializarGameOver();
}

void Jogo::executar() {
    sf::Clock relogio;
    std::vector<Projetil> projeteis;
    while (janela.isOpen()) {
        float deltaTempo = relogio.restart().asSeconds();
        processarEventos();
        atualizar(deltaTempo);
        renderizar();
    }
}

void Jogo::processarEventos() {
    sf::Event evento;
    while (janela.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
            janela.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            janela.close();
        }

        // Dispara um projétil ao clicar com o botão esquerdo do mouse
        if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f posJogador = jogador.getPosicao(); // pegando a posição base do jogador

            // Ajusta para o centro do sprite do jogador
            posJogador.x += jogador.getSprite().getGlobalBounds().width / 2.f;
            posJogador.y += jogador.getSprite().getGlobalBounds().height / 2.f;

            sf::Vector2f destino = janela.mapPixelToCoords(sf::Mouse::getPosition(janela));

            projeteis.emplace_back(posJogador, destino);
        }
    }
}

void Jogo::atualizar(float deltaTempo) {
    jogador.atualizar(deltaTempo);

    // Atualiza os projéteis
    for (auto it = projeteis.begin(); it != projeteis.end(); ) {
        it->atualizar(deltaTempo);

        // Verifica se o projétil acertou o inimigo
        if (it->getForma().getGlobalBounds().intersects(inimigo.getSprite().getGlobalBounds())) {
            inimigo.respawn(); // Respawn do inimigo ao ser atingido
            jogador.adicionarPontos();  // Incrementa a pontuação
            it = projeteis.erase(it); // Remove o projétil da lista
        } else {
            ++it;
        }
    }

    // Faz o inimigo seguir o jogador
    sf::Vector2f posJogador = jogador.getPosicao();
    inimigo.seguir(posJogador, deltaTempo, jogador);
}


// Renderiza tudo na tela
void Jogo::renderizar() {
    janela.clear();
    janela.draw(chao);

    if (!jogador.isGameOver()) {
        janela.draw(inimigo.getSprite());
        janela.draw(jogador.getSprite());

        for (const auto& equipamento : jogador.getEquipamentos()) {
            janela.draw(equipamento);
        }

        janela.draw(jogador.getTextoVidas());
        janela.draw(jogador.getTextoPontos());

        // Renderizar projéteis
        for (const auto& proj : projeteis) {
            proj.desenhar(janela);
        }
    } else {
        janela.draw(textoGameOver);
        janela.draw(textoMensagenzinha);
    }

    janela.display();
}

void Jogo::inicializarGameOver() {
    if (!fonteGameOver.loadFromFile(obterCaminhoAsset("VT323-Regular.ttf"))) {
        std::cerr << "Erro ao carregar fonte!" << std::endl;
    }
    textoGameOver.setFont(fonteGameOver);
    textoGameOver.setString("GAME OVER");
    textoGameOver.setCharacterSize(100);
    textoGameOver.setFillColor(sf::Color::Red);
    textoGameOver.setStyle(sf::Text::Bold);
    textoGameOver.setPosition(JANELA_LARGURA / 2.f - 200.f, JANELA_ALTURA / 2.f - 50.f);

    // "(Pressione ESC para sair)"
    textoMensagenzinha.setFont(fonteGameOver);
    textoMensagenzinha.setString("(Pressione ESC para sair)");
    textoMensagenzinha.setCharacterSize(30);
    textoMensagenzinha.setFillColor(sf::Color::White);
    textoMensagenzinha.setStyle(sf::Text::Regular);
    textoMensagenzinha.setPosition(JANELA_LARGURA / 2.f - 150.f, JANELA_ALTURA / 2.f + 50.f);
}