#pragma once
#include "Gadget.h"
#include <QObject>

class Facade : public QObject
{
  Q_OBJECT

public:
  Facade(QObject* parent = nullptr)
    : QObject(parent)
  {
  }

signals:

  void changedValue(Gadget);
};
