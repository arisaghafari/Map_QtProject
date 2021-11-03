import QtQuick 2.12
import QtQuick.Window 2.12

import QtLocation 5.6
import QtPositioning 5.6
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.4

Window {
    width: Qt.platform.os == "android" ? Screen.width : 512
    height: Qt.platform.os == "android" ? Screen.height : 512
    visible: true
    Plugin {
        id: mapPlugin
        name: "osm" // "mapboxgl", "esri", ...
    }
    property var secondWindow: null

    function createSecondWindow(x, y){

        if(secondWindow !== null){
            destroySecondWindow()
        }
        if(secondWindow == null){
            console.log("create component")
            var component = Qt.createComponent("SecondWindow.qml")
            secondWindow = component.createObject(mouseArea, {"x":x + 20 , "y":y - 100, "width": 100, "height":100} )
        }
    }
    function destroySecondWindow(){
        secondWindow.destroy()
        secondWindow = null
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        zoomLevel: 14
        //zoomLevel: (maximumZoomLevel - minimumZoomLevel)/2
        center {
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
            coordinate: map.center
            anchorPoint.x: 0
            anchorPoint.y: 0
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onPressed: {
                marker.coordinate = map.toCoordinate(Qt.point(mouse.x,mouse.y))
            }
            onClicked: createSecondWindow(mouseX, mouseY)
        }
    }
}
