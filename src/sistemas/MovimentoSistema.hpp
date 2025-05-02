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
        float velocidadeCorrida = velocidade * 3; // Velocidade de Corrida (pixels por segundo)

        // Corrida (os dois shifts)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            velocidade = velocidadeCorrida;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
            velocidade = velocidadeCorrida;

        // Controles de movimento no AWSD
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            transform->posicao.y -= velocidade * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            transform->posicao.y += velocidade * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            transform->posicao.x -= velocidade * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            transform->posicao.x += velocidade * dt;
        
        // Controles de movimento nas setinhas...
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            transform->posicao.y -= velocidade * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            transform->posicao.y += velocidade * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            transform->posicao.x -= velocidade * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
            transform->posicao.x += velocidade * dt;
    }
};

#endif