#ifndef JOGO_H
#define JOGO_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Mundo.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "Caminho.h"

class Jogo {
public:
    Jogo();
    void executar();

private:
    sf::RenderWindow janela;
    Mundo mundo; // <<< ADICIONE ISSO AQUI
    sf::Font fonteGameOver;
    sf::Text textoGameOver;
    sf::Text textoMensagenzinha;

    void processarEventos();
    void renderizar();
    void inicializarGameOver();
};

#endif // JOGO_H