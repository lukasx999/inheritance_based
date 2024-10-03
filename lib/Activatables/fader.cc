#include "structure.hh"

Fader::Fader(pin_t pin, time_t delay)
: Activatable(pin)
, m_current_value    (255)
, m_delay    (delay)

, m_set_time_(0)
{}

Fader::Fader(const Fader &other, pin_t new_pin)
: Fader(new_pin, other.m_delay)
{}

void Fader::on_activate() {
}

void Fader::on_deactivate() {
}

void Fader::loop_impl() {

    time_t now = millis();
    if (now < m_set_time_) return;

    m_set_time_ = now + m_delay; // set new delay time

    analogWrite(m_pin, m_current_value);
    --m_current_value;
    if (m_current_value <= 0) m_current_value = 255;

}