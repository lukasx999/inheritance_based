#include "structure.hh"

BlinkingLight::BlinkingLight(pin_t pin, time_t delay)
: Activatable(pin)
, m_delay    (delay)

, m_set_time_(0)
, m_state_   (false)
{}

BlinkingLight::BlinkingLight(const BlinkingLight &other, pin_t new_pin)
: BlinkingLight(new_pin, other.m_delay)
{}

void BlinkingLight::on_activate() {
}

void BlinkingLight::on_deactivate() {
}

void BlinkingLight::loop_impl() {

    time_t now = millis();
    if (now < m_set_time_) return;

    m_set_time_ = now + m_delay; // set new delay time

    m_state_ = !m_state_;
    digitalWrite(m_pin, m_state_);

}