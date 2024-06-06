import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import Lib.QGadgetTest 1.0


Window {
    width: 640
    height: 480
    visible: true

    Container {
        id: container
    }

    ColumnLayout {
        Text {
            text: {
                container.member.member = 10
                return "Member Type after set to 10 is " + container.member.member
            }
        }

        Text {

            text: {
                container.member.const_member = 10
                return "Constant Member Type after set to 10 is " + container.member.const_member
            }
        }

        Text {

            text: {
                container.member.readonly = 10
                return "Readonly Type after set to 10 is " + container.member.readonly
            }
        }

        Text {

            text: {
                container.member.read_write = 10
                return "Read write Type after set to 10 is " + container.member.read_write
            }
        }

        Text {

            text: {
                container.member.const_read_write = 10
                return "constant Read write Type after set to 10 is " + container.member.const_read_write
            }
        }
    }

}
