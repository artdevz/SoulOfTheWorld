#ifndef SCREEN_HPP
#define SCREEN_HPP

enum ScreenType { MAIN, PLAY, GAME };

class Screen {

public:

    ScreenType screenType;

    Screen();
    void MainMenuScreen();
    void PlayMenuScreen();
    void GameScreen();

private:

};

#endif