import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

RowLayout {
    id: trade_line
    width: parent
    height: 150
    spacing: 0

    layer.enabled: true


    TradeContainer {
        id: buy_trade_container

        name: "Buy"

        Layout.maximumWidth: main.width * 0.4

        price: crp.buy_price
        amount: crp.buy_amount


        button_text: qsTr("Купить BTC")

        balance: crp.buy_balance //+ " USDT"
        reserve: crp.buy_balance_reserve

        round: crp.buy_round
        img_source: "qrc:/img/usdt_32.png"
    }

    BotContainer {
        id: bot_container
        Layout.maximumWidth: main.width * 0.2
        button_text: qsTr("START")
    }

    TradeContainer {
        id: sell_trade_container

        name: "Sell"

        Layout.maximumWidth: main.width * 0.4

        price: crp.sell_price
        amount: crp.sell_amount



        button_text: qsTr("Продать BTC")

        balance: crp.sell_balance //" BTC"
        reserve: crp.sell_balance_reserve

        round: crp.sell_round
        img_source: "qrc:/img/btc_32.png"
    }


}
