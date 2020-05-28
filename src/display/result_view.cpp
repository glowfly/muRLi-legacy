#ifndef RESULTVIEW_H
#define RESULTVIEW_H

#include "view.hpp"
#include "display.hpp"

namespace Murli
{
    class ResultView : public View
    {
        public:
            void drawFrame(U8G2_SH1106_128X64_NONAME_F_4W_SW_SPI& display) override
            {
                display.setFontPosCenter();
                uint8_t displayCenter = (display.getDisplayHeight() - 10) / 2;

                display.setFont(u8g2_font_open_iconic_check_2x_t);
                if(_success)
                {
                    display.drawGlyph(10, displayCenter, 65);
                }
                else
                {
                    display.drawGlyph(10, displayCenter, 66);
                }
                                
                display.setFont(u8g2_font_5x8_tf);
                display.drawStr(35, displayCenter, _text.c_str());

                display.setFontPosBaseline();
            }

            void setText(const std::string& text) 
            {
                _text = text;
            }

            void setResult(const boolean success)
            {
                _success = success;
            }
        
        private:
            boolean _success;
            std::string _text;
    };
}

#endif // RESULTVIEW_H