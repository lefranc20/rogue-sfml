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
    sf::RectangleShape bordaMinimapa;

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
        
        // Adicionando uma bordinha cinza para o minimapa (apenas de teste)
        janela.setView(janela.getDefaultView()); // Reset para coordenadas da janela
        sf::Vector2u tamanhoJanela = janela.getSize();
        sf::FloatRect viewport = viewMiniMapa.getViewport();
    
        bordaMinimapa.setPosition(800 * 0.75f + 1, 0 + 1);  // empurra um pouco mais para dentro
        bordaMinimapa.setSize(sf::Vector2f(200 - 2, 150 - 2)); // 25% de 800x600 é 200x150
        bordaMinimapa.setFillColor(sf::Color::Transparent);
        bordaMinimapa.setOutlineThickness(2);
        bordaMinimapa.setOutlineColor(sf::Color(150, 150, 150)); // RGB para Cinza claro
        janela.draw(bordaMinimapa);

        // --- View do minimapa ---
        janela.setView(viewMiniMapa);
        janela.draw(jogadorShape); // Desenha o jogador também na visão do minimapa
        
        janela.setView(janela.getDefaultView()); // volta para a view padrão para desenhar a borda na posição correta


        // Display final
        janela.display();
    }

    return 0;
}