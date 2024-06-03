# Support of strong types within a Q_GADGET class

Q_GADGET can be used for data exchange between C++ and QML. This is a lightweight alternative to
Q_OBJECT. This proposal answers two questions: 1. When should Q_GADGET be used, and when should
Q_OBJECT be used? 2. Does Q_GADGET support strong types?

## Q_GADGET or Q_OBJECT

Use Q_GADGET:

* When a ValueType in JavaScript and C++ has the same attributes and functions. [1]
* It is best practice to keep a gadget as a property of an object or to emit it as a signal. [1]
* It is passed as a value between C++ and QML. [1]
* Q_GADGETs can have Q_ENUM, Q_PROPERTY, and Q_INVOKABLE, but they cannot have signals or slots. [2]

Use Q_OBJECT:

* When signals/slots are needed.
* A Q_OBJECT is passed as a pointer between C++ and QML. [1]

## Example Code

There is a StrongType. This is a pure C++ data type. Then there is a Q_GADGET Gadget. The StrongType
is a member of the Gadget. The question is, does StrongType also have to be a Q_GADGET?

```cpp
class StrongType
{
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
```

With this code, the StrongType cannot be accessed. The data type is unknown in QML. The error
message is "TypeError: Cannot read property 'x' of undefined"

So the StrongType needs to be a Q_GADGET.

[1]: https://doc.qt.io/qt-6/qtqml-cppintegration-data.html#value-types
[2]: https://doc.qt.io/qt-6/qobject.html#Q_GADGET
