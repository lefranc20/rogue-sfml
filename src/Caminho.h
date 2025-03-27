#ifndef CAMINHO_H
#define CAMINHO_H

#include <filesystem>
#include <string>

inline std::string obterCaminhoAsset(const std::string& nomeArquivo) {
    std::string caminhoBase = std::filesystem::current_path().string();
    return caminhoBase + "/assets/" + nomeArquivo;
}

#endif