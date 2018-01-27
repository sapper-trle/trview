#pragma once

#include <string>
#include "Window.h"

#include "TextAlignment.h"
#include "ParagraphAlignment.h"

namespace trview
{
    namespace ui
    {
        class Label : public Window
        {
        public:
            Label(Point position, 
                Size size, 
                Colour background_colour, 
                std::wstring text, 
                float text_size = 20.0f,
                TextAlignment text_alignment = TextAlignment::Left,
                ParagraphAlignment paragraph_alignment = ParagraphAlignment::Near);

            virtual      ~Label() = default;
            std::wstring text() const;
            float        text_size() const;
            void         set_text(std::wstring text);
            TextAlignment      text_alignment() const;
            ParagraphAlignment paragraph_alignment() const;
        private:
            std::wstring       _text;
            float              _text_size;
            TextAlignment      _text_alignment;
            ParagraphAlignment _paragraph_alignment;
        };
    }
}