import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

//import "book"
//import "qrc:/qml/book/BookHeaderLine.qml" as BookHeaderLine

Rectangle {
    id: rec_header
    Layout.fillWidth: true
    width: main.width
    height: 30
    color: "#232e3c"

    RowLayout {
        width: parent.width
        height: parent.height

        Layout.fillWidth: true
        Layout.fillHeight: true

        spacing: 0

        BookHeaderLine {
            //sale
            width: parent.width * 0.4
            height: parent.height
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#132e3c"

            leftMargin: 20
            rightMargin: 15
        }

        BookHeaderLine {
            //history
            width: parent.width * 0.2
            height: parent.height

            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#132e3c"

            leftMargin: 10
            rightMargin: 5
        }

        BookHeaderLine {
            //buy
            width: parent.width * 0.4
            height: parent.height
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#132e3c"

            leftMargin: 20
            rightMargin: 15
        }

    }
}

