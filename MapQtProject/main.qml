import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.6
import QtPositioning 5.6
import io.qt.examples.backend 1.0

Window {
    //width: Qt.platform.os == "android" ? Screen.width : 512
    //height: Qt.platform.os == "android" ? Screen.height : 512
    width: 640
    height: 480
    visible: true
    //Plugin {
    //    id: mapPlugin
    //    name: "osm" // "mapboxgl", "esri", ...
        // specify plugin parameters if necessary
        // PluginParameter {
        //     name:
        //     value:
        // }
    //}
    ////////////////////
    /*Map {
        id: map
        anchors.fill: parent
        //plugin: Plugin {name: "osm"}
        plugin: mapPlugin
        zoomLevel: 14
        //zoomLevel: (maximumZoomLevel - minimumZoomLevel)/2
        center {
            // The Qt Company in Oslo
            latitude: 35.736415
            longitude: 51.401520
        }

        MapQuickItem {
            id:marker
            sourceItem: Image{
                id: image
                source: "/images/images.png"
                width: 70
                height: 45
            }
        }

        MouseArea {
            anchors.fill: parent
            onPressed: {
                marker.coordinate = map.toCoordinate(Qt.point(mouse.x,mouse.y))
            }
            onClicked: console.log('latitude = '+ (map.toCoordinate(Qt.point(mouse.x,mouse.y)).latitude),
                                           'longitude = '+ (map.toCoordinate(Qt.point(mouse.x,mouse.y)).longitude));
        }*/
    //////////////////////////
        BackEnd {
            id: backend
        }
        Column{
            id: cols
            anchors.fill: parent
            anchors.margins: 5
            spacing: 3
        Rectangle{
            border.color: "gray"
            height: 25
            border.width: 1
            id : frame
            width: parent.width

            TextInput{
                id : textPlain
                anchors.fill: parent
                anchors.margins: 4
            }
        }

            //topPadding: 8
            //font.pointSize: 14
            //bottomPadding: 16
            //text:  backend.userName
            //property string placeholderText: qsTr("User name")
            //anchors.centerIn: parent
            //onEditingFinished: backend.userName = text
        }

   // }
}
