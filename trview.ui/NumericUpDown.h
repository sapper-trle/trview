#pragma once

#include "Window.h"
#include <trview.common/Texture.h>
#include <trview.common/Event.h>

namespace trview
{
    namespace ui
    {
        class Label;

        class NumericUpDown : public Window
        {
        public:
            NumericUpDown(
                Point point, 
                Size size, 
                Colour background_colour, 
                Texture up_texture, 
                Texture down_texture, 
                int32_t minimum,
                int32_t maximum);

            Event<int32_t> on_value_changed;

            void set_value(int32_t value);
        private:
            int32_t _minimum;
            int32_t _maximum;
            int32_t _value{ 0 };

            ui::Label* _label;
        };
    }
}