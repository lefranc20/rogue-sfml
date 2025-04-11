#include "Jogo.h"

Jogo::Jogo() : janela(sf::VideoMode(JANELA_LARGURA, JANELA_ALTURA), "Jogo em SFML!") {
    inicializarGameOver();
}

void Jogo::executar() {
    sf::Clock relogio;
    while (janela.isOpen()) {
        float deltaTempo = relogio.restart().asSeconds();
        processarEventos();
        mundo.atualizar(deltaTempo);
        renderizar();
    }
}

void Jogo::processarEventos() {
    sf::Event evento;
    while (janela.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            janela.close();
        }

        if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f destino = janela.mapPixelToCoords(sf::Mouse::getPosition(janela));
            mundo.dispararProjetil(destino);
        }
    }
}

void Jogo::renderizar() {
    janela.clear();

    if (!mundo.getJogador().isGameOver()) {
        janela.setView(mundo.getCameraView());
        mundo.desenhar(janela);

        janela.setView(janela.getDefaultView()); // HUD não se move com a câmera
        mundo.desenharHUD(janela);               // Vida e Pontuação
    } else {
        janela.setView(janela.getDefaultView());
        janela.draw(textoGameOver);
        janela.draw(textoMensagenzinha);
    }

    janela.display();
}

void Jogo::inicializarGameOver() {
    if (!fonteGameOver.loadFromFile("assets/VT323-Regular.ttf")) {
        std::cerr << "Erro ao carregar fonte!" << std::endl;
    }
    textoGameOver.setFont(fonteGameOver);
    textoGameOver.setString("GAME OVER");
    textoGameOver.setCharacterSize(100);
    textoGameOver.setFillColor(sf::Color::Red);
    textoGameOver.setStyle(sf::Text::Bold);
    textoGameOver.setPosition(JANELA_LARGURA / 2.f - 200.f, JANELA_ALTURA / 2.f - 50.f);

    textoMensagenzinha.setFont(fonteGameOver);
    textoMensagenzinha.setString("(Pressione ESC para sair)");
    textoMensagenzinha.setCharacterSize(30);
    textoMensagenzinha.setFillColor(sf::Color::White);
    textoMensagenzinha.setStyle(sf::Text::Regular);
    textoMensagenzinha.setPosition(JANELA_LARGURA / 2.f - 150.f, JANELA_ALTURA / 2.f + 50.f);
}