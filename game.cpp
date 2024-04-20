#include "game.h"
#include "gui.h"

game::game() {
    //initializing piece(x, y, type)
    //white rook 1
    piece wr1p(1, 8, 5);
    v.push_back(wr1p);

    //white knight 1
    piece wn1p(2, 8, 3);
    v.push_back(wn1p);

    //dark square white bishop
    piece dswbp(3, 8, 4);
    v.push_back(dswbp);
    
    //white queen
    piece wqp(4, 8, 9);
    v.push_back(wqp);

    //white king
    piece wkp(5, 8, 2);
    v.push_back(wkp);

    //light square white bishop
    piece lswbp(6, 8, 4);
    v.push_back(lswbp);

    //white knight 2
    piece wn2p(7, 8, 3);
    v.push_back(wn2p);

    //white rook 2
    piece wr2p(8, 8, 5);
    v.push_back(wr2p);

    //white pawns
    piece wp1p(1, 7, 1);
    v.push_back(wp1p);

    piece wp2p(2, 7, 1);
    v.push_back(wp2p);

    piece wp3p(3, 7, 1);
    v.push_back(wp3p);

    piece wp4p(4, 7, 1);
    v.push_back(wp4p);

    piece wp5p(5, 7, 1);
    v.push_back(wp5p);

    piece wp6p(6, 7, 1);
    v.push_back(wp6p);

    piece wp7p(7, 7, 1);
    v.push_back(wp7p);

    piece wp8p(8, 7, 1);
    v.push_back(wp8p);

    //BLACK PIECES

    //black rook 1
    piece br1p(1, 1, -5);
    v.push_back(br1p);

    //black knight 1
    piece bn1p(2, 1, -3);
    v.push_back(bn1p);

    //dark square black bishop
    piece dsbbp(3, 1, -4);
    v.push_back(dsbbp);

    //black queen
    piece bqp(4, 1, -9);
    v.push_back(bqp);

    //black king
    piece bkp(5, 1, -2);
    v.push_back(bkp);

    //light square black bishop
    piece lsbbp(6, 1, -4);
    v.push_back(lsbbp);

    //black knight 2
    piece bn2p(7, 1, -3);
    v.push_back(bn2p);

    //black rook 2
    piece br2p(8, 1, -5);
    v.push_back(br2p);

    //black pawns
    piece bp1p(1, 2, -1);
    v.push_back(bp1p);

    piece bp2p(2, 2, -1);
    v.push_back(bp2p);

    piece bp3p(3, 2, -1);
    v.push_back(bp3p);

    piece bp4p(4, 2, -1);
    v.push_back(bp4p);

    piece bp5p(5, 2, -1);
    v.push_back(bp5p);

    piece bp6p(6, 2, -1);
    v.push_back(bp6p);

    piece bp7p(7, 2, -1);
    v.push_back(bp7p);

    piece bp8p(8, 2, -1);
    v.push_back(bp8p);
}

