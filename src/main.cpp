#include <SFML/Graphics.hpp>
#include "coordenador/Mundo.hpp"
#include "componentes/TransformaComponente.hpp"

int main() {
    sf::RenderWindow janela(sf::VideoMode(800, 600), "ECS Teste Jogo 2D");
    janela.setFramerateLimit(60);

    Mundo mundo;
    Entidade& jogador = mundo.criarEntidade();
    auto transform = std::make_shared<TransformaComponente>();
    transform->posicao = sf::Vector2f(400, 300);
    jogador.addComponente(transform);

    sf::CircleShape jogadorShape(20.0f);
    jogadorShape.setFillColor(sf::Color::Green);
    jogadorShape.setOrigin(20.0f, 20.0f);

    sf::Clock clock;

    while (janela.isOpen()) {
        sf::Event event;
        while (janela.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                janela.close();
        }

        float dt = clock.restart().asSeconds();
        mundo.atualizar(dt);

        janela.clear();
        jogadorShape.setPosition(transform->posicao);
        janela.draw(jogadorShape);
        janela.display();
    }

    return 0;
}