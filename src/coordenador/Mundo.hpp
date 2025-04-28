#ifndef MUNDO_HPP
#define MUNDO_HPP

#include "../entidades/Entidade.hpp"
#include "../sistemas/MovimentoSistema.hpp"
#include <vector>

class Mundo {
private:
    std::vector<Entidade> entidades;
    MovimentoSistema movimentoSistema;

public:
    Entidade& criarEntidade() {
        entidades.emplace_back();
        return entidades.back();
    }

    void atualizar(float dt) {
        for (auto& entidade : entidades) {
            movimentoSistema.atualizar(entidade, dt);
        }
    }
};

#endif