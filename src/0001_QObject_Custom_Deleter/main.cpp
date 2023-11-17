#include <QCoreApplication>
#include <memory>
#include <QEventLoop>
#include <QSignalSpy>
#include <cassert>
#include <QTimer>


// 2. Test with Class
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
    //  https://stackoverflow.com/questions/51440889/the-timing-to-delete-qobject-using-qobjectdeletelater

    // this works
    QTimer timer;
    timer.singleShot(std::chrono::milliseconds{100}, [&loop](){loop.quit();});
    loop.exec();

    assert(spy2.count() == 1);
    return EXIT_SUCCESS;
}

