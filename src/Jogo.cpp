#include "Jogo.h"
#include <iostream>

Jogo::Jogo() : janela(sf::VideoMode(JANELA_LARGURA, JANELA_ALTURA), "Jogo em SFML!"), inimigo(100.f, 100.f) 
{
    if (!texturaChao.loadFromFile("assets/Ground_01.png")) {
        std::cerr << "Erro ao carregar textura do chão!" << std::endl;
    }
    chao.setSize(sf::Vector2f(JANELA_LARGURA, JANELA_ALTURA));
    chao.setTexture(&texturaChao);

    jogador.adicionarEquipamento("assets/equipamentos/HEAD_hair_blonde.png"); // cabelo
    jogador.adicionarEquipamento("assets/equipamentos/LEGS_plate_armor_pants.png"); // pernas
    jogador.adicionarEquipamento("assets/equipamentos/TORSO_chain_armor_jacket_purple.png"); // torso
    jogador.adicionarEquipamento("assets/equipamentos/TORSO_leather_armor_shoulders.png"); // ombro
    jogador.adicionarEquipamento("assets/equipamentos/FEET_shoes_brown.png"); // pés
    jogador.adicionarEquipamento("assets/equipamentos/BELT_leather.png"); // cinto

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

    // Obtém a posição do jogador e faz o inimigo segui-lo
    sf::Vector2f posJogador = jogador.getPosicao();
    inimigo.seguir(posJogador, deltaTempo, jogador);

}

// Renderiza tudo na tela
void Jogo::renderizar() {
    janela.clear();
    janela.draw(chao);
    janela.draw(inimigo.getSprite());
    janela.draw(jogador.getSprite());
    for (const auto& equipamento : jogador.getEquipamentos()) {
        janela.draw(equipamento);
    }
    janela.draw(jogador.getTextoVidas());
    janela.display();
}
