#ifndef HUD_HPP
#define HUD_HPP

class HUD {

public:

    HUD();
    void Init();
    void Update();
    void Draw();

private:

    void DrawIcon(float, float);
    void DrawHP(float, float);
    void DrawMP(float, float);

};

#endif