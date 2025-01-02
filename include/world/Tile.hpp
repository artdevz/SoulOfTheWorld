#ifndef TILE_HPP
#define TILE_HPP

#include <vector>

class Tile {

    public:

        Tile();
        Tile(Vector2, const char*);

        void Draw() const;

        Vector2 GetPosition() const;

    private:

        Vector2 position;
        Texture2D texture;
        static const int SIZE = 16;

};

#endif