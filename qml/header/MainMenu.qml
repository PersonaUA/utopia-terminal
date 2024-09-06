import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Menu {
    x: parent.width - width
    transformOrigin: Menu.TopLeft
    Material.background: "#3e525c"

    MenuItem {
        icon.name: "List"
        //icon.source: "qrc:/img/scan.svg"

        text: qsTr("Login")
        onTriggered: {
            //root.title = qsTr("Dashboard")
            //root.icon = "qrc:/img/scan.svg"
            crp.login();
            //stackView.push("../ListThings.qml")

        }
    }

    MenuItem {
        icon.name: "Balance"        

        text: qsTr("Balance")
        onTriggered: {            
            crp.balance();
        }
    }

    MenuItem {
        icon.name: "Panel"

        text: qsTr("Panel")
        onTriggered: {
            crp.panel();
        }
    }

    MenuItem {
        icon.name: "History Trade"

        text: qsTr("History Trade")
        onTriggered: {
            crp.history_trade();
        }
    }

    MenuItem {
        icon.name: "My Orders"

        text: qsTr("My Orders")
        onTriggered: {
            crp.load_orders();
        }
    }

}
