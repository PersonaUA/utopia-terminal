import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
import Qt5Compat.GraphicalEffects

import "qrc:/mdi/Icon.js" as MdiFont

import QtPositioning 5.5

import "../order"
import "../book"

ToolBar {
    id: toolBar

    property int bar_height: 450

    background: Item {
        implicitHeight: toolBar.bar_height

        Rectangle {
            id: head
            width: main.width
            height: toolBar.bar_height
            anchors.bottom: parent.bottom
            color: "#17212b" //Material.color(Material.BlueGrey)

            radius: 3
        }
    }

    layer.enabled: true

    layer.effect: DropShadow {
        anchors.fill: toolBar
        horizontalOffset: 0
        verticalOffset: 1
        radius: 3
        samples: 10
        color: "#000"
        opacity: 0.2
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0
        Layout.margins: 0

        MainToolBarRow {}

        RowLayout { Layout.fillHeight: true }

        HeaderTradeRow {}

        HeaderOrdersRow {}

        RowLayout { Layout.fillHeight: true }

        HeaderLine {}
    }
}
