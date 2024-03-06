import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {
    id: root
    width: 640
    height: 480
    visible: true
    property Component component
    property bool active: true

    Loader {
        active: root.active
        sourceComponent: Component {
            Loader {
                sourceComponent: root.component
                anchors.fill: parent
                onLoaded: console.log("Loaded inside")
            }
        }
        onLoaded: console.log("Loaded outside")
        anchors.fill: parent
    }
}
