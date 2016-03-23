#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{
    this->m_nm = new NetworkManager(this);
    this->m_lm = new LocalManager(this);
}

void Manager::init()
{
    this->m_lm->init();
    this->m_nm->init();
}

