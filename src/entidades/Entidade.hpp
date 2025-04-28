#ifndef ENTIDADE_HPP
#define ENTIDADE_HPP

#include <memory>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <cstdint>  // Para uint32_t

class Entidade {
private:
    std::unordered_map<std::type_index, std::shared_ptr<void>> componentes;

public:
    template<typename T>
    void addComponente(std::shared_ptr<T> componente) {
        componentes[std::type_index(typeid(T))] = componente;
    }

    template<typename T>
    std::shared_ptr<T> getComponente() {
        auto it = componentes.find(std::type_index(typeid(T)));
        if (it != componentes.end()) {
            return std::static_pointer_cast<T>(it->second);
        }
        return nullptr;
    }
};

#endif