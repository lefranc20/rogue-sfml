#include "Mundo.h"

Mundo::Mundo() : inimigo(800.f, 800.f) {
    if (!texturaChao.loadFromFile(obterCaminhoAsset("Ground_01.png"))) {
        std::cerr << "Erro ao carregar textura do chão!" << std::endl;
    }
    camera.setSize(JANELA_LARGURA, JANELA_ALTURA);
    camera.setCenter(jogador.getSprite().getPosition());    

    chao.setSize(sf::Vector2f(JANELA_LARGURA, JANELA_ALTURA));
    chao.setTexture(&texturaChao);

    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/HEAD_hair_blonde.png"));
    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/LEGS_plate_armor_pants.png"));
    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/TORSO_chain_armor_jacket_purple.png"));
    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/TORSO_leather_armor_shoulders.png"));
    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/FEET_shoes_brown.png"));
    jogador.adicionarEquipamento(obterCaminhoAsset("equipamentos/BELT_leather.png"));
}

void Mundo::atualizar(float deltaTime) {
    jogador.atualizar(deltaTime);

    camera.setCenter(jogador.getSprite().getPosition());

    // Atualiza os projéteis
    for (auto it = projeteis.begin(); it != projeteis.end(); ) {
        it->atualizar(deltaTime);

         // Verifica se o projétil acertou o inimigo
        if (it->getForma().getGlobalBounds().intersects(inimigo.getSprite().getGlobalBounds())) {
            inimigo.respawn(); // Respawn do inimigo ao ser atingido
            jogador.adicionarPontos(); // Incrementa a pontuação
            it = projeteis.erase(it); // Remove o projétil da lista
        } else {
            ++it;
        }
    }

    // Faz o inimigo seguir o jogador
    inimigo.seguir(jogador.getPosicao(), deltaTime, jogador);

    // Atualiza a câmera para seguir o jogador
    view.setCenter(jogador.getPosicao());
}

void Mundo::desenhar(sf::RenderWindow& janela) {
    janela.setView(view);

    janela.draw(chao);
    janela.draw(inimigo.getSprite());
    janela.draw(jogador.getSprite());

    for (const auto& equipamento : jogador.getEquipamentos()) {
        janela.draw(equipamento);
    }

    for (const auto& proj : projeteis) {
        proj.desenhar(janela);
    }

    janela.setView(janela.getDefaultView());
    jogador.desenharHUD(janela);
    
}

void Mundo::desenharHUD(sf::RenderWindow& janela) {
    jogador.desenharHUD(janela);
}

void Mundo::dispararProjetil(sf::Vector2f destino) {
    sf::Vector2f posJogador = jogador.getPosicao();
    posJogador.x += jogador.getSprite().getGlobalBounds().width / 2.f;
    posJogador.y += jogador.getSprite().getGlobalBounds().height / 2.f;
    projeteis.emplace_back(posJogador, destino);
}

sf::View Mundo::getCameraView() const {
    return camera;
}