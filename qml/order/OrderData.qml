import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    //Layout.fillWidth: true

    Layout.minimumWidth: 100
    Layout.maximumWidth: 100
    Layout.preferredWidth: 100

    property real orderData
    property int round

    property string prefix: ""
    property string suffix: ""

    property int horAlignment: 1

    Label {
        Layout.fillWidth: true
        horizontalAlignment: horAlignment == 1 ? Qt.AlignLeft : Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        font.pointSize: 11
        font.family: "Roboto"
        color: "#bbbbbb"

        //Layout.leftMargin: 20

        text: prefix + 1 * orderData.toFixed(round) + suffix
    }
}
