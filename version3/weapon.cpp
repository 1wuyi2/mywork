#include "weapon.h"
#include"chosemap.h"
weapon::weapon()
{
    if(chosemap::y==1)
    {
        m_shootSound.setSource(QUrl("qrc:/sounds/ak47.WAV"));
    }
    else if(chosemap::y==2)
    {
        m_shootSound.setSource(QUrl("qrc:/sounds/m4a1.WAV"));
    }
    else  if(chosemap::y==3)
    {
        m_shootSound.setSource(QUrl("qrc:/sounds/p90.WAV"));
    }
      else if(chosemap::y==4)
    {
        m_shootSound.setSource(QUrl("qrc:/sounds/famas.WAV"));
    }
  else  if(chosemap::y==5)
    {
        m_shootSound.setSource(QUrl("qrc:/sounds/deagle.WAV"));
    }
    else if(chosemap::y==6)
    {
        m_shootSound.setSource(QUrl("qrc:/sounds/galil.WAV"));
    }
     else if(chosemap::y==7)
    {
        m_shootSound.setSource(QUrl("qrc:/sounds/awp.WAV"));
    }
    else if(chosemap::y==8)
    {
        m_shootSound.setSource(QUrl("qrc:/sounds/usp.WAV"));
    }
    else if(chosemap::y==9)
    {
        m_shootSound.setSource(QUrl("qrc:/sounds/glock18.WAV"));
    }
    else if(chosemap::y==10)
    {
        m_shootSound.setSource(QUrl("qrc:/sounds/sg552.WAV"));
    }
}
