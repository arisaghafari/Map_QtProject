import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{
    //signal submitClicked()
    id : textRectangle
    color: "#f0f0f0"
    border.color : "#dedede"
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
        anchors.topMargin: 40
    }
    Column{
        id: cols
        anchors.fill: parent
        anchors.margins: 5
        anchors.topMargin: 80
        anchors.bottomMargin: 25
        spacing: 3
        Rectangle{
            border.color: "#dedede"
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
            //text.color: "red"
            id :submit
            text: "submit"
            //anchors.horizontalCenter: parent.Center
            onClicked: {
                console.log(latTextPlain.text)
                submitClicked(latTextPlain.text, lonTextPlain.text, textPlain.text)
            }
        }
    }

}

