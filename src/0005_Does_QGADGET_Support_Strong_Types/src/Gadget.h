#pragma once
#include <QObject>

class StrongType
{
  Q_GADGET

  Q_PROPERTY(int x
                   MEMBER x CONSTANT FINAL)

public:
  int x{};
};

class Gadget
{
  Q_GADGET

  Q_PROPERTY(StrongType value
                   MEMBER value CONSTANT FINAL)
public:
  StrongType value;
};

Q_DECLARE_METATYPE(StrongType);
Q_DECLARE_METATYPE(Gadget);
