import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: _btn

    property int diameter: 35
    property int imageSize: 24
    property string backgroundColor: "transparent"
    property string imageSource

    Layout.maximumHeight: diameter
    Layout.minimumHeight: diameter
    Layout.minimumWidth: diameter
    Layout.maximumWidth: diameter

    padding: 0

    flat: true

    Image {
        anchors.centerIn: parent
        width: imageSize; height: imageSize
        source: imageSource
        fillMode: Image.PreserveAspectFit
    }

    background: Rectangle {

        opacity: _btn.hovered ? 0.25 : 1.0
        color: _btn.hovered ? (_btn.down ? "#4b7cb0" : "#5b98d9") : "transparent"

        anchors.fill: parent
        radius: width * 0.5

        // Behavior on opacity { NumberAnimation { duration: 100 } }
        //border.color: "#232e3c"
        //border.width: 1
    }
}
