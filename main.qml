// UTOPIA PROJECT

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "qml"
import "qml/order"
import "qml/book"
import "qml/header"

ApplicationWindow {

    id: main
    property string title
    property string logTxt

    property real price_buy: 0
    property real price_sell: 0

    property real amount_buy: 0
    property real amount_sell: 0

    width: 1000
    height: 820
    visible: true
    title: "BTC / USDT"

    Material.background: "#364554"

    header: MainHeader {} // bar_height: Qt.platform.os === "android" ? 210 : 250 }

    RowLayout {
        anchors.fill: parent
        focus: false
        spacing: 1

        // SALE BOOK LIST
        Rectangle {
            color: 'transparent'
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.maximumWidth: main.width * 0.4

            ScrollView {
                width: parent.width
                height: parent.height

                BookList {
                    model: crp.buy_book
                }
            }
        }

        // TRADE HISTORY LIST
        Rectangle {
            color: 'transparent'
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.maximumWidth: parent.width * 0.2

            ScrollView {

                width: parent.width
                height: parent.height

                TradeHistoryList {
                    model: crp.history_trade_items
                }
            }
        }

        // BUY BOOK LIST
        Rectangle {
            color: 'transparent'
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.maximumWidth: parent.width * 0.4

            ScrollView {

                width: parent.width
                height: parent.height

                BookList {
                    model: crp.sell_book
                }
            }
        }

    }
}
