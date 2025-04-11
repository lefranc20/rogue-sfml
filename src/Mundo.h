#ifndef MUNDO_H
#define MUNDO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Jogador.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "Caminho.h" // obterCaminhoAsset()
#include "Constantes.h" // Largura e altura da janela

class Mundo {
private:
    Jogador jogador;
    Inimigo inimigo;
    sf::RectangleShape chao;
    sf::Texture texturaChao;


    sf::View view = sf::View(sf::FloatRect(0, 0, JANELA_LARGURA, JANELA_ALTURA));

    std::vector<Projetil> projeteis;

public:
    Mundo();
    sf::View camera;
    sf::View getCameraView() const;

    void atualizar(float deltaTime);
    void desenhar(sf::RenderWindow& janela);
    void dispararProjetil(sf::Vector2f destino);
    void desenharHUD(sf::RenderWindow& janela);

    // Acesso ao jogador (por exemplo, para verificar game over)
    const Jogador& getJogador() const { return jogador; }
};

#endif
