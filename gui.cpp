#include "gui.h"
int freezex;
int freezey;

gui::gui(game gamma) {
    g = gamma;

    //create window
    window.create(sf::VideoMode(768, 768), "Chess");

    //create board
    boardt.loadFromFile("assets/chessboard.png");
    board.setTexture(boardt);

    //load textures
    wk.loadFromFile("assets/pieces.png", sf::IntRect(0, 0, 133, 133));
    wq.loadFromFile("assets/pieces.png", sf::IntRect(133, 0, 133, 133));
    wb.loadFromFile("assets/pieces.png", sf::IntRect(266, 0, 133, 133));
    wn.loadFromFile("assets/pieces.png", sf::IntRect(399, 0, 133, 133));
    wr.loadFromFile("assets/pieces.png", sf::IntRect(533, 0, 133, 133));
    wp.loadFromFile("assets/pieces.png", sf::IntRect(666, 0, 133, 133));
    bk.loadFromFile("assets/pieces.png", sf::IntRect(0, 133, 133, 133));
    bq.loadFromFile("assets/pieces.png", sf::IntRect(133, 133, 133, 133));
    bb.loadFromFile("assets/pieces.png", sf::IntRect(266, 133, 133, 133));
    bn.loadFromFile("assets/pieces.png", sf::IntRect(399, 133, 133, 133));
    br.loadFromFile("assets/pieces.png", sf::IntRect(533, 133, 133, 133));
    bp.loadFromFile("assets/pieces.png", sf::IntRect(666, 133, 133, 133));
    pguit.loadFromFile("assets/wood.jpg");

    //insert pieces into piece vector
    //
    //sprite for piece
    //set scale because pieces.png is too big
    //create piece
    //snap piece to square on board
    //set texture for piece sprite
    //add piece to vector for pieces

    //WHITE PIECES

    sf::Sprite wr1s; //white rook 1
    wr1s.setScale(0.67, 0.67);
    wr1s.setTexture(wr);
    sv.push_back(wr1s);

    sf::Sprite wn1s; //white knight 1
    wn1s.setScale(0.67, 0.67);
    wn1s.setTexture(wn);
    sv.push_back(wn1s);

    sf::Sprite dswbs; //dark square white bishop
    dswbs.setScale(0.67, 0.67);
    dswbs.setTexture(wb);
    sv.push_back(dswbs);

    sf::Sprite wqs; //white queen
    wqs.setScale(0.67, 0.67);
    wqs.setTexture(wq);
    sv.push_back(wqs);

    sf::Sprite wks; //white king
    wks.setScale(0.67, 0.67);
    wks.setTexture(wk);
    sv.push_back(wks);

    sf::Sprite lswbs; //light square white bishop
    lswbs.setScale(0.67, 0.67);
    lswbs.setTexture(wb);
    sv.push_back(lswbs);

    sf::Sprite wn2s; //white knight 2
    wn2s.setScale(0.67, 0.67);
    wn2s.setTexture(wn);
    sv.push_back(wn2s);

    sf::Sprite wr2s; //white rook 2
    wr2s.setScale(0.67, 0.67);
    wr2s.setTexture(wr);
    sv.push_back(wr2s);

    //white pawns
    sf::Sprite wp1s;
    wp1s.setScale(0.67, 0.67);
    wp1s.setTexture(wp);
    sv.push_back(wp1s);

    sf::Sprite wp2s;
    wp2s.setScale(0.67, 0.67);
    wp2s.setTexture(wp);
    sv.push_back(wp2s);

    sf::Sprite wp3s;
    wp3s.setScale(0.67, 0.67);
    wp3s.setTexture(wp);
    sv.push_back(wp3s);

    sf::Sprite wp4s;
    wp4s.setScale(0.67, 0.67);
    wp4s.setTexture(wp);
    sv.push_back(wp4s);

    sf::Sprite wp5s;
    wp5s.setScale(0.67, 0.67);
    wp5s.setTexture(wp);
    sv.push_back(wp5s);

    sf::Sprite wp6s;
    wp6s.setScale(0.67, 0.67);
    wp6s.setTexture(wp);
    sv.push_back(wp6s);

    sf::Sprite wp7s;
    wp7s.setScale(0.67, 0.67);
    wp7s.setTexture(wp);
    sv.push_back(wp7s);

    sf::Sprite wp8s;
    wp8s.setScale(0.67, 0.67);
    wp8s.setTexture(wp);
    sv.push_back(wp8s);

    //BLACK PIECES

    sf::Sprite br1s; //black rook 1
    br1s.setScale(0.67, 0.67);
    br1s.setTexture(br);
    sv.push_back(br1s);

    sf::Sprite bn1s; //black knight 1
    bn1s.setScale(0.67, 0.67);
    bn1s.setTexture(bn);
    sv.push_back(bn1s);

    sf::Sprite dsbbs; //dark square black bishop
    dsbbs.setScale(0.67, 0.67);
    dsbbs.setTexture(bb);
    sv.push_back(dsbbs);

    sf::Sprite bqs; //black queen
    bqs.setScale(0.67, 0.67);
    bqs.setTexture(bq);
    sv.push_back(bqs);

    sf::Sprite bks; //black king
    bks.setScale(0.67, 0.67);
    bks.setTexture(bk);
    sv.push_back(bks);

    sf::Sprite lsbbs; //light square black bishop
    lsbbs.setScale(0.67, 0.67);
    lsbbs.setTexture(bb);
    sv.push_back(lsbbs);

    sf::Sprite bn2s; //black knight 2
    bn2s.setScale(0.67, 0.67);
    bn2s.setTexture(bn);
    sv.push_back(bn2s);

    sf::Sprite br2s; //black rook 2
    br2s.setScale(0.67, 0.67);
    br2s.setTexture(br);
    sv.push_back(br2s);

    //black pawns
    sf::Sprite bp1s;
    bp1s.setScale(0.67, 0.67);
    bp1s.setTexture(bp);
    sv.push_back(bp1s);

    sf::Sprite bp2s;
    bp2s.setScale(0.67, 0.67);
    bp2s.setTexture(bp);
    sv.push_back(bp2s);

    sf::Sprite bp3s;
    bp3s.setScale(0.67, 0.67);
    bp3s.setTexture(bp);
    sv.push_back(bp3s);

    sf::Sprite bp4s;
    bp4s.setScale(0.67, 0.67);
    bp4s.setTexture(bp);
    sv.push_back(bp4s);

    sf::Sprite bp5s;
    bp5s.setScale(0.67, 0.67);
    bp5s.setTexture(bp);
    sv.push_back(bp5s);

    sf::Sprite bp6s;
    bp6s.setScale(0.67, 0.67);
    bp6s.setTexture(bp);
    sv.push_back(bp6s);

    sf::Sprite bp7s;
    bp7s.setScale(0.67, 0.67);
    bp7s.setTexture(bp);
    sv.push_back(bp7s);

    sf::Sprite bp8s;
    bp8s.setScale(0.67, 0.67);
    bp8s.setTexture(bp);
    sv.push_back(bp8s);

    //promotion gui
    pguis.setScale(0.1, 0.1);
    pguis.setTexture(pguit);
    
    sf::Sprite pwq;
    pwq.setScale(0.67, 0.67);
    pwq.setTexture(wq);
    pguiv.push_back(pwq);

    sf::Sprite pwr;
    pwr.setScale(0.67, 0.67);
    pwr.setTexture(wr);
    pguiv.push_back(pwr);

    sf::Sprite pwb;
    pwb.setScale(0.67, 0.67);
    pwb.setTexture(wb);
    pguiv.push_back(pwb);

    sf::Sprite pwn;
    pwn.setScale(0.67, 0.67);
    pwn.setTexture(wn);
    pguiv.push_back(pwn);

    sf::Sprite pbq;
    pbq.setScale(0.67, 0.67);
    pbq.setTexture(bq);
    pguiv.push_back(pbq);

    sf::Sprite pbr;
    pbr.setScale(0.67, 0.67);
    pbr.setTexture(br);
    pguiv.push_back(pbr);

    sf::Sprite pbb;
    pbb.setScale(0.67, 0.67);
    pbb.setTexture(bb);
    pguiv.push_back(pbb);

    sf::Sprite pbn;
    pbn.setScale(0.67, 0.67);
    pbn.setTexture(bn);
    pguiv.push_back(pbn);

    drawgui();
}

