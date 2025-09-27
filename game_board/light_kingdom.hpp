//
// Created by muham on 26.09.2025.
//

#ifndef ANKR_DECAY_LIGHT_KINGDOM_HPP
#define ANKR_DECAY_LIGHT_KINGDOM_HPP

#include <iostream>
#include <vector>

enum class TileType{
    EMPTY,
    WALL,
    PLAYER,
    ENEMY
};

class FallenKingdom {
private:
    int height, width;
    std::vector<std::vector<TileType>> tiles;
public:
    FallenKingdom(const int h, const int w) : height(h), width(w), tiles(h, std::vector<TileType>(w, TileType::EMPTY)) {
        tiles.resize(height, std::vector<TileType>(width, TileType::EMPTY));

        for (int i = 0; i < width; i++) {
            tiles[0][i] = TileType::WALL;
            tiles[height - 1][i] = TileType::WALL;
        }

        for (int i = 0; i < height; ++i) {
            tiles[i][0] = TileType::WALL;
            tiles[i][width - 1] = TileType::WALL;
        }
    }

    void display_board() const {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                switch (tiles[i][j]) {
                    case TileType::WALL:    std::cout << "# "; break;
                    case TileType::PLAYER:  std::cout << "P "; break;
                    case TileType::ENEMY:   std::cout << "E "; break;
                    case TileType::EMPTY:   std::cout << ". "; break;
                    default:                std::cout << "? "; break;
                }
            }
            std::cout << std::endl;
        }
    }

    void setTile(const int x, const int y, const TileType type) {
        if (y >= 0 && y < height && x >= 0 && x < width) {
            tiles[y][x] = type;
        }
    }

    [[nodiscard]] TileType getTile(const int x, const int y) const {
        if (y >= 0 && y < height && x >= 0 && x < width) return tiles[y][x];
        return TileType::WALL;
    }
    [[nodiscard]] int getHeight() const { return height; }
    [[nodiscard]] int getWidth() const { return width; }
};

#endif //ANKR_DECAY_LIGHT_KINGDOM_HPP