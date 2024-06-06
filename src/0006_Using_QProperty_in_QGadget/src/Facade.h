#pragma once
#include "Gadget.h"
#include <QObject>

class Facade : public QObject
{
  Q_OBJECT

  Q_PROPERTY(MemberType member
                 READ getMember WRITE setMember NOTIFY memberChanged)

public:
  Facade(QObject* parent = nullptr)
    : QObject(parent)
  {
  }

  MemberType& getMember()
  {
    return member;
  }

  void setMember(const MemberType& mem)
  {
    member = mem;
  }

  MemberType member;

signals:
  void memberChanged();
};
