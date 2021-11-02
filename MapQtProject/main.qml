import QtQuick 2.12
import QtQuick.Window 2.12

import QtLocation 5.6
import QtPositioning 5.6

Window {
    width: Qt.platform.os == "android" ? Screen.width : 512
    height: Qt.platform.os == "android" ? Screen.height : 512
    visible: true
    Plugin {
        id: mapPlugin
        name: "osm" // "mapboxgl", "esri", ...
        // specify plugin parameters if necessary
        // PluginParameter {
        //     name:
        //     value:
        // }
    }

    /*Map {
        id:map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate()
        zoomLevel: 14
    }
    MouseArea{
        anchors.fill: parent
        onClicked: console.log('latitude = '+ (map.toCoordinate(Qt.point(mouse.x,mouse.y)).latitude),
                                       'longitude = '+ (map.toCoordinate(Qt.point(mouse.x,mouse.y)).longitude));
    }*/
    Map {
        id: map
        anchors.fill: parent
        //plugin: Plugin {name: "osm"}
        plugin: mapPlugin
        //zoomLevel: 14
        zoomLevel: (maximumZoomLevel - minimumZoomLevel)/2
        center {
            // The Qt Company in Oslo
            latitude: 59.9485
            longitude: 10.7686
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
            anchors.fill: parent
            onPressed: {
                marker.coordinate = map.toCoordinate(Qt.point(mouse.x,mouse.y))
            }
            onClicked: console.log('latitude = '+ (map.toCoordinate(Qt.point(mouse.x,mouse.y)).latitude),
                                           'longitude = '+ (map.toCoordinate(Qt.point(mouse.x,mouse.y)).longitude));
        }
    }
}
