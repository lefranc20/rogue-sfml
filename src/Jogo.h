#ifndef JOGO_H
#define JOGO_H

#include <SFML/Graphics.hpp>
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

    sf::RenderWindow janela;
    sf::Texture texturaChao;
    sf::RectangleShape chao;
    Jogador jogador;
    Inimigo inimigo;
};

#endif // JOGO_H