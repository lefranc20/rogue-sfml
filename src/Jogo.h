#ifndef JOGO_H
#define JOGO_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jogador.h"
#include "Inimigo.h"

class Jogo {
public:
    Jogo();
    void executar();

private:
    void processarEventos();
    void atualizar(float deltaTempo);
    void renderizar();
    void inicializarGameOver();

    sf::RenderWindow janela;
    sf::Texture texturaChao;
    sf::RectangleShape chao;
    Jogador jogador;
    Inimigo inimigo;

    sf::Font fonteGameOver;
    sf::Text textoGameOver;
};

#endif // JOGO_H