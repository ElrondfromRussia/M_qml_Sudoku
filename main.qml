import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("MySudoku")
    width: 280
    height: 320
    visible: true

    property int diffic: 20
    signal set_diff(int dif)
    signal new_game()

    menuBar: MenuBar {
        Menu {
            title: qsTr("&Game")
            MenuItem {
                text: qsTr("&New")
                onTriggered: {
                     sap_grid.clear()
                     mainrec.color = "transparent"
                     count = 0
                     ind = 0
                     new_game()
                }
            }
            MenuItem {
                text: qsTr("Ex&it")
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: qsTr("&Settings")
            MenuItem {
                text: qsTr("&Light (20)")
                onTriggered: {diffic = 20
                    sap_grid.clear()
                    mainrec.color = "transparent"
                    count = 0
                    ind = 0
                    set_diff(20)}
            }
            MenuItem {
                text: qsTr("Middle (35)")
                onTriggered: {diffic = 35
                    sap_grid.clear()
                    mainrec.color = "transparent"
                    count = 0
                    ind = 0
                    set_diff(35)}
            }
            MenuItem {
                text: qsTr("Hard (45)")
                onTriggered: {diffic = 45
                    sap_grid.clear()
                    mainrec.color = "transparent"
                    count = 0
                    ind = 0
                    set_diff(45)}
            }
        }
    }

    property int ind: 0
    signal check_matr(int n, int ind)
    function start_uprt()
    {
        ind = 0;
        check_matr(sap_grid.get(ind).t, ind)
    }

    function get_send_cheker(ok)
    {
        if(ok === "true")
        {
            if(ind < sap_grid.count - 1)
            {
                ind += 1
                check_matr(sap_grid.get(ind).t, ind)
            }
            else
                win()
        }
        else
        {
            lose()
        }
    }
    function win()
    {
        mainrec.color = "transparent"
        sap_grid.clear()
    }
    function lose()
    {
        mainrec.color = "#ff0000"
    }

    function makeText(ind, text)
    {
        if(sap_grid.count > ind)
            sap_grid.get(ind).t = text
    }

    property int count: 0
    function fill_field(elem)
    {
        sap_grid.append({t: elem , ind: count})
        count+=1
    }

    Rectangle{
        id: mainrec
        anchors.fill: parent
        color: "#88dd88"
        Rectangle{
            id:main_rec
            anchors.top: parent.top
            width: parent.width
            height: parent.height/8*7
            color: "transparent"

            focus: true

            Image {
                id: tab
                anchors.fill: parent
                source: "fon.png"
            }

            ListModel{
                id: sap_grid
                dynamicRoles : false
            }

            Component{
                id: sap_cell
                Item{
                    id: it
                    width: main_grid.cellWidth; height: main_grid.cellHeight
                    Rectangle
                    {
                        id: recc
                        width: main_grid.cellWidth - 1;
                        anchors.centerIn: parent
                        height: main_grid.cellHeight - 1;
                        color: (t === " ") ? "#ADF9FF" : "#ffffff"
                        border.color: "#000000";
                        border.width: 1
                        radius: 4
                        opacity: 1
                        TextEdit{
                            id: txt
                            anchors.fill: parent
                            color: "#000000"
                            inputMethodHints: Qt.ImhDigitsOnly
                            text: (t === "0") ? "" : t
                            font.bold: true
                            font.pointSize: parent.height/2
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            //readOnly: true
                            onTextChanged: makeText(ind, text)
                        }
                    }
                }
            }

            GridView{
                id: main_grid
                anchors.bottom: parent.bottom
                width: parent.width
                height: parent.height

                cellWidth: parent.width/9
                cellHeight: parent.height/9
                model: sap_grid
                delegate: sap_cell
            }
        }
        Rectangle{
            id: che_btn
            anchors.top: main_rec.bottom
            anchors.topMargin: 1
            width: parent.width
            height: parent.height/8 - 1
            border.color: "#000000"
            border.width: 2
            radius: 4
            color: "#cccccc"
            TextEdit{
                id: txt1
                anchors.centerIn: parent
                color: "#000000"
                text: "Проверить"
                font.bold: true
                font.pointSize: parent.height/9*5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                readOnly: true

            }
            MouseArea{
                anchors.fill: parent;
                onClicked:
                {
                    start_uprt()
                }
            }
        }
    }
}
