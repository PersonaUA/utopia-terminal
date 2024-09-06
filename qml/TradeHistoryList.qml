import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

//Pane {
//    //color: "#333333"
//    Layout.fillWidth: true
//    Layout.fillHeight: true
//    Layout.leftMargin: 0
//    spacing: 0
//    Layout.margins: 0



    ListView {
        id: lw_trade_history
        width: parent.width
        height: main.height

        //property var historyModel

        //model: historyModel

        spacing: 0
        highlight: highlight

        delegate: TradeHistoryLine {
            historyModel: model
            historyIndex: index
            historyID: model.id

            historyPrice: model.price
            historyAmount: model.amount
            historyTime: model.created_at

            isBuy: model.is_buy

            width: lw_trade_history.width
        }
    }
//}
