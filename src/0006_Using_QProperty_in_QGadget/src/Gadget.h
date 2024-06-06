#pragma once
#include <QObject>
#include <iostream>

class MemberType
{
  Q_GADGET

  Q_PROPERTY(int member
                   MEMBER member )

  Q_PROPERTY(int const_member
                 MEMBER const_member CONSTANT )

  Q_PROPERTY(int readonly
                 READ read_readonly )
  Q_PROPERTY(int read_write
                 READ get_read_write WRITE set_write_read )
  Q_PROPERTY(int const_read_write
                 READ get_const_read_write WRITE set_const_read_write CONSTANT )
public:
  int read_readonly() const
  {
    return readonly;
  }

  int get_read_write() const
  {
    return read_write;
  }

  void set_write_read(int v)
  {
    read_write = v;
  }

  int get_const_read_write() const
  {
    return const_read_write;
  }

  void set_const_read_write(int v)
  {
    const_read_write = v;
  }

  int readonly{};
  int read_write{};
  int const_read_write{};
  int member{};
  int const_member{};
};

constexpr bool
operator==(const MemberType& lhs, const MemberType& rhs)
{
  return lhs.member == rhs.member && lhs.const_member == rhs.const_member;
}

constexpr bool
operator!=(const MemberType& lhs, const MemberType& rhs)
{
  return !(lhs == rhs);
}

Q_DECLARE_METATYPE(MemberType);
