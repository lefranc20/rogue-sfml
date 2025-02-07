#include <iostream>
#include <SFML/Graphics.hpp>

int main(){

	// =========== INICIALIZA ===========
	const unsigned JANELA_LARGURA = 800;
	const unsigned JANELA_ALTURA = 600;
	sf::ContextSettings configuracoes;
	configuracoes.antialiasingLevel = 8; // Define o nível de suavização das bordas, para não ficar tão serrilhado
	sf::RenderWindow janela(sf::VideoMode(JANELA_LARGURA, JANELA_ALTURA), "Jogo em SFML!", sf::Style::Default, configuracoes);
	// =========== INICIALIZA ===========

	// =========== CARREGA ===========
	// Jogador
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("assets/BODY_skeleton.png")){
		std::cout << "Imagem do jogador carregada" << std::endl;
		playerSprite.setTexture(playerTexture);

		// Define o sprite inicial na primeira posição da spritesheet
		playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		playerSprite.scale(sf::Vector2f(2,2)); // Aumenta o tamanho do sprite
	} else {
		std::cout << "Imagem do jogador falhou no carregamento!" << std::endl;
	}

	// Chão
	sf::Texture chaoTexture;
	if (chaoTexture.loadFromFile("assets/Ground_01.png")) {
		std::cout << "Imagem do chão carregada" << std::endl;
		chaoTexture.setRepeated(true); // Permite que a textura se repita automaticamente
	} else {
		std::cout << "Imagem do chão falhou no carregamento!" << std::endl;
	}

	// Retângulo que cobre a área do chão (toda a janela)
	sf::RectangleShape chaoShape(sf::Vector2f(JANELA_LARGURA, JANELA_ALTURA));
	chaoShape.setTexture(&chaoTexture);
	chaoShape.setTextureRect(sf::IntRect(0, 0, JANELA_LARGURA, JANELA_ALTURA));
	chaoShape.setPosition(0, JANELA_ALTURA - JANELA_ALTURA);

	// =========== CARREGA ===========

	// Variáveis de animação
	int frameIndex = 0;
	const int frameMax = 9; // Número total de frames na animação
	float frameTime = 0.15f; // Tempo para trocar de frame
	float frameClock = 0.0f; // Acumulador de tempo para troca de frames

	int direcao = 2; // 0 = Cima, 1 = Esquerda, 2 = Baixo, 3 = Direita
	sf::Clock clock;
	
	// Configurações extras de tela
	sf::FloatRect player_bounds = playerSprite.getGlobalBounds();
	sf::View view(sf::FloatRect(0.f, 0.f, JANELA_LARGURA, JANELA_ALTURA));  // Define a view com resolução fixa
    janela.setView(view);  // Define a view na janela

	// loop principal do jogo
	while(janela.isOpen()){
		float deltaTime = clock.restart().asSeconds(); // Calcula o tempo entre frames

		// =========== ATUALIZA ===========
		sf::Event evento;
		while (janela.pollEvent(evento)){
			if (evento.type == sf::Event::Closed){
				janela.close();
			}
		}

        // Ajuste da View para redimensionamento
        sf::Vector2u tamanhoJanela = janela.getSize();
        float aspectRatio = static_cast<float>(tamanhoJanela.x) / static_cast<float>(tamanhoJanela.y);  // Relação de aspecto da janela
        view.setSize(JANELA_LARGURA * aspectRatio, JANELA_ALTURA);  // Ajusta o tamanho da view conforme a relação de aspecto
        view.setCenter(JANELA_LARGURA / 2, JANELA_ALTURA / 2);  // Centraliza a view
        janela.setView(view);  // Aplica a view à janela

		sf::Vector2f posicao = playerSprite.getPosition(); // Obtém posição atual do jogador
		bool isMoving = false; // Indica se o jogador está se movendo

		// Controles de Movimento
		float velocidade = 200.0f; // Velocidade normal
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
			velocidade = 400.0f; // Aumenta a velocidade ao segurar Shift
		}

		// Esquerda
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			playerSprite.setPosition(posicao + sf::Vector2f(-velocidade * deltaTime, 0));
			isMoving = true;
			direcao = 1;
		}
		// Cima
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			playerSprite.setPosition(posicao + sf::Vector2f(0, -velocidade * deltaTime)); // segue o padrão de dimensionamento do sfml com o topo em -y
			isMoving = true;
			direcao = 0;
		}
		// Baixo
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			playerSprite.setPosition(posicao + sf::Vector2f(0, velocidade * deltaTime));
			isMoving = true;
			direcao = 2;
		}
		// Direita
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			playerSprite.setPosition(posicao + sf::Vector2f(velocidade * deltaTime, 0));
			isMoving = true;
			direcao = 3;
		}

		// Animação do personagem
		if (isMoving) {
			frameClock += deltaTime; // Acumula tempo
			if (frameClock >= frameTime) { // Verifica se é hora de trocar o frame
				frameClock = 0.0f;
				frameIndex = (frameIndex + 1) % frameMax; // Avança o frame ciclicamente
			}
			// Define o recorte do sprite para exibir o frame correto
			playerSprite.setTextureRect(sf::IntRect(frameIndex * 64, direcao * 64, 64, 64));
		} else {
			// Se o jogador não está se movendo, exibe o primeiro frame da direção atual
			playerSprite.setTextureRect(sf::IntRect(0, direcao * 64, 64, 64));
		}

		// Colisões com a Janela
		// Colisão Esquerda
		if (playerSprite.getPosition().x < 0.f){ // f significa float
			playerSprite.setPosition(0.f, playerSprite.getPosition().y);
		}
		// Colisão Acima
		if (playerSprite.getPosition().y < 0.f){
			playerSprite.setPosition(playerSprite.getPosition().x, 0.f);
		}
		// Colisão Direita
		if (playerSprite.getPosition().x + playerSprite.getGlobalBounds().width > JANELA_LARGURA){
			playerSprite.setPosition(JANELA_LARGURA - playerSprite.getGlobalBounds().width, playerSprite.getPosition().y);
		}
		// Colisão Abaixo
		if (playerSprite.getPosition().y + playerSprite.getGlobalBounds().height > JANELA_ALTURA){
			playerSprite.setPosition(playerSprite.getPosition().x, JANELA_ALTURA - playerSprite.getGlobalBounds().height);
		}
	
		// =========== ATUALIZA ===========

		// =========== EXIBE ===========
		janela.clear(); // Limpa a tela
		janela.draw(chaoShape); // Exibe o chão de fundo
		janela.draw(playerSprite); // Exibe o jogador
		janela.display(); // Exibe o que foi desenhado
		// =========== EXIBE ===========
	}
	return 0;
}
