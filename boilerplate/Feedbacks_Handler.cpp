#include "Feedbacks_Handler.h"

Feedbacks_Handler::Feedbacks_Handler()
{
    HapticAvailable = false;
    RGB_LEDAvailable = false;
}

String Feedbacks_Handler::UpdateFeedback()
{
  if(HapticAvailable)
    HapticMotor->RefreshValues();
}

void Feedbacks_Handler::HandleTime(unsigned int ElapsedTime)
{
  if(HapticAvailable)
    HapticMotor->HandleTime(ElapsedTime);
} 

void Feedbacks_Handler::setHapticMotor(Haptic *pHapticMotor)
{
    HapticMotor = pHapticMotor;
    HapticAvailable = true;
}

void Feedbacks_Handler::Vibrate(unsigned int Time)
{  
    if(HapticAvailable == false)
      return;     
    HapticMotor->Vibrate(Time);
}

void Feedbacks_Handler::Vibrate(String Type)
{
    if(HapticAvailable == false)
      return;    
    if(Type == String("short"))
      HapticMotor->VibrateShort();
    else if(Type == String("long"))
      HapticMotor->VibrateLong();
}


void Feedbacks_Handler::setRGB_LED(RGB_LED *pLED)
{
    LED = pLED;
    RGB_LEDAvailable = true;
}

void Feedbacks_Handler::setColor(String color)
{
  LED->setColor(color);
}


