#include <Arduino.h>

#include "structure.hh"



auto led       = new LED          (PD2);
auto fader     = new Fader        (PD6, 10);
auto fader2    = new Fader        (PD5, 5);
auto blink     = new BlinkingLight(PD7, 500);
auto blink2    = new BlinkingLight(PD4, 2000);
auto blink_cpy = new BlinkingLight(*blink, PD3);


auto setup() -> void {
    Serial.begin(9600);
    // led.activate();
    // led.deactivate();
    // fader.deactivate();
    // fader.toggle();
}

auto loop() -> void {

    // if (millis() >= 5000)
    //     led.deactivate();

    blink_cpy->loop();
    led   ->loop();
    blink ->loop();
    blink2->loop();
    fader ->loop();
    fader2->loop();
}



/*

public:
generelles interface: gleich für alle klassen


protected:
wird von abgeleiteter klasse überschrieben



shallow copy!

inheritance impl in base class auf 0 setzen -> pure virtual


led: loop_impl wird nicht überschrieben: unnätig

*/