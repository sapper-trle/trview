#pragma once

#include "ILayout.h"

namespace trview
{
    namespace ui
    {
        class GridLayout final : public ILayout
        {
        public:
            explicit GridLayout(uint32_t columns);
            virtual ~GridLayout() = default;
            virtual void update_layout(Control& control) override;
        private:
            uint32_t _columns;
        };
    }
}