#ifndef MOVIMENTOSISTEMA_HPP
#define MOVIMENTOSISTEMA_HPP

#include "../entidades/Entidade.hpp"
#include "../componentes/TransformaComponente.hpp"
#include <SFML/Window/Keyboard.hpp>

class MovimentoSistema {
public:
    void atualizar(Entidade& entidade, float dt) {
        auto transform = entidade.getComponente<TransformaComponente>();
        if (!transform) return;

        float velocidade = 250.0f; // pixels por segundo

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            transform->posicao.y -= velocidade * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            transform->posicao.y += velocidade * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            transform->posicao.x -= velocidade * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            transform->posicao.x += velocidade * dt;
    }
};

#endif