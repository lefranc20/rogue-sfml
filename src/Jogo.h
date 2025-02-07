#ifndef JOGO_H
#define JOGO_H

#include <SFML/Graphics.hpp>
#include "Jogador.h"

class Jogo {
public:
    Jogo();
    void executar();

private:
    void processarEventos();
    void atualizar(float deltaTempo);
    void renderizar();

    sf::RenderWindow janela;
    sf::Texture texturaChao;
    sf::RectangleShape chao;
    Jogador jogador;
};

#endif // JOGO_H