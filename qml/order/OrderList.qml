import QtQuick
import QtQuick.Controls
import QtQuick.Layouts



ListView {
    id: lw_orders
    width: parent.width
    height: 150

    model: ordersModel

    spacing: 1
    highlight: highlight

    delegate: OrderLine {

        orderModel: model
        orderIndex: index
        orderID: model.order_id

        //orderTask: model.task
        orderPrice: model.price
        orderAmount: model.amount
        orderValue: model.value

        //orderCur: model.cur
        //orderEcur: model.ecur
    }
}
