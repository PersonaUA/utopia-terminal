import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Button {
    id: _btn
    property int diameter: 45
    property string backgroundColor: "transparent"
    property string borderColor: "#232e3c"

    Layout.maximumHeight: diameter
    Layout.minimumHeight: diameter
    Layout.minimumWidth: diameter
    Layout.maximumWidth: diameter

    Layout.leftMargin: 10
    Layout.rightMargin: 10

    flat: true



    contentItem: Text {
        text: _btn.text
        font: _btn.font



    color: "#dddddd" //color text
//        opacity: enabled ? 1.0 : 0.3

        //color: _btn.down ? "transparent" : backgroundColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        elide: Text.ElideMiddle
    }

    background: Rectangle {

        opacity: _btn.hovered ? 0.75 : 1.0

        //color: "transparent"

        //color: _btn.hovered ? "#5288c1" : "transparent"
        color: _btn.hovered ? (_btn.down ? "#4b7cb0" : "#5b98d9") : "transparent"

        anchors.fill: parent
        radius: width * 0.5
        Behavior on opacity { NumberAnimation { duration: 200 } }

        border.color: borderColor
        border.width: 1

    }

//    background: Rectangle {
//        opacity: 0.3
//        color: btn1.hovered ? "grey" : "transparent"
//        anchors.fill: parent
//        radius: width * 0.5
//        Behavior on color { ColorAnimation { duration: 150 } }
//    }
}
