#include <Adafruit_NeoPixel.h>
#include <IRremote.h>

#define RECV_PIN 3 // Pin IO do sensor infravermelho.
#define PIXEL_PIN 2 //Pin de OUTPUT do NeoPixel.
#define NUMPIXELS 56 //Número de neopixels, 8 pixels de 7 NeoPixels.

/*
1 -> 2295; Vermelho -> RGB(255,0,0)
2 -> 34935; Verde -> RGB(0,255,0)
3 -> 18615; Azul -> RGB(0,0,255)
4 -> 10455; Amarelo -> RGB(255,255,0)
5 -> 43095; Magenta -> RGB(255,0,255)
6 -> 26775; Ciano -> RGB(0,255,255)
7 -> 6375; Rosa -> RGB(217,134,149)
*/

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

IRrecv irrecv(RECV_PIN); // Sensor Infravermelho
decode_results results;

void setup()
{
  irrecv.enableIRIn();
  
  pixels.setBrightness(255);
  pixels.begin();
}

void loop()
{
    if (irrecv.decode(&results)){
        unsigned int value = results.value;
        switch(value){
            case 2295: //botão 1 (VERMELHO)
                for(int i = 0; i < NUMPIXELS; i++) 
                {
                    pixels.setPixelColor(i, pixels.Color(255,0,0));
                    pixels.show();
                }
                break;
            case 34935: // botão 2 (VERDE)
                for(int i = 0; i < NUMPIXELS; i++) 
                {
                    pixels.setPixelColor(i, pixels.Color(0,255,0));
                    pixels.show();
                }
                break;
            case 18615: // botão 3 (AZUL)
                for(int i = 0; i < NUMPIXELS; i++) 
                {
                    pixels.setPixelColor(i, pixels.Color(0,0,255));
                    pixels.show();
                }
                break;
            case 10455: // botão 4 (AMARELO)
                for(int i = 0; i < NUMPIXELS; i++) 
                {
                    pixels.setPixelColor(i, pixels.Color(255,255,0));
                    pixels.show();
                }
                break;
            case 43095: // botão 5 (MAGENTA)
                for(int i = 0; i < NUMPIXELS; i++) 
                {
                    pixels.setPixelColor(i, pixels.Color(255,0,255));
                    pixels.show();
                }
                break;
            case 26775: // botão 6 (CIANO)
                for(int i = 0; i < NUMPIXELS; i++) 
                {
                    pixels.setPixelColor(i, pixels.Color(0,255,255));
                    pixels.show();
                }
                break;
            case 6375: // botão 7 (ROSA)
                for(int i = 0; i < NUMPIXELS; i++) 
                {
                    pixels.setPixelColor(i, pixels.Color(217,134,149));
                    pixels.show();
                }
                break;
        }
      irrecv.resume(); // Recebe o próximo valor.
    }
}