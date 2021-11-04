import QtQuick 2.12
import QtQuick.Controls 1.4
import TableModel 1.0
import QtQml.Models 2.15

Rectangle{
    TableView{
        anchors.fill: parent
        //columnSpacing: 1
        //rowSpacing: 1
        clip: true

        model: TableModel {

        }
        //delegate:
        delegate: Rectangle{
            implicitWidth: 100
            implicitHeight: 50
            Text {
                text: display
            }
        }
    }
}
