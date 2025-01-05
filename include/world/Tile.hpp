#ifndef TILE_HPP
#define TILE_HPP

#include <vector>

class Tile {

    public:
        
        Tile();
        Tile(Vector2, bool, const Texture2D&);

        void Draw() const;

        Vector2 GetPosition() const;
        bool GetHeight() const;
        int GetSize() const;

    private:

        Vector2 position;
        bool height;
        Texture2D texture;
        static const int SIZE = 32;

};

#endif