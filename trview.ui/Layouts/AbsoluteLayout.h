#pragma once

#include "ILayout.h"

namespace trview
{
    namespace ui
    {
        class AbsoluteLayout : public ILayout
        {
        public:
            virtual ~AbsoluteLayout() = default;
            virtual void update_layout(Control& control) override;
        };
    }
}