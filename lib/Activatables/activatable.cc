#include "structure.hh"

Activatable::Activatable(pin_t pin)
: m_pin       (pin)
, m_is_enabled(true)
{
    pinMode(pin, OUTPUT);
}

Activatable::Activatable(const Activatable &other, pin_t new_pin)
: Activatable(new_pin)
{}

Activatable& Activatable::operator= (const Activatable &other) {
    *this = other;
}

Activatable::~Activatable() {

}

void Activatable::activate() {
    m_is_enabled = true;
    on_activate();
}

void Activatable::deactivate() {
    m_is_enabled = false;
    on_deactivate();
}

void Activatable::toggle() {
    if (m_is_enabled) deactivate();
    else activate();
}

void Activatable::loop() {
    if (m_is_enabled)
        loop_impl();
}