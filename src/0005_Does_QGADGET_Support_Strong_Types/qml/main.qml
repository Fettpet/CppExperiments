import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    required property var facade

    Text {
        id: myText
    }

    Connections {
        target: facade
        onChangedValue: (value) => {
            myText.text = value.value.x
        }
    }
}
