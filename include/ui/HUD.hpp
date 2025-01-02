#ifndef HUD_HPP
#define HUD_HPP

class HUD {

public:

    HUD();
    void Init();
    void Update();
    void Draw();

private:

    void DrawIcon();
    void DrawHP();
    void DrawMP();

};

#endif