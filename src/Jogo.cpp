#include "Jogo.h"
#include <iostream>

Jogo::Jogo() : janela(sf::VideoMode(JANELA_LARGURA, JANELA_ALTURA), "Jogo em SFML!") {
    if (!texturaChao.loadFromFile("assets/Ground_01.png")) {
        std::cerr << "Erro ao carregar textura do chão!" << std::endl;
    }
    chao.setSize(sf::Vector2f(JANELA_LARGURA, JANELA_ALTURA));
    chao.setTexture(&texturaChao);
    
}

void Jogo::executar() {
    sf::Clock relogio;
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
    }
}

void Jogo::atualizar(float deltaTempo) {
    jogador.atualizar(deltaTempo);
}

void Jogo::renderizar() {
    janela.clear();
    janela.draw(chao);
    janela.draw(jogador.getSprite());
    janela.display();
}
