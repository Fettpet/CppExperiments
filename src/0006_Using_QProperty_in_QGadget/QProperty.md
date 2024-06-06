# How does the Q_Property System handle the Constant Flag

 Constant properties in QML are properties that cannot be changed once set. They are particularly
 useful when you want to expose values that should not be altered by the QML code. By setting a
 Q_PROPERTY as CONSTANT, you are indicating to QML that the value of that property will not change,
 and it should not allow attempts to change it.

In your specific case, we have five different properties, each with a different configuration. By
testing the Constant Flag for Q_PROPERTY on each of these properties, you will be able to see how
QML handles attempts to change them when they are marked as CONSTANT.

## Test Cases

Acutally we have 5 different test cases:

1. Modify member - This test case checks whether a property that is not marked CONSTANT can be
modified successfully in QML. It should pass without any issues.
1. Modify const_member - This test case checks whether a property that is marked as CONSTANT will
fail when an attempt is made to modify it in QML. It should fail with an error message indicating
that the value cannot be changed.
1. Modify readonly - This test case checks whether a property that is read-only (i.e., has no
associated setter function) will fail when an attempt is made to modify it in QML. It should fail
with an error message.
1. Modify read_write - This test case checks whether a property that has both a getter and a setter
function can be modified successfully in QML. It should pass without any issues.
1. Modify const_read_write - This test case checks whether a property that has both a getter and a
setter function and is marked as CONSTANT will fail when an attempt is made to modify it in QML. It
should fail with an error message indicating that the value cannot be changed.

```cpp
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
```

## Results

1. Modify member - can be modified, work as expected
1. Modify const_member - the value remains constant. No error message is shown.
1. Modify readonly - the value doesnt change. No error message is triggerd.
1. Modify read_write - can be modified, work as expected
1. Modify const_read_write - the value remains constant. No error message is shown.
