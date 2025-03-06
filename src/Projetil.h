#ifndef PROJETIL_H
#define PROJETIL_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Projetil {
public:
    Projetil(sf::Vector2f posInicial, sf::Vector2f destino);
    void atualizar(float deltaTempo);
    void desenhar(sf::RenderWindow& janela) const;
    bool foraDaTela(sf::Vector2u tamanhoJanela);

private:
    sf::CircleShape forma;
    sf::Vector2f velocidade;
    float velocidadeProjetil = 500.f; // Velocidade do projétil
};

#endif