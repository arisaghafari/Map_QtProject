import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{
    id : textRectangle
    color: "#dedede"
    border.color : "gray"
    radius : 5
    visible: true

    Text{
        id : latTextPlain
        anchors.fill: parent
        anchors.margins: 4
    }
    Text{
        id : lonTextPlain
        anchors.fill: parent
        anchors.margins: 4
        anchors.topMargin: 25
    }
    Column{
        id: cols
        anchors.fill: parent
        anchors.margins: 5
        anchors.topMargin: 50
        spacing: 3
        Rectangle{
            border.color: "gray"
            height: parent.height - 35
            border.width: 1
            id : frame
            width: parent.width

            TextInput{
                id : textPlain
                anchors.fill: parent
                anchors.margins: 4
            }
        }
        Button{
            id :submit
            text: "submit"
            anchors.horizontalCenter: parent.Center
        }
    }

}

