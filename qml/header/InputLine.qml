import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../"

import "qrc:/mdi/Icon.js" as MdiFont

Rectangle {
    id: price_input_line
    color: "transparent" //"#3e525c"
    width: parent.width
    height: 50

    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    Layout.margins: 0

    Layout.bottomMargin: 10

    property string placeholderText

   // property int lineHeight: 50
    property double value: 1

    ColumnLayout {
        anchors.fill: parent

        //Layout.fillHeight: true
        spacing: -1

        RowLayout {
            width: parent.width
            Layout.fillWidth: true
            Layout.fillHeight: true
            focus: false
            spacing: -1

            CustomRoundButton {
                text: MdiFont.Icon.chevronDown
                onClicked: {
                    value = value - 10.0;
                    console.log(data);
                }
            }

            ColumnLayout { Layout.fillWidth: true }

            CustomTextInput {

                Layout.fillWidth: true
                Layout.maximumWidth: 300
                Layout.minimumWidth: 150
                Layout.preferredWidth: 200

                Layout.alignment: Qt.AlignHCenter

                //priceText: value.toFixed(2) //1 * price.toFixed(2)
            }

            ColumnLayout { Layout.fillWidth: true }

            CustomRoundButton {
                text: MdiFont.Icon.chevronUp
                onClicked: {
                    value = value + 10.0;
                    console.log(value);
                }
            }
        }
    }
}

