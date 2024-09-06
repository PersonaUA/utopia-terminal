import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: priceTextInput

    //property string priceText: ""

    property int fontSize: 20

    //property string placeholderText: "Price"


    implicitHeight: input.font.pixelSize * 1.5
   // implicitWidth: 100

    Rectangle{
        id: body
        color: "transparent"
        anchors.fill: parent
        border.color: "#232e3c"
        border.width: 1
        radius: 4
       // Layout.margins: 10


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
            text: 1 * value.toFixed(2) // 1 * price.toFixed(2) //priceText


            Text {
                width: parent.width
                horizontalAlignment: Qt.AlignRight
                text: placeholderText
                color: "#888"
                rightPadding: 5


                //Layout.leftMargin: 10
                //visible: !textEdit.text
                layer.enabled: true
            }

            onTextEdited: {
                if (placeholderText == "Price Buy")
                    main.price_buy = parseFloat(input.text);
                else if (placeholderText == "Price Sell")
                    main.price_sell = parseFloat(input.text);
            }

        }
    }
}
