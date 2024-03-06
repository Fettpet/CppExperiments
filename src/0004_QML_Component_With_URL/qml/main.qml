import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true

    Button {
       id: button_inline
       text: "Load Inline"
       onClicked: {
           view.component = inline_comp
       }
    }

    Button {
        id: button_file
       text: "Load File"
       onClicked: {
           view.component = file_comp
       }
       anchors.left: button_inline.right
    }

    Button {

       text: "toggle active"
       onClicked: {
           view.active = !view.active
       }
       anchors.left: button_file.right
    }


    View {
        id: view
        z: -1
        active: true
    }

    Component {
        id: file_comp
        Loader {
            source: "MyRect.qml"
            onLoaded: console.log("Load file MyRect.qml")
        }
    }

    Component {
        id: inline_comp
        Rectangle {
            color: "red"
            anchors.fill: parent

            Text {
                anchors.centerIn: parent
                text: qsTr("Inline Component")
            }
        }
    }
}
