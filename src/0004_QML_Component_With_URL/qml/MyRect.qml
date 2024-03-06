import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle {
    color: "blue"
    anchors.fill: parent

    Text {
        anchors.centerIn: parent
        text: qsTr("file Component")
    }
}
