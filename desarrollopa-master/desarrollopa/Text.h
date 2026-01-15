#pragma once

#include <string>
using namespace std;

#include <GL/glut.h>
#include "Solid.h"

class Text : public Solid {
protected:
    string text;   // Texto
    void* font;    // Fuente

public:
    // Constructor
    Text(const string txt = "", void* font = GLUT_BITMAP_HELVETICA_18)
        : Solid(), text(txt), font(font)
    {
    }

    // Setters
    void SetText(const string txt) { text = txt; }
    void SetFont(void* f) { font = f; }

    // Getters
    string GetText() const { return text; }
    void* GetFont() const { return font; }

    // Renderiza el texto
    virtual void Render() override;

    virtual Solid* Clone() override { return new Text(*this); }

    virtual ~Text() {}
};
