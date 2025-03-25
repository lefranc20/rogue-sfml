#include "Projetil.h"

Projetil::Projetil(sf::Vector2f posJogador, sf::Vector2f destino) {
    forma.setRadius(10.f);
    forma.setFillColor(sf::Color::Blue);

    // Define a origem no centro do círculo
    forma.setOrigin(forma.getRadius(), forma.getRadius());

    // Definir a posição inicial do projétil (já ajustada no Jogo.cpp)
    forma.setPosition(posJogador);

    // Calcular a direção normalizada pra seguir até o destino do mouser
    sf::Vector2f direcao = destino - posJogador;
    float comprimento = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
    
    if (comprimento != 0) {
        direcao /= comprimento;
    }

    velocidade = direcao * velocidadeProjetil;
}


void Projetil::atualizar(float deltaTempo) {
    forma.move(velocidade * deltaTempo);
}

void Projetil::desenhar(sf::RenderWindow& janela) const {
    janela.draw(forma);
}

bool Projetil::foraDaTela(sf::Vector2u tamanhoJanela) {
    sf::Vector2f pos = forma.getPosition();
    return (pos.x < 0 || pos.x > tamanhoJanela.x || pos.y < 0 || pos.y > tamanhoJanela.y);
}