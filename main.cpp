#include <iostream>
#include "TextureManager.h"
#include "DungeonFloor.h"
#include "PC.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "SnakeBoss.h"
#include "UI.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Rouge Dungeon");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    DungeonFloor floor1;
    UI test;

    //PC
    PC pc;
    pc.setPosition(300, 300);
    BulletManager bullets = BulletManager();
    sf::Sprite crosshair;
    crosshair.setOrigin(113.0 / 2, 113.0 / 2);
    crosshair.setTexture(TextureManager::GetTexture("Crosshair"));
    string currRoomID = "C3";
    SnakeBoss snakeBoss;

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        Bullet newBullet(pc.getDamage());
        while (window.pollEvent(event)) {
            for (int i = 0; i < 4; ++i) {
                auto currDoors = floor1.getRooms()[currRoomID].getDoors();
                if (pc.getGlobalBounds().intersects(currDoors[i].getGlobalBounds())) {
                    switch (i) {
                        case 0:
                            if (currDoors[i].isVisable() && !currDoors[i].isLocked()) {
                                floor1.moveRoom("north");
                                pc.setPosition(currDoors[3].getPosition().x, currDoors[3].getPosition().y - 100);
                            }
                            break;
                        case 1:
                            if (currDoors[i].isVisable() && !currDoors[i].isLocked()) {
                                floor1.moveRoom("west");
                                pc.setPosition(currDoors[2].getPosition().x - 100, currDoors[2].getPosition().y);
                            }
                            break;
                        case 2:
                            if (currDoors[i].isVisable() && !currDoors[i].isLocked()) {
                                floor1.moveRoom("east");
                                pc.setPosition(currDoors[1].getPosition().x + 100, currDoors[1].getPosition().y);
                            }
                            break;
                        case 3:
                            if (currDoors[i].isVisable() && !currDoors[i].isLocked()) {
                                floor1.moveRoom("south");
                                pc.setPosition(currDoors[0].getPosition().x, currDoors[0].getPosition().y + 100);
                            }
                            break;
                        default:
                            break;
                    }
                }
                currRoomID = floor1.getCurrPos();
            }
            if (floor1.getRooms()[currRoomID].isBossRoom()) {
                floor1.getRooms()[currRoomID].setDoorsLocked(true);
                snakeBoss.setAlive(true);
            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::W) {
                    floor1.moveRoom("north");
                } else if (event.key.code == sf::Keyboard::A) {
                    floor1.moveRoom("west");
                } else if (event.key.code == sf::Keyboard::S) {
                    floor1.moveRoom("south");
                } else if (event.key.code == sf::Keyboard::D) {
                    floor1.moveRoom("east");
                }
                currRoomID = floor1.getCurrPos();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                Bullet *newBullet = new Bullet(pc.getDamage());
                newBullet->setPosition(pc.getPosition());
                newBullet->rotate(pc.getAngle());
                bullets.addBullet(newBullet);
                auto mousePos = sf::Mouse::getPosition(window);
                auto mouseCords = window.mapPixelToCoords(mousePos);
                std::cout << mouseCords.x << " " << mouseCords.y << std::endl;
            }
        }
        auto tempPCPos = pc.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            tempPCPos.x -= 10.f;
            if (floor1.getRooms()[currRoomID].getGlobalBounds().contains(tempPCPos)) {
                pc.move(-10.f, 0.f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            tempPCPos.y -= 10.f;
            if (floor1.getRooms()[currRoomID].getGlobalBounds().contains(tempPCPos)) {
                pc.move(0.f, -10.f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            tempPCPos.y += 10.f;
            if (floor1.getRooms()[currRoomID].getGlobalBounds().contains(tempPCPos)) {
                pc.move(0.f, 10.f);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            tempPCPos.x += 10.f;
            if (floor1.getRooms()[currRoomID].getGlobalBounds().contains(tempPCPos)) {
                pc.move(10.f, 0.f);
            }
        }
        if (snakeBoss.isAlive()) {
            snakeBoss.update();
            if(snakeBoss.getGlobalBounds().intersects(pc.getGlobalBounds())){
                pc.takeDamage(10);
            }
        }
        if(!pc.isAlive()){
            window.close();
        }

        window.clear();
        window.draw(floor1);
        auto currRoom = floor1.getRooms()[currRoomID];
        window.draw(currRoom);
        for (int i = 0; i < 4; ++i) {
            if (currRoom.getDoors()[i].isVisable()) {
                window.draw(currRoom.getDoors()[i]);
            }
        }
        bullets.updateBullets(window);
        //Stuff to upload because mess
        window.draw(pc);
        test.draw(window, &pc);
        //window.draw(floor1.getRooms()[currRoomID].getEnemies()[0]);
        pc.pointMouseCursor(window);
        if (snakeBoss.isAlive()) {
            for (const auto &tail : snakeBoss.getTails()) {
                window.draw(tail);
            }
            window.draw(snakeBoss);
        }
        auto mousePos = sf::Mouse::getPosition(window);
        auto mouseCords = window.mapPixelToCoords(mousePos);
        crosshair.setPosition(mouseCords);
        window.draw(crosshair);
        window.display();

    }

    return 0;
}