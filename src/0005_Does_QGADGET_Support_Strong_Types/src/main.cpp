#include "Facade.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>

int
main(int argc, char* argv[])
{
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));

  qmlRegisterType<Facade>("Lib.Facade", 1, 0, "Facade");

  Facade facade;

  engine.setInitialProperties({{"facade", QVariant::fromValue(&facade)}});
  QTimer timer;
  timer.start(1000);
  timer.callOnTimeout([&facade]() {
    facade.changedValue(Gadget{rand()});
  });

  QObject::connect(
    &engine,
    &QQmlApplicationEngine::objectCreated,
    &app,
    [url](QObject* obj, const QUrl& objUrl) {
      if (!obj && url == objUrl) {
        QCoreApplication::exit(-1);
      }
    },
    Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
