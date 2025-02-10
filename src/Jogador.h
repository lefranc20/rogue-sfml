#ifndef JOGADOR_H
#define JOGADOR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory> // Para shared_ptr
#include <sstream> // Necessário para converter número em string

const unsigned JANELA_LARGURA = 800;
const unsigned JANELA_ALTURA = 600;

class Jogador {
public:
    Jogador();
    void atualizar(float deltaTime);
    void adicionarEquipamento(const std::string& caminhoTextura);

    sf::Sprite& getSprite();
    const std::vector<sf::Sprite>& getEquipamentos() const;
    sf::Vector2f getPosicao();

    // para as Vidas
    const sf::Text& getTextoVidas() const { return textoVidas; }
    int getVidas() const; // Para acessar o número de vidas
    void perderVida(); // Reduz a vida do jogador

    bool isGameOver() const { return gameOver; }

private:
    sf::Texture textura;
    sf::Sprite sprite;

    std::vector<std::shared_ptr<sf::Texture>> texturasEquipamentos;
    std::vector<sf::Sprite> spritesEquipamentos;
    
    // Variáveis de animação
    int frameIndex = 0;
    const int frameMax = 9;
    float frameTime = 0.15f;
    float frameClock = 0.0f;
    int direcao = 2; // 0 = Cima, 1 = Esquerda, 2 = Baixo, 3 = Direita

    // Para o Sistema de Vidas
    int vidas = 3; // O jogador começa com 3 vidas
    sf::Font fonte; // Fonte para exibir as vidas na tela
    sf::Text textoVidas;
    void atualizarTextoVidas();

    bool gameOver = false;

};

#endif