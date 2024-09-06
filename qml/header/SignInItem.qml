import QtQuick

import QtQuick.Layouts

Item {

    //anchors.fill: parent
    width: parent.width

    property string placeholderText
    property string value
    property int fontSize

    //id: pkTextInput
    implicitHeight: input.font.pixelSize * 1.5

    Rectangle {

            color: "transparent"
            //anchors.fill: parent
            border.color: "#495e73" //"#232e3c"
            border.width: 1
            radius: 4

            width: parent.width
            height: 50


            TextInput{
                id: input
                leftPadding: 10

                horizontalAlignment: Qt.AlignLeft
                verticalAlignment: Qt.AlignVCenter

                anchors {
                    fill: parent
                }
                font.pointSize: fontSize
                color: "#dddddd"
                selectByMouse: true
                layer.enabled: true
                text: value

                onEditingFinished: {
                    value = text
                }


                Text {
                    width: parent.width
                    horizontalAlignment: Qt.AlignRight
                    text: placeholderText
                    color: "#999"
                    rightPadding: 5
                    layer.enabled: true
                }
        }
    }
}

