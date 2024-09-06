import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Slider {
    id: control

    from: 0
    to: 100
    stepSize: 10

    value: 20

    snapMode: Slider.SnapAlways

    background: Rectangle {
        id: circle
        x: control.leftPadding
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 300
        implicitHeight: 4
        width: control.availableWidth
        height: implicitHeight
        radius: 2
        color: "#bdbebf"

        Rectangle {
            width: control.visualPosition * parent.width
            height: parent.height
            color: "#21be2b"
            radius: 2
        }


        RowLayout {
            spacing: 20
            Repeater {

                id: repeater
                model: 11
                width: 280 //control.availableWidth - width //parent.width


                Rectangle {
                    id: rec
                    property int tickIndex: index
                    //Layout.leftMargin: 10

                    width: 8; height: 8
                    radius: rec.width / 2

                    //border.width: 1
                    color: "#bdbebf"
                    //x: tickIndex * 70
                    y: control.topPadding + control.availableHeight / 2 - height / 2 - 14 // circle.y - 17 // control.availableHeight / 2 //- height / 2


                }
            }
        }
    }

    handle: Rectangle {
        x: control.visualPosition * 280 // (control.availableWidth - width)
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 20
        implicitHeight: 20
        radius: 10
        color: control.pressed ? "#f0f0f0" : "#f6f6f6"
        border.color: "#bdbebf"
    }

    onMoved: {
        if (trade_container.name == "Buy")
        {
            amount_buy = crp.buy_balance / main.price_buy * control.visualPosition;
            console.log(amount_buy);
        }
        else if (trade_container.name == "Sell")
        {
            amount_sell = parseFloat(crp.sell_balance.toFixed(5)) * main.price_sell * control.visualPosition;
            console.log(amount_sell);
        }

        console.log(control.visualPosition);
    }
}
