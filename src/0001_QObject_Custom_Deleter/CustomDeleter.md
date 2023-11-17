# Howto Implement and Test a Custom Deleter of a unique_ptr which holds a QObject

Qt is based on reference semantics, which means that objects are passed by reference rather than by value. An object without a parent must be manually deleted. The unique_ptr is a good option for this, as it calls delete by default. However, it must be ensured that [1]

* there are no pending events that the object should receive or it might crash.
* Additionally, the object must live in the same thread as the one you are calling delete from, and
* the method in which you call delete is not a slot triggered by the object you are trying to delete or it might crash.

If these conditions cannot be met, deleteLater should be used. Further conditions for deleteLater:

* using it in a multithreaded environment, and implementing it with a custom deleter if necessary. [2]

To utilize the deleteLater functionality, a custom deleter can be written.

```cpp
struct DeleteLater {
    void operator()(QObject* obj) {
        obj->deleteLater();
    }
};
using QObjectUniqueStruct = std::unique_ptr<QObject, DeleteLater>;
```

A check whether obj is nullptr is not required, since [3]

```
23.11.1.2.2 unique_ptr destructor [unique.ptr.single.dtor]

2 Effects: If get() == nullptr there are no effects. Otherwise get_deleter()(get()).
```

To test the implementation you utilize an event loop. After the delete of the pointer, you need to
execute the event loop. A call to processEvents doesn't work, since QDeferredDeleteEvent are not
scheduled. [4], [5]

```
In the event that you are running a local loop which calls this function continuously, without an event loop, the DeferredDelete events will not be processed.
```

The complete example looks like:

```cpp
#include <QCoreApplication>
#include <memory>
#include <QEventLoop>
#include <QSignalSpy>
#include <cassert>
#include <QTimer>

// Create the Deleter
struct DeleteLater {
    void operator()(QObject* obj) {
        if(obj != nullptr) {
            obj->deleteLater();
        }
    }
};
using QObjectUniqueStruct = std::unique_ptr<QObject, DeleteLater>;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QEventLoop loop;

    auto ptr2 = QObjectUniqueStruct(new QObject{});
    QSignalSpy spy2(ptr2.get(), &QObject::destroyed);
    // register the connection
    loop.processEvents();
    // delete the qobject
    ptr2.reset();
    // the destructor should not be triggered, since deleteLater is used
    assert(spy2.count() == 0);

    // a loop.processEvents(); doesnt work, see
    // https://stackoverflow.com/questions/51440889/the-timing-to-delete-qobject-using-qobjectdeletelater

    // Use an exec to verify, that the object is deleted.
    QTimer timer;
    timer.singleShot(std::chrono::milliseconds{100}, [&loop](){loop.quit();});
    loop.exec();

    assert(spy2.count() == 1);
    return EXIT_SUCCESS;
}
```

[1]: <https://forum.qt.io/post/460996>
[2]: <https://stackoverflow.com/a/4894820/2127939>
[3]: https://timsong-cpp.github.io/cppwp/n4659/unique.ptr.single.dtor
[4]: https://doc.qt.io/qt-5/qcoreapplication.html#processEvents
[5]: https://stackoverflow.com/questions/51440889/the-timing-to-delete-qobject-using-qobjectdeletelater
