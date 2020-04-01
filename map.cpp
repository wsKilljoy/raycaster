#include "map.h"
#include "config.h"
#include "sprite.h"

std::vector<std::vector<int>> worldMap
{
        {'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'},
        {'w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ','g','g','g','g','g',' ',' ',' ',' ','r',' ','r',' ','r',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ','g','P','P','P','g',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ','g',' ',' ',' ','g',' ',' ',' ',' ','r',' ',' ',' ','r',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ','g',' ','L',' ','g',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ','g','g',' ','g','g',' ',' ',' ',' ','r',' ','r',' ','r',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','B',' ',' ',' ','B',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','P',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','B',' ',' ',' ',' ',' ','w'},
        {'w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w','m','m','m','m','m','m','m','m',' ',' ',' ',' ',' ',' ','B',' ',' ',' ','B',' ',' ',' ','w'},
        {'w','m',' ','m',' ',' ',' ',' ','m',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w','m',' ',' ',' ',' ','e',' ','m',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w','m',' ','m',' ',' ',' ',' ','m',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w','m',' ','m','m','m','m','m','m',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w','m',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w','m','m','m','m','m','m','m','m',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w'},
        {'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'}
};

std::vector<TileReference> tileReferences;

void generateTiles() {
    TileReference empty;
    empty.name = " ";
    empty.symbol = ' ';
    empty.collidable = false;
    tileReferences.push_back(empty);

    createTile("wood", 'w');
    createTile("mossy", 'm');
    createTile("eagle", 'e');
    createTile("greystone", 'g');
    createTile("redbrick", 'r');

    createTile("barrel", 'B', true, true);
    createTile("pillar", 'P', true, true);
    createTile("greenlight", 'L', false, true);
}

void loadMap(std::vector<std::vector<int>> map) {
    int i = 0;
    int j = 0;
    for(auto & vec : map) {
        j = 0;
        for(auto & t : vec) {
             TileReference* ref;

            if(getTileReference(t) != NULL) {
                ref = getTileReference(t);
            } else {
                ref = getTileReference(' ');
            }
            if(ref->sprite == true) {
                Sprite sprite = Sprite(i + 0.5, j + 0.5, ref);
                sprites.push_back(sprite);
            }
            j += 1;
        }
        i += 1;
    }
}

void createTile(std::string name, int symbol, bool collidable, bool sprite) {
    TileReference ref;
    ref.name = name;
    ref.symbol = symbol;
    ref.collidable = collidable;
    ref.sprite = sprite;

    sf::Image image;
    image.loadFromFile("/home/will/raycaster/pics/" + name + ".png");
    ref.texture = image;

    tileReferences.push_back(ref);
}

TileReference* getTileReference(int symbol) {
    for(int i = 0; i < tileReferences.size(); i++) {
        if(tileReferences[i].symbol == symbol) {
            return &tileReferences[i];
        }
    }
    return NULL;
}