sf::Vector2i gui::getclick() {
    sf::Vector2i pos(-1, -1);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        pos = sf::Mouse::getPosition(window);
        //std::cout << pos.x << ", " << pos.y << std::endl;
    }
    return pos;
}

//snap pieces to their square on the board
void gui::snap(int i) {
    sv[i].setPosition((g.getv()[i].getx() - 1) * 96, (g.getv()[i].gety() - 1) * 96);
}

void gui::drawpgui(int x, int y) {
    /*
    sf::Vector2i mousepos = sf::Mouse::getPosition(window);
    sf::Vector2f pos(mousepos.x, mousepos.y);
    int x = mousepos.x;
    int y = mousepos.y;*/

    if (x >= 384 && y >= 384) {
        pguis.setPosition(x - 192, y - 192);
    }
    else if (x < 384 && y >= 384) {
        pguis.setPosition(x, y - 192);
    }
    else if (x < 384 && y < 384) {
        pguis.setPosition(x, y);
    }
    else if (x >= 384 && y < 384) {
        pguis.setPosition(x - 192, y);
    }

    window.draw(pguis);

    if (g.ispromoting() < 16) {
        pguiv[0].setPosition(pguis.getPosition().x, pguis.getPosition().y);
        pguiv[1].setPosition(pguis.getPosition().x + 96, pguis.getPosition().y);
        pguiv[2].setPosition(pguis.getPosition().x, pguis.getPosition().y + 96);
        pguiv[3].setPosition(pguis.getPosition().x + 96, pguis.getPosition().y + 96);
        for (int i = 0; i < 4; i++) {
            window.draw(pguiv[i]);
        }
    }
    else if (g.ispromoting() >= 16) {
        pguiv[4].setPosition(pguis.getPosition().x, pguis.getPosition().y);
        pguiv[5].setPosition(pguis.getPosition().x + 96, pguis.getPosition().y);
        pguiv[6].setPosition(pguis.getPosition().x, pguis.getPosition().y + 96);
        pguiv[7].setPosition(pguis.getPosition().x + 96, pguis.getPosition().y + 96);
        for (int i = 4; i < 8; i++) {
            window.draw(pguiv[i]);
        }
    }
}

