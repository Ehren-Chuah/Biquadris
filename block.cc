#include "block.h"
#include "board.h"

Block::Block(): pos{Coord{0, 3}}, orientation{0}, heavy{0} {}

Block::Block(const Block &other):
    pos{other.pos}, orientation{other.orientation}, heavy{other.heavy}
    {}

void Block::rotateClockwise() {
    ++orientation;
    orientation %= 4;
}

void Block::rotateCounterClockwise() {
    --orientation;
    orientation %= 4;
    if (orientation < 0) {
        orientation += 4;
    }
}

void Block::moveLeft() {
    --pos.x;
}

void Block::moveRight() {
    ++pos.x;
}

void Block::moveDown() {
    ++pos.y;
}

void Block::moveUp() {
    --pos.y;
}

Coord Block::getPos() const {
    return pos;
}
void Block::setPos(Coord newPos) {
    pos = newPos;
}
int Block::getOrientation() const {
    return orientation;
}

void Block::setOrientation(int newOri) {
    orientation = newOri;
}

int Block::getHeavy() const {
    return heavy;
}

void Block::setHeavy(int newHeaviness) {
    heavy = newHeaviness;
}

char I::blockType() const {
    return blockChar;
}

vector<Coord> I::blockCoords() const {
    vector<Coord> retvec;
    if (orientation % 2 == 0) {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{1, 0});
        retvec.emplace_back(Coord{2, 0});
        retvec.emplace_back(Coord{3, 0});
    } else {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{0, -2});
        retvec.emplace_back(Coord{0, -3});
    }
    for (Coord &square : retvec) {
        square.x += pos.x;
        square.y += pos.y;
    }
    return retvec;
}

char J::blockType() const {
    return blockChar;
}

vector<Coord> J::blockCoords() const {
    vector<Coord> retvec;
    if (orientation == 0) {
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{1, 0});
        retvec.emplace_back(Coord{2, 0});
    } else if (orientation == 1) {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{0, -2});
        retvec.emplace_back(Coord{1, -2});
    } else if (orientation == 2) {
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{2, -1});
        retvec.emplace_back(Coord{2, 0});
    } else if (orientation == 3) {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{1, 0});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{1, -2});
    }
    for (Coord &square : retvec) {
        square.x += pos.x;
        square.y += pos.y;
    }
    return retvec;
}

char L::blockType() const {
    return blockChar;
}

vector<Coord> L::blockCoords() const {
    vector<Coord> retvec;
    if (orientation == 0) {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{1, 0});
        retvec.emplace_back(Coord{2, 0});
        retvec.emplace_back(Coord{2, -1});
    } else if (orientation == 1) {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{0, -2});
        retvec.emplace_back(Coord{1, 0});
    } else if (orientation == 2) {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{2, -1});
    } else if (orientation == 3) {
        retvec.emplace_back(Coord{0, -2});
        retvec.emplace_back(Coord{1, -2});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{1, 0});
    }
    for (Coord &square : retvec) {
        square.x += pos.x;
        square.y += pos.y;
    }
    return retvec;
}


char O::blockType() const {
    return blockChar;
}

vector<Coord> O::blockCoords() const {
    vector<Coord> retvec;
    retvec.emplace_back(Coord{0, 0});
    retvec.emplace_back(Coord{1, 0});
    retvec.emplace_back(Coord{0, -1});
    retvec.emplace_back(Coord{1, -1});
    for (Coord &square : retvec) {
        square.x += pos.x;
        square.y += pos.y;
    }
    return retvec;
}


char S::blockType() const {
    return blockChar;
}

vector<Coord> S::blockCoords() const {
    vector<Coord> retvec;
    if (orientation % 2 == 0) {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{1, 0});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{2, -1});
    } else {
        retvec.emplace_back(Coord{0, -2});
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{1, 0});
    }
    for (Coord &square : retvec) {
        square.x += pos.x;
        square.y += pos.y;
    }
    return retvec;
}


char Z::blockType() const {
    return blockChar;
}

vector<Coord> Z::blockCoords() const {
    vector<Coord> retvec;
    if (orientation % 2 == 0) {
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{1, 0});
        retvec.emplace_back(Coord{2, 0});
    } else {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{1, -2});
    }
    for (Coord &square : retvec) {
        square.x += pos.x;
        square.y += pos.y;
    }
    return retvec;
}

char T::blockType() const {
    return blockChar;
}

vector<Coord> T::blockCoords() const {
    vector<Coord> retvec;
    if (orientation == 0) {
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{1, 0});
        retvec.emplace_back(Coord{2, -1});
    } else if (orientation == 1) {
        retvec.emplace_back(Coord{1, 0});
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{1, -2});
    } else if (orientation == 2) {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{1, 0});
        retvec.emplace_back(Coord{1, -1});
        retvec.emplace_back(Coord{2, 0});
    } else if (orientation == 3) {
        retvec.emplace_back(Coord{0, 0});
        retvec.emplace_back(Coord{0, -1});
        retvec.emplace_back(Coord{0, -2});
        retvec.emplace_back(Coord{1, -1});
    }
    for (Coord &square : retvec) {
        square.x += pos.x;
        square.y += pos.y;
    }
    return retvec;
}
