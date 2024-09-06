import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


ListView {
    id: lw_book_list
    width: parent.width
    height: main.height

    spacing: 1
    highlight: highlight

    delegate: BookLine {
        orderModel: model
        orderIndex: index
        orderID: model.id
        orderPrice: model.price
        orderAmount: model.amount
        orderValue: model.value
        orderWidth: lw_book_list.width
    }
}


