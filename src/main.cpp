#include <SFML/Graphics.hpp>
#include "coordenador/Mundo.hpp"
#include "componentes/TransformaComponente.hpp"

int main() {
    sf::RenderWindow janela(sf::VideoMode(800, 600), "ECS Teste Jogo 2D", sf::Style::Titlebar | sf::Style::Close);    
    janela.setFramerateLimit(60);

    // View principal (tela cheia)
    sf::View view = janela.getDefaultView();
    view.setSize(800, 600);
    janela.setView(view);

    // View do minimapa
    sf::View viewMiniMapa = view;
    viewMiniMapa.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));

    // Criando o mundo e a entidade jogador
    Mundo mundo;
    Entidade& jogador = mundo.criarEntidade();

    auto transformJogador = std::make_shared<TransformaComponente>();
    transformJogador->posicao = sf::Vector2f(400, 300);
    jogador.addComponente(transformJogador);

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

        // --- View principal ---
        janela.setView(view);
        jogadorShape.setPosition(transformJogador->posicao);
        janela.draw(jogadorShape);

        // --- View do minimapa ---
        janela.setView(viewMiniMapa);
        janela.draw(jogadorShape); // Desenha o jogador também na visão do minimapa

        janela.display();
    }

    return 0;
}