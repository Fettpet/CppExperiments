# CppExperiments

This Repository stores all C++ experiments I have done.

## Experiments

| Description  | Link |
| ------------- | ------------- |
| Is auto deduced to a pointer, if it is initialized with a pointer  | [Godbolt](https://godbolt.org/z/EPGP9x4qq)  |
| Experiments with noexcept specifier, some old examples dont work   | [Godbolt](https://godbolt.org/z/vzhqerbjq)  |
| Howto Implement and Test a custom Deleter of a QObject             | [Custom Deleter](src/0001_QObject_Custom_Deleter/CustomDeleter.md) |
| Howto Implement custom operator as friend                          | [Friend Operator](src/0002_Friend_Template_Operator/main.cpp) |
| Does void_t<is_same<A,B>> deactivate specialization                | [void_t<is_same<A, B>>](src/0003_void_t_with_is_same/main.cpp) |
| Is a nested Loader load/unloaded by the outer one?                 | [Loader](src/0004_QML_Component_With_URL/Loader.md) |
| What is Q_GADGET used for? Does it support native strong Type?     | [Q_GADGET](src/0005_Does_QGADGET_Support_Strong_Types/StrongType.md) |
| Testing Constant Flag of QProperty                                 | [QProperty](src/0006_Using_QProperty_in_QGadget/QProperty.md) |
