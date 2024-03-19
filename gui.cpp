#include "gui.h"

gui::gui() {
    //create window
    //window.create(sf::VideoMode(768, 768), "My window");
    // 
    //insert piece sprites into v
    //load piece textures
    sf::Texture p;
    p.loadFromFile("assets/pieces.png");

    sf::Sprite wk;
    piece* wkp = new piece(wk, 5, 8);
    wk.setTexture(p);
    wk.setTextureRect(sf::IntRect(0, 0, 133, 133));
    wk.setPosition(wkp->rank-1*96, wkp->file-1*96);
    wk.setScale(0.75, 0.75);
    v.push_back(wkp);

    sf::Sprite wq;
    piece* wqp = new piece(wq, 4, 8);
    wq.setTexture(p);
    wq.setTextureRect(sf::IntRect(133, 0, 133, 133));
    wk.setPosition(wqp->rank - 1 * 96, wqp->file - 1 * 96);
    wk.setScale(0.75, 0.75);
    v.push_back(wqp);

    //set adjust sprite pos and size
    for (int i = 0; i < v.size(); i++) {
        v[i]->sprite.setPosition(v[i]->rank - 1 * 96, v[i]->rank - 1 * 96);
        v[i]->sprite.setScale(0.75, 0.75);
    }

}

void gui::drawgui() {
    sf::RenderWindow window(sf::VideoMode(768, 768), "My window");
    while (window.isOpen())
    {
        //check for close
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        
        // draw everything here...
        // window.draw(...);
        //da board
        sf::Texture boardt;
        boardt.loadFromFile("assets/chessboard.png");
        sf::Sprite board;
        board.setTexture(boardt);
        window.draw(board);

        //da pieces
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i]->rank << std::endl;
            window.draw(v[i]->sprite);
        }
        /*
        sf::Texture p;
        p.loadFromFile("assets/pieces.png");
        sf::Sprite wk;
        wk.setTexture(p);
        wk.setTextureRect(sf::IntRect(0, 0, 133, 133));
        wk.setPosition(384, 672);
        wk.setScale(0.75, 0.75);
        window.draw(wk);

        sf::Sprite wq;
        wq.setTexture(p);
        wq.setTextureRect(sf::IntRect(133, 0, 133, 133));
        wq.setPosition(288, 672);
        wq.setScale(0.75, 0.75);
        window.draw(wq);*/
        
        // end the current frame
        window.display();
    }
}

void gui::makemove() {
    while (window.isOpen()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            std::cout << "fuck" << std::endl;
        }
    }
}