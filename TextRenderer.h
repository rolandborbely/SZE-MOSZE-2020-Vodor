#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include "Renderer.h"
#include <ostream>

class TextRenderer : public Renderer{
private:
    std::ostream& b_stream;
public:
    TextRenderer(std::ostream& stream = std::cout) : b_stream(stream){}
    virtual void render(const Game&) const = 0;
    void setOutputStream(std::ostream& stream){
        b_stream.copyfmt(stream);
    }
};

class HeroTextRender : public TextRenderer{
public:
    void render(const Game&) const override;
};  

class ObserverTextRenderer : public TextRenderer{
public:
    void render(const Game&) const override;
};


#endif