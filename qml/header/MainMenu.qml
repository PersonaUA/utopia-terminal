import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
import QtQuick.Dialogs

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
           // crp.login();
            //stackView.push("../ListThings.qml")

            signInDialog.open()
        }

        Dialog {
                id: signInDialog
                title: "Sign In"

                parent: Overlay.overlay

                x: Math.round((parent.width - width) / 2)
                y: Math.round((parent.height - height) / 2)
                width: 640
                height: 250

                margins: 5
                padding: 15


                ColumnLayout {
                    width: parent.width
                    height: parent.height
                    spacing: 0
                    //anchors.fill: parent

                SignInItem {
                    id: pk
                    placeholderText: "Public Key"
                    value: settings.pk
                    fontSize: 12

                }
                SignInItem {
                    id: pass
                    placeholderText: "Password"
                    value: settings.pass
                    fontSize: 12
                }

                }
                standardButtons: Dialog.Ok | Dialog.Cancel

                onAccepted: {

                    settings.pk = pk.value
                    settings.pass = pass.value

                    crp.login(settings.pk, settings.pass);
                }

                onRejected: {
                    pk.value = settings.pk
                    pass.value = settings.pass
                }
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