void gui::refresh() {
    //clear screen
    window.clear(sf::Color::Black);

    //create sprites
    //da board
    window.draw(board);

    //da pieces
    for (int i = 0; i < sv.size(); i++) {
        //don't draw dead pieces
        if (g.getv()[i].isalive()) {
            snap(i);
            window.draw(sv[i]);
        }
    }

    if (g.ispromoting() != -1) {
        drawpgui(freezex, freezey);
    }
}

int selected(std::vector<piece> vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].getselect()) {
            return i;
        }
    }
    return -1;
}

void gui::drawgui() {
    while (window.isOpen())
    {
        //draw everything
        refresh();
        
        //le events
        sf::Event event;
        while (window.pollEvent(event))
        {
            //"close requested" event: close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            //on click, move piece to cursor if one is selected or set piece as selected if none are
            static bool clicking;
            static int selectindex = -1;
            if (event.type == sf::Event::MouseButtonPressed) {
                //Sleep(1);
                sf::Vector2i mousepos = sf::Mouse::getPosition(window);
                sf::Vector2f pos(mousepos.x, mousepos.y);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clicking == false) {
                    //if no piece is selected
                    if (selectindex == -1) {
                        if (g.ispromoting() == -1) {
                            //set clicked piece as selected if not promoting
                            for (int i = 0; i < sv.size(); i++) {
                                if (g.getv()[i].isalive() && sv[i].getGlobalBounds().contains(pos)) {
                                    selectindex = i;
                                    std::cout << "selected " << g.getv()[selectindex].getx() << ", " << g.getv()[selectindex].gety() << std::endl;
                                    break;
                                }
                            }
                        }
                        else {
                            //get clicks on promotion gui if promoting
                            for (int i = 0; i < pguiv.size(); i++) {
                                if (pguiv[i].getGlobalBounds().contains(pos)) {
                                    selectindex = i;
                                    break;
                                }
                            }
                        }
                    }
                    //if piece is already selected, make move with the piece
                    else {
                        //normal
                        if (g.ispromoting() == -1) {
                            std::cout << "selected piece id " << selectindex << std::endl;
                            bool gameover = g.makemove(selectindex, ceil(pos.x / 96), ceil(pos.y / 96));
                            if (gameover) {
                                return;
                            }
                        }
                        //promotion
                        //update piece id and sprite texture
                        else {
                            if (selectindex == 0) {
                                g.getv()[g.ispromoting()].promote(9);
                                sv[g.ispromoting()].setTexture(wq);
                            }
                            else if (selectindex == 1) {
                                g.getv()[g.ispromoting()].promote(5);
                                sv[g.ispromoting()].setTexture(wr);
                            }
                            else if (selectindex == 2) {
                                g.getv()[g.ispromoting()].promote(4);
                                sv[g.ispromoting()].setTexture(wb);
                            }
                            else if (selectindex == 3) {
                                g.getv()[g.ispromoting()].promote(3);
                                sv[g.ispromoting()].setTexture(wn);
                            }
                            else if (selectindex == 4) {
                                g.getv()[g.ispromoting()].promote(-9);
                                sv[g.ispromoting()].setTexture(bq);
                            }
                            else if (selectindex == 5) {
                                g.getv()[g.ispromoting()].promote(-5);
                                sv[g.ispromoting()].setTexture(br);
                            }
                            else if (selectindex == 6) {
                                g.getv()[g.ispromoting()].promote(-4);
                                sv[g.ispromoting()].setTexture(bb);
                            }
                            else if (selectindex == 7) {
                                g.getv()[g.ispromoting()].promote(-3);
                                sv[g.ispromoting()].setTexture(bn);
                            }
                            g.donepromoting();
                        }
                        selectindex = -1;
                    }
                }
                clicking = true;
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    clicking = false;
                    //load pgui upon mouse release if promoting
                    //this is such a horrendous way to do it but it works
                    if (g.ispromoting()) {
                        sf::Vector2i mousepos = sf::Mouse::getPosition(window);
                        sf::Vector2f pos(mousepos.x, mousepos.y);
                        freezex = mousepos.x;
                        freezey = mousepos.y;
                    }
                }
            }
        }
        
        //end the current frame
        window.display();
    }
}
