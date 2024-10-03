#pragma once

#include <Arduino.h>
#include <stdint.h>

typedef const uint8_t pin_t;
typedef unsigned long time_t;

class Activatable {
public:
    pin_t  m_pin;

    Activatable(pin_t pin);
    Activatable(const Activatable &other, pin_t new_pin); // copy
    Activatable& operator=(const Activatable &other);
    virtual ~Activatable();

    virtual void activate();
    virtual void deactivate();
    virtual void toggle();
    virtual void loop();

protected:
    virtual void on_activate()   = 0;
    virtual void on_deactivate() = 0;
    virtual void loop_impl()     = 0;

private:
    bool   m_is_enabled;
};



class LED : public Activatable {
public:
    LED(pin_t pin);
    LED(const LED &other, pin_t new_pin); // copy to another pin
    LED& operator=(const LED &other);

protected:
    virtual void on_activate()   override;
    virtual void on_deactivate() override;
    virtual void loop_impl()     override; // no need to override this
};




// pin must be pwm capable (`~`)
class Fader : public Activatable {
public:
    int          m_current_value;
    const time_t m_delay; // delay inbetween values

    Fader(pin_t pin, time_t delay);
    Fader(const Fader &other, pin_t new_pin); // copy

protected:
    time_t m_set_time_;

    virtual void on_activate()   override;
    virtual void on_deactivate() override;
    virtual void loop_impl()     override;
};






class BlinkingLight : public Activatable {
public:
    const time_t m_delay; // delay inbetween values

    BlinkingLight(pin_t pin, time_t delay);
    BlinkingLight(const BlinkingLight &other, pin_t new_pin); // copy

protected:
    time_t m_set_time_;
    bool   m_state_;

    virtual void on_activate()   override;
    virtual void on_deactivate() override;
    virtual void loop_impl()     override;
};






