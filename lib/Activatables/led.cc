#include "structure.hh"

LED::LED(pin_t pin)
: Activatable(pin)
{
    activate();
}


// TODO: this
LED::LED(const LED &other, pin_t new_pin)
: LED(new_pin)
{
    activate();
}

LED& LED::operator=(const LED &other) {

}

// virtual ~LED() {

// }



void LED::on_activate() {
    digitalWrite(m_pin, HIGH);
}

void LED::on_deactivate() {
    digitalWrite(m_pin, LOW);
}

void LED::loop_impl() {
    // no override
}