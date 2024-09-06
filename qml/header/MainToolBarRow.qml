import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
import Qt5Compat.GraphicalEffects

import "qrc:/mdi/Icon.js" as MdiFont

import QtPositioning 5.5

import "../order"
import "../book"

RowLayout {
    width: parent
    height: 50
    spacing: 0

    ToolButton {

        Layout.fillWidth: true
        Layout.minimumWidth: 50
        Layout.maximumWidth: 50
        Layout.alignment: Qt.AlignBottom
        font.family: "Material Design Icons"
        font.pointSize: 20
        text: MdiFont.Icon.loginVariant
        onClicked: crp.login()
        //MainMenu { id: _mainMenu }
    }


    Label {
        //Layout.minimumWidth: 100
        Layout.fillWidth: true
        horizontalAlignment: Qt.AlignHCenter
        width: parent.width
        font.family: "Roboto"
        font.pointSize: 16
        text: main.title
    }

    ToolButton {

        Layout.fillWidth: true
        Layout.minimumWidth: 50
        Layout.maximumWidth: 50
        Layout.alignment: Qt.AlignBottom
        font.family: "Material Design Icons"
        font.pointSize: 20
        text: MdiFont.Icon.dotsVertical
        onClicked: _mainMenu.open()

        MainMenu { id: _mainMenu }
    }
}

