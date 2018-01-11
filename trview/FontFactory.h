#pragma once

#include <string>

#include <atlbase.h>
#include <d2d1.h>
#include <dwrite.h>
#include <memory>
#include <d3d11.h>

#include "Font.h"

namespace trview
{
    class FontFactory
    {
    public:
        FontFactory();

        FontFactory(const FontFactory&) = delete;

        std::unique_ptr<Font> create_font(CComPtr<ID3D11Device> device, const std::wstring& font_face);
    private:
        CComPtr<ID2D1Factory>   _d2d_factory;
        CComPtr<IDWriteFactory> _dwrite_factory;
    };
}