void game::printboard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << gameboard[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void game::updateboard(int i, int newx, int newy) {
    int oldx = v[i].getx();
    int oldy = v[i].gety();
    //std::cout << "update board: " << oldx << ", " << oldy << " to " << newx << ", " << newy << std::endl;
    v[i].setpos(newx, newy);
    std::cout << std::endl;
    gameboard[oldy - 1][oldx - 1] = 0;
    gameboard[newy-1][newx-1] = v[i].gettype();
    //printboard();
}

std::vector<piece> &game::getv() {
    return v;
}


int game::collision(int x, int y) {
    return gameboard[y - 1][x - 1];
}

bool game::check(int x, int y) {
    if (whiteturn) {
        //check black knights
        std::vector<std::pair<int, int>> knights;
        if (v[17].isalive()) {
            possiblemoves(-3, v[17].getx(), v[17].gety(), knights);
        }
        if (v[22].isalive()) {
            possiblemoves(-3, v[22].getx(), v[22].gety(), knights);
        }
        for (int i = 0; i < knights.size(); i++) {
            if (knights[i].first == x && knights[i].second == y) {
                return true;
            }
        }


        //i forgot the gameboard is [y-1][x-1]
        //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        y = y - 1;
        x = x - 1;
        
        //check for pawns
        if (y - 1 > 0 && (gameboard[y - 1][x + 1] == -1 || gameboard[y - 1][x - 1] == -1)) {
            return true;
        }

        //check cardinal directions
        int i = 1;
        while (x + i <= 7) {
            //if a friendly piece is found in this direction before any hostiles, break
            if (gameboard[y][x + i] > 0) {
                break;
            }
            //if a hostile piece is found before any friendlies, check if dangerous (rook or queen)
            //break if not dangerous
            if (gameboard[y][x + i] < 0) {
                if (gameboard[y][x + i] == -5 || gameboard[y][x + i] == -9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (x - i >= 0) {
            if (gameboard[y][x - i] > 0) {
                break;
            }
            if (gameboard[y][x - i] < 0) {
                if (gameboard[y][x - i] == -5 || gameboard[y][x - i] == -9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (y + i <= 7) {
            if (gameboard[y + i][x] > 0) {
                break;
            }
            if (gameboard[y + i][x] < 0) {
                if (gameboard[y + i][x] == -5 || gameboard[y + i][x] == -9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (y - i >= 0) {
            if (gameboard[y - i][x] > 0) {
                break;
            }
            if (gameboard[y - i][x] < 0) {
                if (gameboard[y - i][x] == -5 || gameboard[y - i][x] == -9) {
                    return true;
                }
                break;
            }
            i++;
        }

        //check intercardinal directions
        i = 1;
        while (x + i <= 7 && y + i <= 7) {
            //if a friendly piece is found in this direction before any hostiles, break
            if (gameboard[y + i][x + i] > 0) {
                break;
            }
            //if a hostile piece is found before any friendlies, check if dangerous (bishop or queen)
            //break if not dangerous
            if (gameboard[y + i][x + i] < 0) {
                if (gameboard[y + i][x + i] == -4 || gameboard[y + i][x + i] == -9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (x - i >= 0 && y + i <= 7) {
            if (gameboard[y + i][x - i] > 0) {
                break;
            }
            if (gameboard[y + i][x - i] < 0) {
                if (gameboard[y + i][x - i] == -4 || gameboard[y + i][x - i] == -9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (x + i <= 7 && y - i >= 0) {
            if (gameboard[y - i][x + i] > 0) {
                break;
            }
            if (gameboard[y - i][x + i] < 0) {
                if (gameboard[y - i][x + i] == -4 || gameboard[y - i][x + i] == -9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (x - i >= 0 && y - i >= 0) {
            if (gameboard[y - i][x - i] > 0) {
                break;
            }
            if (gameboard[y - i][x - i] < 0) {
                if (gameboard[y - i][x - i] == -4 || gameboard[y - i][x - i] == -9) {
                    return true;
                }
                break;
            }
            i++;
        }
    }
    else {
        //check white knights
        std::vector<std::pair<int, int>> knights;
        if (v[17].isalive()) {
            possiblemoves(3, v[1].getx(), v[1].gety(), knights);
        }
        if (v[22].isalive()) {
            possiblemoves(3, v[6].getx(), v[6].gety(), knights);
        }
        for (int i = 0; i < knights.size(); i++) {
            if (knights[i].first == x && knights[i].second == y) {
                return true;
            }
        }

        y = y - 1;
        x = x - 1;

        //check for pawns
        if (y + 1 < 7 && (gameboard[y + 1][x + 1] == 1 || gameboard[y + 1][x - 1] == 1)) {
            return true;
        }

        //check cardinal directions
        int i = 1;
        while (x + i <= 7) {
            //if a friendly piece is found in this direction before any hostiles, break
            if (gameboard[y][x + i] < 0) {
                break;
            }
            //if a hostile piece is found before any friendlies, check if dangerous (rook or queen)
            //break if not dangerous
            if (gameboard[y][x + i] > 0) {
                if (gameboard[y][x + i] == 5 || gameboard[y][x + i] == 9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (x - i >= 0) {
            if (gameboard[y][x - i] < 0) {
                break;
            }
            if (gameboard[y][x - i] > 0) {
                if (gameboard[y][x - i] == 5 || gameboard[y][x - i] == 9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (y + i <= 7) {
            if (gameboard[y + i][x] < 0) {
                break;
            }
            if (gameboard[y + i][x] > 0) {
                if (gameboard[y + i][x] == 5 || gameboard[y + i][x] == 9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (y - i >= 0) {
            if (gameboard[y - i][x] < 0) {
                break;
            }
            if (gameboard[y - i][x] > 0) {
                if (gameboard[y - i][x] == 5 || gameboard[y - i][x] == 9) {
                    return true;
                }
                break;
            }
            i++;
        }

        //check intercardinal directions
        i = 1;
        while (x + i <= 7 && y + i <= 7) {
            //if a friendly piece is found in this direction before any hostiles, break
            if (gameboard[y + i][x + i] < 0) {
                break;
            }
            //if a hostile piece is found before any friendlies, check if dangerous (bishop or queen)
            //break if not dangerous
            if (gameboard[y + i][x + i] > 0) {
                if (gameboard[y + i][x + i] == 4 || gameboard[y + i][x + i] == 9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (x - i >= 0 && y + i <= 7) {
            if (gameboard[y + i][x - i] < 0) {
                break;
            }
            if (gameboard[y + i][x - i] > 0) {
                if (gameboard[y + i][x - i] == 4 || gameboard[y + i][x - i] == 9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (x + i <= 7 && y - i >= 0) {
            if (gameboard[y - i][x + i] < 0) {
                break;
            }
            if (gameboard[y - i][x + i] > 0) {
                if (gameboard[y - i][x + i] == 4 || gameboard[y - i][x + i] == 9) {
                    return true;
                }
                break;
            }
            i++;
        }

        i = 1;
        while (x - i >= 0 && y - i >= 0) {
            if (gameboard[y - i][x - i] < 0) {
                break;
            }
            if (gameboard[y - i][x - i] > 0) {
                if (gameboard[y - i][x - i] == 4 || gameboard[y - i][x - i] == 9) {
                    return true;
                }
                break;
            }
            i++;
        }
    }
    return false;
}

bool game::checkmate() {
    std::vector<std::pair<int, int>> vec;
    if (whiteturn) {
        possiblemoves(2, v[4].getx(), v[4].gety(), vec);
        if (check(v[4].getx(), v[4].gety()) && vec.size() == 0) {
            std::cout << "white is checkmated";
            return true;
        }
    }
    else {
        possiblemoves(-2, v[20].getx(), v[20].gety(), vec);
        if (check(v[20].getx(), v[20].gety()) && vec.size() == 0) {
            std::cout << "black is checkmated";
            return true;
        }
    }

    return false;
}

void game::possiblemoves(int type, int _x, int _y, std::vector<std::pair<int, int>> &res) {
    //pawn
    if (abs(type) == 1) {
        if (type == 1) {
            //check for enpassant
            if (enpassant.first == true) {
                res.push_back(std::make_pair(enpassant.second, _y - 1));
            }

            //normal moves
            if (_y == 7) {
                for (int i = 1; i <= 2; i++) {
                    if (collision(_x, _y - i) != 0) {
                        break;
                    }
                    res.push_back(std::make_pair(_x, _y - i));
                }
            }
            else {
                if (collision(_x, _y - 1) == 0) {
                    res.push_back(std::make_pair(_x, _y - 1));
                }
            }

            //captures
            if (collision(_x + 1, _y - 1) < 0) {
                res.push_back(std::make_pair(_x + 1, _y - 1));
            }
            if (collision(_x - 1, _y - 1) < 0) {
                res.push_back(std::make_pair(_x - 1, _y - 1));
            }
        }
        else if (type == -1) {
            //check for enpassant
            if (enpassant.first == true) {
                res.push_back(std::make_pair(enpassant.second, _y + 1));
            }

            //normal moves
            if (_y == 2) {
                for (int i = 1; i <= 2; i++) {
                    if (collision(_x, _y + i) != 0) {
                        break;
                    }
                    res.push_back(std::make_pair(_x, _y + i));
                }
            }
            else {
                if (collision(_x, _y + 1) == 0) {
                    res.push_back(std::make_pair(_x, _y + 1));
                }
            }

            //captures
            if (collision(_x + 1, _y + 1) > 0) {
                res.push_back(std::make_pair(_x + 1, _y + 1));
            }
            if (collision(_x - 1, _y + 1) > 0) {
                res.push_back(std::make_pair(_x - 1, _y + 1));
            }
        }
    }

    //rook
    else if (abs(type) == 5) {
        int i = 1;
        if (type == 5) {
            while (_x + i <= 8) {
                if (collision(_x + i, _y) < 0) {
                    res.push_back(std::make_pair(_x + i, _y));
                    break;
                }
                else if (collision(_x + i, _y) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y));
                i++;
            }
            i = 1;
            while (_x - i >= 1) {
                if (collision(_x - i, _y) < 0) {
                    res.push_back(std::make_pair(_x + i, _y));
                    break;
                }
                else if (collision(_x - i, _y) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y));
                i++;
            }
            i = 1;
            while (_y + i <= 8) {
                if (collision(_x, _y + i) < 0) {
                    res.push_back(std::make_pair(_x, _y + i));
                    break;
                }
                else if (collision(_x, _y + i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x, _y + i));
                i++;
            }
            i = 1;
            while (_y - i >= 1) {
                if (collision(_x, _y - i) < 0) {
                    res.push_back(std::make_pair(_x, _y - i));
                    break;
                }
                else if (collision(_x, _y - i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x, _y - i));
                i++;
            }
        }
        else if (type == -5) {
            while (_x + i <= 8) {
                if (collision(_x + i, _y) > 0) {
                    res.push_back(std::make_pair(_x + i, _y));
                    break;
                }
                else if (collision(_x + i, _y) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y));
                i++;
            }
            i = 1;
            while (_x - i >= 1) {
                if (collision(_x - i, _y) > 0) {
                    res.push_back(std::make_pair(_x + i, _y));
                    break;
                }
                else if (collision(_x - i, _y) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y));
                i++;
            }
            i = 1;
            while (_y + i <= 8) {
                if (collision(_x, _y + i) > 0) {
                    res.push_back(std::make_pair(_x, _y + i));
                    break;
                }
                else if (collision(_x, _y + i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x, _y + i));
                i++;
            }
            i = 1;
            while (_y - i >= 1) {
                if (collision(_x, _y - i) > 0) {
                    res.push_back(std::make_pair(_x, _y - i));
                    break;
                }
                else if (collision(_x, _y - i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x, _y - i));
                i++;
            }
        }
    }

    //bishop
    else if (abs(type) == 4) {
        int i = 1;
        if (type == 4) {
            while (_x + i <= 8 && _y + i <= 8) {
                if (collision(_x + i, _y + i) < 0) {
                    res.push_back(std::make_pair(_x + i, _y + i));
                    break;
                }
                else if (collision(_x + i, _y + i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y + i));
                i++;
            }
            i = 1;
            while (_x + i <= 8 && _y - i >= 1) {
                if (collision(_x + i, _y - i) < 0) {
                    res.push_back(std::make_pair(_x + i, _y - i));
                    break;
                }
                else if (collision(_x + i, _y - i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y - i));
                i++;
            }
            i = 1;
            while (_x - i >= 1 && _y + i <= 8) {
                if (collision(_x - i, _y + i) < 0) {
                    res.push_back(std::make_pair(_x - i, _y + i));
                    break;
                }
                else if (collision(_x - i, _y + i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y + i));
                i++;
            }
            i = 1;
            while (_x - i >= 1 && _y - i >= 1) {
                if (collision(_x - i, _y - i) < 0) {
                    res.push_back(std::make_pair(_x - i, _y - i));
                    break;
                }
                else if (collision(_x - i, _y - i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y - i));
                i++;
            }
        }
        if (type == -4) {
            while (_x + i <= 8 && _y + i <= 8) {
                if (collision(_x + i, _y + i) > 0) {
                    res.push_back(std::make_pair(_x + i, _y + i));
                    break;
                }
                else if (collision(_x + i, _y + i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y + i));
                i++;
            }
            i = 1;
            while (_x + i <= 8 && _y - i >= 1) {
                if (collision(_x + i, _y - i) > 0) {
                    res.push_back(std::make_pair(_x + i, _y - i));
                    break;
                }
                else if (collision(_x + i, _y - i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y - i));
                i++;
            }
            i = 1;
            while (_x - i >= 1 && _y + i <= 8) {
                if (collision(_x - i, _y + i) > 0) {
                    res.push_back(std::make_pair(_x - i, _y + i));
                    break;
                }
                else if (collision(_x - i, _y + i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y + i));
                i++;
            }
            i = 1;
            while (_x - i >= 1 && _y - i >= 1) {
                if (collision(_x - i, _y - i) > 0) {
                    res.push_back(std::make_pair(_x - i, _y - i));
                    break;
                }
                else if (collision(_x - i, _y - i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y - i));
                i++;
            }
        }
    }

    //knight
    else if (abs(type) == 3) {
        if (type == 3) {
            if (_x + 2 <= 8) {
                if (_y + 1 <= 8 && collision(_x + 2, _y + 1) <= 0) {
                    res.push_back(std::make_pair(_x + 2, _y + 1));
                }
                if (_y - 1 >= 1 && collision(_x + 2, _y - 1) <= 0) {
                    res.push_back(std::make_pair(_x + 2, _y - 1));
                }
            }
            if (_x - 2 >= 1) {
                if (_y + 1 <= 8 && collision(_x - 2, _y + 1) <= 0) {
                    res.push_back(std::make_pair(_x - 2, _y + 1));
                }
                if (_y - 1 >= 0 && collision(_x - 2, _y - 1) <= 0) {
                    res.push_back(std::make_pair(_x - 2, _y - 1));
                }
            }
            if (_y + 2 <= 8) {
                if (_x + 1 <= 8 && collision(_x + 1, _y + 2) <= 0) {
                    res.push_back(std::make_pair(_x + 1, _y + 2));
                }
                if (_x - 1 >= 0 && collision(_x - 1, _y + 2) <= 0) {
                    res.push_back(std::make_pair(_x - 1, _y + 2));
                }
            }
            if (_y - 2 >= 1) {
                if (_x + 1 <= 8 && collision(_x + 1, _y - 2) <= 0) {
                    res.push_back(std::make_pair(_x + 1, _y - 2));
                }
                if (_x - 1 >= 0 && collision(_x - 1, _y - 2) <= 0) {
                    res.push_back(std::make_pair(_x - 1, _y - 2));
                }
            }
        }
        else if (type == -3) {
            if (_x + 2 <= 8) {
                if (_y + 1 <= 8 && collision(_x + 2, _y + 1) >= 0) {
                    res.push_back(std::make_pair(_x + 2, _y + 1));
                }
                if (_y - 1 >= 1 && collision(_x + 2, _y - 1) >= 0) {
                    res.push_back(std::make_pair(_x + 2, _y - 1));
                }
            }
            if (_x - 2 >= 1) {
                if (_y + 1 <= 8 && collision(_x - 2, _y + 1) >= 0) {
                    res.push_back(std::make_pair(_x - 2, _y + 1));
                }
                if (_y - 1 >= 0 && collision(_x - 2, _y - 1) >= 0) {
                    res.push_back(std::make_pair(_x - 2, _y - 1));
                }
            }
            if (_y + 2 <= 8) {
                if (_x + 1 <= 8 && collision(_x + 1, _y + 2) >= 0) {
                    res.push_back(std::make_pair(_x + 1, _y + 2));
                }
                if (_x - 1 >= 0 && collision(_x - 1, _y + 2) >= 0) {
                    res.push_back(std::make_pair(_x - 1, _y + 2));
                }
            }
            if (_y - 2 >= 1) {
                if (_x + 1 <= 8 && collision(_x + 1, _y - 2) >= 0) {
                    res.push_back(std::make_pair(_x + 1, _y - 2));
                }
                if (_x - 1 >= 0 && collision(_x - 1, _y - 2) >= 0) {
                    res.push_back(std::make_pair(_x - 1, _y - 2));
                }
            }
        }
    }

    //queen
    else if (abs(type) == 9) {
        //bishop + rook
        int i = 1;
        if (type == 9) {
            //bishop part
            while (_x + i <= 8 && _y + i <= 8) {
                if (collision(_x + i, _y + i) < 0) {
                    res.push_back(std::make_pair(_x + i, _y + i));
                    break;
                }
                else if (collision(_x + i, _y + i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y + i));
                i++;
            }
            i = 1;
            while (_x + i <= 8 && _y - i >= 1) {
                if (collision(_x + i, _y - i) < 0) {
                    res.push_back(std::make_pair(_x + i, _y - i));
                    break;
                }
                else if (collision(_x + i, _y - i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y - i));
                i++;
            }
            i = 1;
            while (_x - i >= 1 && _y + i <= 8) {
                if (collision(_x - i, _y + i) < 0) {
                    res.push_back(std::make_pair(_x - i, _y + i));
                    break;
                }
                else if (collision(_x - i, _y + i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y + i));
                i++;
            }
            i = 1;
            while (_x - i >= 1 && _y - i >= 1) {
                if (collision(_x - i, _y - i) < 0) {
                    res.push_back(std::make_pair(_x - i, _y - i));
                    break;
                }
                else if (collision(_x - i, _y - i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y - i));
                i++;
            }
            //rook part
            i = 1;
            while (_x + i <= 8) {
                if (collision(_x + i, _y) < 0) {
                    res.push_back(std::make_pair(_x + i, _y));
                    break;
                }
                else if (collision(_x + i, _y) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y));
                i++;
            }
            i = 1;
            while (_x - i >= 1) {
                if (collision(_x - i, _y) < 0) {
                    res.push_back(std::make_pair(_x + i, _y));
                    break;
                }
                else if (collision(_x - i, _y) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y));
                i++;
            }
            i = 1;
            while (_y + i <= 8) {
                if (collision(_x, _y + i) < 0) {
                    res.push_back(std::make_pair(_x, _y + i));
                    break;
                }
                else if (collision(_x, _y + i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x, _y + i));
                i++;
            }
            i = 1;
            while (_y - i >= 1) {
                if (collision(_x, _y - i) < 0) {
                    res.push_back(std::make_pair(_x, _y - i));
                    break;
                }
                else if (collision(_x, _y - i) > 0) {
                    break;
                }
                res.push_back(std::make_pair(_x, _y - i));
                i++;
            }
        }
        else if (type == -9) {
            //bishop part
            while (_x + i <= 8 && _y + i <= 8) {
                if (collision(_x + i, _y + i) > 0) {
                    res.push_back(std::make_pair(_x + i, _y + i));
                    break;
                }
                else if (collision(_x + i, _y + i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y + i));
                i++;
            }
            i = 1;
            while (_x + i <= 8 && _y - i >= 1) {
                if (collision(_x + i, _y - i) > 0) {
                    res.push_back(std::make_pair(_x + i, _y - i));
                    break;
                }
                else if (collision(_x + i, _y - i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y - i));
                i++;
            }
            i = 1;
            while (_x - i >= 1 && _y + i <= 8) {
                if (collision(_x - i, _y + i) > 0) {
                    res.push_back(std::make_pair(_x - i, _y + i));
                    break;
                }
                else if (collision(_x - i, _y + i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y + i));
                i++;
            }
            i = 1;
            while (_x - i >= 1 && _y - i >= 1) {
                if (collision(_x - i, _y - i) > 0) {
                    res.push_back(std::make_pair(_x - i, _y - i));
                    break;
                }
                else if (collision(_x - i, _y - i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y - i));
                i++;
            }
            //rook part
            i = 1;
            while (_x + i <= 8) {
                std::cout << i << std::endl;
                if (collision(_x + i, _y) > 0) {
                    res.push_back(std::make_pair(_x + i, _y));
                    break;
                }
                else if (collision(_x + i, _y) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x + i, _y));
                i++;
            }
            i = 1;
            while (_x - i >= 1) {
                if (collision(_x - i, _y) > 0) {
                    res.push_back(std::make_pair(_x + i, _y));
                    break;
                }
                else if (collision(_x - i, _y) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x - i, _y));
                i++;
            }
            i = 1;
            while (_y + i <= 8) {
                std::cout << i << std::endl;
                if (collision(_x, _y + i) > 0) {
                    res.push_back(std::make_pair(_x, _y + i));
                    break;
                }
                else if (collision(_x, _y + i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x, _y + i));
                i++;
            }
            i = 1;
            while (_y - i >= 1) {
                if (collision(_x, _y - i) > 0) {
                    res.push_back(std::make_pair(_x, _y - i));
                    break;
                }
                else if (collision(_x, _y - i) < 0) {
                    break;
                }
                res.push_back(std::make_pair(_x, _y - i));
                i++;
            }
        }
    }

    //king
    else if (abs(type) == 2) {
        if (type == 2) {
            //normal moves
            if (_x + 1 <= 8 && collision(_x + 1, _y) <= 0 && check(_x + 1, _y) == false) {
                res.push_back(std::make_pair(_x + 1, _y));
            }
            if (_x + 1 <= 8 && _y + 1 <= 8 && collision(_x + 1, _y + 1) <= 0 && check(_x + 1, _y + 1) == false) {
                res.push_back(std::make_pair(_x + 1, _y + 1));
            }
            if (_y + 1 <= 8 && collision(_x, _y + 1) <= 0 && check(_x, _y + 1) == false) {
                res.push_back(std::make_pair(_x, _y + 1));
            }
            if (_x - 1 >= 0 && _y + 1 <= 8 && collision(_x - 1, _y + 1) <= 0 && check(_x - 1, _y + 1) == false) {
                res.push_back(std::make_pair(_x - 1, _y + 1));
            }
            if (_x - 1 >= 0 && collision(_x - 1, _y) <= 0 && check(_x - 1, _y) == false) {
                res.push_back(std::make_pair(_x - 1, _y));
            }
            if (_x - 1 >= 0 && _y - 1 >= 0 && collision(_x - 1, _y - 1) <= 0 && check(_x - 1, _y - 1) == false) {
                res.push_back(std::make_pair(_x - 1, _y - 1));
            }
            if (_y - 1 >= 0 && collision(_x, _y - 1) <= 0 && check(_x, _y - 1) == false) {
                res.push_back(std::make_pair(_x, _y - 1));
            }
            if (_x + 1 <= 8 && _y - 1 >= 0 && collision(_x + 1, _y - 1) <= 0 && check(_x + 1, _y - 1) == false) {
                res.push_back(std::make_pair(_x + 1, _y - 1));
            }
            //castling
            if (wkmove == false) {
                if (v[0].isalive() && wr1move == false && collision(2, 8) == 0 && collision(3, 8) == 0 && collision(4, 8) == 0 && !check(_x, _y) && !check(2, 8) && !check(3, 8) && !check(4, 8)) {
                    res.push_back(std::make_pair(3, 8));
                }
                if (v[7].isalive() && wr2move == false && collision(6, 8) == 0 && collision(7, 8) == 0 && !check(_x, _y) && !check(6, 8) && !check(7, 8)) {
                    res.push_back(std::make_pair(7, 8));
                }
            }
        }
        if (type == -2) {
            //normal moves
            if (_x + 1 <= 8 && collision(_x + 1, _y) >= 0 && check(_x + 1, _y) == false) {
                res.push_back(std::make_pair(_x + 1, _y));
            }
            if (_x + 1 <= 8 && _y + 1 <= 8 && collision(_x + 1, _y + 1) >= 0 && check(_x + 1, _y + 1) == false) {
                res.push_back(std::make_pair(_x + 1, _y + 1));
            }
            if (_y + 1 <= 8 && collision(_x, _y + 1) >= 0 && check(_x, _y + 1) == false) {
                res.push_back(std::make_pair(_x, _y + 1));
            }
            if (_x - 1 >= 0 && _y + 1 <= 8 && collision(_x - 1, _y + 1) >= 0 && check(_x - 1, _y + 1) == false) {
                res.push_back(std::make_pair(_x - 1, _y + 1));
            }
            if (_x - 1 >= 0 && collision(_x - 1, _y) >= 0 && check(_x - 1, _y) == false) {
                res.push_back(std::make_pair(_x - 1, _y));
            }
            if (_x - 1 >= 0 && _y - 1 >= 0 && collision(_x - 1, _y - 1) >= 0 && check(_x - 1, _y - 1) == false) {
                res.push_back(std::make_pair(_x - 1, _y - 1));
            }
            if (_y - 1 >= 0 && collision(_x, _y - 1) >= 0 && check(_x, _y - 1) == false) {
                res.push_back(std::make_pair(_x, _y - 1));
            }
            if (_x + 1 <= 8 && _y - 1 >= 0 && collision(_x + 1, _y - 1) >= 0 && check(_x + 1, _y - 1) == false) {
                res.push_back(std::make_pair(_x + 1, _y - 1));
            }
            //castling
            if (bkmove == false) {
                if (v[16].isalive() && br1move == false && collision(2, 1) == 0 && collision(3, 1) == 0 && collision(4, 1) == 0 && !check(_x, _y) && !check(2, 1) && !check(3, 1) && !check(4, 1)) {
                    res.push_back(std::make_pair(3, 1));
                }
                if (v[23].isalive() && br2move == false && collision(6, 1) == 0 && collision(7, 1) == 0 && !check(_x, _y) && !check(6, 1) && !check(7, 1)) {
                    res.push_back(std::make_pair(7, 1));
                }
            }
        }
    }

    //std::cout << "possiblemoves done" << std::endl;
}

void game::capture(int capturer, int capturee) {
    updateboard(capturer, v[capturee].getx(), v[capturee].gety());
    v[capturee].kill();
    //printboard();
    //std::cout << "id " << capturee << " killed" << std::endl;
}

int game::findid(int x, int y) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getx() == x && v[i].gety() == y) {
            return i;
        }
    }
    return -1;
}

bool game::validmove(int i, int x, int y) {
    //printboard();
    //check for correct turn
    if (whiteturn == true && gameboard[v[i].gety() - 1][v[i].getx() - 1] < 0) {
        return false;
    }
    else if (whiteturn == false && gameboard[v[i].gety() - 1][v[i].getx() - 1] > 0) {
        return false;
    }

    //check that selected piece is "alive"
    if (v[i].isalive() == false) {
        return false;
    }

    //check that x and y don't equal current pos
    if (v[i].getx() == x && v[i].gety() == y) {
        return false;
    }

    //get possible moves for a piece
    std::vector<std::pair<int, int>> pm;
    possiblemoves(v[i].gettype(), v[i].getx(), v[i].gety(), pm);
    for (int a = 0; a < pm.size(); a++) {
        std::cout << pm[a].first << ", " << pm[a].second << std::endl;
    }

    //check if the move played was within the array of valid moves
    for (int h = 0; h < pm.size(); h++) {
        if (pm[h].first == x && pm[h].second == y) {
            return true;
        }
    }

    return false;
}

bool game::makemove(int i, int x, int y) {
    std::cout << "moving " << x << ", " << y << std::endl;
    //check for turn
    if (checkmate()) {
        return true;
    }
    if (validmove(i, x, y)) {
        //note: the sprite still exists even when the piece is killed and the sprite isn't drawn, the sprite is still alive
        //update board
        bool c = false;
        int oldx = v[i].getx();
        int oldy = v[i].gety();
        int victim = findid(x, y);

        //castling
        if (i == 4 && abs(x-v[i].getx()) > 1) {
            if (x == 3) {
                updateboard(i, x, y);
                updateboard(0, 4, y);
            }
            else if (x == 7) {
                updateboard(i, x, y);
                updateboard(7, 6, y);
            }
        }
        else if (i == 20 && abs(x - v[i].getx()) > 1) {
            if (x == 3) {
                updateboard(i, x, y);
                updateboard(16, 4, y);
            }
            else if (x == 7) {
                updateboard(i, x, y);
                updateboard(23, 6, y);
            }
        }

        //enpassant
        else if (abs(v[i].gettype()) == 1 && oldx != x && collision(x, y) == 0) {
            std::cout << "doing le enpassant" << std::endl;
            v[findid(x, oldy)].kill();
            gameboard[oldy - 1][x - 1] = 0;
            updateboard(i, x, y);
        }

        //normal gameplay
        else if (gameboard[y - 1][x - 1] != 0) {
            capture(i, victim);
            c = true;
        }
        else {
            updateboard(i, x, y);
        }
        printboard();

        //if king is still in check, rollback move
        if (whiteturn && check(v[4].getx(), v[4].gety())) {
            updateboard(i, oldx, oldy);
            if (c) {
                v[victim].revive();
                updateboard(victim, x, y);
            }
            return false;
        }
        else if (!whiteturn && check(v[20].getx(), v[20].gety())) {
            updateboard(i, oldx, oldy);
            if (c) {
                v[victim].revive();
                updateboard(victim, x, y);
            }
            return false;
        }

        //update enpassant flag
        if (enpassant.first == true) {
            enpassant.first = false;
        }
        //if pawn moved 2 spaces and ended up directly next to a hostile pawn then flag enpassant as true
        if (v[i].gettype() == 1 && abs(oldy-y) == 2) {
            if (x + 1 <= 8 && collision(x + 1, y) == -1) {
                enpassant = std::make_pair(true, x);
            }
            else if (x - 1 >= 0 && collision(x - 1, y) == -1) {
                enpassant = std::make_pair(true, x);
            }
        }
        else if (v[i].gettype() == -1 && abs(oldy - y) == 2) {
            if (x + 1 <= 8 && collision(x + 1, y) == 1) {
                enpassant = std::make_pair(true, x);
            }
            else if (x - 1 >= 0 && collision(x - 1, y) == 1) {
                enpassant = std::make_pair(true, x);
            }
        }

        //update castling flags if necessary
        if (whiteturn) {
            if (wkmove == false && i == 4) {
                wr2move = true;
            }
            else if (wr1move == false && i == 0) {
                wr1move = true;
            }
            else if (wr2move == false && i == 7) {
                wr2move = true;
            }
        }
        else {
            if (bkmove == false && i == 20) {
                br2move = true;
            }
            else if (br1move == false && i == 16) {
                br1move = true;
            }
            else if (br2move == false && i == 23) {
                br2move = true;
            }
        }

        //promotion
        if (v[i].gettype() == 1 && v[i].gety() == 1) {
            promoting = i;
        }
        else if (v[i].gettype() == -1 && v[i].gety() == 8) {
            promoting = i;
        }

        //change the turn
        if (whiteturn == true) {
            std::cout << "black's turn" << std::endl;
            whiteturn = false;
        }
        else {
            std::cout << "white's turn" << std::endl;
            whiteturn = true;
        }
    }
    else {
        std::cout << "invalid move" << std::endl;
    }
    return false;
}

int game::ispromoting() {
    return promoting;
}

void game::donepromoting() {
    promoting = -1;
}